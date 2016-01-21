/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int comparedates(char*, char*);
struct transaction * mergeSortedArrays(struct transaction *A, int Alen, struct transaction *B, int Blen)
{
	if (A && B && Alen>0 && Blen>0){
		struct transaction *M = (struct transaction*)malloc(sizeof(struct transaction)*(Alen + Blen));
		int i, j, r;
		for (i = 0, j = 0, r = 0; i<Alen && j<Blen; r++)
		{
			if (comparedates(A[i].date, B[j].date))
			{
				M[r] = A[i];
				i++;
			}
			else{
				M[r] = B[j];
				j++;
			}
		}
		if (j<Blen)
		{
			for (; j<Blen; j++, r++)
				M[r] = B[j];
		}
		if (i<Alen)
		{
			for (; i<Alen; i++, r++)
				M[r] = A[i];
		}
		return M;
	}
	return NULL;
}
int comparedates(char *date1, char *date2)
{
	int d = 1, m = 1, y = 1, n1 = 0, n2 = 0, j, i;
	for (i = 0; date1[i] != '-'; i++)
	{
		n1 = n1 * 10 + (date1[i] - '0');
		n2 = n2 * 10 + (date2[i] - '0');
	}
	if (n1<n2)
		d = 2;
	else if (n1 == n2)
		d = 0;

	for (j = i + 1, n1 = 0, n2 = 0; date1[j] != '-'; j++)
	{
		n1 = n1 * 10 + (date1[j] - '0');
		n2 = n2 * 10 + (date2[j] - '0');
	}
	if (n1<n2)
		m = 2;
	else if (n1 == n2)
		m = 0;
	for (i = j + 1, n1 = 0, n2 = 0; i != 10; i++)
	{
		n1 = n1 * 10 + (date1[i] - '0');
		n2 = n2 * 10 + (date2[i] - '0');
	}
	if (n1<n2)
		y = 2;
	else if (n1 == n2)
		y = 0;
	if (y == 2)
		return 1;
	else if (y == 0 && m == 2)
		return 1;
	else if (y == 0 && m == 0 && d == 2)
		return 1;
	else
		return 0;
}
