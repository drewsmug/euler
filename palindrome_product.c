#include <stdio.h>
#include <stdlib.h>

#define MAX 999

/*
* A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
* Find the largest palindrome made from the product of two 3-digit numbers.
*/

void add_to_list(int num);

typedef struct Number Number;
int is_palindrome(int num);

struct Number {
	int num;
	Number *next;
};
	
Number *palindromes;

int main()
{

	int numA;
	int numB;
	int total = 0;

	for(numA = MAX; numA > 0; numA--) {
		for(numB = MAX; numB > 0; numB--) {
			total++;
			add_to_list(numA * numB);
		}
	}

	Number *curr = palindromes;
	int maximum = 0;
	while(curr) {
		if(curr->num > maximum)
			maximum = curr->num;

		curr = curr->next;
	}

	printf("Largest palindrome is: %d\n",maximum);

	return 1;
}

void add_to_list(int num)
{
	if(!is_palindrome(num))
		return;

	Number *curr = palindromes;

	/* add head */
	if(!curr) {
		Number *first_number = malloc(sizeof(Number));
		if(!first_number) {
			printf("Not enough memory");
		}

		first_number->num = num;
		first_number->next = NULL;

		palindromes = first_number;
		return;
	}

	/* see if product already exist */
	int found = 0;
	while(curr) {
		if(curr->num == num) {
			found = 1;
			break;
		}

		if(curr->next == NULL)
			break;

		curr = curr->next;
	}

	/* add palidrome */
	if(!found) {
		Number *new_number = malloc(sizeof(Number));
		if(!new_number) {
			printf("Not enough memory");
		}

		new_number->num = num;
		new_number->next = NULL;

		curr->next = new_number;
	}
}

int is_palindrome(int num)
{
	char string[6];
	char *str = string;
	int length = 0;

	sprintf(string, "%d", num);

	/* get length */
	while(*str != '\0') {
		length++;
		str++;
	}

	if(length == 1)
		return 1;

	int i, j;
	for(i = 0, j = (length - 1); i < (length / 2); i++, j--) {
		if(string[i] != string[j]) {
			return 0;
		}
	}

	return 1;
}
