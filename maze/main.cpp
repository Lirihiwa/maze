#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
	Window window(VideoMode(800, 600), "My window");

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
	}
}