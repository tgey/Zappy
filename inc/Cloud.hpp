/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Cloud
*/

#ifndef CLOUD_HPP_
	#define CLOUD_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cassert>
#include <iostream>

class Manager;

class Cloud {
	public:
		Cloud(Manager &manager);
		~Cloud();
		void cloudAppear(sf::RenderWindow &window);
		void cloudDisappear(sf::RenderWindow &window);

	protected:
	private:
		sf::Texture _leftCloudTx;
		sf::Texture _rightCloudTx;
		sf::Sprite _rightCloudSp;
		sf::Sprite _leftCloudSp;
		Manager &_manager;
		int _posXLeft;
		int _posYLeft;
		int _posXRight;
		int _posYRight;
};

#endif /* !CLOUD_HPP_ */
