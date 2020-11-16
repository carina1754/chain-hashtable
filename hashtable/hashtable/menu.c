// menu.c

#include "functions.h"

void menu_r(ptr_record Rec, char name[])
{
	int probes = 1;
	int hash_value;

	// 입력 받은 회사명 hash value 구하기
	hash_value = hash(name);

	while (1) {
		// hash_value 위치에 있다면
		if (strcmp(Rec[hash_value].name, name) == 0) { break; }
		// 없다면
		else {
			// 링크를 한번 건너
			hash_value = Rec[hash_value].link;
			probes++;
			// DUMMY_RECORD 확인(체인의 끝 여부)
			if (hash_value == DUMMY_RECORD) { 
				printf("그런 데이타는 존재하지 않습니다.\n");
				return;
			} // if ()
		}	// else
	}	// while(1)
	printf("\t저장위치 = %d, Probe 수 = %d\n", hash_value, probes);
}

void menu_v(ptr_record Rec)
{
	int success_count = 0;
	int fail_count = 0;
	char temp_Company[str_MAX];
	int hash_value;
	FILE *fp = fopen(Text_File_Name, "r");

	while (1) {
		// uns.txt 파일상에서 한줄씩 받는다
		if (fgets(temp_Company, str_MAX, fp) == NULL) { break; }
		// fgets() 함수는 '\n'까지 넣으므로 문자열 끝에 붙은 '\n' 제거
		strtok(temp_Company, "\n");
		// 입력 받은 회사명 hash value 구하기
		hash_value = hash(temp_Company);

		while (2) {
			// hash_value 위치에 있다면
			if (strcmp(Rec[hash_value].name, temp_Company) == 0) {
				success_count++;
				break;
			}	// if ()
			// 없다면
			else {
				// 링크를 한번 건너
				hash_value = Rec[hash_value].link;
				// DUMMY_RECORD 확인(체인의 끝 여부)
				if (hash_value == DUMMY_RECORD) {
					fail_count++;
					break;
				}	// if ()
			}	// else
		}	// while(2)

	}	//	while (1)

	printf("\tSuccess count: %d,\t Fail count: %d\n"
		, success_count, fail_count);
	fclose(fp);
}

void menu_p(ptr_record Rec)
{
	int probes = 1;
	double apn = 0;
	char temp_Company[str_MAX];
	int hash_value;
	FILE *fp = fopen(Text_File_Name, "r");

	while (1) {
		// uns.txt 파일상에서 한줄씩 받는다
		if (fgets(temp_Company, str_MAX, fp) == NULL) { break; }
		// fgets() 함수는 '\n'까지 넣으므로 문자열 끝에 붙은 '\n' 제거
		strtok(temp_Company, "\n");
		// 입력 받은 회사명 hash value 구하기
		hash_value = hash(temp_Company);

		while (2) {
			// hash_value 위치에 있다면
			if (strcmp(Rec[hash_value].name, temp_Company) == 0) { break; }
			// 없다면
			else {
				// 링크를 한번 건너
				hash_value = Rec[hash_value].link;
				probes++;
				// DUMMY_RECORD 확인(체인의 끝 여부)
				if (hash_value == DUMMY_RECORD) { break; }
			}	// else
		}	// while(2)

		apn += probes;
		probes = 1;
	}	//	while (1)

	apn /= N;
	printf("\tAverage probe number = %lf\n", apn);
	fclose(fp);
}