#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 20

// it contains at least 3 vowels
// contains at least one letter that appears twice in a row
// it does not contain 'ab', 'cd, 'pq', 'xy'

int contains_any(char* input, char* sequence[2], int sequence_size) {
	for (unsigned int i = 0; i < sequence_size; ++i) {
		if (strstr(input, sequence[i]) != NULL) {
			return 1;
		}
	}
	return 0;
}

int count_chars(char* input, char char_array[], int char_array_size) {
	int counter = 0;
	for (unsigned int i = 0; input[i] != '\0' || i > MAX_INPUT; ++i) {
		for (unsigned int j = 0; j < char_array_size; ++j) {
			if (input[i] == char_array[j]) {
				counter++;
			}
		}
	}
	return counter;
}

int contains_duplicate(char *input) {
	char last_char = input[0];
	for (unsigned int i = 1; input[i] != '\0' || i > MAX_INPUT; ++i) {
		if (input[i] == last_char) {
			return 1;
		}
		last_char = input[i];
	}
	return 0;
}


int is_nice_string(char* input) {
	char* forbidden[] = { "ab", "cd", "pq", "xy" };
	size_t forbidden_size = sizeof(forbidden) / sizeof(char*);
	if (contains_any(input, forbidden, forbidden_size)) {
		return 0;
	}
	char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
	size_t vowels_size = sizeof(vowels) / sizeof(char);
	if (count_chars(input, vowels, vowels_size) < 3) {
		return 0;
	}

	if (!contains_duplicate(input)) {
		return 0;
	}
	return 1;
}


int main() { 
	char input[MAX_INPUT];
	int counter = 0;
	while (scanf("%19s", input) != EOF) {
		int check = is_nice_string(input);
		printf("%s %d\n", input, check);
		if (check) {
			counter++;
		}
	}

	// printf("test: ugknbfddgicrmopn %d\n", is_nice_string("ugknbfddgicrmopn"));
	// printf("test: aaa %d\n", is_nice_string("aaa"));
	// printf("test: jchzalrnumimnmhp %d\n", is_nice_string("jchzalrnumimnmhp"));
	// printf("test: haegwjzuvuyypxyu %d\n", is_nice_string("haegwjzuvuyypxyu"));
	// printf("test: dvszwmarrgswjxmb %d\n", is_nice_string("dvszwmarrgswjxmb"));
	printf("count: %d\n", counter);
	return 0;
}
