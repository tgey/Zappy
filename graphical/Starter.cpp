/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** starter
*/

#include "Starter.hpp"

Starter::Starter()
{
}

Starter::~Starter()
{
}

void Starter::run()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Zappy");
	Zappy zappy(window);

	zappy.run(window);
}