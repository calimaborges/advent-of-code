#include <stdio.h>
#include <stdlib.h>

#define UP '('
#define DOWN ')'
#define BASEMENT -1

int main() {
	int current_position = 1;
	int current_floor = 0;
	for (char c = getchar(); c != EOF; c = getchar(), current_position++) {
		if (c == UP) {
			current_floor++;
		} else if (c == DOWN) {
			current_floor--;
		}

		if (current_floor == BASEMENT) {
			break;
		}
	}

	printf("current floor: %d\n", current_floor);
	printf("current position: %d\n", current_position);
	return 0;
}
