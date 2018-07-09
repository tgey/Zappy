/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** player
*/

#include "Player.hpp"
#include "Manager.hpp"

Player::Player(Manager &manager, t_player *player) : _manager(manager),
	_animation(new Animation(*this)), _player(player)
{
	srand(time(NULL));
	_random.x = static_cast<float>((rand() % 60) + 20) / 100;
	_random.y = static_cast<float>((rand() % 60) + 20) / 100;
	_direction = static_cast<Direction>(_player->dir - 1);
	setPosition(sf::Vector2i(_player->x, _player->y));
}

Player::~Player()
{
}

bool Player::isPlayerWithFd(int fd)
{
	return (fd == _player->fd);
}

int Player::getFrequency() const
{
	return _manager.getFrequency();
}

graph_t *Player::getGraph()
{
	return _manager.getGraph();
}

int Player::getOriginX() const
{
	return _manager.getOriginX();
}

int Player::getOriginY() const
{
	return _manager.getOriginY();
}

float Player::getChangeX() const
{
	return _manager.getChangeX();
}

float Player::getChangeY() const
{
	return _manager.getChangeY();
}

int Player::getTotalWidth() const
{
	return _manager.getTotalWidth();
}

float Player::getSquareSize() const
{
	return _manager.getSquareSize();
}

int Player::getLongest() const
{
	return _manager.getLongest();
}

float Player::getImgScale() const
{
	return _manager.getImgScale();
}

float Player::getInitialSquareSize() const
{
	return _manager.getInitialSquareSize();
}

void Player::draw(sf::RenderWindow &window)
{
	_animation->run(window);
}

void Player::setupNewAnimation()
{
	switch (_player->anim) {
	case 0:
		_animation->endAnimation();
		break;
	case 1:
		_animation->setupRotateLeft();
		break;
	case 2:
		_animation->setupRotateRight();
		break;
	case 3:
		_animation->setupMove();
		break;
	case 4:
		_animation->setupIncatate();
		break;
	default:
		break;
	}
}

void Player::run(sf::RenderWindow &window)
{
	if (_player->changed) {
		setupNewAnimation();
		_player->changed = false;
	}
	draw(window);
}

sf::Vector2f Player::getPosition() const
{
	return _position;
}

void Player::setPosition(sf::Vector2i position)
{
	_position.x = position.x + _random.x;
	_position.y = position.y + _random.y;
}

void Player::setPosition(sf::Vector2f position)
{
	_position = position;
}

void Player::updatePosition()
{
	if (_position.x != _player->x || _position.y != _player->y)
		setPosition(sf::Vector2i(_player->x, _player->y));
}

void Player::setDirection(Direction direction)
{
	_direction = direction;
}

Direction Player::getDirection() const
{
	return _direction;
}

void Player::setupMove()
{
	_animation->setupMove();
}

void Player::setupRotateLeft()
{
	_animation->setupRotateLeft();
}

void Player::setupRotateRight()
{
	_animation->setupRotateRight();
}

void Player::setupIncantate()
{
	_animation->setupIncatate();
}