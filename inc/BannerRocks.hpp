/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** BannerRocks
*/

#ifndef BANNERROCKS_HPP_
	#define BANNERROCKS_HPP_

extern "C" {
	#include "graph.h"
}

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cassert>
#include <iostream>

class Manager;

class BannerRocks {
	public:
		BannerRocks(Manager &manager);
		~BannerRocks();
		sf::Vector2i getTarget() const;
		void run(sf::RenderWindow &window);
		void drawRocks(sf::RenderWindow &window);
		void drawSquareText(sf::RenderWindow &window, int opacity,
			std::string text);
		sf::Text drawStoneText(sf::Text
			textLabel, std::string text, int posX);
		void manageStoneText(sf::RenderWindow &window);
		void placeGems();
		void setText(sf::Text &);
		void setTexts();
		graph_t *getGraph();

	protected:
	private:
		Manager &_manager;
		sf::Font _font;
		sf::Text _infoSquare;
		sf::Text _lineText;
		sf::Text _deraText;
		sf::Text _sibuText;
		sf::Text _mendText;
		sf::Text _phirText;
		sf::Text _thysText;
		sf::Texture _gemRedTexture;
		sf::Texture _gemBlueTexture;
		sf::Texture _gemGreenTexture;
		sf::Texture _gemYellowTexture;
		sf::Texture _gemPinkTexture;
		sf::Texture _gemPurpleTexture;
		sf::Sprite _gemRedSprite;
		sf::Sprite _gemBlueSprite;
		sf::Sprite _gemGreenSprite;
		sf::Sprite _gemYellowSprite;
		sf::Sprite _gemPinkSprite;
		sf::Sprite _gemPurpleSprite;
};

#endif /* !BANNERROCKS_HPP_ */
