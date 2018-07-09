/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** zappy
*/

#include "Zappy.hpp"

Zappy::Zappy(sf::RenderWindow &window) :
	_active(true), _size(50), _higher(1),
	_screenSize(window.getSize())
{
	assert(_backTexture.loadFromFile("./design/back.jpg"));
        _backSprite.setTexture(_backTexture);
	assert(_font.loadFromFile("./design/Supercell-magic-webfont.ttf"));
	assert(_musicBuffer.loadFromFile("./design/music.ogg"));
        _musicSound.setBuffer(_musicBuffer);
	_musicSound.setLoop(true);
	_musicSound.setVolume(100);
	initTexts();
}

Zappy::~Zappy()
{
}

void Zappy::initTexts()
{
	_clickOnScreenToPlay.setString("Click on the screen to play !");
	_clickOnScreenToPlay.setFillColor(sf::Color(250, 250, 250, 250));
	_clickOnScreenToPlay.setFont(_font);
	_clickOnScreenToPlay.setStyle(sf::Text::Bold);
	_clashOfZappyBack.setString("Clash of Zappy");
	_clashOfZappyBack.setFillColor(sf::Color(0, 0, 0, 100));
	_clashOfZappyBack.setFont(_font);
	_clashOfZappyBack.setCharacterSize(150);
	_clashOfZappyBack.setPosition(305, 25);
	_clashOfZappyBack.setStyle(sf::Text::Bold);
	_clashOfZappyFront.setString("Clash of Zappy");
	_clashOfZappyFront.setFillColor(sf::Color(0, 0, 0, 190));
	_clashOfZappyFront.setFont(_font);
	_clashOfZappyFront.setCharacterSize(150);
	_clashOfZappyFront.setPosition(300, 20);
	_clashOfZappyFront.setStyle(sf::Text::Bold);
}

bool Zappy::isActive() const
{
	return _active;
}

void Zappy::setActive(bool active)
{
	_active = active;
}

void Zappy::manageSize()
{
	sf::FloatRect rect;

	_size += 0.075 * _higher;
	if (_size > 60)
		_higher = -1;
	if (_size < 50)
		_higher = 1;
	_clickOnScreenToPlay.setCharacterSize(_size);
	rect = _clickOnScreenToPlay.getLocalBounds();
	_clickOnScreenToPlay.setPosition(_screenSize.x / 2 - rect.width / 2,
	_screenSize.y / 2 - rect.height / 2);
}

void Zappy::draw(sf::RenderWindow &window)
{
	window.draw(_backSprite);
	window.draw(_clashOfZappyBack);
	window.draw(_clashOfZappyFront);
	manageSize();
	window.draw(_clickOnScreenToPlay);
}

void Zappy::eventHandler(sf::RenderWindow &window, sf::Event &event)
{
	if (event.type == sf::Event::Closed)
		window.close();
	if (event.type == sf::Event::MouseButtonPressed &&
	event.mouseButton.button == sf::Mouse::Button::Left) {
		Form form(window);
		form.run(window);
	}
}

void Zappy::run(sf::RenderWindow &window)
{
	sf::Event event;

	_musicSound.play();
	while (window.isOpen() && _active) {
		while (window.pollEvent(event))
			eventHandler(window, event);
		window.clear(sf::Color(10,10,10));
		draw(window);
		window.display();
	}
	_musicSound.stop();
}