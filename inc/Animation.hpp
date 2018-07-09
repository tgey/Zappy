/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** animation
*/

#pragma once

extern "C" {
	#include "graph.h"
}

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cassert>
#include <iostream>
#include <math.h>

enum Direction {
	TOP,
	RIGHT,
	BOTTOM,
	LEFT
};

enum Activity {
	IDLE,
	ROTATE_LEFT,
	ROTATE_RIGHT,
	MOVE,
	INCANTATION
};

class Player;
class Animation {
	public:
		Animation(Player &player);
		~Animation();
		void setIdleSprites();
		void setRunSprites();
		void setRotateSprites();
		void run(sf::RenderWindow &window);
		void setOrigin(sf::Vector2f origin);
		void setEnd(sf::Vector2f end);
		sf::Vector2f getOrigin() const;
		sf::Vector2f getEnd() const;
		graph_t *getGraph();
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
		void setIdles();
		void idle(sf::RenderWindow &window);
		void setActivity(Activity activity);
		Activity getActivity() const;
		void setDirection(Direction direction);
		Direction getDirection() const;
		void setupMove();
		void endMove();
		void move(sf::RenderWindow &window);
		void moveTop(sf::RenderWindow &window);
		void moveRight(sf::RenderWindow &window);
		void moveBottom(sf::RenderWindow &window);
		void moveLeft(sf::RenderWindow &window);
		void setupRotateRight();
		void setupRotateLeft();
		void rotationTopRight(sf::RenderWindow &, sf::Time &);
		void rotationTopLeft(sf::RenderWindow &, sf::Time &);
		void rotationBottomRight(sf::RenderWindow &, sf::Time &);
		void rotationBottomLeft(sf::RenderWindow &, sf::Time &);
		void rotateRight(sf::RenderWindow &);
		void rotateLeft(sf::RenderWindow &);
		void setRotates();
		void setRotatesTop();
		void endRotation();
		void setIncantationSprites();
		void endIncantation();
		void setupIncatate();
		void incantate(sf::RenderWindow &window);
		void setIncantate();
		void incant(sf::RenderWindow &window, sf::Time &t);
		void endAnimation();

	protected:
	private:
		Player &_player;
		sf::Vector2f _origin;
		sf::Vector2f _end;
		Activity _activity;
		sf::Sprite _idleTopSprite;
		sf::Sprite _idleRightSprite;
		sf::Sprite _idleBottomSprite;
		sf::Sprite _idleLeftSprite;
		sf::Texture _idleTopTexture;
		sf::Texture _idleRightTexture;
		sf::Texture _idleBottomTexture;
		sf::Texture _idleLeftTexture;
		sf::Sprite _runTopSprite;
		sf::Sprite _runRightSprite;
		sf::Sprite _runBottomSprite;
		sf::Sprite _runLeftSprite;
		sf::Texture _runTopTexture;
		sf::Texture _runRightTexture;
		sf::Texture _runBottomTexture;
		sf::Texture _runLeftTexture;
		sf::Clock _duration;
		sf::Sprite _rotateTopLeftSprite;
		sf::Sprite _rotateTopRightSprite;
		sf::Sprite _rotateBottomLeftSprite;
		sf::Sprite _rotateBottomRightSprite;
		sf::Texture _rotateTopLeftTexture;
		sf::Texture _rotateTopRightTexture;
		sf::Texture _rotateBottomLeftTexture;
		sf::Texture _rotateBottomRightTexture;
		sf::Sprite _incantationSprite;
		sf::Texture _incantationTexture;
};
