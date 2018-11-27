#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include "Engine/Core/ResourceManager.hpp"
#include <SFML/Graphics/Font.hpp>

class FontManager : public ResourceManager<FontManager, sf::Font>
{
public:
    FontManager() : ResourceManager("resources/fonts.cfg") {}

    sf::Font* load(const std::string& path)
    {
        sf::Font* font = new sf::Font();
        if(!font->loadFromFile(Utils::GetWorkingDirectory() + path))
		{
			delete font;
			font = nullptr;
			std::cerr << "! Failed to load font: " << path << std::endl;
		}
		return font;
    }
};

#endif