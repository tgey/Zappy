/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** form
*/

#pragma once

extern "C" {
	#include "graph.h"
	graph_t *graph_init(const char *, const char *);
}

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cassert>
#include <iostream>
#include "Dame.hpp"
#include "Manager.hpp"

enum FormFocus {
	FORM_NONE,
	FORM_HOSTNAME,
	FORM_PORT,
	FORM_SEND
};

class Form {
	public:
		Form(sf::RenderWindow &);
		~Form();
		bool isActive() const;
		void setActive(bool active);
		void draw(sf::RenderWindow &window);
		void eventHandler(sf::RenderWindow &window, sf::Event &);
		void run(sf::RenderWindow &window);
		void initFormPlace();
		void initFormFields();
		void initFormTexts();
		void initTitles();
		void setupColors();
		void handleMouseClick(sf::RenderWindow &);
		void addChar(char);
		void deleteChar();
		void setupDrawTexts(sf::RenderWindow &);
		void connectClient(sf::RenderWindow &);

	protected:
	private:
		bool _active;
		sf::Texture _backTexture;
		sf::Sprite _backSprite;
		sf::Font _font;
		sf::SoundBuffer	_clickBuffer;
		sf::Sound _clickSound;
		Dame *_dame;
		std::string _hostName;
		std::string _port;
		FormFocus _focus;
		sf::RectangleShape _formPlaceBack;
		sf::RectangleShape _formPlaceFront;
		sf::RectangleShape _hostNameBack;
		sf::RectangleShape _hostNameFront;
		sf::Text _hostNameText;
		sf::Text _hostNameFieldText;
		sf::RectangleShape _portBack;
		sf::RectangleShape _portFront;
		sf::Text _portText;
		sf::Text _portFieldText;
		sf::RectangleShape _sendBack;
		sf::RectangleShape _sendFront;
		sf::Text _sendText;
		sf::Text _titleForm;
		sf::Text _errorConnecting;
};