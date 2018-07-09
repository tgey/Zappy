/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** rocks
*/

#include "MapRocks.hpp"
#include "Manager.hpp"

MapRocks::MapRocks(Manager &manager) : _manager(manager),
	_initialized(false)
{
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
	assert(_foodTexture.loadFromFile("./design/food.png"));
	_foodSprite.setTexture(_foodTexture);
}

MapRocks::~MapRocks()
{
}

void MapRocks::setupPercents()
{
	float imgScale = _manager.getImgScale();
	float squareSize = _manager.getSquareSize();

	getGraph()->map->percent_x = static_cast<float>(_gemBlueSprite
		.getTexture()->getSize().x) * imgScale / squareSize * 100;
	getGraph()->map->percent_y = static_cast<float>(_gemBlueSprite
		.getTexture()->getSize().y) * imgScale / squareSize * 100;
}

void MapRocks::drawResourcesSquare(sf::RenderWindow &window,
	t_chained_list *list,
	std::pair<std::pair<int, int>, sf::Sprite> idx)
{
	int originX = _manager.getOriginX();
	int originY = _manager.getOriginY();
	float changeX = _manager.getChangeX();
	float changeY = _manager.getChangeY();
	float squareSize = _manager.getSquareSize();
	sf::Vector2f pos;
	t_chained *current = list->first;

	while (!current->last) {
		place_t *place = static_cast<place_t *>(current->data);
		pos.x = originX + changeX + (idx.first.first * squareSize) +
			(static_cast<float>(place->x) / 100 * squareSize);
		pos.y = originY + changeY + (idx.first.second * squareSize) +
			(static_cast<float>(place->y) / 100 * squareSize);
		idx.second.setPosition(pos.x, pos.y);
		window.draw(idx.second);
		current = current->next;
	}
}

void MapRocks::setScales()
{
	float imgScale = _manager.getImgScale();

	_gemGreenSprite.setScale(imgScale, imgScale);
	_gemBlueSprite.setScale(imgScale, imgScale);
	_gemYellowSprite.setScale(imgScale, imgScale);
	_gemPurpleSprite.setScale(imgScale, imgScale);
	_gemPinkSprite.setScale(imgScale, imgScale);
	_gemRedSprite.setScale(imgScale, imgScale);
	_foodSprite.setScale(imgScale / 2.5f, imgScale / 2.5f);
}

void MapRocks::drawResourcesCell(sf::RenderWindow &window,
	cell_t *cell, std::pair<int, int> idx)
{
	drawResourcesSquare(window, cell->stones->linemate,
		std::pair<std::pair<int, int>,
		sf::Sprite>(idx, _gemGreenSprite));
	drawResourcesSquare(window, cell->stones->deraumere,
		std::pair<std::pair<int, int>,
		sf::Sprite>(idx, _gemBlueSprite));
	drawResourcesSquare(window, cell->stones->sibur,
		std::pair<std::pair<int, int>,
		sf::Sprite>(idx, _gemYellowSprite));
	drawResourcesSquare(window, cell->stones->mendiane,
		std::pair<std::pair<int, int>,
		sf::Sprite>(idx, _gemPurpleSprite));
	drawResourcesSquare(window, cell->stones->phiras,
		std::pair<std::pair<int, int>,
		sf::Sprite>(idx, _gemPinkSprite));
	drawResourcesSquare(window, cell->stones->thystame,
		std::pair<std::pair<int, int>,
		sf::Sprite>(idx, _gemRedSprite));
	drawResourcesSquare(window, cell->food, std::pair<std::pair<int, int>,
		sf::Sprite>(idx, _foodSprite));
}

graph_t *MapRocks::getGraph()
{
	return _manager.getGraph();
}

void MapRocks::draw(sf::RenderWindow &window)
{
	setScales();
	for (int y = 0; y < getGraph()->map->height; y++) {
		for (int x = 0; x < getGraph()->map->width; x++) {
			drawResourcesCell(window,
			getGraph()->map->map[y][x],
			std::pair<int, int>(x, y));
		}
	}
}

void MapRocks::run(sf::RenderWindow &window)
{
	draw(window);
}
