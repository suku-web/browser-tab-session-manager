/*
  tab_history.c
  MEMBER 2 : NAVIGATION HISTORY
  showHistory - print all pages of a tab
*/

#include "tab.h"

void showHistory(struct tab *t)
{
    struct page *temp = t->first;
    printf("\nHistory of tab %d:\n", t->id);
    while (temp != NULL) {
        if (temp == t->current)
            printf(" --> ");
        else
            printf("     ");
        printf("%s\n", temp->url);
        temp = temp->next;
    }
}
