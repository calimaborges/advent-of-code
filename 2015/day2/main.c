#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_DIMENSIONS 3

int main() {
	int total = 0;
	int length, width, height;
	while (scanf("%dx%dx%d", &length, &width, &height) == NUMBER_OF_DIMENSIONS) {
		int surface_area = 2 * length * width + 2 * width * height + 2 * height * length;
		int smallest_area = length * width;
		if (width * height < smallest_area) {
			smallest_area = width * height;
		} 

		if (height * length < smallest_area) {
			smallest_area = height * length;
		}

		total += (surface_area + smallest_area);
	}

	printf("total: %d\n", total);
	return 0;
}
