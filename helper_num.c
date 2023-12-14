#include "shell.h"

/**
 * long_to_string - Convert a number to a string representation.
 * @number: The number to be converted into a string.
 * @string: Buffer to store the number as a string.
 * @base: The base to convert the number.
 *
 * This function converts a given number into its string representation
 * using the specified base and stores it in the provided string buffer.
 * It handles both positive and negative numbers.
 */
void long_to_string(long number, char *string, int base)
{
	int index = 0, inNegative = 0;
	long cociente = number;
	char letters[] = {"0123456789abcdef"};

	if (cociente == 0)
		string[index++] = '0';

	if (string[0] == '-')
		inNegative = 1;

	while (cociente)
	{
		if (cociente < 0)
			string[index++] = letters[-(cociente % base)];
		else
			string[index++] = letters[cociente % base];
		cociente /= base;
	}
	if (inNegative)
		string[index++] = '-';

	string[index] = '\0';
	str_reverse(string);
}

/**
 * _atoi - Convert a string to an integer.
 * @s: Pointer to the string source.
 * Return: The integer value of the string or 0.
 *
 * This function converts the provided string into an integer value.
 * It scans through the string to extract and convert the integer value.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int number = 0;
	/*1- analisys sign*/
	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		if (*s == '+')
			sign *= +1;
		s++;
	}

	/*2 - extract the number */
	while ('0' <= *s && *s <= '9' && *s != '\0')
	{

		number = (number * 10) + (*s - '0');
		s++;
	}
	return (number * sign);
}

/**
 * count_characters - Count the occurrences of a character in a string.
 * @string: Pointer to the string source.
 * @character: String containing characters to be counted.
 * Return: The count of occurrences of the character in the string.
 *
 * This function counts the number of occurrences of a specific character
 * within the given string and returns the count.
 */
int count_characters(char *string, char *character)
{
	int i = 0, counter = 0;

	for (; string[i]; i++)
	{
		if (string[i] == character[0])
			counter++;
	}
	return (counter);
}
