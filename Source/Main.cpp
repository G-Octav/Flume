#include <SFGUI/SFGUI.hpp>
#include <SFML/Graphics.hpp>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

class HelloWorld {
	public:
		void OnButtonClick();

		void Run();

	private:
		sfg::SFGUI m_sfgui;
		sfg::Label::Ptr m_label;
};

void HelloWorld::OnButtonClick() {
	m_label->SetText("Hello SFGUI, pleased to meet you!");
}

void HelloWorld::Run() {
	sf::RenderWindow render_window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Hello world!");

	m_label = sfg::Label::Create("Hello world!");

	auto button = sfg::Button::Create("Greet SFGUI!");
	button->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&HelloWorld::OnButtonClick, this));

	auto frame = sfg::Frame::Create("Info");
	auto lb1 = sfg::Label::Create("loremipsum lorem ipsum \nlorem ipsum lorem ipsum lorem ipsum lorem \nipsum lorem ipsum");

	frame->Add(lb1);

	auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);
	box->Pack(m_label);
	box->Pack(frame);
	box->Pack(button, false);

	box->SetRequisition(sf::Vector2f(100,100));

	auto window = sfg::Window::Create();
	window->SetTitle("Hello world!");
	window->Add(box);
	window->SetPosition(sf::Vector2f(render_window.getSize().x/2, render_window.getSize().y/2));

	sfg::Desktop desktop;
	desktop.Add(window);

	render_window.resetGLStates();

	sf::Event event;
	sf::Clock clock;

	while (render_window.isOpen()) {
		while (render_window.pollEvent(event)) {
			desktop.HandleEvent(event);

			if (event.type == sf::Event::Closed) {
				render_window.close();
			}
		}

		desktop.Update(clock.restart().asSeconds());

		// Rendering.
		render_window.clear();
		m_sfgui.Display(render_window);
		render_window.display();
	}
}

int main() 
{
	HelloWorld hello_world;
	hello_world.Run();

	return 0;
}
