//
// Created by JAD on 17/10/2025.
//

#include "Sprite.h"

Sprite *createSprite(char symbols[SPRITE_SIZE][SPRITE_SIZE]) {
	Sprite *sprite = malloc(sizeof(Sprite));
	for (int row = 0; row < SPRITE_SIZE; row++) {
		for (int column = 0; column < SPRITE_SIZE; column++) {
			sprite->symbols[row][column] = symbols[row][column];
		}
	}
	return sprite;
}

void destroySprite(Sprite *sprite) {
	if (sprite == NULL) return;
	free(sprite);
}
