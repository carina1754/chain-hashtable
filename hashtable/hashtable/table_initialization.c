// initialization.c

#include "functions.h"

void table_initialization(ptr_record Rec) 
{ 
	printf("테이블 초기화 작업을 시작합니다.\n");
	// monincome, link에 DUMMY_RECORD 
	for (int i = 0; i < Tbl_Size; i++) {
		Rec[i].monincome = Rec[i].link = DUMMY_RECORD; 
		strcpy(Rec[i].name, "");
	}	// for () 
	printf("테이블 초기화 작업이 완료되었습니다.\n\n"); 
}