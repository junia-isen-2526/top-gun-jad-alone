#include <stdlib.h>
#include "Sky.h"

int main(void) {
	Sky *sky = createSky(20, 100);
	displaySky(sky);
	destroySky(sky);
	system("Pause");
	return 0;
}
