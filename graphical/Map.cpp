/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** map
*/

#include "Map.hpp"
#include "Manager.hpp"

Map::Map(Manager &manager) : _manager(manager),
	_originX(0), _originY(50), _changeX(0), _changeY(0), _totalWidth(800),
	_initialized(false), _target(sf::Vector2i(-1, -1)),
	_scrollTo(sf::Vector2i(-1, -1)),
	_speedScrollX(0.f), _speedScrollY(0.f)
{
	assert(_mapClearTexture
	.loadFromFile("./design/map_clear.png"));
	_mapClearSprite.setTexture(_mapClearTexture);
	assert(_mapDarkTexture
	.loadFromFile("./design/map_dark.png"));
	_mapDarkSprite.setTexture(_mapDarkTexture);
	assert(_mapMoreClearTexture
	.loadFromFile("./design/map_more_clear.png"));
	_mapMoreClearSprite.setTexture(_mapMoreClearTexture);
	assert(_mapMoreDarkTexture
	.loadFromFile("./design/map_more_dark.png"));
	_mapMoreDarkSprite.setTexture(_mapMoreDarkTexture);
}

Map::~Map()
{
}

graph_t *Map::getGraph()
{
	return _manager.getGraph();
}

void Map::initMapData()
{
	_longest = getGraph()->map->width;
	if (getGraph()->map->height > getGraph()->map->width)
		_longest = getGraph()->map->height;
	_initialSquareSize = _mapClearSprite.getTexture()->getSize().x *
		_mapClearSprite.getScale().x;
	_imgScale = _totalWidth / (_initialSquareSize * _longest);
	_mapClearSprite.setScale(_imgScale, _imgScale);
	_mapDarkSprite.setScale(_imgScale, _imgScale);
	_mapMoreClearSprite.setScale(_imgScale, _imgScale);
	_mapMoreDarkSprite.setScale(_imgScale, _imgScale);
	_squareSize = _mapClearSprite.getTexture()->getSize().x *
		_mapClearSprite.getScale().x;
	_originX = 960 - ((_squareSize * getGraph()->map->width) / 2);
	_initialized = true;
}

int Map::getOriginX() const
{
	return _originX;
}

int Map::getOriginY() const
{
	return _originY;
}

float Map::getChangeX() const
{
	return _changeX;
}

float Map::getChangeY() const
{
	return _changeY;
}

int Map::getTotalWidth() const
{
	return _totalWidth;
}

float Map::getSquareSize() const
{
	return _squareSize;
}

int Map::getLongest() const
{
	return _longest;
}

float Map::getImgScale() const
{
	return _imgScale;
}

float Map::getInitialSquareSize() const
{
	return _initialSquareSize;
}

void Map::block()
{
	if (_changeX < ((-1) * _totalWidth) + 30)
		_changeX = ((-1) * _totalWidth) + 30;
	if (_changeX > 800 - 30)
		_changeX = 800 - 30;
	if (_changeY < ((-1) * _totalWidth) + 40)
		_changeY = ((-1) * _totalWidth) + 40;
	if (_changeY > 800 - 30)
		_changeY = 800 - 30;
}

void Map::zoom()
{
	_totalWidth = _totalWidth + _longest;
	_imgScale = _totalWidth / (_initialSquareSize * _longest);
	_mapClearSprite.setScale(_imgScale, _imgScale);
	_mapDarkSprite.setScale(_imgScale, _imgScale);
	_mapMoreClearSprite.setScale(_imgScale, _imgScale);
	_mapMoreDarkSprite.setScale(_imgScale, _imgScale);
	_squareSize = _mapClearSprite.getTexture()->getSize().x *
		_mapClearSprite.getScale().x;
	_changeX = _changeX - (_longest / 2);
	_changeY = _changeY - (_longest / 2);
	block();
	usleep(10000);
}

void Map::unzoom()
{
	if (_totalWidth - _longest < 100)
		return;
	_totalWidth -= _longest;
	_imgScale = _totalWidth / (_initialSquareSize * _longest);
	_mapClearSprite.setScale(_imgScale, _imgScale);
	_mapDarkSprite.setScale(_imgScale, _imgScale);
	_mapMoreClearSprite.setScale(_imgScale, _imgScale);
	_mapMoreDarkSprite.setScale(_imgScale, _imgScale);
	_squareSize = _mapClearSprite.getTexture()->getSize().x *
		_mapClearSprite.getScale().x;
	_changeX = _changeX + (_longest / 2);
	_changeY = _changeY + (_longest / 2);
	block();
	usleep(10000);
}

sf::Vector2i Map::getTarget() const
{
	return _target;
}

void Map::realTimeEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		_changeY += 2 + _squareSize * 4.f / _initialSquareSize;
		_scrollTo = sf::Vector2i(-1, -1);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		_changeY -= 2 + _squareSize * 4.f / _initialSquareSize;
		_scrollTo = sf::Vector2i(-1, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		_changeX += 2 + _squareSize * 4.f / _initialSquareSize;
		_scrollTo = sf::Vector2i(-1, -1);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		_changeX -= 2 + _squareSize * 4.f / _initialSquareSize;
		_scrollTo = sf::Vector2i(-1, -1);
	}
	block();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		zoom();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		unzoom();
}

void Map::handleMoreEvents(sf::RenderWindow &window, sf::Event &event)
{
	if (event.type == sf::Event::MouseButtonPressed &&
	event.mouseButton.button == sf::Mouse::Button::Right) {
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
		if (worldPos.x < _originX + _changeX ||
		worldPos.x > _originX + _changeX + _totalWidth ||
		worldPos.y < _originY + _changeY ||
		worldPos.y > _originY + _changeY + _totalWidth ||
		worldPos.x < 960 - 400 || worldPos.x > 960 + 400 ||
		worldPos.y < 50 || worldPos.y > 850)
			_scrollTo = sf::Vector2i(-1, -1);
		else {
			_scrollTo.x = (worldPos.x - _changeX - _originX)
				/ _squareSize;
			_scrollTo.y = (worldPos.y - _changeY - _originY)
				/ _squareSize;
		}
	}
}

void Map::eventHandler(sf::RenderWindow &window, sf::Event &event)
{
	if (event.type == sf::Event::MouseButtonPressed &&
	event.mouseButton.button == sf::Mouse::Button::Left) {
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
		if (worldPos.x < _originX + _changeX ||
		worldPos.x > _originX + _changeX + _totalWidth ||
		worldPos.y < _originY + _changeY ||
		worldPos.y > _originY + _changeY + _totalWidth ||
		worldPos.x < 960 - 400 || worldPos.x > 960 + 400 ||
		worldPos.y < 50 || worldPos.y > 850)
			_target = sf::Vector2i(-1, -1);
		else {
			_target.x = (worldPos.x - _changeX - _originX)
				/ _squareSize;
			_target.y = (worldPos.y - _changeY - _originY)
				/ _squareSize;
		}
	} else
		handleMoreEvents(window, event);
}

void Map::drawSquare(sf::RenderWindow &window, bool pair,
	std::pair<sf::Vector2i, sf::Vector2i> pos)
{
	_mapClearSprite.setPosition(pos.first.x, pos.first.y);
	_mapDarkSprite.setPosition(pos.first.x, pos.first.y);
	_mapMoreClearSprite.setPosition(pos.first.x, pos.first.y);
	_mapMoreDarkSprite.setPosition(pos.first.x, pos.first.y);
	if (_target.x == pos.second.x && _target.y == pos.second.y)
		window.draw(_mapMoreClearSprite);
	else if (pair)
		window.draw(_mapDarkSprite);
	else
		window.draw(_mapClearSprite);
}

void Map::scrollSmoothly()
{
	if (_scrollTo.x >= 0 && _scrollTo.x < getGraph()->map->width &&
	_scrollTo.y >= 0 && _scrollTo.y < getGraph()->map->height) {
		int changeToX = 400 - (_scrollTo.x * getSquareSize()
			+ getSquareSize() / 2.f);
		int changeToY = 400 - (_scrollTo.y * getSquareSize()
			+ getSquareSize() / 2.f);
		_speedScrollX = (changeToX - _changeX) / 100;
		_speedScrollY = (changeToY - _changeY) / 100;
		_changeX = _changeX + _speedScrollX;
		_changeY = _changeY + _speedScrollY;
		if (_speedScrollX <= 0.1f && _speedScrollY <= 0.1f &&
			_speedScrollX >= -0.1f && _speedScrollY >= -0.1f)
			_scrollTo = sf::Vector2i(-1, -1);
	}
}

void Map::draw(sf::RenderWindow &window)
{
	int currentX = _originX + _changeX;
	int currentY = _originY + _changeY;
	bool pair = false;
	bool dec = false;

	for (int y = 0; y < getGraph()->map->height; y++) {
		for (int x = 0; x < getGraph()->map->width; x++) {
			drawSquare(window, pair, std::pair<sf::Vector2i,
				sf::Vector2i>(sf::Vector2i(currentX,
				currentY), sf::Vector2i(x, y)));
			pair = !pair;
			currentX = currentX + _squareSize;
		}
		dec = !dec;
		pair = dec;
		currentX = _originX + _changeX;
		currentY = currentY + _squareSize;
	}
	scrollSmoothly();
}

void Map::run(sf::RenderWindow &window)
{
	if (!_initialized)
		initMapData();
	draw(window);
}