#include "Stdafx.hpp"

/* ----------------------------------------------------------------------
 * Author: Julian
 * Date: 31 January 2014
 * Description: Centers the origin of a circle shape
 * ----------------------------------------------------------------------
 */
void centerOrigin(sf::CircleShape& circleShape)
{
	// Center the origin of a circle shape
	sf::FloatRect bounds = circleShape.getLocalBounds();
	circleShape.setOrigin(float(int(bounds.width / 2.0f)), float(int(bounds.height / 2.0f)));
}

void centerOrigin(sf::RectangleShape& rectangleShape)
{
	// Center the origin of a circle shape
	sf::FloatRect bounds = rectangleShape.getLocalBounds();
	rectangleShape.setOrigin(float(int(bounds.width / 2.0f)), float(int(bounds.height / 2.0f)));
}

/* ----------------------------------------------------------------------
 * Author: Julian
 * Date: 19 January 2014
 * Description: Centers the origin of a sprite
 * ----------------------------------------------------------------------
 */
void centerOrigin(sf::Sprite& sprite)
{
	// Center the origin of a sprite
	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(float(int(bounds.width / 2.0f)), float(int(bounds.height / 2.0f)));
}

/* ----------------------------------------------------------------------
 * Author: Julian
 * Date: 19 January 2014
 * Description: Centers the origin of a text
 * ----------------------------------------------------------------------
 */
void centerOrigin(sf::Text& text)
{
	// Center the origin of a text
	sf::FloatRect bounds = text.getLocalBounds();
	text.setOrigin(float(int(bounds.width / 2.0f)), float(int(bounds.height / 2.0f)));
}

/* ----------------------------------------------------------------------
 * Author: Julian
 * Date: 1 February
 * Description: Calculates the dot product of two vectors
 * ----------------------------------------------------------------------
 */
float dotProduct(const sf::Vector2f& vector1, const sf::Vector2f& vector2)
{
	// Return the dot product
	return vector1.x * vector2.x + vector1.y * vector2.y;
}

/* ----------------------------------------------------------------------
 * Author: Julian
 * Date: 2 February
 * Description: Calculates the sum of the vector
 * ----------------------------------------------------------------------
 */
float magnitude(const sf::Vector2f& vector)
{
	// Return the sum of the vector
	return sqrt(vector.x * vector.x + vector.y * vector.y);
}

/* ----------------------------------------------------------------------
 * Author: Julian
 * Date: 1 February
 * Description: Normalizes the vector
 * ----------------------------------------------------------------------
 */
sf::Vector2f normalize(const sf::Vector2f& vector)
{
	// Normalize the vector
	float sum = magnitude(vector);
	return sf::Vector2f(vector.x / sum, vector.y / sum);
}

/* ----------------------------------------------------------------------
 * Author: Julian
 * Date: 28 March
 * Description: Returns tru if the sprite is within the camera
 * ----------------------------------------------------------------------
 */
bool isOnScreen(const sf::Sprite& sprite, const sf::View& camera)
{
	// Calculate the position of the camera
	float camPosX = camera.getCenter().x - camera.getSize().x / 2.0f;
	float camPosY = camera.getCenter().y - camera.getSize().y / 2.0f;

	// Return true if the sprite is on the view of the camera
	return sprite.getPosition().x + sprite.getLocalBounds().width > camPosX && sprite.getPosition().x < camPosX + camera.getSize().x &&
		sprite.getPosition().y + sprite.getLocalBounds().height > camPosY && sprite.getPosition().y < camPosY + camera.getSize().y;
}

float randomFloat(float min, float max)
{
	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min + 1.0f)));
}

int randomInteger(int min, int max)
{
	return min + rand() / (RAND_MAX / (max - min + 1));
}

float distance(const sf::Vector2f first, const sf::Vector2f second)
{
	float x = second.x - first.x;
	float y = second.y - first.y;

	return sqrtf(x * x + y * y);
}

std::string wrap(std::string text, size_t line_length)
{
	std::istringstream words(text);
	std::ostringstream wrapped;
	std::string word;

	if (words >> word) {
		wrapped << word;
		size_t space_left = line_length - word.length();
		while (words >> word) {
			if (space_left < word.length() + 1) {
				wrapped << '\n' << word;
				space_left = line_length - word.length();
			}
			else {
				wrapped << ' ' << word;
				space_left -= word.length() + 1;
			}
		}
	}
	return wrapped.str();
}