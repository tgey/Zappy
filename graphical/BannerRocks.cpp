/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** BannerRocks
*/

#include "BannerRocks.hpp"
#include "Manager.hpp"

BannerRocks::BannerRocks(Manager &manager) : _manager(manager)
{
	assert(_font.loadFromFile("./design/Supercell-magic-webfont.ttf"));
	_infoSquare.setFont(_font);
	_infoSquare.setCharacterSize(20);
	_infoSquare.setPosition(1200, 990);
	_infoSquare.setStyle(sf::Text::Bold);
	assert(_gemBlueTexture.loadFromFile("./design/gem_blue.png"));
	_gemBlueSprite.setTexture(_gemBlueTexture);
	assert(_gemGreenTexture.loadFromFile("./design/gem_green.png"));
	_gemGreenSprite.setTexture(_gemGreenTexture);
	assert(_gemYellowTexture.loadFromFile("./design/gem_yellow.png"));
	_gemYellowSprite.setTexture(_gemYellowTexture);
	assert(_gemRedTexture.loadFromFile("./design/gem_red.png"));
	_gemRedSprite.setTexture(_gemRedTexture);
	assert(_gemPinkTexture.loadFromFile("./design/gem_pink.png"));
	_gemPinkSprite.setTexture(_gemPinkTexture);
	assert(_gemPurpleTexture.loadFromFile("./design/gem_purple.png"));
	_gemPurpleSprite.setTexture(_gemPurpleTexture);
	setTexts();
	placeGems();
}

BannerRocks::~BannerRocks()
{
}

void BannerRocks::placeGems()
{
	_gemGreenSprite.setPosition(1230, 880);
	_gemBlueSprite.setPosition(1330, 880);
	_gemYellowSprite.setPosition(1430, 880);
	_gemPurpleSprite.setPosition(1530, 880);
	_gemPinkSprite.setPosition(1630, 880);
	_gemRedSprite.setPosition(1730, 880);
}

void BannerRocks::setText(sf::Text &textLabel)
{
	textLabel.setFont(_font);
	textLabel.setCharacterSize(20);
	textLabel.setStyle(sf::Text::Bold);
	textLabel.setFillColor(sf::Color(0, 0, 0, 190));
}

void BannerRocks::setTexts()
{
	setText(_lineText);
	setText(_deraText);
	setText(_sibuText);
	setText(_mendText);
	setText(_phirText);
	setText(_thysText);
}

sf::Vector2i BannerRocks::getTarget() const
{
	return _manager.getTarget();
}

void	BannerRocks::drawRocks(sf::RenderWindow &window)
{
	window.draw(_gemGreenSprite);
	window.draw(_gemBlueSprite);
	window.draw(_gemYellowSprite);
	window.draw(_gemPinkSprite);
	window.draw(_gemPurpleSprite);
	window.draw(_gemRedSprite);
}

void	BannerRocks::drawSquareText(sf::RenderWindow &window, int opacity,
	std::string text)
{
	_infoSquare.setFillColor(sf::Color(0, 0, 0, opacity));
	_infoSquare.setString(text);
	window.draw(_infoSquare);
}

sf::Text	BannerRocks::drawStoneText(sf::Text textLabel,
	std::string text, int posX)
{
	textLabel.setPosition(posX + _gemBlueSprite.getTexture()->getSize()
		.x / 2 - textLabel.getLocalBounds().width / 2, 940);
	textLabel.setString(text);
	return textLabel;
}

graph_t *BannerRocks::getGraph()
{
	return _manager.getGraph();
}

void	BannerRocks::manageStoneText(sf::RenderWindow &window)
{
	window.draw(drawStoneText(_lineText, std::to_string(
		chained_list_len(getGraph()->map->map[getTarget().y][
			getTarget().x]->stones->linemate)), 1225));
	window.draw(drawStoneText(_deraText, std::to_string(
		chained_list_len(getGraph()->map->map[getTarget().y][
			getTarget().x]->stones->deraumere)), 1325));
	window.draw(drawStoneText(_sibuText, std::to_string(
		chained_list_len(getGraph()->map->map[getTarget().y][
			getTarget().x]->stones->sibur)), 1425));
	window.draw(drawStoneText(_mendText, std::to_string(
		chained_list_len(getGraph()->map->map[getTarget().y][
			getTarget().x]->stones->mendiane)), 1525));
	window.draw(drawStoneText(_phirText, std::to_string(
		chained_list_len(getGraph()->map->map[getTarget().y][
			getTarget().x]->stones->phiras)), 1625));
	window.draw(drawStoneText(_thysText, std::to_string(
		chained_list_len(getGraph()->map->map[getTarget().y][
			getTarget().x]->stones->thystame)), 1725));
}

void	BannerRocks::run(sf::RenderWindow &window)
{
	drawRocks(window);
	if (getTarget().x != -1 && getTarget().y != -1 &&
	getTarget().x < getGraph()->map->width &&
	getTarget().y < getGraph()->map->height) {
		manageStoneText(window);
		drawSquareText(window, 190, "Square: " +
		std::to_string(getTarget().x) + ", " +
		std::to_string(getTarget().y));
	} else {
		drawSquareText(window, 100, "No square selected.");
	}
}