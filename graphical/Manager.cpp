/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** game manager
*/

#include "Manager.hpp"

Manager::Manager(UNUSED sf::RenderWindow &window, graph_t *graph) :
	_active(false), _graph(graph), _handler(new CommandHandler(*this)),
	_map(new Map(*this)), _mapRocks(new MapRocks(*this)),
	_scroller(new FrequencyScroller(std::pair<sf::Vector2i,
	sf::Vector2i>({1450, 650}, {1800, 750}), window,
	sf::Color(237, 185, 101, 255))),
	_banRocks(new BannerRocks(*this)), _menu(new Menu(*this)),
	_cloud(new Cloud(*this)), _info(new CommandInfo(*this))
{
	assert(_backTexture.loadFromFile("./design/back.jpg"));
        _backSprite.setTexture(_backTexture);
	assert(_gameBackTexture.loadFromFile("./design/back_game.png"));
        _gameBackSprite.setTexture(_gameBackTexture);
	assert(_squareBackTexture.loadFromFile("./design/square_back.jpeg"));
	_squareBackSprite.setTexture(_squareBackTexture);
	_squareBackSprite.setPosition(560, 40);
	_squareBackSprite.setScale(
		810.f / _squareBackSprite.getTexture()->getSize().x,
		810.f / _squareBackSprite.getTexture()->getSize().y);
	assert(_font.loadFromFile("./design/Supercell-magic-webfont.ttf"));
	_connecting.setFont(_font);
	_connecting.setCharacterSize(40);
	_connecting.setPosition(800, 500);
	_connecting.setStyle(sf::Text::Bold);
	_connecting.setFillColor(sf::Color(250, 250, 250, 250));
	_connecting.setString("Connecting...");
}

Manager::~Manager()
{
}

bool Manager::isActive() const
{
	return _active;
}

void Manager::setActive(bool active)
{
	_active = active;
}

void Manager::initMapData()
{
	_map->initMapData();
}

void Manager::setupPercents()
{
	_mapRocks->setupPercents();
}

void Manager::sendFrequencyToServer()
{
	std::string str("sst " +
		std::to_string(_scroller->getFrequency()));
	graph_send_command(_graph, str.c_str());
	_scroller->setUpdated(false);
}

void Manager::setIsActiveScroller(bool active)
{
	_scroller->setIsActive(active);
}

void Manager::createNewPlayer(t_player *player)
{
	if (player->new_one) {
		_players.push_back(new Player(*this, player));
		player->new_one = false;
		insert_chained_list(_graph->map->map[player->y][player->x]
			->players, player);
	}
}

void Manager::deletePlayerInVector(t_player *player)
{
	for (auto it = _players.begin(); it != _players.end(); ++it) {
		if ((*it)->isPlayerWithFd(player->fd)) {
			_players.erase((it));
			break;
		}
	}
}

void Manager::deletePlayer()
{
	t_chained *current = _graph->players->first;

	while (!current->last) {
		t_player *player = (t_player *)current->data;
		if (player && player->died) {
			deletePlayerInVector(player);
			delete_player_fd(_graph->map->map[player->y][player->x]
			->players, &player->fd);
			delete_player_fd(_graph->players, &player->fd);
		}
		current = current->next;
	}
}

void Manager::managePlayers(sf::RenderWindow &window)
{
	t_chained *current = _graph->players->first;

	if (_graph->new_player) {
		while (!current->last) {
			createNewPlayer(
				static_cast<t_player *>(current->data));
			current = current->next;
		}
		_graph->new_player = false;
	}
	if (_graph->player_died) {
		deletePlayer();
		_graph->player_died = false;
	}
	for (auto it = _players.begin(); it != _players.end(); ++it) {
		(*it)->run(window);
	}
}

void Manager::drawInside(sf::RenderWindow &window)
{
	window.draw(_squareBackSprite);
	_map->run(window);
	_mapRocks->run(window);
	managePlayers(window);
}

void Manager::draw(sf::RenderWindow &window)
{
	if (_handler->getDone() < 4) {
		_scroller->setFrequency(_graph->frequency);
		window.draw(_backSprite);
		_cloud->cloudAppear(window);
		window.draw(_connecting);
	} else {
		drawInside(window);
		window.draw(_gameBackSprite);
		_scroller->draw(window);
		_banRocks->run(window);
		_info->run(window);
		_menu->run(window);
		_cloud->cloudDisappear(window);
	}
	_handler->run(_graph);
	if (_scroller->getUpdated())
		sendFrequencyToServer();
	setIsActiveScroller(!_menu->getDeployed());
}

int Manager::getOriginX() const
{
	return _map->getOriginX();
}

int Manager::getOriginY() const
{
	return _map->getOriginY();
}

float Manager::getChangeX() const
{
	return _map->getChangeX();
}

float Manager::getChangeY() const
{
	return _map->getChangeY();
}

int Manager::getTotalWidth() const
{
	return _map->getTotalWidth();
}

float Manager::getSquareSize() const
{
	return _map->getSquareSize();
}

int Manager::getLongest() const
{
	return _map->getLongest();
}

float Manager::getImgScale() const
{
	return _map->getImgScale();
}

float Manager::getInitialSquareSize() const
{
	return _map->getInitialSquareSize();
}

graph_t *Manager::getGraph() const
{
	return _graph;
}

sf::Vector2i Manager::getTarget() const
{
	return _map->getTarget();
}

void Manager::realTimeEvents()
{
	_map->realTimeEvents();
}

int Manager::getFrequency() const
{
	return _scroller->getFrequency();
}

float Manager::getMaximum() const
{
	return _scroller->getMaximum();
}

void Manager::setMaximum(float newValue)
{
	_scroller->setMaximum(newValue);
}

void Manager::eventHandler(sf::RenderWindow &window, sf::Event &event)
{
	if (event.type == sf::Event::Closed)
		window.close();
	if (event.type == sf::Event::KeyPressed) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			_active = false;
	}
	_map->eventHandler(window, event);
	_scroller->handleEvents(window, event);
	_menu->handleEvents(window, event);
}

bool Manager::run(sf::RenderWindow &window)
{
	sf::Event event;

	if (!_graph)
		return false;
	_active = true;
	while (window.isOpen() && _active) {
		while (window.pollEvent(event))
			eventHandler(window, event);
		realTimeEvents();
		window.clear(sf::Color(10, 10, 10));
		draw(window);
		window.display();
	}
	return true;
}
