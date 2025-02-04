#include <stdlib.h>

void	strdel(char **s)
{
	if (!s || !*s)
		return ;
	free(*s);
	*s = NULL;
}

void swap(char *x, char *y) {
	char t = *x; *x = *y; *y = t;
}

// function to reverse buffer[i..j]
char* reverse(char *buffer, int i, int j)
{
	while (i < j)
		swap(&buffer[i++], &buffer[j--]);

	return buffer;
}

// Iterative function to implement itoa() function in C
char* itoa(int value, char* buffer, int base)
{
	// invalid input
	if (base < 2 || base > 32)
		return buffer;

	// consider absolute value of number
	int n = abs(value);

	int i = 0;
	while (n)
	{
		int r = n % base;

		if (r >= 10) 
			buffer[i++] = 65 + (r - 10);
		else
			buffer[i++] = 48 + r;

		n = n / base;
	}

	// if number is 0
	if (i == 0)
		buffer[i++] = '0';

	// If base is 10 and value is negative, the resulting string 
	// is preceded with a minus sign (-)
	// With any other base, value is always considered unsigned
	if (value < 0 && base == 10)
		buffer[i++] = '-';

	buffer[i] = '\0'; // null terminate string

	// reverse the string and return it
	return reverse(buffer, 0, i - 1);
}

char	*argGenerator(char *typ)
{
	char	arg[100];

	arg[0] = 0;
	strcat(arg, "%");
	if (rand() % 2)
		strcat(arg, " ");
	if (rand() % 2)
		strcat(arg, "+");
	if (rand() % 2)
		strcat(arg, "-");
	if (rand() % 2)
		strcat(arg, "#");
	if (rand() % 2)
		strcat(arg, "0");
	if (rand() % 2)
		itoa(rand() % 100, arg + strlen(arg), 10);
	if (rand() % 2)
	{
		strcat(arg, ".");
		if (rand() % 2)
			itoa(rand() % 100, arg + strlen(arg), 10);
	}
	strcat(arg, typ);
	return (strdup(arg));
}

char	*stringGenerator(int i)
{
	char	*s;

	if (rand() % 20)
		return (NULL);
	if (!(s = malloc((i + 1) * sizeof(char))))
		return (NULL);
	while (i)
	{
		i--;
		s[i] = rand();
	}
	return (s);
}
