//
// EPITECH PROJECT, 2018
// zappy
// File description:
// frequency scroller
//

#include "FrequencyScroller.hpp"
#include <unistd.h>

FrequencyScroller::FrequencyScroller(
	std::pair<sf::Vector2i, sf::Vector2i> pos,
	sf::RenderWindow &window,
	sf::Color color) :
	_isActive(true),
	_from(pos.first), _to(pos.second),
	_frequency(1), _color(color), _sep(35.f), _maximum(500.f),
	_drag(false), _tolerate(10), _baseSize(window.getSize()),
	_saveFrom(pos.first), _saveTo(pos.second), _updated(false),
	_saveFrequency(1)
{
	assert(_font.loadFromFile("./design/Supercell-magic-webfont.ttf"));
	_text.setFont(_font);
	_text.setCharacterSize(18);
	_text.setFillColor(_color * sf::Color(255, 255, 255, 255));
	_text.setString("Frequency :");
	_value.setFont(_font);
	_value.setCharacterSize(12);
	_value.setFillColor(_color * sf::Color(255, 255, 255, 255));
	initShapes();
}

FrequencyScroller::~FrequencyScroller()
{
}

void FrequencyScroller::setFrequency(int frequency)
{
	_frequency = frequency;
	if (_frequency < 1)
		_frequency = 1;
	else if (_frequency >= _maximum)
		_frequency = _maximum;
	if (!_drag && _saveFrequency != _frequency) {
		_saveFrequency = _frequency;
		_updated = true;
	}
}

int FrequencyScroller::getFrequency() const
{
	return _saveFrequency;
}

float FrequencyScroller::getMaximum() const
{
	return _maximum;
}

void FrequencyScroller::setMaximum(float maximum)
{
	_maximum = maximum;
	setFrequency(_frequency);
}

void FrequencyScroller::updateFromCursor(sf::Vector2f pos)
{
	float percent;

	percent = (pos.x - (_from.x + _sep)) / ((_to
		.x - _from.x) - (_sep * 2));
	setFrequency(percent * _maximum);
}

void FrequencyScroller::initShapes()
{
	sf::Vector2f pos;

	_text.setPosition(_from.x + ((_to.x - _from.x) / 2) -
		(_text.getLocalBounds().width / 2), _from.y + 3);
	_size.x = _to.x - _from.x - (_sep * 2);
	_size.y = 15.f;
	pos.x = _from.x + _sep;
	pos.y = _from.y + ((_to.y - _from.y) / 2) - (_size.y / 2);
	_scalePos = pos;
	_back.setSize(sf::Vector2f(_to.x - _from.x, _to.y - _from.y));
	_back.setPosition(_from.x, _from.y);
	_back.setFillColor(_color * sf::Color(115, 115, 115, 255));
	_scale.setSize(_size);
	_scale.setPosition(pos);
	_scale.setFillColor(_color * sf::Color(50, 50, 50, 255));
	_cursor.setPointCount(5);
	_cursor.setFillColor(_color * sf::Color(255, 255, 255, 255));
}

void FrequencyScroller::setCursorPosition()
{
	sf::Vector2f pos;
	float percent = _frequency / _maximum;
	sf::FloatRect rec;

	pos.x = _from.x + _sep + (_size.x * percent);
	pos.y = _from.y + ((_to.y - _from.y) / 2) - (_size.y / 2);
	_cursor.setPoint(0, sf::Vector2f(pos.x, pos.y));
	_cursor.setPoint(1, sf::Vector2f(pos.x + 6.f, pos.y + 10.f));
	_cursor.setPoint(2, sf::Vector2f(pos.x + 6.f, pos.y + 10.f + _size.y));
	_cursor.setPoint(3, sf::Vector2f(pos.x - 6.f, pos.y + 10.f + _size.y));
	_cursor.setPoint(4, sf::Vector2f(pos.x - 6.f, pos.y + 10.f));
	rec = _value.getLocalBounds();
	_value.setPosition(pos.x - (rec.width / 2),
		pos.y + 10.f + _size.y + 10.f);
}

void FrequencyScroller::updateFrequencyValue()
{
	_value.setString(std::to_string(_frequency));
}

sf::ConvexShape FrequencyScroller::getCursor() const
{
	return _cursor;
}

void FrequencyScroller::setDrag(bool drag)
{
	if (_drag && !drag) {
		_updated = true;
		_saveFrequency = _frequency;
	}
	_drag = drag;
}

bool FrequencyScroller::getDrag() const
{
	return _drag;
}

void FrequencyScroller::clickOnCursor(sf::Vector2f pos)
{
	sf::Vector2f first = _cursor.getPoint(1);
	sf::Vector2f third = _cursor.getPoint(3);

	if (pos.x >= third.x - _tolerate &&
	pos.x <= first.x + _tolerate &&
	pos.y >= first.y - _tolerate &&
	pos.y <= third.y + _tolerate)
		_drag = true;
}

void FrequencyScroller::clickOnScale(sf::Vector2f pos)
{
	sf::Vector2f position = _scalePos;
	sf::Vector2f size = _size;

	if (pos.x >= position.x - _tolerate &&
	pos.x <= position.x + size.x + _tolerate &&
	pos.y >= position.y - _tolerate &&
	pos.y <= position.y + size.y + _tolerate) {
		_drag = true;
		updateFromCursor(pos);
	}
}

void FrequencyScroller::draw(sf::RenderWindow &window)
{
	window.draw(_back);
	window.draw(_scale);
	updateFrequencyValue();
	setCursorPosition();
	window.draw(_cursor);
	window.draw(_value);
	window.draw(_text);
}

void FrequencyScroller::handleEvents(sf::RenderWindow &window,
	sf::Event &event)
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

	if (!_isActive)
		return;
	if (event.type == sf::Event::Closed)
		window.close();
	if (event.type == sf::Event::MouseMoved && _drag)
		updateFromCursor(worldPos);
	if (event.type == sf::Event::MouseButtonPressed &&
	event.mouseButton.button == sf::Mouse::Button::Left) {
		clickOnCursor(worldPos);
		clickOnScale(worldPos);
	}
	if (event.type == sf::Event::MouseButtonReleased &&
	event.mouseButton.button == sf::Mouse::Button::Left)
		setDrag(false);
	if (event.type == sf::Event::Resized)
		initShapes();
}

void FrequencyScroller::setIsActive(bool active)
{
	_isActive = active;
}

bool FrequencyScroller::isActive() const
{
	return _isActive;
}

bool FrequencyScroller::getUpdated() const
{
	return _updated;
}

void FrequencyScroller::setUpdated(bool updated)
{
	_updated = updated;
}

void FrequencyScroller::run(sf::RenderWindow &window)
{
	if (_isActive)
		draw(window);
}