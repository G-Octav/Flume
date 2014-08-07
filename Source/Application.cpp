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
		auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 0.0f);
		auto layersBox = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);
		auto button_row = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 0.0f);
		auto button_row2 = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 0.0f);
		auto button1 = sfg::Button::Create("Save Map");
		auto button2 = sfg::Button::Create("Load Map");
		auto button3 = sfg::Button::Create("New Map");
		auto button_add_layer = sfg::Button::Create(" + ");
		auto button_remove_layer = sfg::Button::Create("  -  ");
		auto button_layer_up = sfg::Button::Create("up");
		auto button_layer_down = sfg::Button::Create("down");
		auto button_layer_delete = sfg::Button::Create("  x  ");
		auto infoframe = sfg::Frame::Create("info");
		auto scrolledwindow = sfg::ScrolledWindow::Create();

		scrolledwindow->SetScrollbarPolicy(sfg::ScrolledWindow::HORIZONTAL_NEVER | sfg::ScrolledWindow::VERTICAL_AUTOMATIC);
		scrolledwindow->SetRequisition(sf::Vector2f(170.f, 200.f));
		tools->SetTitle("Tool window");
		tools->SetPosition(sf::Vector2f(30,30));

		std::string frameText = wrap("This is the alpha version of Flume. Use the buttons above to create a new layer and save your work", 20);
		
		auto infotext = sfg::Label::Create(frameText);
		infoframe->Add(infotext);

		button_add_layer->SetId("addlayer");
		button_remove_layer->SetId("removelayer");
		sfg::Context::Get().GetEngine().SetProperty("Button#addlayer", "BackgroundColor", sf::Color(0, 100, 0));
		sfg::Context::Get().GetEngine().SetProperty("Button#addlayer", "BorderColor", sf::Color(0, 100, 0));
		sfg::Context::Get().GetEngine().SetProperty("Button#addlayer:Prelight", "BackgroundColor", sf::Color(0, 130, 0));
		sfg::Context::Get().GetEngine().SetProperty("Button#addlayer:Prelight", "BorderColor", sf::Color(0, 130, 0));
		sfg::Context::Get().GetEngine().SetProperty("Button#addlayer > Label", "FontSize", 20.f);
		sfg::Context::Get().GetEngine().SetProperty("Button#removelayer", "BackgroundColor", sf::Color(100, 0, 0));
		sfg::Context::Get().GetEngine().SetProperty("Button#removelayer", "BorderColor", sf::Color(100, 0, 0));
		sfg::Context::Get().GetEngine().SetProperty("Button#removelayer:Prelight", "BackgroundColor", sf::Color(130, 0, 0));
		sfg::Context::Get().GetEngine().SetProperty("Button#removelayer:Prelight", "BorderColor", sf::Color(130, 0, 0));
		sfg::Context::Get().GetEngine().SetProperty("Button#removelayer > Label", "FontSize", 20.f);

		button_row->Pack(button1, true);
		button_row->Pack(button2, true);
		button_row2->Pack(button_add_layer, false);
		button_row2->Pack(button_remove_layer, false);
		button_row2->Pack(button_layer_up, true);
		button_row2->Pack(button_layer_down, false);
		button_row2->Pack(button_layer_delete, false);

		box->Pack(button_row);
		box->Pack(button3, true);
		//box->Pack(sfg::Label::Create("Layer list: "), false, true);
		box->Pack(button_row2);
		box->Pack(scrolledwindow, false, true);
		box->Pack(infoframe);

		tools->Add(box);
		desktop.Add(tools);
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