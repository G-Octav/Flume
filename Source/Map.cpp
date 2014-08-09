#include "Map.hpp"
#include "Stdafx.hpp"

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 8th August 2014
* Description: Constructs a map
* ----------------------------------------------------------------------
*/
	flume::Map::Map(sf::String filename)
	: mapGrid(sf::Lines, SCREEN_WIDTH / TILE_SIZE + SCREEN_HEIGHT / TILE_SIZE)
	{
		int t_index = 0;

		for (float x = 0; x < SCREEN_WIDTH; x += TILE_SIZE) 
		{
				sf::Vertex tile[2];

				tile[0].position = sf::Vector2f(x, 0);
				tile[1].position = sf::Vector2f(x, SCREEN_HEIGHT);

				tile[0].color = grid_color;
				tile[1].color = grid_color;

				mapGrid.append(tile[0]);
				mapGrid.append(tile[1]);
		}

		for (float y = 0; y < SCREEN_HEIGHT; y += TILE_SIZE)
		{
			sf::Vertex tile[2];

			tile[0].position = sf::Vector2f(0, y);
			tile[1].position = sf::Vector2f(SCREEN_WIDTH, y);

			tile[0].color = grid_color;
			tile[1].color = grid_color;

			mapGrid.append(tile[0]);
			mapGrid.append(tile[1]);
		}
	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 8th August 2014
* Description: Returns the map grid
* ----------------------------------------------------------------------
*/
	const sf::VertexArray& flume::Map::getMapGrid()
	{
		return mapGrid;
	}