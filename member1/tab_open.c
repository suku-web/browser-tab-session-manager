/*
  tab_open.c  (Member 1)
  Global variables of tab list + openTab + findTab
*/

#include "tab.h"

// global variables for tab list
struct tab *head = NULL;
struct tab *tail = NULL;
struct tab *active = NULL;
int idCounter = 1;
int totalTabs = 0;

void openTab(char url[])
{
    // Step 1: node banao (notes: N1 = malloc)
    struct tab *N1 = (struct tab *)malloc(sizeof(struct tab));
    N1->id = idCounter++;
    N1->prev = NULL;
    N1->next = NULL;
    N1->first = NULL;
    N1->current = NULL;

    visitUrl(N1, url);

    // Step 2: link nodes
    if (head == NULL)
    {
        head = N1;
        tail = N1;
    }
    else
    {
        tail->next = N1; // purana last -> N1
        N1->prev = tail; // N1 -> purana last
        tail = N1;
    }
    totalTabs++;
    active = N1;
    printf("Tab %d opened: %s\n", N1->id, url);
}

struct tab *findTab(int id)
{
    struct tab *temp = head;
    while (temp != NULL)
    {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}