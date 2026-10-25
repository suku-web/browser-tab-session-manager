#include "../member1/tab.h"

struct tab *closedStack[MAX];
int top = -1;

void push(struct tab *t)
{
    if (t == NULL)
        return;

    if (top == MAX - 1) {
        printf("Closed tabs full. Oldest tab deleted permanently.\n");

        struct tab *oldest = closedStack[0];
        freeHistory(oldest);
        free(oldest);

        for (int i = 1; i < MAX; i++)
            closedStack[i - 1] = closedStack[i];

        top--;
    }

    closedStack[++top] = t;
}

struct tab *pop()
{
    if (top == -1)
        return NULL;

    return closedStack[top--];
}

void restoreTab()
{
    struct tab *t = pop();

    if (t == NULL) {
        printf("No closed tab to restore.\n");
        return;
    }

    t->prev = tail;
    t->next = NULL;

    if (tail == NULL)
        head = tail = t;
    else {
        tail->next = t;
        tail = t;
    }

    totalTabs++;
    active = t;

    printf("Tab %d restored: %s\n",
           t->id,
           t->current ? t->current->url : "No URL");
}

void showClosedTabs()
{
    if (top == -1) {
        printf("No closed tabs.\n");
        return;
    }

    printf("\nClosed Tabs (Latest First):\n");

    for (int i = top; i >= 0; i--) {
        printf("Tab %d: %s\n",
               closedStack[i]->id,
               closedStack[i]->current
                   ? closedStack[i]->current->url
                   : "No URL");
    }
}

void freeAll()
{
    struct tab *temp = head;

    while (temp != NULL) {
        struct tab *next = temp->next;
        freeHistory(temp);
        free(temp);
        temp = next;
    }

    head = tail = active = NULL;
    totalTabs = 0;

    while (top != -1) {
        struct tab *t = pop();
        freeHistory(t);
        free(t);
    }
}