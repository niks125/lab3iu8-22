/** 
@file List.cpp
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <locale.h>

/**
namespace std;
@brief Пространство имен A
*/

struct address {
  char name[40];
  char street[40];
  char city[20];
  char state[3];
  char zip[11];
  struct address *next; /// ссылка на следующий адрес 
}

/**
@brief  Вставка в упорядоченный односвязный список. 
*/
void sls_store(struct address *i, /// новый элемент 
               struct address **start, /// начало списка 
               struct address **last) /// конец списка 
{
  struct address *old, *prev;

  prev = *start;

  /**
  @brief первый элемент в списке 
  */
  if(!*last) {
    i->next = NULL;
    *last = i;
    *start = i;
    return;
  }

  old = NULL;
  while(prev) {
    if(strcmp(prev->name, i->name)<0) {
      old = prev;
      prev = prev->next;
    }
    else {

	/**
	@brief в середину 
	*/
      if(old) {
        old->next = i;
        i->next = prev;
        return;
      }
      i->next = prev; /// в начало 
      *start = i;
      return;
    }
  }
  (*last)->next = i; /// в конец 
  i->next = NULL;
  *last = i;
}

/**
@brief Функция вывода структуры 
*/
void display(struct address *start)
{
  while(start) {
    printf("%s\n", start->name);
    start = start->next;
  }
}

/**
@brief поиск элемента в списке 
*/
struct address *search(struct address *start, char *n)
{
  while(start) {
    if(!strcmp(n, start->name)) return start;
    start = start->next;
  }
  return NULL;  /// подходящий элемент не найден
}


void sldelete(
     struct address *prev, /// предыдущий элемент 
     struct address *i, /// удаляемый элемент 
     struct address **start, /// начало списка 
     struct address **last) /// конец списка 
{
  if(prev) prev->next = i->next;
  else *start = i->next;

  if(i==*last && prev) *last = prev;
}

/**
@brief  Основная функция. 
@return Функция возвращает пустое значение
*/
int main()
{
	address *a, *b, *c;
	a = new address;
	a->next = b;
	b->next = c;
	address *d = new address;
	sls_store(d, *a, *b);

	return 0;
}

