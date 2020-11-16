// print_PT.c

#include "functions.h"

void print_PT(ptr_record Rec, char menu)
{
	// 수행시간 출력용 변수들
	float PT;
	LARGE_INTEGER TPS, ST, ET;
	LONGLONG CT;

	// 수행시간 구하기(시작 시간)
	QueryPerformanceFrequency(&TPS);
	QueryPerformanceCounter(&ST);

	// 메뉴별 수행
	switch (menu) { 
	case 'v':
		menu_v(Rec);
		break;
	case 'p':
		menu_p(Rec);
		break;
	default:
		printf("print_PT() 함수에서 오류 발생\n");
		return;
	}	// switch ()

	// 수행시간 구하기
	QueryPerformanceCounter(&ET);
	CT = ET.QuadPart - ST.QuadPart;
	PT = (float)CT / (float)TPS.QuadPart;

	// 수행시간 출력
	printf("\t수행시간 %f초\n", PT);
}