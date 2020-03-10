#include <iostream>

#pragma warning(disable:4996)
using namespace std;

void Study0();
void Study1();
void Study2();
void Study3();
void Study4();

int main()
{
	Study4();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////fprintf 공부

//사칙 연산결과 파일로 출력
void Study0()
{
	FILE *fp;

	fopen_s(&fp, "Study0.txt", "wt");

	if (fp == NULL)
	{
		printf("실패\n");
		return;
	}

	int a, b;
	printf("1.숫자 입력 : ");
	scanf("%d", &a);
	printf("2.숫자 입력 : ");
	scanf("%d", &b);
	fprintf(fp, "%d+%d=%d\n", a, b, a + b);
	fprintf(fp, "%d-%d=%d\n", a, b, a - b);
	fprintf(fp, "%d*%d=%d\n", a, b, a * b);
	fprintf(fp, "%d/%d=%d\n", a, b, a / b);
	fclose(fp);

	printf("완료\n");
}

//사칙 입력결과 파일로 출력
void Study1()
{
	FILE *fp;

	fopen_s(&fp, "Study1.txt", "wt");

	if (fp == NULL)
	{
		printf("실패\n");
		return;
	}

	printf("100자 이내의 문자들을 기록하는 프로그램 입니다.\n");
	printf("문자열을 입력하세요\n\n");

	char str[100] = { 0, };
	gets_s(str,_countof(str));

	fprintf(fp,"<입력받은 문자열의 내용입니다.> \n");
	fprintf(fp, str);

	printf("입려력받은 문자열 : %s\n", str);

	fclose(fp);
	printf("완료\n");
}

///////fputs 공부

void Study2()
{
	FILE *fp;
	
	fopen_s(&fp, "Study2.txt", "wt");

	if (fp == NULL)
	{
		printf("실패\n");
		return;
	}

	const char *str = "이 파일은 C 표준 함수로 생성된 텍스트 파일입니다.\nC드라이브의 루트 디렉토리에 Study2.txt라는 이름으로 생성됩니다.\n";
	fputs(str, fp);
	fclose(fp);
	printf("완료\n");
}

///////fgets 공부

void Study3()
{
	FILE *fp;

	fopen_s(&fp, "Study2.txt", "rt");

	if (fp == NULL)
	{
		printf("실패\n");
		return;
	}

	while (!feof(fp))
	{
		char buf[256] = { 0, };
		fgets(buf, 256, fp);
		printf("%s", buf);
	}

	fclose(fp);	
}

void Study4()
{
	FILE *rp;
	FILE *wp;
	fopen_s(&rp, "Img.jpg", "rb");
	fopen_s(&wp, "CopyImg.jpg", "wb");
	if (rp == NULL)
	{
		printf("실패\n");
		return;
	}

	while (!feof(rp))
	{
		char buf[256] = { 0, };
		fgets(buf, 256, rp);
		fputs(buf, wp);
		printf("%s", buf);
	}



	fclose(rp);
	fclose(wp);
}