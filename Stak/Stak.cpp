/**
@file Stak.cpp
*/

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <locale.h>

#define MAX 100

int *free_pam9t;   /// ��������� �� ������� ��������� ������
int *top; /// ��������� �� ������� �����
int *end; /// ��������� �� ��� �����

/**
@brief ��������� �������� � ����. 
*/
/**
@param ����� �������� 
*/
void vnesenie(int i)
{
	/**
	@brief ����� ��������� ���� ���� ���������� 
	*/
	if(free_pam9t > end) {
		printf("���� ����������\n");
		return;
	}
	*free_pam9t = i;
	free_pam9t++;
}

/**
@brief ��������� �������� �������� �� �����. 
*/
int topp(void)
{
	free_pam9t--;

	/**
	@brief ����� ��������� ���� ���� ������ 
	*/
	/**
	@return �������� ���������� 
	*/
	if(free_pam9t < top) {
		printf("���� ������\n");
		return 0;
	}
	return *free_pam9t;
}

/** 
�������� ������� 
*/
int main()
{

  setlocale( LC_CTYPE, ".1251" ); ///�������������
	
  char s[80]; ///�������������� ������ ����������� 80

  free_pam9t = (int *) malloc(MAX*sizeof(int)); /// �������� ������ ��� ����� 

  /**
  @brief ����� ���������, ���� �� �������� ������ ��� �����
  */
  if(!free_pam9t) {
    printf("������ ��� ��������� ������\n");
    exit(1);
  }
  top = free_pam9t;
  end = free_pam9t + MAX-1;


  do {
    printf("1 - vnesenie, 2- topp");
    gets(s);

	/**
	@brief �������� �� �������� ������ 
	*/
    switch(*s) {
       case '1':
		int a;
		printf(": ");
		scanf("%d", a);
		vnesenie(a);
		break;
      case '2':{
        int b = topp();
        printf("%d", b);
        break;
	  default:
		  {
			  break;
		  }
		}
	     
    }
  }
  while(*s != 'q');
	
  return 0;
}



