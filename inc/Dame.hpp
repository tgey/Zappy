/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** dame
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <cassert>
#include <iostream>

class Dame {
	public:
		Dame(sf::RenderWindow &);
		~Dame();
		void draw(sf::RenderWindow &window);

	protected:
	private:
		sf::Font _font;
		sf::Sprite _dameSprite;
		sf::Texture _dameTexture;
		sf::Text _quote;
};
