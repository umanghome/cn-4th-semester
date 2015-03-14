#include <stdio.h>
#include <string.h>
#include <conio.h>

#define MAX 20

char xor (char a, char b);

void main()
{
	char orig_dw[MAX], divisor[MAX], new_dw[MAX], zero_dw[MAX], rem[MAX], ans[MAX], to_divide[MAX], sent[MAX], tmpch1 = '\0';
	int div_length, orig_dw_length, new_dw_length, sent_length, i, j, recieved = 1;
	clrscr();
	printf("Enter data word: ");
	gets(orig_dw);
	printf("Enter divisor: ");
	gets(divisor);
	div_length = strlen(divisor);
	orig_dw_length = strlen(orig_dw);
	strcpy(new_dw, orig_dw);
	for (i = orig_dw_length; i < (orig_dw_length + div_length - 1); i++)
		new_dw[i] = '0';
	new_dw[i] = '\0';
	new_dw_length = strlen(new_dw);
	for (i = 0; i < div_length; i++)
		zero_dw[i] = '0';
	zero_dw[i] = '\0';
	for (i = 0; i < (new_dw_length - (div_length - 1)); i++)
	{
		if (i == 0)
		{
			for (j = 0; j < div_length; j++)
				rem[j] = new_dw[j];
			rem[j] = '\0';
		}
		tmpch1 = rem[0];
		if (tmpch1 == '1')
			strcpy(to_divide, divisor);
		else
			strcpy(to_divide, zero_dw);
		for (j = 0; j < div_length; j++)
			rem[j] = xor(rem[j], to_divide[j]);
		for (j = 0; j < (div_length - 1); j++)
			rem[j] = rem[j + 1];
		rem[j] = new_dw[i + j + 1];
		rem[j + 1] = '\0';
	}
	strcpy(sent, orig_dw);
	strcat(sent, rem);
	sent_length = strlen(sent);
	printf("The sent data is: ");
	puts(sent);
	for (i = 0; i < (sent_length - 3); i++)
	{
		if (i == 0)
		{
			for (j = 0; j < div_length; j++)
				rem[j] = sent[j];
			rem[j] = '\0';
		}
		tmpch1 = rem[0];
		if (tmpch1 == '1')
			strcpy(to_divide, divisor);
		else
			strcpy(to_divide, zero_dw);
		for (j = 0; j < div_length; j++)
			rem[j] = xor(rem[j], to_divide[j]);
		for (j = 0; j < (div_length - 1); j++)
			rem[j] = rem[j + 1];
		rem[j] = sent[i + j + 1];
		rem[j + 1] = '\0';
	}
	for (i = 0; i < (div_length - 1); i++)
	{
		if (rem[i] != '0')
			recieved = 0;
	}
	if (recieved == 1)
	{
		printf("Data received correctly!\n");
		printf("The recieved data is: ");
		for (i = 0; i < orig_dw_length; i++)
			printf("%c", sent[i]);
	}
	getch();
}

char xor (char a, char b)
{
	if (a == b)
		return '0';
	return '1';
}