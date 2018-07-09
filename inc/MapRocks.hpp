/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** rocks
*/

#pragma once

extern "C" {
	#include "graph.h"
}

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cassert>
#include <iostream>

class Manager;
class MapRocks {
	public:
		MapRocks(Manager &manager);
		~MapRocks();
		void run(sf::RenderWindow &);
		void draw(sf::RenderWindow &);
		graph_t *getGraph();
		void drawResourcesCell(sf::RenderWindow &window,
			cell_t *cell, std::pair<int, int> idx);
		void setupPercents();
		void drawResourcesSquare(sf::RenderWindow &window,
			t_chained_list *list,
			std::pair<std::pair<int, int>, sf::Sprite> idx);
		void setScales();

	protected:
	private:
		Manager &_manager;
		bool _initialized;
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
		sf::Texture _foodTexture;
		sf::Sprite _foodSprite;
};
