/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int dateearly(char*, char*);
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i = 0;
	if (Arr && len>0 && date){
		for (i = 0; i<len; i++)
		{
			if (dateearly(date, (Arr[i].date)))
				break;
		}
		return len - i;
	}
	return -1;
}

int dateearly(char *date1, char *date2)
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
