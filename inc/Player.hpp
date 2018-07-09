/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** player
*/

#pragma once

extern "C" {
	#include "graph.h"
}

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cassert>
#include <iostream>
#include "Animation.hpp"

class Manager;
class Player {
	public:
		Player(Manager &manager, t_player *player);
		~Player();
		void draw(sf::RenderWindow &window);
		void run(sf::RenderWindow &window);
		graph_t *getGraph();
		void setPosition(sf::Vector2i position);
		void setPosition(sf::Vector2f position);
		void updatePosition();
		int getFrequency() const;
		int getOriginX() const;
		int getOriginY() const;
		float getChangeX() const;
		float getChangeY() const;
		int getTotalWidth() const;
		float getSquareSize() const;
		float getInitialSquareSize() const;
		int getLongest() const;
		float getImgScale() const;
		void setDirection(Direction);
		Direction getDirection() const;
		sf::Vector2f getPosition() const;
		void setupMove();
		void setupRotateRight();
		void setupRotateLeft();
		void setupIncantate();
		void setupNewAnimation();
		bool isPlayerWithFd(int fd);

	protected:
	private:
		Manager &_manager;
		sf::Vector2f _random;
		sf::Vector2f _position;
		Animation *_animation;
		sf::Sprite _sprite;
		Direction _direction;
		t_player *_player;
};
