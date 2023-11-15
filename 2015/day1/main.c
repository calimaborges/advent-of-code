#include <stdio.h>

#define UP '('
#define DOWN ')'

int main() {
	int current_floor = 0;
	for (char c = getchar(); c != EOF; c = getchar()) {
		if (c == UP) {
			current_floor++;
		} else if (c == DOWN) {
			current_floor--;
		}
	}

	printf("%d\n", current_floor);
	return 0;
}
