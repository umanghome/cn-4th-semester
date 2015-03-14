#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 20
void main()
{
	char input[MAX], output[MAX + 5], tempch = '\0';
	int input_length, output_length, i = 0, j = 0, counter = 0;
	clrscr();
	printf("Enter input data: ");
	gets(input);
	input_length = strlen(input);

	for (i = 0; i < input_length; i++)
	{
		output[j++] = input[i];
		if (input[i] == '1')
			counter++;
		else
			counter = 0;
		if (counter == 5)
		{
			output[j++] = '0';
			counter = 0;
		}
	}
	output[j] = '\0';
	printf("\nStuffed: ");
	puts(output);
	output_length = strlen(output);
	for (i = 0, j = 0; i < output_length; i++)
	{
		input[j++] = output[i];
		if (output[i] == '1')
			counter++;
		else
			counter = 0;
		if (counter == 5)
		{
			i++;
			counter = 0;
		}
	}
	input[j] = '\0';
	printf("\nUnstuffed: ");
	puts(input);
	getch();
}