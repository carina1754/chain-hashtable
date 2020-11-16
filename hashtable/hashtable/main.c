// main.c

#include "functions.h"

int main()
{
	char menu[str_MAX];			// 메뉴 입력
	int name_len = 0;			// r 메뉴 입력에서 이름 길이 
	char* temp_name = NULL;		// r 메뉴 입력에서 이름 추출용 
	long R = Tbl_Size - 1;		// 단순 빈자리 찾기에서 현재 빈자리 위치 

	// make table
	ptr_record Rec = (ptr_record)malloc(Tbl_Size*sizeof(type_record));
	table_initialization(Rec); 

	printf("\n단순한 빈자리 찾기로 삽입을 시작합니다.\n");
	// 해시테이블 삽입 작업
	make_ht_with_naive_empty_finding(Rec, &R);
	printf("삽입이 완료되었습니다.\n");

	// e(종료) 입력 때까지 반복
	// 검색, (일괄)삭제, 성능측정 작업
	while (1) {
		printf("명령은? ");
		// 메뉴 menu 문자열에 받기
		fgets(menu, str_MAX, stdin);
		// menu 문자열에서 '\n' 제거
		strtok(menu, "\n");
		// 입력 버퍼 비우기
		fflush(stdin);

		switch (menu[0]) {
		case 'r':
			// 메뉴 입력에서 이름 추출
			name_len = strlen(menu) - 1;
			temp_name = malloc((name_len) * sizeof(char));
			name_extracting(menu, temp_name, name_len);
			menu_r(Rec, temp_name);
			break; 
		case 'v':
			print_PT(Rec, 'v'); 
			break;
		case 'p':
			print_PT(Rec, 'p'); 
			break;
		case 'e':
			printf("실험을 종료합니다.\n");
			return 0;
		default:
			printf("그런 명령은 존재하지 않습니다.\n");
			break;
		}	// switch ()

	}	// while (1)

	return 0;
}