#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const char symbols[] = "qwertyuiopasdfghjklzxcvbnm"
						"QWERTYUIOPASDFGHJKLZXCVBNM"
						"1234567890"
						"-_";

void usage(const char *msg)
{
	fprintf(stderr, "Usage: %s <num_of_characters>\n", msg);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	size_t num_of_symbols = sizeof(symbols) - 1;

	if (argc != 2) usage(argv[0]);

	int length = atoi(argv[1]);

	if (length == 0) usage(argv[0]);

	for (int i = 0; i < length; ++i) {
		uint32_t x = arc4random_uniform(num_of_symbols);
		putchar(symbols[x]);
	}

	putchar('\n');
	return 0;
}
