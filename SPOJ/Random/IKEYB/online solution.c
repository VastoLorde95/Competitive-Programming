/* ACM International Collegiate Programming Contest
   Central European Regional Contest 2000
   
   Problem I - I-Keyboard
   Michal Sevcenko
*/
         
#include <stdio.h>

#define MAX_CHARS 100
#define MAX_BUTTONS 100

/* penalty for single character */
int Counts[MAX_CHARS];

/* Dynamic programming buffer, holding minimum penalties for different
 *	button configurations
 *            +-- no. of buttons allocated from the left - 1
 *            |          +-- no. of characters in allocated buttons - 1
 *            v          v  */
int Buffer[MAX_BUTTONS][MAX_CHARS]; /*  <-- mininum sum of penalties for
				     *      allocated buttons
				     */

/* This buffer will be used for reconstruction of the result (widths
 * of buttons)
 *            +-- no. of buttons allocated from the left - 1
 *            |          +-- no. of characters in allocated buttons - 1
 *            v          v   */
int Widths[MAX_BUTTONS][MAX_CHARS];/*  <-- optimal no. of characters
				    *      excluding the last allocated
				    *      button
				    */

/* Array of precomputed penalties for one button with given character
 *	offset and no. of characters
 *            +-- first character in a button
 *            |          +-- length of a button - 1
 *            v          v   */
int Penalties[MAX_CHARS][MAX_CHARS]; /* <-- penalty */

char CharacterNames[MAX_CHARS];
char ButtonNames[MAX_CHARS];


/* initialize array of precomputed penalties */
void PrecomputePenalties(int chars, int buttons)
{
	int i, j;
	for (i=0; i<chars; i++)
		for (j=0; j<chars-buttons+1; j++)
			Penalties[i][j] = 0;

	for (i=0; i<chars; i++)
	{
		Penalties[i][0] = Counts[i];
		for (j=2; j<=chars-buttons+1; j++)
			Penalties[i][j-1] = Penalties[i][j-2] + j * Counts[i+j-1];
	}
/*	printf("penalties:\n");
	for (i=0; i<chars; i++)
	{
		for (j=0; j<chars-buttons+1; j++)
			printf("%3i ", Penalties[i][j]);
		printf("\n");
	}*/
}

void PrintWidths(int row, int column)
{
	if (row > 0)
	{
		int i;
		PrintWidths(row-1, Widths[row][column]);
		printf("%c: ", ButtonNames[row]);
		for (i=Widths[row][column]+1; i<column+1; i++)
			printf("%c", CharacterNames[i]);
		printf("\n");
	}
	else
	{
		int i;
		printf("%c: ", ButtonNames[0]);
		for (i=0; i<column+1; i++)
			printf("%c", CharacterNames[i]);
		printf("\n");
	}
}

/* solve one instance of the problem */
void DoIt()
{
	int i, j, k;
	int buttons, chars;

	scanf("%i %i\n", &buttons, &chars);
	gets(ButtonNames);
	gets(CharacterNames);

	for (i=0; i<chars; i++)
		scanf("%i", Counts+i);

	PrecomputePenalties(chars, buttons);

	/* prepare bottom layer (one allocated button, different no.
		of characters in it) */
	for (i=0; i<chars - buttons + 1; i++)
		Buffer[0][i] = Penalties[0][i];

	/* "i+1" is no. of buttons allocated, "j+1" is no. of characters on
		allocated buttons */
	for (i=1; i<buttons; i++)
	{
		/* optimal configurations with i buttons are computed at
			this point */

		/* try all possible no. of characters for configurations with
			i+1 buttons */
		for (j=i; j<chars - buttons + i + 1; j++)
		{
			Buffer[i][j] = 2000000000;
			for (k=i-1; k<j; k++)
			{
				int p = Buffer[i-1][k] + Penalties[k+1][j-k-1];
				if (Buffer[i][j] > p)
				{
					Buffer[i][j] = p;
					Widths[i][j] = k;
				}
			}
		}
	}
/*	printf("Buffer:\n");
	for (i=0; i<buttons; i++)
	{
		for (j=0; j<chars; j++)
			printf("%3i ", Buffer[i][j]);
		printf("\n");
	}
	printf("Widths:\n");
	for (i=0; i<buttons; i++)
	{
		for (j=0; j<chars; j++)
			printf("%3i ", Widths[i][j]);
		printf("\n");
	}
	printf("minimum penalty is %i\n", Buffer[buttons-1][chars-1]);*/
	PrintWidths(buttons-1, chars-1);
	printf("\n");
}

int main()
{
	int i, n;

	scanf("%i", &n);
	for (i=0; i<n; i++)
	{
		printf("Keypad #%i:\n", i+1);
		DoIt();
	}

	return 0;
}
