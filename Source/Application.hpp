#pragma once

#include <SFGUI/SFGUI.hpp>
#include <SFML/Graphics.hpp>

#include "Map.hpp"


/*  This class contains the logic of the top-down
 *	tiled map editor known as "Flume"
 */
	class Application
	{
		private:
			sf::RectangleShape hoverRect;
			sf::RenderWindow window;
			sfg::Desktop desktop;
			sfg::SFGUI sfgui;

			flume::Map map;
			unsigned int snapSize;

			void update(const sf::Time& elapsedTime);
			void handleEvents();
			void render();

		public:
			Application();

			void run();
	};