#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H

#include <map>
#include <string>
#include <cassert>

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
    void load(Identifier id, const std::string& filename);
    template <typename Parameter>
    void load(Identifier id, const std::string& filename, const Parameter& secondParam);
    Resource& get(Identifier id);
    const Resource& get(Identifier id) const;

private:
    void insertResource(Identifier id, Resource* resource);

    std::map<Identifier, Resource*> resource_map;
};

#include "Engine/Core/ResourceHolder.inl"

#endif