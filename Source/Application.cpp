#include <SFML/Graphics.hpp>

#include "Application.hpp"
#include "Stdafx.hpp"

/* ----------------------------------------------------------------------
* Author: Octav
* Date: 2nd August 2014
* Description: Constructs an application.
* ----------------------------------------------------------------------
*/
Application::Application()
	: window {{SCREEN_WIDTH, SCREEN_HEIGHT, 32}, "Flume Tiled Map Editor", sf::Style::Close}
	, map {"nothing"}
	, hoverRect {{32, 32}}
	, snapSize {TILE_SIZE}
	{
		auto box1 = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 0.0f);
		auto box2 = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 0.0f);
		auto tools = sfg::Window::Create();
		auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 10.0f);
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
		auto btn_hide_layer = sfg::Button::Create("hide");
		auto button_layer_delete = sfg::Button::Create("delete");
		auto infoframe = sfg::Frame::Create("info");
		auto scrolledwindow = sfg::ScrolledWindow::Create();
		auto tilesettab = sfg::Notebook::Create();
		auto listBox = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
		auto directoryListing = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);

		window.setFramerateLimit(60);
		window.setPosition(sf::Vector2i(0, 0));
		hoverRect.setFillColor(sf::Color(112,146,190));
		tools->SetStyle(tools->GetStyle() ^ sfg::Window::TITLEBAR);
		scrolledwindow->SetScrollbarPolicy(sfg::ScrolledWindow::HORIZONTAL_NEVER | sfg::ScrolledWindow::VERTICAL_AUTOMATIC);
		tilesettab->AppendPage(sfg::Label::Create(), sfg::Label::Create("   Tileset   "));
		tilesettab->AppendPage(sfg::Label::Create(), sfg::Label::Create("   Properties   "));
		tilesettab->AppendPage(directoryListing, sfg::Label::Create("   Directory   "));
		tilesettab->SetRequisition(sf::Vector2f(170.f, 500.f));
		scrolledwindow->SetRequisition(sf::Vector2f(170.f, 200.f));
		tools->SetTitle("Tool window");
		tools->SetRequisition(sf::Vector2f(300.f, 0.f));

		std::string frameText = "This is the alpha version of Flume. Use the buttons above to create a new layer and save your work. Flume is still a work in progress, so report any bug you can find on the original repository. There is no open file dialogue yet, in order to load a map you'll have to click on the Directory tab and select one.";
		
		auto infotext = sfg::Label::Create(frameText);
		infotext->SetLineWrap(true);
		infoframe->Add(infotext);

		listBox->Pack(sfg::Label::Create("test"), true, true);
		scrolledwindow->Add(listBox);

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
		button_row2->Pack(button_layer_down, true);
		button_row2->Pack(btn_hide_layer, true);
		button_row2->Pack(button_layer_delete, true);

		box1->Pack(button_row);
		box1->Pack(button3, true);
		box1->Pack(button_row2);
		box1->Pack(scrolledwindow);

		box2->Pack(tilesettab);

		box->Pack(box1);
		box->Pack(box2);
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
	void Application::run()
	{
		// Some variables for a fixed timestep
		sf::Clock clock {};
		sf::Time lastUpdateTime {sf::Time::Zero};
		const sf::Time frameTime = sf::seconds(1.f / 60.f);

		window.resetGLStates();

		while (window.isOpen())
		{
			lastUpdateTime += clock.restart();

			while(lastUpdateTime > frameTime)
			{
				lastUpdateTime -= frameTime;

				handleEvents();
				update(frameTime);
			}

			render();
		}
	}

/* ----------------------------------------------------------------------
* Author: Julian
* Date: 13th August 2014
* Description: Updates the application.
* ----------------------------------------------------------------------
*/
	void Application::update(const sf::Time& elapsedTime)
	{
		sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
		mousePos.x = static_cast<float>(mousePos.x - fmod(mousePos.x, snapSize));
		mousePos.y = static_cast<float>(mousePos.y - fmod(mousePos.y, snapSize));
		hoverRect.setPosition(mousePos);

		desktop.Update(elapsedTime.asSeconds());
	}

/* ----------------------------------------------------------------------
* Author: Julian
* Date: 13th August 2014
* Description: Renders everything on screen.
* ----------------------------------------------------------------------
*/
	void Application::render()
	{
		window.clear(sf::Color(25, 25, 25));

		window.draw(map.getMapGrid());
		window.draw(hoverRect);
		sfgui.Display(window);

		window.display();
	}

/* ----------------------------------------------------------------------
* Author: Julian
* Date: 13th August 2014
* Description: Handles all window events.
* ----------------------------------------------------------------------
*/
	void Application::handleEvents()
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			desktop.HandleEvent(event);

			if(event.type == sf::Event::Closed)
				window.close();

			else if(event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}
	}