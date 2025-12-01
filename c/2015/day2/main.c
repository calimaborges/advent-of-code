#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_DIMENSIONS 3

typedef struct {
	int length, width, height;
} Dimension;

int calculate_surface_area(Dimension dimension) {
	return 2 * dimension.length * dimension.width  +
               2 * dimension.width  * dimension.height +
	       2 * dimension.height * dimension.length;
}

int calculate_smallest_area(Dimension dimension) {
	int smallest_area = dimension.length * dimension.width;
	if (dimension.width * dimension.height < smallest_area) {
		smallest_area = dimension.width * dimension.height;
	}

	if (dimension.height * dimension.length < smallest_area) {
		smallest_area = dimension.height * dimension.length;
	}

	return smallest_area;
}

int calculate_smallest_distance(Dimension dimension) {
	int smallest_distance = dimension.length + dimension.width;
	if (dimension.width + dimension.height < smallest_distance) {
		smallest_distance = dimension.width + dimension.height;
	}

	if (dimension.height + dimension.length < smallest_distance) {
		smallest_distance = dimension.height + dimension.length;
	}
	return smallest_distance;
}

int main() {
	int total_paper = 0;
	int total_ribbon = 0;

	Dimension dimension;
	while (scanf("%dx%dx%d", &(dimension.length), &(dimension.width), &(dimension.height)) == NUMBER_OF_DIMENSIONS) {
		int surface_area = calculate_surface_area(dimension);
		int smallest_area = calculate_smallest_area(dimension);
		total_paper += (surface_area + smallest_area);

		int smallest_distance = calculate_smallest_distance(dimension);	
		total_ribbon += ((smallest_distance * 2) + (dimension.length * dimension.width * dimension.height));
	}

	printf("papers: %d\n", total_paper);
	printf("ribbons: %d\n", total_ribbon);
	return 0;
}
