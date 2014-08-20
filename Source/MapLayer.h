#pragma once

#include <string>
#include <map>

/*  A map layer is basically a container of tiles organized
 *  with other layers to form a map. Every layer should hold
 *  the tile data, and contain properties that affect every tile
 */
	class MapLayer
	{
		private:
			std::string name;
			std::map<std::string, bool> properties;

		public:
			MapLayer();
	};