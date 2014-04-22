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

int *free_pam9t;   /// указатель на область свободной памяти
int *top; /// указатель на вершину стека
int *end; /// указатель на дно стека

/**
@brief Занесение элемента в стек. 
*/
/**
@param Номер элемента 
*/
void vnesenie(int i)
{
	/**
	@brief Вывод сообщения если стек переполнен 
	*/
	if(free_pam9t > end) {
		printf("Стек переполнен\n");
		return;
	}
	*free_pam9t = i;
	free_pam9t++;
}

/**
@brief Получение верхнего элемента из стека. 
*/
int topp(void)
{
	free_pam9t--;

	/**
	@brief Вывод сообщения если стек пустой 
	*/
	/**
	@return Успешное завершение 
	*/
	if(free_pam9t < top) {
		printf("Стек пустой\n");
		return 0;
	}
	return *free_pam9t;
}

/** 
Основная функция 
*/
int main()
{

  setlocale( LC_CTYPE, ".1251" ); ///Руссифицируем
	
  char s[80]; ///Инициализируем массим разверности 80

  free_pam9t = (int *) malloc(MAX*sizeof(int)); /// получаем память для стека 

  /**
  @brief Вывод сообщения, если не получена память для стека
  */
  if(!free_pam9t) {
    printf("Ошибка при выделении памяти\n");
    exit(1);
  }
  top = free_pam9t;
  end = free_pam9t + MAX-1;


  do {
    printf("1 - vnesenie, 2- topp");
    gets(s);

	/**
	@brief Проверка на введеный символ 
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



