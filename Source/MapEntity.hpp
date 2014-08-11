#pragma once

#include <SFML/Graphics.hpp>
#include <map>

/*  This class represents a simple entity in a map.
 *  It can represent an animation, or a trigger, or
 *	simply a normal regular tile! Note that the map
 *  itself is not a collection of map entities, these
 *  kinds of classes are isolated cases, and the map
 *  itself, from a graphical point of view is a vertex array
 */
	class MapEntity
	{
		protected:
			std::map<std::string, bool> properties;
			sf::Vector2f position;
			float rotation;
			bool flippedX;
			bool flippedY;
			bool visible;
			int height;
			int width;

		public:
			MapEntity();

			/* ---------- Getters -------------- */

			std::map<std::string, bool>& getProperties();
			sf::Vector2f& getRelativePosition();
			sf::Vector2f& getPosition();
			int& getWidth();
			int& getHeight();
			float& getRotation();
			bool isFlippedX();
			bool isFlippedY();
			bool isVisible();

			/* ---------- Setters -------------- */
			virtual void setProperty(std::string key, bool state);
			virtual void setRelativePosition(int x, int y);
			virtual void setPosition(sf::Vector2f pos);
			virtual void setPosition(float x, float y);
			virtual void setVisibile(bool state);
			virtual void rotate(float degrees);
			virtual void flipHorizontally();
			virtual void flipVertically();
			virtual void setHeight(int h);
			virtual void setWidth(int w);
	};