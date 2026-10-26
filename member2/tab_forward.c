/*
  tab_forward.c
  MEMBER 2 : NAVIGATION HISTORY
  goForward - move to the next page
*/

#include "tab.h"

void goForward(struct tab *t)
{
    if (t->current->next == NULL) {
        printf("No next page\n");
        return;
    }
    t->current = t->current->next;
    printf("Forward to: %s\n", t->current->url);
}
