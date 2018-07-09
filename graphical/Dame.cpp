/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Dame
*/

#include "Dame.hpp"

Dame::Dame(sf::RenderWindow &window)
{
	sf::FloatRect rect;
	sf::Vector2u size = window.getSize();

	assert(_font.loadFromFile("./design/Supercell-magic-webfont.ttf"));
	assert(_dameTexture.loadFromFile("./design/dame.png"));
	_dameSprite.setTexture(_dameTexture);
	rect = _dameSprite.getLocalBounds();
	_dameSprite.setPosition(100, size.y - rect.height);
	_quote.setString(std::string("Enter the port id,\nhostname and your\n"
		"team name to connect\nto the server."));
	_quote.setFont(_font);
	_quote.setCharacterSize(15);
	_quote.setStyle(sf::Text::Bold);
	_quote.setPosition(325, size.y - rect.height + 60);
	_quote.setFillColor(sf::Color(0, 0, 0, 220));
}

Dame::~Dame()
{
}

void Dame::draw(sf::RenderWindow &window)
{
	window.draw(_dameSprite);
	window.draw(_quote);
}
