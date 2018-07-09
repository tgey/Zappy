/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** CommandInfo
*/

#ifndef COMMANDINFO_HPP_
	#define COMMANDINFO_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cassert>
#include <iostream>

class Manager;

class CommandInfo {
	public:
		CommandInfo(Manager &manager);
		~CommandInfo();
		void run(sf::RenderWindow &window);
		void initSprites();
		void initText();

	protected:
	private:
		Manager &_manager;
		sf::Font _font;
		sf::Text _zoom;
		sf::Text _unzoom;
		sf::Text _movement;
		sf::Texture _ATexture;
		sf::Sprite _ASprite;
		sf::Texture _ZTexture;
		sf::Sprite _ZSprite;
		sf::Texture _ArrowLeftTexture;
		sf::Sprite _ArrowLeftSprite;
		sf::Texture _ArrowRightTexture;
		sf::Sprite _ArrowRightSprite;
		sf::Texture _ArrowUpDownTexture;
		sf::Sprite _ArrowUpDownSprite;
};

#endif /* !COMMANDINFO_HPP_ */
