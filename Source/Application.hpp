#pragma once

#include <SFGUI/SFGUI.hpp>
#include <SFML/Graphics.hpp>
#include "Stdafx.hpp"
#include "Map.hpp"


/*  This class contains the logic of the top-down
 *	tiled map editor known as "Flume"
 */
	class Application
	{
		public:
			Application();
			void run();

		private:
			sf::RectangleShape hoverRect;
			sf::RenderWindow window;
			sf::Uint8 windowStyle;
			sfg::Desktop desktop;
			sfg::SFGUI sfgui;
			Context context;

			flume::Map map;
			unsigned int snapSize;

			void update(const sf::Time& elapsedTime);
			void loadResolution();
			void handleEvents();
			void render();
	};