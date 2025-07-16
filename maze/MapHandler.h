#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class MapHandler
{
	public:
	int renderMap(RenderWindow& window) {
		const Color BLOCK_COLOR = Color::Green;
		const Vector2i BLOCK_SIZE = Vector2i(50, 50);
		const int BLOCK_SIDE_SIZE = 50;
		vector<vector<int>> map(20, vector<int>(20));

		map = generateMap();

		for (int x = 0; x < 20; x++) {
			for (int y = 0; y < 20; y++) {
				RectangleShape block = RectangleShape(Vector2f(BLOCK_SIZE));
				
				if (map[x][y] == 1) {
					block.setPosition(BLOCK_SIDE_SIZE * y, BLOCK_SIDE_SIZE * x);
					block.setFillColor(BLOCK_COLOR);

					window.draw(block);
				}
			}
		}

		return 0;
	}

private: 
	vector<vector<int>> generateMap() {
		vector<vector<int>> map(20, vector<int>(20));

		for (int x = 0; x < 20; x++) {
			for (int y = 0; y < 20; y++) {
				if (x == 0 || x == 19 || y == 0 || y == 19) {
					map[x][y] = 1;
				}
				else {
					map[x][y] = 0;
				}
			}
		}
		return map;
	}
};

