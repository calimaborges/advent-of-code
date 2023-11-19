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
	int counter = 0;
	int positions[MAX_SIZE][MAX_SIZE] = { 0, };
	Point position_santa = { .x = MAX_SIZE / 2, .y = MAX_SIZE / 2 };
	Point position_robot = { .x = MAX_SIZE / 2, .y = MAX_SIZE / 2 };
	char c;

	while ((c = getchar()) != EOF) {
		if (counter % 2 == 0) {
			position_santa = next_position(position_santa, c);
			positions[position_santa.x][position_santa.y] += 1;
		} else {
			position_robot = next_position(position_robot, c);
			positions[position_robot.x][position_robot.y] += 1;
		}
		counter++;
	}

	printf("%d\n", count_positions(positions));
	return 0;
}
