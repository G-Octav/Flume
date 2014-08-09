#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/View.hpp>
#include <sstream>
#include <string>
#include <map>

const int TILES_PER_ROW = 8;
const int TILE_SIZE = 32;

const int SCREEN_WIDTH = 1290;
const int SCREEN_HEIGHT = 964;

int toCategory(std::string string);

// Some colors
const sf::Color error_color = sf::Color(221, 61, 6);
const sf::Color success_color = sf::Color(110, 201, 28);
const sf::Color warning_color = sf::Color(225, 174, 0);
const sf::Color collision_debug_color = sf::Color::Green;
const sf::Color grid_color = sf::Color(50,50,50);



// Convert enumerators to strings
std::string toString(sf::Keyboard::Key key);

void centerOrigin(sf::CircleShape& circleShape);
void centerOrigin(sf::RectangleShape& rectangleShape);
void centerOrigin(sf::Sprite& sprite);
void centerOrigin(sf::Text& text);

bool isOnScreen(const sf::Sprite& sprite, const sf::View& camera);
float randomFloat(float min, float max);
int randomInteger(int min, int max);

float distance(const sf::Vector2f first, const sf::Vector2f second);
float dotProduct(const sf::Vector2f& vector1, const sf::Vector2f& vector2);
float magnitude(const sf::Vector2f& vector);
sf::Vector2f normalize(const sf::Vector2f&vector);
std::string wrap(std::string text, size_t line_length = 35);