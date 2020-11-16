// name_extracting.c

#include "functions.h"

void name_extracting(char menu[], char name[], int name_len)
{
	for (int i = 0; i < name_len; i++) {
		name[i] = menu[i + 2];
	}	// for ()
}