#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 20
int binadd(char *a1, char *a2, char *a3, int size);
void main()
{
	char input[MAX], add1[MAX], add2[MAX], add3[MAX], addT[MAX], addT2[MAX], add_ans[MAX];
	int carry = 0, i, j, input_l;
	clrscr();
	printf("Enter the data (size should be even): ");
	gets(input);
	input_l = strlen(input);
	for (i = 0; i < (input_l / 2); i++)
		add1[i] = input[i];
	add1[i] = '\0';
	for (i = (input_l / 2), j = 0; i < input_l; i++, j++)
		add2[j] = input[i];
	add2[j] = '\0';
	if (binadd(add1, add2, add_ans, (input_l / 2)) == 1)
	{
		addT[(input_l / 2) - 1] = '1';
		for (i = 0; i < (input_l / 2) - 1; i++)
			addT[i] = '0';
		addT[(input_l / 2)] = '\0';
		carry = binadd(add_ans, addT, addT2, (input_l / 2));
		strcpy(add_ans, addT2);
	}
	for (i = 0; i < (input_l / 2); i++)
	{
		if (add_ans[i] == '1')
			add_ans[i] = '0';
		else
			add_ans[i] = '1';
	}
	strcat(input, add_ans);
	printf("Sent data: ");
	puts(input);
	for (i = input_l, j = 0; i < strlen(input); i++, j++)
		add3[j] = input[i];
	add3[j] = '\0';
	if (binadd(add1, add2, addT, (input_l / 2)) == 1)
	{
		addT2[(input_l / 2) - 1] = '1';
		for (i = 0; i < (input_l / 2) - 1; i++)
			addT2[i] = '0';
		addT2[(input_l / 2)] = '\0';
		carry = binadd(addT, addT2, add_ans, (input_l / 2));
		strcpy(addT, add_ans);
	}
	if (binadd(addT, add3, addT2, (input_l / 2)) == 1)
	{
		add_ans[(input_l / 2) - 1] = '1';
		for (i = 0; i < (input_l / 2) - 1; i++)
			add_ans[i] = '0';
		add_ans[(input_l / 2)] = '\0';
		carry = binadd(add_ans, addT2, addT, (input_l / 2));
		strcpy(addT2, addT);
	}
	for (i = 0; i < (input_l / 2); i++)
	{
		if (addT2[i] == '1')
			addT2[i] = '0';
		else
			addT2[i] = '1';
	}
	printf("1's complement of the sum is: ");
	puts(addT2);
	for (i = 0; i < (input_l / 2); i++)
		addT[i] = '0';
	addT[i] = '\0';
	if (strcmp(addT, addT2) == 0)
		printf("The data was received correctly!");
	else
		printf("The data has some error.");
	getch();
}
int binadd (char *a1, char *a2, char *a3, int size)
{
	int i, carry = 0;
	for (i = 0; i < size; i++)
		a3[i] = '0';
	for (i = (size - 1); i >= 0; i--)
	{
		if (a1[i] == '0' && a2[i] == '0')
		{
			if (carry == 1)
				a3[i] = '1';
			else
				a3[i] = '0';
			carry = 0;
		}
		else if ((a1[i] == '0' && a2[i] == '1') || (a1[i] == '1' && a2[i] == '0'))
		{
			if (carry == 1)
			{
				a3[i] = '0';
				carry = 1;
			}
			else
			{
				a3[i] = '1';
				carry = 0;
			}
		}
		else if (a1[i] == '1' && a2[i] == '1')
		{
			if (carry == 1)
				a3[i] = '1';
			else
				a3[i] = '0';
			carry = 1;
		}
	}
	a3[size] = '\0';
	return carry;
}