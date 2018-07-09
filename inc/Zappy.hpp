/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** zappy
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cassert>
#include <iostream>
#include "Form.hpp"

class Zappy {
	public:
		Zappy(sf::RenderWindow &);
		~Zappy();
		bool isActive() const;
		void setActive(bool active);
		void draw(sf::RenderWindow &);
		void eventHandler(sf::RenderWindow &, sf::Event &);
		void run(sf::RenderWindow &);
		void manageSize();
		void initTexts();

	protected:
	private:
		bool _active;
		sf::Texture _backTexture;
		sf::Sprite _backSprite;
		sf::Text _clickOnScreenToPlay;
		sf::Text _clashOfZappyFront;
		sf::Text _clashOfZappyBack;
		sf::Font _font;
		float _size;
		int _higher;
		sf::Vector2u _screenSize;
		sf::SoundBuffer	_musicBuffer;
		sf::Sound	_musicSound;
};
