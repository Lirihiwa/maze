#pragma once

#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>

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

		map = generateMap(Vector2i(8, 10));

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
	vector<vector<int>> generateMap(Vector2i startPos) {
		vector<vector<int>> map(20, vector<int>(20));

		map[startPos.x][startPos.y] = 1;

		Vector2i direction = chooseDirection();

		return map;
	}

	Vector2i chooseDirection() {
		srand(time(0));

		vector<Vector2i> directions = {
			Vector2i(0, 1),
			Vector2i(0, -1),
			Vector2i(1, 0),
			Vector2i(-1, 0),
		};

		return directions[rand() % 4];
	}
};

