/*
  tab_free.c
  MEMBER 2 : NAVIGATION HISTORY
  freeHistory - free all pages of a tab
*/

#include "tab.h"

void freeHistory(struct tab *t)
{
    struct page *temp = t->first;
    while (temp != NULL) {
        struct page *del = temp;
        temp = temp->next;
        free(del);
    }
}
