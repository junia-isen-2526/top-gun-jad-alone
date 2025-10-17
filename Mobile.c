//
// Created by JAD on 17/10/2025.
//

#include "Mobile.h"

Mobile *createMobile(int x, int y, Direction direction, Sprite *sprite, int maxHeight, int maxWidth) {
	Mobile *mobile = malloc(sizeof(Mobile));
	mobile->x = x;
	mobile->y = y;
	mobile->direction = direction;
	mobile->sprite = sprite;
	mobile->maxHeight = maxHeight;
	mobile->maxWidth = maxWidth;
	return mobile;
}
void destroyMobile(Mobile *mobile) {
	if (mobile == NULL) return;
	destroySprite(mobile->sprite);
	free(mobile);
}

int getMobileX(Mobile *mobile) {
	return mobile == NULL ? 0 : mobile->x;
}

int getMobileY(Mobile *mobile) {
	return mobile == NULL ? 0 : mobile->y;
}

Direction getDirection(Mobile *mobile) {
	return mobile == NULL ? NORTH : mobile->direction;
}

void turnMobileLeft(Mobile *mobile) {
	if (mobile == NULL) return;
	mobile->direction = (mobile->direction + 3) % 4;
}

void turnMobileRight(Mobile *mobile) {
	if (mobile == NULL) return;
	mobile->direction = (mobile->direction + 5) % 4;
}

Sprite *getMobileSprite(Mobile *mobile) {
	return mobile == NULL ? 0 : mobile->sprite;
}

void moveMobileForward(Mobile *mobile) {
	if (mobile == NULL) return;
	switch (mobile->direction) {
		case NORTH: mobile->y = (mobile->y + 1) % mobile->maxHeight;
			break;
		case EAST: mobile->x = (mobile->x + 1) % mobile->maxWidth;
			break;
		case SOUTH: mobile->y = (mobile->y - 1 + mobile->maxHeight) % mobile->maxHeight;
			break;
		case WEST: mobile->x = (mobile->x - 1 + mobile->maxWidth) % mobile->maxWidth;
			break;
		default: break;
	}
}

Mobile *createPLane(int x, int y, Direction direction, int maxHeight, int maxWidth) {
	char planeSymbols[5][5] = {{' ', ' ', '*', ' ', ' '},
							   {'*', ' ', ' ', '*', ' '},
							   {'*', '*', '*', '*', '*'},
							   {' ', ' ', ' ', '*', ' '},
							   {' ', ' ', '*', ' ', ' '}};
	Sprite *planeSprite = createSprite(planeSymbols);
	return createMobile(x, y, direction, planeSprite, maxHeight, maxWidth);
}
