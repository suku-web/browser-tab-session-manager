/*
  tab_switch.c  (Member 1)
  switchToTab, nextTab, prevTab
*/

#include "tab.h"

void switchToTab(int id)
{
    struct tab *t = findTab(id);
    if (t == NULL)
    {
        printf("Tab not found\n");
        return;
    }
    active = t;
    printf("Now on tab %d (%s)\n", t->id, t->current->url);
}

void nextTab()
{
    if (active == NULL)
    {
        printf("No tabs open\n");
        return;
    }
    if (active->next != NULL)
        active = active->next;
    else
        active = head;
    printf("Now on tab %d (%s)\n", active->id, active->current->url);
}

void prevTab()
{
    if (active == NULL)
    {
        printf("No tabs open\n");
        return;
    }
    if (active->prev != NULL)
        active = active->prev;
    else
        active = tail;
    printf("Now on tab %d (%s)\n", active->id, active->current->url);
}