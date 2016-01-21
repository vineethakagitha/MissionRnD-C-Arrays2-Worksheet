/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include<iostream>

int findSingleOccurenceNumber(int *A, int len) {
		if (A && len>0)
		{
			int i, j, bcount = 0, *B = (int*)malloc(sizeof(int)*(len / 3)), p;
			for (i = 0; i<len; i++)
			{
				for (j = 0; j<bcount && A[i] != B[j]; j++);
				if (j == bcount)
				{
					for (p = len - 1; p >= 0 && A[p] != A[i]; p--);
					if (i == p)
						break;
					else{
						B[bcount] = A[i];
						bcount++;
					}
				}
			}
			return A[i];
		}
		return -1;

	}