// hash.c

#include "functions.h"

int hash(char recname[])
{
	unsigned char u;
	int HA, j, leng, halfleng;
	long sum = 0;
	int A[100];

	// name의 글자 j에 대하여 다음을 수행한다
	leng = strlen(recname);
	for (j = 0; j < leng; j++) {
		u = recname[j];
		A[j] = u;
	}
	halfleng = leng / 2;

	for (j = 0; j < halfleng; j++)
	{ sum += A[j] * A[leng - 1 - j] * A[(leng - 1) / 2]; }

	if (leng % 2 == 1)
	{ sum += A[halfleng] * A[halfleng + 1] * A[(leng - 1) / 2]; }

	HA = sum % Tbl_Size;	// HA is a home address given by the hash function

	return HA;
}