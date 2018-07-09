/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** game manager
*/

#pragma once

extern "C" {
	#include "graph.h"
}

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cassert>
#include <iostream>
#include "Map.hpp"
#include "MapRocks.hpp"
#include "FrequencyScroller.hpp"
#include "BannerRocks.hpp"
#include "Player.hpp"
#include "Menu.hpp"
#include "Cloud.hpp"
#include "CommandHandler.hpp"
#include "CommandInfo.hpp"

class Manager {
	public:
		Manager(sf::RenderWindow &window, graph_t *graph);
		~Manager();
		bool isActive() const;
		void setActive(bool active);
		void setIsActiveScroller(bool);
		void draw(sf::RenderWindow &window);
		void eventHandler(sf::RenderWindow &window, sf::Event &);
		void realTimeEvents();
		bool run(sf::RenderWindow &window);
		void drawInside(sf::RenderWindow &window);
		int getOriginX() const;
		int getOriginY() const;
		float getChangeX() const;
		float getChangeY() const;
		int getTotalWidth() const;
		float getSquareSize() const;
		float getInitialSquareSize() const;
		int getLongest() const;
		float getImgScale() const;
		sf::Vector2i getTarget() const;
		int getFrequency() const;
		void setFrequency(int);
		float getMaximum() const;
		void setMaximum(float);
		graph_t *getGraph() const;
		void initMapData();
		void setupPercents();
		void sendFrequencyToServer();
		void managePlayers(sf::RenderWindow &window);
		void createNewPlayer(t_player *player);
		void deletePlayer();
		void deletePlayerInVector(t_player *player);

	protected:
	private:
		bool _active;
		sf::Texture _backTexture;
		sf::Sprite _backSprite;
		sf::Texture _gameBackTexture;
		sf::Sprite _gameBackSprite;
		sf::Sprite _squareBackSprite;
		sf::Texture _squareBackTexture;
		sf::Font _font;
		graph_t *_graph;
		CommandHandler *_handler;
		sf::Text _connecting;
		Map *_map;
		MapRocks *_mapRocks;
		FrequencyScroller *_scroller;
		BannerRocks *_banRocks;
		std::vector<Player *> _players;
		Menu *_menu;
		Cloud *_cloud;
		CommandInfo *_info;
};
