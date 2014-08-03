#pragma once

#include <SFGUI/SFGUI.hpp>
#include <SFML/Graphics.hpp>


/*  This class contains the logic of the top-down
 *	tiled map editor known as "Flume"
 */
	class Application
	{
		private:
			sf::RenderWindow window;
			sfg::Desktop desktop;
			sfg::SFGUI m_sfgui;
			sf::Event event;
			sf::Clock clock;

		public:
			Application();

			void Run();
	};