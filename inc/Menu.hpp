/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Menu
*/

#ifndef MENU_HPP_
	#define MENU_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cassert>
#include <iostream>
#include <cstring>
#include <string>

class Manager;

class Menu {
	public:
		Menu(Manager &manager);
		~Menu();
		void initText();
		void initVolSprites();
		void run(sf::RenderWindow &window);
		void handleEvents(sf::RenderWindow &window, sf::Event &event);
		void drawMenu(sf::RenderWindow &window);
		void hideMenu(sf::RenderWindow &window);
		void drawMenuComponents(sf::RenderWindow &window);
		void drawTextInput(sf::RenderWindow &window);
		void textInputFocus(sf::Vector2f worldPos);
		void textInputFill(sf::Event &event);
		void updateFreqMax();
		void updateVolMax(sf::Vector2f worldPos);
		bool getDeployed() const;
	protected:
	private:
		Manager &_manager;
		sf::Font _fontMenu;
		sf::Font _fontClash;
		sf::Text _menuText;
		sf::Texture _menuTexture;
		sf::Sprite _menuSprite;
		bool _deployed;
		int _posX;
		sf::RectangleShape _maxFreqShapeBack;
		sf::RectangleShape _maxFreqShapeFront;
		sf::Text _maxFreqText;
		bool _focusTextInput;
		std::string _freqText;
		sf::Text _inputText;
		bool _errorInput;
		sf::Texture _vol1Texture;
		sf::Sprite _vol1Sprite;
		sf::Texture _vol2Texture;
		sf::Sprite _vol2Sprite;
		sf::Texture _vol3Texture;
		sf::Sprite _vol3Sprite;
		sf::Texture _vol4Texture;
		sf::Sprite _vol4Sprite;
		int _vol;
};

#endif /* !MENU_HPP_ */
