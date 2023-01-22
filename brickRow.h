#pragma once
#include "settings.h"
#include "brick.h"
#include "SFML/Graphics.hpp"
#include "func.h"
#include "bat.h"

struct BrickRow {
	Brick arr[20];
	int size;
};

void brick_row_init(BrickRow& brickrow, int size, sf::Vector2f position, float stepX) {
	brickrow.size = size;
	for (int i = 0; i < brickrow.size; i++) {
		sf::Color color{ (sf::Uint8)(rand() % 256),(sf::Uint8)(rand() % 256) ,(sf::Uint8)(rand() % 256) };
		sf::Vector2f brick_pos{ position.x + i * stepX,position.y };
		brick_init(brickrow.arr[i], color, brick_pos);
	}
}



void brick_row_draw(sf::RenderWindow& window, const BrickRow& brickrow) {
	for (int i = 0; i < brickrow.size; i++) {
		brick_draw(brickrow.arr[i],window);
	}
}