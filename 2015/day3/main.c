#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 256

typedef struct {
	int x,y;
} Point;

void print_matrix(int matrix[MAX_SIZE][MAX_SIZE]) {
	for (int x = 0; x < MAX_SIZE; ++x) {
		for (int y = 0; y < MAX_SIZE; y++) {
			printf("%d", matrix[x][y]);
		}
		printf("\n");
	}
}

Point next_position(Point point, char c) {
	switch(c) {
		case '^': return (Point) { .x = point.x, .y = point.y + 1 };	
		case 'v': return (Point) { .x = point.x, .y = point.y - 1 };	
		case '>': return (Point) { .x = point.x + 1, .y = point.y };	
		case '<': return (Point) { .x = point.x - 1, .y = point.y };	
		default: return point;
	}
}

int count_positions(int positions[MAX_SIZE][MAX_SIZE]) {
	int counter = 0;
	for (int x = 0; x < MAX_SIZE; ++x) {
		for (int y = 0; y < MAX_SIZE; y++) {
			if (positions[x][y] > 0) counter++;
		}
	}
	return counter;
}

int main() { 
	int positions[MAX_SIZE][MAX_SIZE] = { 0, };
	Point current_point = { .x = MAX_SIZE / 2, .y = MAX_SIZE / 2 };
	char c;

	while ((c = getchar()) != EOF) {
		positions[current_point.x][current_point.y] += 1;
		current_point = next_position(current_point, c);	
	}

	printf("%d\n", count_positions(positions));
	return 0;
}
