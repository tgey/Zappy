/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** CommandInfo
*/

#include "CommandInfo.hpp"
#include "Manager.hpp"

CommandInfo::CommandInfo(Manager &manager) : _manager(manager)
{
	assert(_font.loadFromFile("./design/Supercell-magic-webfont.ttf"));
	initSprites();
	initText();
}

CommandInfo::~CommandInfo()
{
}

void	CommandInfo::initText()
{
	_zoom.setFont(_font);
	_zoom.setCharacterSize(15);
	_zoom.setPosition(75, 960);
	_zoom.setFillColor(sf::Color(0, 0, 0, 200));
	_zoom.setString("Zoom");
	_zoom.setStyle(sf::Text::Bold);
	_unzoom.setFont(_font);
	_unzoom.setCharacterSize(15);
	_unzoom.setPosition(140, 960);
	_unzoom.setFillColor(sf::Color(0, 0, 0, 200));
	_unzoom.setString("Unzoom");
	_unzoom.setStyle(sf::Text::Bold);
	_movement.setFont(_font);
	_movement.setCharacterSize(15);
	_movement.setPosition(245, 960);
	_movement.setFillColor(sf::Color(0, 0, 0, 200));
	_movement.setString("Move on the map");
	_movement.setStyle(sf::Text::Bold);
}

void	CommandInfo::initSprites()
{
	assert(_ATexture.loadFromFile("./design/A.png"));
	_ASprite.setTexture(_ATexture);
	_ASprite.setPosition(50, 880);
	assert(_ZTexture.loadFromFile("./design/Z.png"));
	_ZSprite.setTexture(_ZTexture);
	_ZSprite.setPosition(120, 880);
	assert(_ArrowLeftTexture.loadFromFile("./design/ArrowLeft.png"));
	_ArrowLeftSprite.setTexture(_ArrowLeftTexture);
	_ArrowLeftSprite.setPosition(220, 890);
	assert(_ArrowUpDownTexture.loadFromFile("./design/ArrowUpDown.png"));
	_ArrowUpDownSprite.setTexture(_ArrowUpDownTexture);
	_ArrowUpDownSprite.setPosition(280, 875);
	assert(_ArrowRightTexture.loadFromFile("./design/ArrowRight.png"));
	_ArrowRightSprite.setTexture(_ArrowRightTexture);
	_ArrowRightSprite.setPosition(340, 890);
}

void	CommandInfo::run(sf::RenderWindow &window)
{
	window.draw(_ASprite);
	window.draw(_ZSprite);
	window.draw(_ArrowLeftSprite);
	window.draw(_ArrowUpDownSprite);
	window.draw(_ArrowRightSprite);
	window.draw(_zoom);
	window.draw(_unzoom);
	window.draw(_movement);
}