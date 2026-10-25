/*
  tab_close.c  (Member 1)
  closeTab
*/

#include "tab.h"

void closeTab(int id)
{
    struct tab *N2 = findTab(id); // jo node hatana hai
    if (N2 == NULL)
    {
        printf("Tab not found\n");
        return;
    }

    if (active == N2)
    {
        if (N2->next != NULL)
            active = N2->next;
        else
            active = N2->prev;
    }

    // unlink: pichhla node agle ko, agla node pichhle ko point kare
    if (N2->prev != NULL)
        N2->prev->next = N2->next;
    else
        head = N2->next;

    if (N2->next != NULL)
        N2->next->prev = N2->prev;
    else
        tail = N2->prev;

    N2->prev = NULL;
    N2->next = NULL;
    totalTabs--;

    printf("Tab %d closed\n", N2->id);
    push(N2);
}