/*
  tab_back.c
  MEMBER 2 : NAVIGATION HISTORY
  goBack - move to the previous page
*/

#include "tab.h"

void goBack(struct tab *t)
{
    if (t->current->prev == NULL) {
        printf("No previous page\n");
        return;
    }
    t->current = t->current->prev;
    printf("Back to: %s\n", t->current->url);
}
