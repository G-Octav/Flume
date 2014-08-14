#pragma once

#include <SFML/Graphics.hpp>
#include "Stdafx.hpp"

/*  This class represents a 2D map
*/
namespace flume
{
	class Map
	{
		public:
			Map(Context context, sf::String filename);
			const sf::VertexArray& getMapGrid();

		private:
			sf::VertexArray mapGrid;
			Context context;
	};
}