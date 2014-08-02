#pragma once

#include <SFGUI/SFGUI.hpp>
#include <SFML/Graphics.hpp>

class Application
{
	private:
		sf::RenderWindow window;
		sfg::Window sfg_window;
		sfg::Desktop desktop;
		sf::Event event;
		sf::Clock clock;

	public:
		void Run();
};