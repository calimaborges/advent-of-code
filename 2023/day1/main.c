#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


#define DOWN ')'
#define BASEMENT -1

int main() {
	char first_number = -1;
	char last_number = -1;
	int sum = 0;
	for (char c = getchar(); c != EOF; c = getchar()) {
		if (isdigit(c) && first_number == -1) {
			first_number = c;
		} 

		if (isdigit(c)) {
			last_number = c;
		} 

		if (c == '\n') {
			char str[3] = { first_number, last_number, '\0' }; 
			int number = atoi(str);
			printf("%d\n", number);
			sum += number;

			first_number = -1;
			last_number = -1;
		}
	}


	printf("sum: %d\n", sum);
	return 0;
}
