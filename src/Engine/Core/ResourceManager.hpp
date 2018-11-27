#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "Engine/Core/Utilities.hpp"
#include <string>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>

template<typename T>
using ResourcePair = std::pair<T*, unsigned int>;
template<typename T>
using ResourceContainer = std::unordered_map<std::string, ResourcePair<T>>;
using PathContainer = std::unordered_map<std::string, std::string>;

template <typename Derived, typename T>
class ResourceManager
{
public:
    ResourceManager(const std::string& pathsFile)
    {
        loadPaths(pathsFile);
    }

    virtual ~ResourceManager() { purgeResources(); }

    T* getResource(const std::string& id)
    {
        //sf::Lock lock(m_mutex);
		auto res = find(id);
		return(res ? res->first : nullptr);
    }

    bool requireResource(const std::string& id)
    {
        auto res = find(id);
		if(res){
			++res->second;
			return true;
		}
		auto path = m_paths.find(id);
		if (path == m_paths.end()){ return false; }
		T* resource = load(path->second);
		if (!resource){ return false; }
		m_resources.emplace(id, std::make_pair(resource, 1));
		return true;
    }
    
    bool releaseResource(const std::string& id)
    {
        //sf::Lock lock(m_mutex);
		auto res = find(id);
		if (!res) { return false; }
		--res->second;
		if (!res->second) { unload(id); }
		return true;
    }
    
    void purgeResources()
    {
        //sf::Lock lock(m_mutex);
        std::cout << "Purging all resources:" << std::endl;
        while(m_resources.begin() != m_resources.end()) {
            std::cout << "Removing: " << m_resources.begin()->first << std::endl;
            m_resources.erase(m_resources.begin());
        }
        std::cout << "Purging finished." << std::endl;
    }

protected:
    T* load(const std::string& path)
    {
        return static_cast<Derived*>(this)->load(path);
    }

private:
    ResourcePair<T>* find(const std::string& id)
    {
		auto itr = m_resources.find(id);
		return (itr != m_resources.end() ? &itr->second : nullptr);
	}

    bool unload(const std::string& id)
    {
        auto itr = m_resources.find(id);
		if (itr == m_resources.end()) { return false; }
		m_resources.erase(itr);
		return true;
    }

    void loadPaths(const std::string& pathFile) {
		std::ifstream paths;
		paths.open(Utils::GetWorkingDirectory() + pathFile);
		if(paths.is_open()) {
			std::string line;
			while(std::getline(paths,line)) {
				std::stringstream keystream(line);
				std::string pathName;
				std::string path;
				keystream >> pathName;
				keystream >> path;
				m_paths.emplace(pathName,path);
			}
			paths.close();
			return;
		}
		std::cerr << "! Failed loading the path file: " << pathFile << std::endl;
	}

    ResourceContainer<T> m_resources;
    PathContainer m_paths;
    // sf::Mutex m_mutex;
};

#endif