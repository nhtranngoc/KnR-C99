#include <stdio.h>

void printbits(size_t const size, void const * const ptr);
int invert(unsigned int x, int p, int n);

int main() {
	unsigned int b1 = 0b00111100;

	unsigned int b2 = invert(b1,5,4);

	printbits(1, &b2);

	return 0;
}

int invert(unsigned int x, int p, int n) {
	for(int i = 0; i < n; ++i) {
		x ^= 1UL << (p-i);
	}

	return x;
}


// Print binary, size is the number of bits
void printbits(size_t const size, void const * const ptr) {
	unsigned char *b = (unsigned char*) ptr;
	unsigned char byte;
	int i, j;

	for(i=size-1;i>=0;i--) {
		for(j=7;j>=0;j--) {
			byte = (b[i] >> j) & 1;
			if(j == 3) {
				printf(" ");
			}
			printf("%u", byte);
		}
	}
	puts("");
}