/*
  tab_show.c  (Member 1)
  showTabs
*/

#include "tab.h"

void showTabs()
{
    struct tab *temp = head;
    if (temp == NULL)
    {
        printf("No tabs open\n");
        return;
    }
    printf("\nOpen tabs (%d):\n", totalTabs);
    while (temp != NULL)
    {
        if (temp == active)
            printf(" --> ");
        else
            printf("     ");
        printf("Tab %d : %s\n", temp->id, temp->current->url);
        temp = temp->next;
    }
}