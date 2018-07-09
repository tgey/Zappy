//
// EPITECH PROJECT, 2018
// zappy
// File description:
// frequency scroller
//

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cassert>
#include <iostream>

class FrequencyScroller {
	public:
		FrequencyScroller(
			std::pair<sf::Vector2i, sf::Vector2i> pos,
			sf::RenderWindow &window,
			sf::Color color = sf::Color(120, 120, 120, 255));
		~FrequencyScroller();
		void setFrequency(int);
		int getFrequency() const;
		float getMaximum() const;
		void setMaximum(float);
		void updateFromCursor(sf::Vector2f pos);
		void initShapes();
		void draw(sf::RenderWindow &window);
		void setCursorPosition();
		void updateFrequencyValue();
		sf::ConvexShape getCursor() const;
		void setDrag(bool drag);
		bool getDrag() const;
		void clickOnCursor(sf::Vector2f);
		void clickOnScale(sf::Vector2f);
		void handleEvents(sf::RenderWindow &window, sf::Event &);
		void run(sf::RenderWindow &window);
		void setIsActive(bool);
		bool isActive() const;
		bool getUpdated() const;
		void setUpdated(bool);

	protected:
	private:
		bool _isActive;
		sf::Vector2i _from;
		sf::Vector2i _to;
		bool _useImages;
		int _frequency;
		sf::Color _color;
		sf::RectangleShape _back;
		sf::RectangleShape _scale;
		sf::ConvexShape _cursor;
		sf::Vector2f _size;
		float _sep;
		sf::Text _text;
		sf::Text _value;
		sf::Font _font;
		float _maximum;
		bool _drag;
		int _tolerate;
		sf::Vector2u _baseSize;
		sf::Vector2i _saveFrom;
		sf::Vector2i _saveTo;
		sf::Vector2f _scalePos;
		sf::Vector2f _percent;
		bool _updated;
		int _saveFrequency;
};
