#pragma once

#include <SFML/Graphics.hpp>

/*  This class represents a 2D map
*/
namespace flume
{
	class Map
	{
		private:
			sf::VertexArray mapGrid;

		public:
			Map(sf::String filename);

			const sf::VertexArray& getMapGrid();
	};
}