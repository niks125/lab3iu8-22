/**
@file O4ered.cpp
*/

/**
@brief �������� �������
*/
/**
@detailed � ������� ��������� ������� � ��������� ������� ��� ������ � ���: ���������� � �������� 
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <locale.h>

/**
namespace std;
@brief ������������ ���� A
*/

#define MAX 100

char *p[MAX], *qretrieve(void);
int spos = 0;
int rpos = 0;

/**
@brief ������� � ������� ������ ��������
	*/
/**
@detailed ������ ������� ��������� �������� � ������� ����� ������� ��� �������, ��� ���������� ��������� �� ����� ��������� �����������
*/
void enter(void)
{
	char s[256], *p;

	do {
		printf("������� ������� %d: ", spos+1);
		gets(s);
		if(*s==0) break; 
		p = (char *) malloc(strlen(s)+1);/// ��������� ������, ���� ��������
		if(!p) {
			printf("�� ������� ������.\n");
			return;
		}
		strcpy(p, s);/// ������� ��������
		if(*s) qstore(p);
	} while(*s);
}

/**
@brief ������� � ������� ������ ��������
	*/
/**
@detailed ������ ������� ��������� �������� � ������� ����� ������� ��� �������, ��� ���������� ��������� �� ����� ��������� �����������
*/
void qstore(char *q)
{
	if(spos==MAX) {
		printf("List Full\n");
		return;
	}
	p[spos] = q;///���������� ��������
	spos++;///���������� ��������
}

/**
@brief ������� � ������� ������ ��������
*/
/**
@detailed ������ ������� ��������� ����������� ��� �������� ������� �� �������
*/
void review(void)
{
	int t;///������������� ��������

	for(t=rpos; t < spos; ++t)
		printf("%d. %s\n", t+1, p[t]);///
}

/**
@brief �������� �������� �� �������
*/
/**
@detailed ������ ������� ��������� ������� ������� �� ������� 
*/
void delete_ap(void)
{
	char *p;///������������� ��������������� �������

	if((p=qretrieve())==NULL) return;///�������� ��������
	printf("%s\n", p);
}

char retrieve (void);
/**
@brief ���������� ��������
*/
/**
@detailed ������ ������� ��������� ������� ������� �� ������� 
*/

char *qretrieve(void)
{
	if(rpos==spos) {
		printf("������� ������ ���.\n");
		return NULL;
	}
	rpos++;///���������� ��������
	return p[rpos-1];///���������� ��������
}


/**
@brief �������� �������
*/
int main()
{
	setlocale( LC_CTYPE, ".1251" ); ///�������������
	char s[80]; /// ������������� ������� �������
	int t; /// ������������� ��������

	for(t=0; t < MAX; ++t) p[t] = NULL;  

	for(;;)
	{
		printf("������ (E), ������ (L), ������� (R), ����� (Q): ");/// ����� ���� ������� �� �����
		gets(s);
		*s = toupper(*s);

		switch(*s) {
			case 'E':
			enter();
			break;
		case 'L':
			review();
			break;
		case 'R':
			delete_ap();
			break;
		case 'Q':
			exit(0);
    }/// ����� ������� �������������
  }
  return 0;
}















