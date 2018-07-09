/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** form
*/

#include "Form.hpp"

Form::Form(sf::RenderWindow &window) :
	_active(false), _dame(new Dame(window)),
	_hostName(std::string("localhost")), _port(std::string("4242")),
	_focus(FORM_NONE)
{
	assert(_backTexture.loadFromFile("./design/back.jpg"));
        _backSprite.setTexture(_backTexture);
	assert(_font.loadFromFile("./design/Supercell-magic-webfont.ttf"));
	assert(_clickBuffer.loadFromFile("./design/click.ogg"));
        _clickSound.setBuffer(_clickBuffer);
	initFormPlace();
	initFormFields();
	initFormTexts();
	initTitles();
	_errorConnecting.setFont(_font);
	_errorConnecting.setCharacterSize(25);
	_errorConnecting.setPosition(910, 810);
	_errorConnecting.setStyle(sf::Text::Bold);
	_errorConnecting.setFillColor(sf::Color(250, 0, 0, 200));
	_errorConnecting.setString("");
}

Form::~Form()
{
}

void Form::initFormPlace()
{
	_formPlaceBack.setSize(sf::Vector2f(700, 750));
	_formPlaceBack.setPosition(705, 205);
	_formPlaceBack.setFillColor(sf::Color(50, 50, 50, 150));
	_formPlaceFront.setSize(sf::Vector2f(700, 750));
	_formPlaceFront.setPosition(700, 200);
	_formPlaceFront.setFillColor(sf::Color(250, 250, 250, 200));
	_titleForm.setString("Connection to server");
	_hostNameFieldText.setString("Host Name:");
	_portFieldText.setString("Port:");
	_sendText.setString("SEND");
}

void Form::initFormFields()
{
	_hostNameBack.setSize(sf::Vector2f(406, 56));
	_hostNameBack.setPosition(747, 397);
	_hostNameFront.setSize(sf::Vector2f(400, 50));
	_hostNameFront.setPosition(750, 400);
	_hostNameFront.setFillColor(sf::Color(180, 180, 180, 250));
	_portBack.setSize(sf::Vector2f(406, 56));
	_portBack.setPosition(747, 547);
	_portFront.setSize(sf::Vector2f(400, 50));
	_portFront.setPosition(750, 550);
	_portFront.setFillColor(sf::Color(180, 180, 180, 250));
	_sendBack.setSize(sf::Vector2f(168, 58));
	_sendBack.setPosition(965, 855);
	_sendBack.setFillColor(sf::Color(50, 50, 50, 150));
	_sendFront.setSize(sf::Vector2f(170, 60));
	_sendFront.setPosition(960, 850);
}

void Form::initFormTexts()
{
	_hostNameText.setFont(_font);
	_hostNameText.setCharacterSize(25);
	_hostNameText.setPosition(770, 410);
	_hostNameText.setStyle(sf::Text::Bold);
	_hostNameText.setFillColor(sf::Color(120, 120, 120, 200));
	_portText.setFont(_font);
	_portText.setCharacterSize(25);
	_portText.setPosition(770, 560);
	_portText.setStyle(sf::Text::Bold);
	_portText.setFillColor(sf::Color(120, 120, 120, 200));
	_sendText.setFont(_font);
	_sendText.setCharacterSize(20);
	_sendText.setPosition(1010, 870);
	_sendText.setStyle(sf::Text::Bold);
	_sendText.setFillColor(sf::Color(250, 250, 250, 250));
}

void Form::initTitles()
{
	_titleForm.setFont(_font);
	_titleForm.setCharacterSize(30);
	_titleForm.setPosition(750, 250);
	_titleForm.setStyle(sf::Text::Bold);
	_titleForm.setFillColor(sf::Color(0, 0, 0, 250));
	_hostNameFieldText.setFont(_font);
	_hostNameFieldText.setCharacterSize(20);
	_hostNameFieldText.setPosition(750, 360);
	_hostNameFieldText.setStyle(sf::Text::Bold);
	_hostNameFieldText.setFillColor(sf::Color(120, 120, 120, 250));
	_portFieldText.setFont(_font);
	_portFieldText.setCharacterSize(20);
	_portFieldText.setPosition(750, 510);
	_portFieldText.setStyle(sf::Text::Bold);
	_portFieldText.setFillColor(sf::Color(120, 120, 120, 250));
}

bool Form::isActive() const
{
	return _active;
}

void Form::setActive(bool active)
{
	_active = active;
}

void Form::deleteChar()
{
	int	count;

	if (_focus == FORM_HOSTNAME) {
		count = _hostName.size() - 1;
		if (count >= 0)
			_hostName.erase(count, 1);
	}
	if (_focus == FORM_PORT) {
		count = _port.size() - 1;
		if (count >= 0)
			_port.erase(count, 1);
	}
}

void Form::addChar(char new_char)
{
	if (_focus == FORM_HOSTNAME)
		_hostName.append(1, new_char);
	if (_focus == FORM_PORT)
		_port.append(1, new_char);
}

void Form::setupColors()
{
	_hostNameBack.setFillColor(sf::Color(50, 50, 50, 150));
	_portBack.setFillColor(sf::Color(50, 50, 50, 150));
	if (_focus == FORM_HOSTNAME)
		_hostNameBack.setFillColor(sf::Color(0, 0, 250, 100));
	if (_focus == FORM_PORT)
		_portBack.setFillColor(sf::Color(0, 0, 250, 100));
	_sendFront.setFillColor(sf::Color(0, 250, 0, 250));
	if (_hostName == "")
		_sendFront.setFillColor(sf::Color(250, 0, 0, 250));
	else if (_focus == FORM_SEND)
		_sendFront.setFillColor(sf::Color(0, 0, 250, 250));
}

void Form::setupDrawTexts(sf::RenderWindow &window)
{
	_hostNameText.setString(_hostName);
	_portText.setString(_port);
	window.draw(_titleForm);
	window.draw(_hostNameFieldText);
	window.draw(_portFieldText);
	window.draw(_hostNameText);
	window.draw(_portText);
	window.draw(_sendText);
}

void Form::draw(sf::RenderWindow &window)
{
	window.draw(_backSprite);
	_dame->draw(window);
	setupColors();
	window.draw(_formPlaceBack);
	window.draw(_formPlaceFront);
	window.draw(_hostNameBack);
	window.draw(_hostNameFront);
	window.draw(_portBack);
	window.draw(_portFront);
	window.draw(_sendBack);
	window.draw(_sendFront);
	window.draw(_errorConnecting);
	setupDrawTexts(window);
}

void Form::connectClient(sf::RenderWindow &window)
{
	Manager manager(window, graph_init(_port.c_str(), _hostName.c_str()));

	if (!manager.run(window))
		_errorConnecting.setString("Connexion Failed !");
	else
		_errorConnecting.setString("");
}

void Form::handleMouseClick(sf::RenderWindow &window)
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

	_focus = FORM_NONE;
	if (worldPos.y > 400 && worldPos.y < 450 && worldPos.x >
	750 && worldPos.x < 1150)
		_focus = FORM_HOSTNAME;
	if (worldPos.y > 550 && worldPos.y < 600 && worldPos.x >
	750 && worldPos.x < 1150)
		_focus = FORM_PORT;
	if (worldPos.y > 850 && worldPos.y < 910 && worldPos.x >
	960 && worldPos.x < 1130)
		_focus = FORM_SEND;
	if (_focus != FORM_NONE)
		_clickSound.play();
	if (_focus == FORM_SEND)
		connectClient(window);
}

void Form::eventHandler(sf::RenderWindow &window, sf::Event &event)
{
	if (event.type == sf::Event::Closed)
		window.close();
	if (event.type == sf::Event::MouseButtonPressed &&
	event.mouseButton.button == sf::Mouse::Button::Left)
		handleMouseClick(window);
	if (event.type == sf::Event::KeyPressed) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			_active = false;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
			deleteChar();
	}
	if (event.type == sf::Event::TextEntered &&
	event.text.unicode < 128 && event.text.unicode > 31)
		addChar(event.text.unicode);
}

void Form::run(sf::RenderWindow &window)
{
	sf::Event event;

	_active = true;
	while (window.isOpen() && _active) {
		while (window.pollEvent(event))
			eventHandler(window, event);
		window.clear(sf::Color(10,10,10));
		draw(window);
		window.display();
	}
}