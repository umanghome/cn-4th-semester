#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define MAX 20

int exp2 (int x)
{
	int i, ret = 1;
	for (i = 0; i < x; i++)
		ret *= 2;
	return ret;
}

void main()
{
	char input[MAX], cw[MAX * 2];
	int parPos[MAX], input_l, errCtr = 0, i, j, temp, tempCtr, temp2, parCtr = 0, m, r;
	clrscr();
	printf("Enter the input data: ");
	gets(input);
	input_l = strlen(input);
	for (i = 0; i < MAX * 2; i++)
		cw[i] = '_';
	m = 1;
	r = 1;
	while (m != input_l + 1)
	{
		if ((int) exp2(r) >= (m + r + 1))
		{
			cw[m + r - 1] = input[input_l - m];
			m++;
		}
		else
		{
			parCtr++;
			r++;
		}
	}
	parCtr++;
	for(i = (input_l + parCtr); i < MAX * 2; i++)
		cw[i] = '\0';
	for (i = 0, j = 0; i < (input_l + parCtr); i++)
	{
		if (cw[i] != '0' && cw[i] != '1')
		{
			cw[i] = '_';
			parPos[j] = i + 1;
			j++;
		}
	}
	strrev(cw);
	printf("Code word without parity: ");
	puts(cw);
	strrev(cw);
	for (i = 0; i < parCtr; i++)
	{
		tempCtr = 0;
		temp = 0;
		for (j = i; j < (input_l + parCtr); j++)
		{
			if (cw[j] == '1')
				temp += 1;
			tempCtr++;
			if (tempCtr == i + 1)
			{
				j += i + 1;
				tempCtr = 0;
			}
		}
		if (temp % 2 == 0)
			cw[parPos[i] - 1] = '0';
		else
			cw[parPos[i] - 1] = '1';
	}
	printf("The final code word: ");
	strrev(cw);
	puts(cw);
	strrev(cw);
	printf("Enter the position to change: ");
	scanf("%d", &temp);
	if (cw[temp - 1] == '0')
		cw[temp - 1] = '1';
	else
		cw[temp - 1] = '0';
	strrev(cw);
	printf("The data word with error is: ");
	puts(cw);
	strrev(cw);
	for (i = 0; i < parCtr; i++)
	{
		tempCtr = 0;
		temp = 0;
		for (j = parPos[i] - 1; j < (input_l + parCtr); j++)
		{
			if (cw[j] == '1')
				temp += 1;
			tempCtr++;
			if (tempCtr == parPos[i])
			{
				j += parPos[i];
				tempCtr = 0;
			}
		}
		if (temp % 2 == 1)
			errCtr += parPos[i];
	}
	printf("Found error at position %d.\n", errCtr);
	if (cw[errCtr - 1] == '0')
		cw[errCtr - 1] = '1';
	else
		cw[errCtr - 1] = '0';
	strrev(cw);
	printf("The corrected code word is: ");
	puts(cw);
	getch();
}