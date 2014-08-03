#include "Application.hpp"
#include "Stdafx.hpp"

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 2nd August 2014
* Description: Constructs an application.
* ----------------------------------------------------------------------
*/
	Application::Application() 
	: window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Flume Tiled Map Editor")
	{
		auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);
		auto button_row = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 5.0f);
		auto button1 = sfg::Button::Create("New layer");
		auto button2 = sfg::Button::Create("Load Tileset");
	}

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 2nd August 2014
* Description: Constructs an application.
* ----------------------------------------------------------------------
*/
	void Application::Run()
	{
		window.resetGLStates();

		while (window.isOpen()) {
			while (window.pollEvent(event)) {
				desktop.HandleEvent(event);

				if (event.type == sf::Event::Closed) {
					window.close();
				}

				else if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();
			}

			desktop.Update(clock.restart().asSeconds());

			window.clear();
			m_sfgui.Display(window);
			window.display();
		}
	}