/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Menu
*/

#include "Menu.hpp"
#include "Manager.hpp"

Menu::Menu(Manager &manager) : _manager(manager),
	_deployed(false), _posX(1920), _focusTextInput(false),
	_errorInput(false), _vol(4)
{
	assert(_fontMenu.loadFromFile("./design/main.ttf"));
	assert(_fontClash.loadFromFile(
		"./design/Supercell-magic-webfont.ttf"));
	initText();
	assert(_menuTexture.loadFromFile("./design/menu.png"));
	_menuSprite.setTexture(_menuTexture);
	_freqText = std::to_string(static_cast<int>(_manager.getMaximum()));
	assert(_vol1Texture.loadFromFile("./design/vol1.png"));
	_vol1Sprite.setTexture(_vol1Texture);
	assert(_vol2Texture.loadFromFile("./design/vol2.png"));
	_vol2Sprite.setTexture(_vol2Texture);
	assert(_vol3Texture.loadFromFile("./design/vol3.png"));
	_vol3Sprite.setTexture(_vol3Texture);
	assert(_vol4Texture.loadFromFile("./design/vol4.png"));
	_vol4Sprite.setTexture(_vol4Texture);
	initVolSprites();
}

Menu::~Menu()
{
}

void	Menu::initVolSprites()
{
	_vol1Sprite.setPosition(1568, 276);
	_vol2Sprite.setPosition(1596, 276);
	_vol3Sprite.setPosition(1624, 276);
	_vol4Sprite.setPosition(1652, 276);
}

void	Menu::initText()
{
	_menuText.setFont(_fontMenu);
	_menuText.setCharacterSize(50);
	_menuText.setPosition(1700, 70);
	_menuText.setStyle(sf::Text::Bold);
	_menuText.setFillColor(sf::Color(0, 0, 0, 200));
	_menuText.setString("Menu");
	_inputText.setFont(_fontClash);
	_inputText.setCharacterSize(20);
	_inputText.setPosition(1562, 683);
	_inputText.setStyle(sf::Text::Bold);
	_inputText.setFillColor(sf::Color(120, 120, 120, 250));
}

void	Menu::textInputFocus(sf::Vector2f worldPos)
{
	if (worldPos.y >= 669 && worldPos.y <= 718 &&
		worldPos.x >= 1556 && worldPos.x <= 1659) {
		_focusTextInput = true;
	} else
		_focusTextInput = false;
}

void	Menu::textInputFill(sf::Event &event)
{
	int	count = 0;

	if (event.type == sf::Event::KeyPressed &&
	sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
		count = _freqText.size() - 1;
		if (count >= 0)
			_freqText.erase(count, 1);
	}
	if (event.type == sf::Event::TextEntered &&
	event.text.unicode >= 48 && event.text.unicode <= 57 &&
		std::strlen(_freqText.c_str()) < 6) {
		_freqText.append(1, event.text.unicode);
	}
}

void	Menu::updateFreqMax()
{
	std::string::size_type	sz;
	float			maxFreq;

	if (std::strlen(_freqText.c_str()) > 0) {
		maxFreq = std::stof(_freqText, &sz);
		if (maxFreq < 100) {
			_errorInput = true;
		} else {
			_manager.setMaximum(maxFreq);
			_errorInput = false;
		}
	} else {
		_errorInput = true;
	}
}

void	Menu::updateVolMax(sf::Vector2f worldPos)
{
	if (worldPos.y >= 394 && worldPos.y <= 426 &&
		worldPos.x >= 1568 && worldPos.x <= 1580)
		_vol = 1;
	if (worldPos.y >= 375 && worldPos.y <= 426 &&
		worldPos.x >= 1598 && worldPos.x <= 1610)
		_vol = 2;
	if (worldPos.y >= 353 && worldPos.y <= 426 &&
		worldPos.x >= 1624 && worldPos.x <= 1636)
		_vol = 3;
	if (worldPos.y >= 334 && worldPos.y <= 426 &&
		worldPos.x >= 1654 && worldPos.x <= 1666)
		_vol = 4;
}

void	Menu::handleEvents(sf::RenderWindow &window, sf::Event &event)
{
	if (event.type == sf::Event::MouseButtonPressed &&
	event.mouseButton.button == sf::Mouse::Button::Left && !_deployed) {
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
		if (worldPos.y >= 37 && worldPos.y <= 183 &&
			worldPos.x >= 1646 && worldPos.x <= 1862)
			_deployed = true;
	} else if (event.type == sf::Event::MouseButtonPressed &&
	event.mouseButton.button == sf::Mouse::Button::Left && _deployed) {
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
		textInputFocus(worldPos);
		updateVolMax(worldPos);
		if (worldPos.y >= 32 && worldPos.y <= 87 &&
			worldPos.x >= 1456 && worldPos.x <= 1510)
			_deployed = false;
	}
	textInputFill(event);
	updateFreqMax();
}

void	Menu::drawTextInput(sf::RenderWindow &window)
{
	_maxFreqShapeBack.setSize(sf::Vector2f(106, 56));
	_maxFreqShapeBack.setPosition(1555, 667);
	if (!_focusTextInput && (_errorInput == false))
		_maxFreqShapeBack.setFillColor(sf::Color(50, 50, 50, 200));
	else if (_errorInput == false)
		_maxFreqShapeBack.setFillColor(sf::Color(0, 0, 250, 100));
	else
		_maxFreqShapeBack.setFillColor(sf::Color(250, 0, 0, 200));
	_maxFreqShapeFront.setSize(sf::Vector2f(100, 50));
	_maxFreqShapeFront.setPosition(1558, 670);
	_maxFreqShapeFront.setFillColor(sf::Color(250, 250, 250, 200));
	window.draw(_maxFreqShapeBack);
	window.draw(_maxFreqShapeFront);
	_inputText.setString(_freqText);
	window.draw(_inputText);
}

void	Menu::drawMenuComponents(sf::RenderWindow &window)
{
	drawTextInput(window);
	if (_vol >= 1)
		window.draw(_vol1Sprite);
	if (_vol >= 2)
		window.draw(_vol2Sprite);
	if (_vol >= 3)
		window.draw(_vol3Sprite);
	if (_vol >= 4)
		window.draw(_vol4Sprite);
}

void	Menu::hideMenu(sf::RenderWindow &window)
{
	if (_posX < 1920) {
		_posX = _posX + 5;
		_menuSprite.setPosition(_posX, 0);
	}
	window.draw(_menuSprite);
}

void	Menu::drawMenu(sf::RenderWindow &window)
{
	if (_posX > 1420) {
		_posX = _posX - 5;
		_menuSprite.setPosition(_posX, 0);
		window.draw(_menuSprite);
	} else {
		window.draw(_menuSprite);
		drawMenuComponents(window);
	}
}

void	Menu::run(sf::RenderWindow &window)
{
	if (_deployed)
		drawMenu(window);
	else if (!_deployed && _posX < 1920)
		hideMenu(window);
	else
		window.draw(_menuText);
}

bool	Menu::getDeployed() const
{
	return _deployed;
}