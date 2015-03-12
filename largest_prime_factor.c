// What is the largest prime factor of the number 600851475143 ?

#include <stdio.h>

#define NUMBER 600851475143UL
//#define NUMBER   13195UL
#define ULONG unsigned long

int is_prime(ULONG number);
int is_factor(ULONG factor, ULONG product);

void main() {
	ULONG i = NUMBER / 2;
	ULONG half = NUMBER / 2;
	if(i % 2 == 0)
		i++;

	for(i = 1; i < half; i += 2)
	{
		//printf("number: %lu\n",i);
		if(is_factor(i, NUMBER))
		{
			printf("factor number: %lu\n",i);
			if(is_prime(i))
			{
				printf("\tprime number: %lu\n",i);
				//break;
			}
		}
	}

	printf("largest prime factor=%lu\n",i);
}

int is_prime(ULONG number)
{
	ULONG c = number / 2;
	if(c % 2 == 0)
		c++;

	for(c; c > 1; c -= 2)
	{
		if(is_factor(c, number))
			return 0; /* is not a prime */
	}

	return 1; /* is a prime */
}

int is_factor(ULONG factor, ULONG product)
{
	ULONG remainder = product % factor;

	if(remainder == 0)
		return 1; /* is a factor */
	else
		return 0; /* is not a factor */
}
