/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** main for scrollfrequency
*/

#include <SFML/Graphics.hpp>
#include "FrequencyScroller.hpp"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1500, 1000), "scroll frequency",
	sf::Style::Default, settings);
	sf::Event event;
	FrequencyScroller scroller(
		std::pair<sf::Vector2i, sf::Vector2i>({1100, 50}, {1400, 150}),
		window, sf::Color(30, 255, 60, 255));

	scroller.setFrequency(100);
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			scroller.handleEvents(event);
		}
		// scroller.setFrequency(scroller.getFrequency() + 1);
		// if (scroller.getFrequency() >= scroller.getMaximum())
		// 	scroller.setFrequency(1);
		window.clear(sf::Color(30, 30, 30, 255));
		scroller.draw();
		window.display();
	}
	return 0;
}
