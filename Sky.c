//
// Created by JAD on 17/10/2025.
//

#include "Sky.h"

Sky *createSky(int height, int width) {
	Sky *sky = malloc(sizeof(Sky));
	sky->height = height;
	sky->width = width;
	return sky;
}

void destroySky(Sky *sky) {
	if (sky == NULL) return;
	free(sky);
}

void displaySky(Sky *sky) {
	for (int row = 0; row < sky->height; row++) {
		for (int column = 0; column < sky->width; column++) {
			printf("%c", EMPTY_SKY_TILE);
		}
		printf("\n");
	}
}

int getSkyHeight(Sky *sky) {
	return sky == NULL ? 0 : sky->height;
}

int getSkyWidth(Sky *sky) {
	return sky == NULL ? 0 : sky->width;
}

void putMobileOnSky(Sky *sky, Mobile *mobile) {

}
