#include <stdio.h>
#include "md5.c"

int main(int argc, char *argv[]) {
	uint8_t result[16];
	md5_string(argv[1], result);
	print_hash(result);
	return 0;
}
