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
		auto tools = sfg::Window::Create();
		auto layers = sfg::Window::Create();
		auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);
		auto layersBox = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);
		auto button_row = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 0.0f);
		auto button1 = sfg::Button::Create("Save Map");
		auto button2 = sfg::Button::Create("Load Map");
		auto infoframe = sfg::Frame::Create("info");
		auto scrolledwindow = sfg::ScrolledWindow::Create();

		scrolledwindow->SetScrollbarPolicy(sfg::ScrolledWindow::HORIZONTAL_NEVER | sfg::ScrolledWindow::VERTICAL_AUTOMATIC);
		scrolledwindow->SetRequisition(sf::Vector2f(170.f, 100.f));
		tools->SetTitle("Tool window");
		layers->SetTitle("Layer List");
		tools->SetPosition(sf::Vector2f(30,30));

		std::string frameText = wrap("This is the alpha version of Flume. Use the buttons above to create a new layer and save your work", 20);
		
		auto infotext = sfg::Label::Create(frameText);
		infoframe->Add(infotext);
		layers->SetPosition(sf::Vector2f(tools->GetAbsolutePosition().x, tools->GetAbsolutePosition().y+tools->GetClientRect().height*5));

		button_row->Pack(button1, true);
		button_row->Pack(button2, true);
		box->Pack(button_row);
		box->Pack(infoframe);
		layersBox->Pack(sfg::Label::Create("Layer list: "), false, true);
		layersBox->Pack(scrolledwindow, false, true);
		tools->Add(box);
		layers->Add(layersBox);
		desktop.Add(tools);
		desktop.Add(layers);
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