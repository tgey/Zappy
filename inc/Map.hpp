/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** map
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
class Map {
	public:
		Map(Manager &manager);
		~Map();
		int getOriginX() const;
		int getOriginY() const;
		float getChangeX() const;
		float getChangeY() const;
		int getTotalWidth() const;
		float getSquareSize() const;
		float getInitialSquareSize() const;
		int getLongest() const;
		float getImgScale() const;
		void realTimeEvents();
		void initMapData();
		graph_t *getGraph();
		void draw(sf::RenderWindow &window);
		void run(sf::RenderWindow &window);
		void zoom();
		void unzoom();
		void eventHandler(sf::RenderWindow &window, sf::Event &event);
		void handleMoreEvents(sf::RenderWindow &window, sf::Event &);
		sf::Vector2i getTarget() const;
		void drawSquare(sf::RenderWindow &window, bool,
			std::pair<sf::Vector2i, sf::Vector2i>);
		void scrollSmoothly();
		void block();

	protected:
	private:
		Manager &_manager;
		sf::Sprite _mapClearSprite;
		sf::Sprite _mapDarkSprite;
		sf::Sprite _mapMoreClearSprite;
		sf::Sprite _mapMoreDarkSprite;
		sf::Texture _mapClearTexture;
		sf::Texture _mapDarkTexture;
		sf::Texture _mapMoreClearTexture;
		sf::Texture _mapMoreDarkTexture;
		int _originX;
		int _originY;
		float _changeX;
		float _changeY;
		int _totalWidth;
		int _longest;
		float _squareSize;
		float _initialSquareSize;
		float _imgScale;
		bool _initialized;
		sf::Vector2i _target;
		sf::Vector2i _scrollTo;
		float _speedScrollX;
		float _speedScrollY;
};
