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
@brief ������������ ���� A
*/

struct address {
  char name[40];
  char street[40];
  char city[20];
  char state[3];
  char zip[11];
  struct address *next; /// ������ �� ��������� ����� 
}

/**
@brief  ������� � ������������� ����������� ������. 
*/
void sls_store(struct address *i, /// ����� ������� 
               struct address **start, /// ������ ������ 
               struct address **last) /// ����� ������ 
{
  struct address *old, *prev;

  prev = *start;

  /**
  @brief ������ ������� � ������ 
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
	@brief � �������� 
	*/
      if(old) {
        old->next = i;
        i->next = prev;
        return;
      }
      i->next = prev; /// � ������ 
      *start = i;
      return;
    }
  }
  (*last)->next = i; /// � ����� 
  i->next = NULL;
  *last = i;
}

/**
@brief ������� ������ ��������� 
*/
void display(struct address *start)
{
  while(start) {
    printf("%s\n", start->name);
    start = start->next;
  }
}

/**
@brief ����� �������� � ������ 
*/
struct address *search(struct address *start, char *n)
{
  while(start) {
    if(!strcmp(n, start->name)) return start;
    start = start->next;
  }
  return NULL;  /// ���������� ������� �� ������
}


void sldelete(
     struct address *prev, /// ���������� ������� 
     struct address *i, /// ��������� ������� 
     struct address **start, /// ������ ������ 
     struct address **last) /// ����� ������ 
{
  if(prev) prev->next = i->next;
  else *start = i->next;

  if(i==*last && prev) *last = prev;
}

/**
@brief  �������� �������. 
@return ������� ���������� ������ ��������
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

