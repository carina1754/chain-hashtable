// functions.h

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "GV.h"

int hash(char recname[]);

void table_initialization(ptr_record Rec); 

void make_ht_with_naive_empty_finding(ptr_record Rec, long* R);
long naive_find_empty_loc(ptr_record Rec, long* R); 

void name_extracting(char menu[], char name[], int name_len);

void menu_r(ptr_record Rec, char name[]); 
void menu_v(ptr_record Rec);
void menu_p(ptr_record Rec);

void print_PT(ptr_record Rec, char menu); 

#endif	// FUNCTIONS_H