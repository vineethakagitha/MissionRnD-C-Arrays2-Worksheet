/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int equaldates(char*, char*);
struct transaction * sortedArraysCommonElements(struct transaction *A, int Alen, struct transaction *B, int Blen)
{
	if (A && B){
		struct transaction *C = (struct transaction*)malloc(sizeof(struct transaction)*(Alen + Blen));
		int i, r = 0, j;
		for (i = 0, r = 0; i<Alen; i++)
		{
			for (j = 0; j<Blen; j++)
			{
				if (equaldates(A[i].date, B[j].date))
				{
					C[r] = A[i];
					r++;
					break;
				}
			}
		}
		if (r == 0)
			return NULL;
		else
			return C;
	}
	return  NULL;
}
int equaldates(char *date1, char *date2)
{
	int i, j;
	for (i = 0; date1[i] && date2[i] ; i++)
	{
		if (date1[i] != date2[i])
			return 0;
	}
	return 1;
}
