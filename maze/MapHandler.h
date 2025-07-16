#pragma once

#include <SFML/Graphics.hpp>

class MapHandler
{
public:
    int renderMap(sf::RenderWindow& window) {
        const sf::Color BLOCK_COLOR = sf::Color::Green;
        const sf::Vector2i BLOCK_SIZE = sf::Vector2i(50, 50);
        const int BLOCK_SIDE_SIZE = 50;
        int map[20][20];

        //  опируем данные из generateMap
        for (int x = 0; x < 20; x++) {
            for (int y = 0; y < 20; y++) {
                map[x][y] = generateMap()[x][y];
            }
        }

        for (int x = 0; x < 20; x++) {
            for (int y = 0; y < 20; y++) {
                sf::RectangleShape block = sf::RectangleShape(sf::Vector2f(BLOCK_SIZE));

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
    int(*generateMap())[20] {  // ¬озвращает указатель на массив из 20 int'ов
        static int map[20][20]; // static чтобы массив не уничтожалс€ после выхода
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