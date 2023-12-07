#include <stdio.h>
#include <stdlib.h>
#include "../shared/md5.c"

#define MAX_LENGTH 100

int starts_with_zeroes(uint8_t result[16], int amount_of_zeroes) {
	int total = 0x00;
	for (unsigned int i = 0; i < amount_of_zeroes / 2; ++i) {
		total |= result[i];
	}
	if (amount_of_zeroes % 2 != 0) {
		total |= (result[amount_of_zeroes / 2] >> 4);
		
	}
	return total == 0;
}

int main() { 
	char input[20];
	scanf("%19s", input);
	printf("%s\n", input);

	uint8_t result[16];
	char updated_input[MAX_LENGTH];
	snprintf(updated_input, MAX_LENGTH, "%s", input);
	for (unsigned int i = 0;;++i) {
		printf("%s ", updated_input);
		md5_string(updated_input, result);
		print_hash(result);
		if (starts_with_zeroes(result, 5)) {
			printf("found the number is: %d\n", i - 1);
			break;
		}
		snprintf(updated_input, MAX_LENGTH, "%s%d", input, i);
	}
	return 0;
}
