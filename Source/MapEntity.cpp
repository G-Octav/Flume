#include "MapEntity.hpp"
#include "Stdafx.hpp"

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 10th August 2014
* Description: Constructs a map entity
* ----------------------------------------------------------------------
*/
	MapEntity::MapEntity()
	{

	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 10th August 2014
* Description: Returns the properties list
* ----------------------------------------------------------------------
*/
	std::map<std::string, bool>& MapEntity::getProperties()
	{
		return properties;
	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 10th August 2014
* Description: Returns the relative position (in tiles)
* ----------------------------------------------------------------------
*/
	sf::Vector2f& MapEntity::getRelativePosition()
	{
		return sf::Vector2f(position.x / TILE_SIZE, position.y / TILE_SIZE);
	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 10th August 2014
* Description: Returns the position (in pixels)
* ----------------------------------------------------------------------
*/
	sf::Vector2f& MapEntity::getPosition()
	{
		return position;
	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 10th August 2014
* Description: Returns the width of the map entity.
* ----------------------------------------------------------------------
*/
	int& MapEntity::getWidth()
	{
		return width;
	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 10th August 2014
* Description: Returns the height of the map entity.
* ----------------------------------------------------------------------
*/
	int& MapEntity::getHeight() 
	{
		return height;
	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 10th August 2014
* Description: Returns the rotation of the entity.
* ----------------------------------------------------------------------
*/
	float& MapEntity::getRotation()
	{
		return rotation;
	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 10th August 2014
* Description: Returns true if the entity is flipped horizontally
* ----------------------------------------------------------------------
*/
	bool MapEntity::isFlippedX() 
	{
		return isFlippedX;
	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 10th August 2014
* Description: Returns true if the entity is flipped vertically
* ----------------------------------------------------------------------
*/
	bool MapEntity::isFlippedY() 
	{
		return isFlippedY;
	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 10th August 2014
* Description: Returns the visible state of the map entity.
* ----------------------------------------------------------------------
*/
	bool MapEntity::isVisible() 
	{
		return visible;
	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 10th August 2014
* Description: Sets a certain property of the entity
* ----------------------------------------------------------------------
*/
	void MapEntity::setProperty(std::string key, bool state)
	{
		if (properties.count(key))
		{
			properties[key] = state;
		}
	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 10th August 2014
* Description: Sets the relative position of the entity (in tiles)
* ----------------------------------------------------------------------
*/
	void MapEntity::setRelativePosition(int x, int y)
	{
		position.x = x * TILE_SIZE;
		position.y = y * TILE_SIZE;
	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 10th August 2014
* Description: Sets the position of the entity (in pixels)
* ----------------------------------------------------------------------
*/
	void MapEntity::setPosition(sf::Vector2f pos)
	{
		position = pos;
	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 10th August 2014
* Description: Sets the position (no vector)
* ----------------------------------------------------------------------
*/
	void MapEntity::setPosition(float x, float y)
	{
		position = sf::Vector2f(x, y);
	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 10th August 2014
* Description: Sets the visible state of the entity
* ----------------------------------------------------------------------
*/
	void MapEntity::setVisibile(bool state)
	{
		visible = state;
	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 10th August 2014
* Description: Sets the rotation of the entity
* ----------------------------------------------------------------------
*/
	void MapEntity::rotate(float degrees)
	{
		rotation = degrees;
	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 10th August 2014
* Description: Flips the entity horizontally
* ----------------------------------------------------------------------
*/
	void MapEntity::flipHorizontally()
	{
		flippedX = !isFlippedX;
	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 10th August 2014
* Description: Flips the entity vertically
* ----------------------------------------------------------------------
*/
	void MapEntity::flipVertically()
	{
		flippedY = !isFlippedY;
	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 10th August 2014
* Description: Sets the height of the entity
* ----------------------------------------------------------------------
*/
	void MapEntity::setHeight(int h)
	{
		height = h;
	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 10th August 2014
* Description: Sets the width of the entity.
* ----------------------------------------------------------------------
*/
	void MapEntity::setWidth(int w)
	{
		width = w;
	}
