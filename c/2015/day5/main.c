#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_INPUT 20

bool contains_non_overlapping_pair_of_any_two_letters(char *input) {
	int len = strnlen(input, MAX_INPUT);
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 2; j < len - 1; j++) {
			if (input[i] == input[j] && input[i + 1] == input[j + 1]) {
				return true;
			}
		}
	}
	return false;
}

bool repeats_with_letter_in_between(char *input) {
	int len = strnlen(input, MAX_INPUT);
	for(unsigned int i = 2; i < len; ++i) {
		if (input[i - 2] == input[i]) {
			return true;
		}
	}
	return false;
}


bool is_nice_string(char* input) {
	if (!contains_non_overlapping_pair_of_any_two_letters(input)) {
		printf("%s failed pair check\n", input);
		return false;
	}
	if (!repeats_with_letter_in_between(input)) {
		printf("%s failed repeat check\n", input);
		return false;
	}
	printf("%s success\n", input);
	return true;
}


int main() { 
	char input[MAX_INPUT];
	int counter = 0;
	while (scanf("%19s", input) != EOF) {
		if (is_nice_string(input)) {
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
