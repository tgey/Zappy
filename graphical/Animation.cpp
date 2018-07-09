/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** animation
*/

#include "Animation.hpp"
#include "Player.hpp"

Animation::Animation(Player &player) : _player(player)
{
	setActivity(IDLE);
	setRunSprites();
	setRotateSprites();
	setIdleSprites();
	setIncantationSprites();
}

Animation::~Animation()
{
}

void Animation::setIdleSprites()
{
	assert(_idleTopTexture
		.loadFromFile("./design/KnightSprites/KnightRightBackTurn.png",
		sf::IntRect(0, 0, 100, 100)));
	_idleTopSprite.setTexture(_idleTopTexture);
	assert(_idleRightTexture
		.loadFromFile("./design/KnightSprites/KnightRightRun.png",
		sf::IntRect(100, 0, 100, 100)));
	_idleRightSprite.setTexture(_idleRightTexture);
	assert(_idleBottomTexture
		.loadFromFile("./design/KnightSprites/KnightFrontRun.png",
		sf::IntRect(0, 0, 100, 100)));
	_idleBottomSprite.setTexture(_idleBottomTexture);
	assert(_idleLeftTexture
		.loadFromFile("./design/KnightSprites/KnightLeftBackTurn.png",
		sf::IntRect(0, 0, 100, 100)));
	_idleLeftSprite.setTexture(_idleLeftTexture);
}

void Animation::setRunSprites()
{
	assert(_runTopTexture
		.loadFromFile("./design/KnightSprites/KnightBackRun.png"));
	_runTopSprite.setTexture(_runTopTexture);
	assert(_runRightTexture
		.loadFromFile("./design/KnightSprites/KnightRightRun.png"));
	_runRightSprite.setTexture(_runRightTexture);
	assert(_runBottomTexture
		.loadFromFile("./design/KnightSprites/KnightFrontRun.png"));
	_runBottomSprite.setTexture(_runBottomTexture);
	assert(_runLeftTexture
		.loadFromFile("./design/KnightSprites/KnightLeftRun.png"));
	_runLeftSprite.setTexture(_runLeftTexture);
}

void Animation::setRotateSprites()
{
	assert(_rotateTopLeftTexture
		.loadFromFile(
			"./design/KnightSprites/KnightLeftBackTurn.png"));
	_rotateTopLeftSprite.setTexture(_rotateTopLeftTexture);
	assert(_rotateTopRightTexture
		.loadFromFile(
			"./design/KnightSprites/KnightRightBackTurn.png"));
	_rotateTopRightSprite.setTexture(_rotateTopRightTexture);
	assert(_rotateBottomLeftTexture
		.loadFromFile(
			"./design/KnightSprites/KnightLeftFrontTurn.png"));
	_rotateBottomLeftSprite.setTexture(_rotateBottomLeftTexture);
	assert(_rotateBottomRightTexture
		.loadFromFile(
			"./design/KnightSprites/KnightRightFrontTurn.png"));
	_rotateBottomRightSprite.setTexture(_rotateBottomRightTexture);
}

void Animation::setIncantationSprites()
{
	assert(_incantationTexture
		.loadFromFile("./design/incantation.png"));
	_incantationSprite.setTexture(_incantationTexture);
}

int Animation::getFrequency() const
{
	return _player.getFrequency();
}

graph_t *Animation::getGraph()
{
	return _player.getGraph();
}

int Animation::getOriginX() const
{
	return _player.getOriginX();
}

int Animation::getOriginY() const
{
	return _player.getOriginY();
}

float Animation::getChangeX() const
{
	return _player.getChangeX();
}

float Animation::getChangeY() const
{
	return _player.getChangeY();
}

int Animation::getTotalWidth() const
{
	return _player.getTotalWidth();
}

float Animation::getSquareSize() const
{
	return _player.getSquareSize();
}

int Animation::getLongest() const
{
	return _player.getLongest();
}

float Animation::getImgScale() const
{
	return _player.getImgScale();
}

float Animation::getInitialSquareSize() const
{
	return _player.getInitialSquareSize();
}

void Animation::setOrigin(sf::Vector2f origin)
{
	_origin = origin;
}

void Animation::setEnd(sf::Vector2f end)
{
	_end = end;
}

sf::Vector2f Animation::getOrigin() const
{
	return _origin;
}

sf::Vector2f Animation::getEnd() const
{
	return _end;
}

void Animation::setActivity(Activity activity)
{
	_activity = activity;
}

Activity Animation::getActivity() const
{
	return _activity;
}

void Animation::setDirection(Direction direction)
{
	_player.setDirection(direction);
}

Direction Animation::getDirection() const
{
	return _player.getDirection();
}

void Animation::setIdles()
{
	_idleLeftSprite.setPosition(getOriginX() + getChangeX() + _player
		.getPosition().x * getSquareSize() - (20.f * (getImgScale() * 5.f)), getOriginY() +
		getChangeY() + _player.getPosition().y * getSquareSize()
		- 80.f * (getImgScale() * 5));
	_idleLeftSprite.setScale(getImgScale() * 5, getImgScale() * 5);
	_idleTopSprite.setPosition(getOriginX() + getChangeX() + _player
		.getPosition().x * getSquareSize() - (20.f * (getImgScale() * 5.f)), getOriginY() +
		getChangeY() + _player.getPosition().y * getSquareSize()
		- 80.f * (getImgScale() * 5));
	_idleTopSprite.setScale(getImgScale() * 5, getImgScale() * 5);
	_idleRightSprite.setPosition(getOriginX() + getChangeX() + _player
		.getPosition().x * getSquareSize() - (20.f * (getImgScale() * 5.f)), getOriginY() +
		getChangeY() + _player.getPosition().y * getSquareSize()
		- 80.f * (getImgScale() * 5));
	_idleRightSprite.setScale(getImgScale() * 5, getImgScale() * 5);
	_idleBottomSprite.setPosition(getOriginX() + getChangeX() + _player
		.getPosition().x * getSquareSize() - (20.f * (getImgScale() * 5.f)), getOriginY() +
		getChangeY() + _player.getPosition().y * getSquareSize()
		- 80.f * (getImgScale() * 5));
	_idleBottomSprite.setScale(getImgScale() * 5, getImgScale() * 5);
}

void Animation::idle(sf::RenderWindow &window)
{
	setIdles();
	switch (_player.getDirection()) {
	case TOP:
		window.draw(_idleTopSprite);
		break;
	case RIGHT:
		window.draw(_idleRightSprite);
		break;
	case BOTTOM:
		window.draw(_idleBottomSprite);
		break;
	case LEFT:
		window.draw(_idleLeftSprite);
		break;
	default:
		break;
	}
}

void Animation::endAnimation()
{
	if (getActivity() != IDLE) {
		if (getActivity() == MOVE)
			endMove();
		if (getActivity() == ROTATE_LEFT)
			endRotation();
		if (getActivity() == ROTATE_RIGHT)
			endRotation();
		if (getActivity() == INCANTATION)
			endIncantation();
	}
}

void Animation::setupMove()
{
	sf::Vector2f end;
	int width = getGraph()->map->width;
	int height = getGraph()->map->height;

	endAnimation();
	setOrigin(_player.getPosition());
	end = _player.getPosition();
	if (_player.getDirection() == TOP)
		end.y = end.y - 1.f <= 0 ? height - 1.f : end.y - 1.f;
	if (_player.getDirection() == RIGHT)
		end.x = end.x + 1.f >= width ? 0.f : end.x + 1.f;
	if (_player.getDirection() == BOTTOM)
		end.y = end.y + 1.f >= height ? 0.f : end.y + 1.f;
	if (_player.getDirection() == LEFT)
		end.x = end.x - 1.f <= 0 ? width - 1.f : end.x - 1.f;
	setEnd(end);
	setActivity(MOVE);
	_duration.restart();
}

void Animation::endMove()
{
	setActivity(IDLE);
	_player.updatePosition();
}

void Animation::moveTop(sf::RenderWindow &window)
{
	sf::Time t = _duration.getElapsedTime();

	_runTopSprite.setScale(getImgScale() * 5, getImgScale() * 5);
	_runTopSprite.setPosition(getOriginX() + getChangeX() + _origin.x *
		getSquareSize() - (20.f * (getImgScale() * 5.f)),
		getOriginY() + getChangeY() + _origin.y *
		getSquareSize() - 80.f * (getImgScale() * 5));
	if (t.asSeconds() < 7.f / getFrequency()) {
		float percent = t.asSeconds() / (7.f / getFrequency());
		float speed = (_player.getPosition().y - _end.y) / (7.f /
			getFrequency());
		_runTopSprite.setTextureRect(sf::IntRect(static_cast<int>(
			percent * 6.f * ceil(4.f / getFrequency())) % 6 * 100,
			0, 100, 100));
		window.draw(_runTopSprite);
		_origin.y = _player.getPosition().y - (speed * t.asSeconds());
		if (_origin.y <= 0)
			_origin.y = getGraph()->map->height - 1.f;
	} else
		endMove();
}

void Animation::moveRight(sf::RenderWindow &window)
{
	sf::Time t = _duration.getElapsedTime();

	_runRightSprite.setScale(getImgScale() * 5, getImgScale() * 5);
	_runRightSprite.setPosition(getOriginX() + getChangeX() + _origin.x *
		getSquareSize() - (20.f * (getImgScale() * 5.f)),
		getOriginY() + getChangeY() + _origin.y *
		getSquareSize() - 80.f * (getImgScale() * 5));
	if (t.asSeconds() < 7.f / getFrequency()) {
		float percent = t.asSeconds() / (7.f / getFrequency());
		float speed = (_end.x - _player.getPosition().x) / (7.f /
			getFrequency());
		_runRightSprite.setTextureRect(sf::IntRect(static_cast<int>(
			percent * 6.f * ceil(4.f / getFrequency())) % 6 * 100,
			0, 100, 100));
		window.draw(_runRightSprite);
		_origin.x = _player.getPosition().x + (speed * t.asSeconds());
		if (_origin.x >= getGraph()->map->width)
			_origin.x = 0.f;
	} else
		endMove();
}

void Animation::moveBottom(sf::RenderWindow &window)
{
	sf::Time t = _duration.getElapsedTime();

	_runBottomSprite.setScale(getImgScale() * 5, getImgScale() * 5);
	_runBottomSprite.setPosition(getOriginX() + getChangeX() + _origin.x *
		getSquareSize() - (20.f * (getImgScale() * 5.f)),
		getOriginY() + getChangeY() + _origin.y *
		getSquareSize() - 80.f * (getImgScale() * 5));
	if (t.asSeconds() < 7.f / getFrequency()) {
		float percent = t.asSeconds() / (7.f / getFrequency());
		float speed = (_end.y - _player.getPosition().y) / (7.f /
			getFrequency());
		_runBottomSprite.setTextureRect(sf::IntRect(static_cast<int>(
			percent * 6.f * ceil(4.f / getFrequency())) % 6 * 100,
			0, 100, 100));
		window.draw(_runBottomSprite);
		_origin.y = _player.getPosition().y + (speed * t.asSeconds());
		if (_origin.y >= getGraph()->map->height)
			_origin.y = 0.f;
	} else
		endMove();
}

void Animation::moveLeft(sf::RenderWindow &window)
{
	sf::Time t = _duration.getElapsedTime();

	_runLeftSprite.setScale(getImgScale() * 5, getImgScale() * 5);
	_runLeftSprite.setPosition(getOriginX() + getChangeX() + _origin.x *
		getSquareSize() - (20.f * (getImgScale() * 5.f)),
		getOriginY() + getChangeY() + _origin.y *
		getSquareSize() - 80.f * (getImgScale() * 5));
	if (t.asSeconds() < 7.f / getFrequency()) {
		float percent = t.asSeconds() / (7.f / getFrequency());
		float speed = (_player.getPosition().x - _end.x) / (7.f /
			getFrequency());
		_runLeftSprite.setTextureRect(sf::IntRect(static_cast<int>(
			percent * 6.f * ceil(4.f / getFrequency())) % 6 * 100,
			0, 100, 100));
		window.draw(_runLeftSprite);
		_origin.x = _player.getPosition().x - (speed * t.asSeconds());
		if (_origin.x <= 0)
			_origin.x = getGraph()->map->width - 1.f;
	} else
		endMove();
}

void Animation::move(sf::RenderWindow &window)
{
	switch (_player.getDirection()) {
	case TOP:
		moveTop(window);
		break;
	case RIGHT:
		moveRight(window);
		break;
	case BOTTOM:
		moveBottom(window);
		break;
	case LEFT:
		moveLeft(window);
		break;
	default:
		break;
	}
}

void Animation::endRotation()
{
	if (getActivity() == ROTATE_RIGHT)
		setDirection(static_cast<Direction>((getDirection() + 1) % 4));
	else if (getActivity() == ROTATE_LEFT)
		setDirection(getDirection() - 1 < 0 ?
			static_cast<Direction>(3) :
			static_cast<Direction>(getDirection() - 1));
	setActivity(IDLE);
}

void Animation::rotationTopRight(sf::RenderWindow &window, sf::Time &t)
{
	float percent = t.asSeconds() / (7.f / getFrequency());

	if (getActivity() == ROTATE_RIGHT)
		_rotateTopRightSprite.setTextureRect(sf::IntRect(
			static_cast<int>(
			percent * 6.f) % 6 * 100, 0, 100, 100));
	else if (getActivity() == ROTATE_LEFT)
		_rotateTopRightSprite.setTextureRect(sf::IntRect(
			static_cast<int>(6 -
			percent * 6.f) % 6 * 100, 0, 100, 100));
	window.draw(_rotateTopRightSprite);
}

void Animation::rotationTopLeft(sf::RenderWindow &window, sf::Time &t)
{
	float percent = t.asSeconds() / (7.f / getFrequency());

	if (getActivity() == ROTATE_RIGHT)
		_rotateTopLeftSprite.setTextureRect(sf::IntRect(
			static_cast<int>(
			percent * 6.f) % 6 * 100, 0, 100, 100));
	else if (getActivity() == ROTATE_LEFT)
		_rotateTopLeftSprite.setTextureRect(sf::IntRect(
			static_cast<int>(6 -
			percent * 6.f) % 6 * 100, 0, 100, 100));
	window.draw(_rotateTopLeftSprite);
}

void Animation::rotationBottomRight(sf::RenderWindow &window, sf::Time &t)
{
	float percent = t.asSeconds() / (7.f / getFrequency());

	if (getActivity() == ROTATE_RIGHT)
		_rotateBottomRightSprite.setTextureRect(sf::IntRect(
			static_cast<int>(6 -
			percent * 6.f) % 6 * 100, 0, 100, 100));
	else if (getActivity() == ROTATE_LEFT)
		_rotateBottomRightSprite.setTextureRect(sf::IntRect(
			static_cast<int>(
			percent * 6.f) % 6 * 100, 0, 100, 100));
	window.draw(_rotateBottomRightSprite);
}

void Animation::rotationBottomLeft(sf::RenderWindow &window, sf::Time &t)
{
	float percent = t.asSeconds() / (7.f / getFrequency());

	if (getActivity() == ROTATE_RIGHT)
		_rotateBottomLeftSprite.setTextureRect(sf::IntRect(
			static_cast<int>(6 -
			percent * 6.f) % 6 * 100, 0, 100, 100));
	else if (getActivity() == ROTATE_LEFT)
		_rotateBottomLeftSprite.setTextureRect(sf::IntRect(
			static_cast<int>(
			percent * 6.f) % 6 * 100, 0, 100, 100));
	window.draw(_rotateBottomLeftSprite);
}

void Animation::setupRotateRight()
{
	endAnimation();
	setActivity(ROTATE_RIGHT);
	_duration.restart();
}

void Animation::setupRotateLeft()
{
	endAnimation();
	setActivity(ROTATE_LEFT);
	_duration.restart();
}

void Animation::setRotatesTop()
{
	_rotateTopLeftSprite.setScale(getImgScale() * 5,
		getImgScale() * 5);
	_rotateTopLeftSprite.setPosition(getOriginX() + getChangeX() +
		_player.getPosition().x * getSquareSize() -
		(20.f * (getImgScale() * 5.f)), getOriginY() +
		getChangeY() + _player.getPosition().y * getSquareSize()
		- 80.f * (getImgScale() * 5));
	_rotateTopRightSprite.setScale(getImgScale() * 5,
		getImgScale() * 5);
	_rotateTopRightSprite.setPosition(getOriginX() + getChangeX() +
		_player.getPosition().x * getSquareSize() -
		(20.f * (getImgScale() * 5.f)), getOriginY() +
		getChangeY() + _player.getPosition().y * getSquareSize()
		- 80.f * (getImgScale() * 5));
}

void Animation::setRotates()
{
	_rotateBottomLeftSprite.setScale(getImgScale() * 5,
		getImgScale() * 5);
	_rotateBottomLeftSprite.setPosition(getOriginX() + getChangeX() +
		_player.getPosition().x * getSquareSize() -
		(20.f * (getImgScale() * 5.f)), getOriginY() +
		getChangeY() + _player.getPosition().y * getSquareSize()
		- 80.f * (getImgScale() * 5));
	_rotateBottomRightSprite.setScale(getImgScale() * 5,
		getImgScale() * 5);
	_rotateBottomRightSprite.setPosition(getOriginX() + getChangeX() +
		_player.getPosition().x * getSquareSize() -
		(20.f * (getImgScale() * 5.f)), getOriginY() +
		getChangeY() + _player.getPosition().y * getSquareSize()
		- 80.f * (getImgScale() * 5));
	setRotatesTop();
}

void Animation::rotateRight(sf::RenderWindow &window)
{
	sf::Time t = _duration.getElapsedTime();

	setRotates();
	if (t.asSeconds() < 7.f / getFrequency()) {
		if (getDirection() == TOP)
			rotationTopRight(window, t);
		if (getDirection() == RIGHT)
			rotationBottomRight(window, t);
		if (getDirection() == BOTTOM)
			rotationBottomLeft(window, t);
		if (getDirection() == LEFT)
			rotationTopLeft(window, t);
	} else
		endRotation();
}

void Animation::rotateLeft(sf::RenderWindow &window)
{
	sf::Time t = _duration.getElapsedTime();

	setRotates();
	if (t.asSeconds() < 7.f / getFrequency()) {
		if (getDirection() == TOP)
			rotationTopLeft(window, t);
		if (getDirection() == RIGHT)
			rotationTopRight(window, t);
		if (getDirection() == BOTTOM)
			rotationBottomRight(window, t);
		if (getDirection() == LEFT)
			rotationBottomLeft(window, t);
	} else
		endRotation();
}

void Animation::run(sf::RenderWindow &window)
{
	if (_activity == IDLE)
		idle(window);
	if (_activity == MOVE)
		move(window);
	if (_activity == ROTATE_RIGHT)
		rotateRight(window);
	if (_activity == ROTATE_LEFT)
		rotateLeft(window);
	if (_activity == INCANTATION)
		incantate(window);
}

void Animation::endIncantation()
{
	setActivity(IDLE);
}

void Animation::setupIncatate()
{
	endAnimation();
	setActivity(INCANTATION);
	_duration.restart();
}

void Animation::incant(sf::RenderWindow &window, sf::Time &t)
{
	float percent = t.asSeconds() / (300.f / getFrequency());
	int idx = static_cast<int>(
		percent * 25.f * ceil(150.f / getFrequency())) % 25;

	_incantationSprite.setTextureRect(sf::IntRect(idx % 25 * 200,
		0, 200, 200));
	if (idx < 4 || (idx > 22) || (idx >= 9 && idx <= 17)) {
		window.draw(_incantationSprite);
		idle(window);
	} else {
		idle(window);
		window.draw(_incantationSprite);
	}
}

void Animation::setIncantate()
{
	_incantationSprite.setScale(getImgScale() * 2.5f,
		getImgScale() * 2.5f);
	_incantationSprite.setPosition(getOriginX() + getChangeX() +
		_player.getPosition().x * getSquareSize() -
		(100.f * (getImgScale() * 2.5f)) / 2 -
		(20.f * (getImgScale() * 5.f)), getOriginY() +
		getChangeY() + _player.getPosition().y * getSquareSize()
		- 180 * (getImgScale() * 2.5f));
}

void Animation::incantate(sf::RenderWindow &window)
{
	sf::Time t = _duration.getElapsedTime();

	setIncantate();
	if (t.asSeconds() < 300.f / getFrequency())
		incant(window, t);
	else
		endIncantation();
}