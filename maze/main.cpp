#include <SFML/Graphics.hpp>
#include "MapHandler.h"

using namespace sf;

int main() {
	RenderWindow window(VideoMode(1000, 1000), "Maze");
	MapHandler mp;

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		window.clear();
		mp.renderMap(window);
		window.display();
	}

	return 0;
}