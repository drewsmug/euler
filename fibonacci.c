// What is the first term in the Fibonacci sequence to contain 1000 digits?

#include <stdio.h>
#include <stdlib.h>

#define DIGITS 1000

void add_digits(int tailA[], int tailB[]);

int term = 2;
int overflow = 0;

int main()
{
	int tailA[DIGITS], tailB[DIGITS];

	int c;
	for(c = 0; c < DIGITS; c++) {
		tailA[c] = 0;
		tailB[c] = 0;
	}

	tailA[0] = tailB[0] =  1;

	while(1) {
		term++;
		add_digits(tailA, tailB);
		if(overflow)
			break;
		term++;
		add_digits(tailB, tailA);
		if(overflow)
			break;
	}

	printf("term = %d\n", term);
	return 1;
}

/* A is the bigger one going in to add_digits and should be unchanged */
/* B is the smaller one to be over written */
void add_digits(int tailA[], int tailB[])
{
	int sum = 0;
	int c;

	for(c = 0; c < DIGITS; c++) {
		sum += tailA[c] + tailB[c];
		tailB[c] = sum % 10;
		sum -= tailB[c];
		sum /= 10;
	}

	if(sum || (tailB[DIGITS - 1]))
		overflow = 1;
}
