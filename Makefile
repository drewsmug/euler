FILES = largest_prime_factor fibonacci palindrome_product

palindrome_product: palindrome_product.c
	gcc palindrome_product.c -o palindrome_product

fibonacci: fibonacci.c
	gcc fibonacci.c -o fibonacci

prime: largest_prime_factor.c
	gcc largest_prime_factor.c -o largest_prime_factor

clean:
	rm -f $(FILES)
