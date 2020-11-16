// naive.c

#include "functions.h"

long naive_find_empty_loc(ptr_record Rec, long* R)
{
	while (1) {
		// 0 보다 작으면(= 빈자리가 없으면)
		if (/* Fill your code */*R<0) { return -1; }
		// (*R)이 빈자리라면(그 다음 빈자리 위치를 한칸 위로 올리고)
		if (Rec[(*R)--].monincome == DUMMY_RECORD) {
			// 빈자리 위치 반환
			return /* Fill your code */*R+1;
		}	// if ()
	}	// while (1)
}

void make_ht_with_naive_empty_finding(ptr_record Rec, long* R)
{
	char temp_Company[str_MAX];					// 파일에서 이름 받아오기용
	int rand1, rand2;							// 월 매출 랜덤 입력용
	int hash_value;								// hash값
	int empty_location;							// 빈자리 위치
	FILE* fp;									// 받아오는 파일
	FILE* fpout = fopen("HT_naive.txt", "w");	// 해시테이블 파일 출력용

	// 수행시간 출력용 변수들
	float PT;
	LARGE_INTEGER TPS, ST, ET;
	LONGLONG CT;

	// 수행시간 구하기(시작 시간)
	QueryPerformanceFrequency(&TPS);
	QueryPerformanceCounter(&ST);

	fp = fopen(Text_File_Name, "r");
	if (!fp) {
		printf("파일 읽기 과정에서 오류가 발생하였습니다.\n");
		printf("작업을 취소합니다.");
		return;
	}

	srand(time(NULL));	// For every different seed value

	while (1) {
		// uns.txt 파일상에서 한줄씩 받는다
		if (fgets(temp_Company, str_MAX, fp) == NULL) { break; }
		// fgets() 함수는 '\n'까지 넣으므로 문자열 끝에 붙은 '\n' 제거
		strtok(temp_Company, "\n");
		// 입력 받은 회사명 hash value 구하기
		hash_value = hash(temp_Company);
		// monincome 삽입용 값 구해놓기
		rand1 = rand() % 20001;
		rand2 = rand() % 1001;

		// 홈주소(hash_value)가 빈 자리라면
		if (Rec[hash_value].monincome == DUMMY_RECORD) {
			// 레코드 삽입
			strcpy(Rec[hash_value].name, temp_Company);
			Rec[hash_value].monincome = rand1 * rand2;
			Rec[hash_value].link = DUMMY_RECORD;
		}	// if ()

		// 빈 자리가 아니라면
		else {
			// 빈자리를 찾고
			empty_location = naive_find_empty_loc(Rec, R);
			// 링크를 연결하기 위해 홈주소부터 마지막 연결 체인을 찾아서
			while (Rec[hash_value].link != DUMMY_RECORD) {
				hash_value = /* Fill your code */Rec[hash_value].link;
			}	// while ()
			// 삽입할 위치랑 연결
			Rec[hash_value].link = /* Fill your code */empty_location;
			// 레코드 삽입
			strcpy(Rec[empty_location].name, /* Fill your code */temp_Company);
			Rec[empty_location].monincome = rand1 * rand2;
			Rec[empty_location].link = /* Fill your code */DUMMY_RECORD;
		}	// else

	}	//	while (1)

	// 수행시간 구하기
	QueryPerformanceCounter(&ET);
	CT = ET.QuadPart - ST.QuadPart;
	PT = (float)CT / (float)TPS.QuadPart;

	// 수행시간 출력
	printf("\t수행시간 %f초\n", PT);

	// 해시테이블 파일 출력
	for (int i = 0; i < Tbl_Size; i++) {
		fprintf(fpout, "%d, 이름 : %s, 월매출 : %d, 링크 : %d\n",
			i, Rec[i].name, Rec[i].monincome, Rec[i].link);
	}	// for () 

	// 파일 연결 닫기
	fclose(fpout); fclose(fp);
}