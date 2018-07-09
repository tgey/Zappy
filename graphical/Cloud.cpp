/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Cloud
*/

#include "Cloud.hpp"
#include "Manager.hpp"

Cloud::Cloud(Manager &manager) : _manager(manager),
	_posXLeft(-1700), _posYLeft(340),
	_posXRight(1700), _posYRight(-340)
{
	assert(_leftCloudTx.loadFromFile("./design/leftCloud.png"));
	_leftCloudSp.setTexture(_leftCloudTx);
	assert(_rightCloudTx.loadFromFile("./design/rightCloud.png"));
	_rightCloudSp.setTexture(_rightCloudTx);
	_leftCloudSp.setColor(sf::Color(180, 180, 180, 255));
	_rightCloudSp.setColor(sf::Color(180, 180, 180, 255));
}

Cloud::~Cloud()
{
}

void	Cloud::cloudAppear(sf::RenderWindow &window)
{
	if (_posXLeft < 0) {
		_posXLeft += 10;
		_posYLeft -= 2;
		_posXRight -= 10;
		_posYRight += 2;
	}
	_leftCloudSp.setPosition(_posXLeft, _posYLeft);
	window.draw(_leftCloudSp);
	_rightCloudSp.setPosition(_posXRight, _posYRight);
	window.draw(_rightCloudSp);
}

void	Cloud::cloudDisappear(sf::RenderWindow &window)
{
	if (_posXLeft > -1700) {
		_posXLeft -= 10;
		_posYLeft += 2;
		_posXRight += 10;
		_posYRight -= 2;
		_leftCloudSp.setPosition(_posXLeft, _posYLeft);
		window.draw(_leftCloudSp);
		_rightCloudSp.setPosition(_posXRight, _posYRight);
		window.draw(_rightCloudSp);
	}
}
