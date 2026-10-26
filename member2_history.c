/*
  member2_history.c
  MEMBER 2 : NAVIGATION HISTORY
  Doubly linked list of pages for each tab
  (visit url, back, forward, show history)
*/

#include "tab.h"

void visitUrl(struct tab *t, char url[])
{
    struct page *p = (struct page *)malloc(sizeof(struct page));
    strcpy(p->url, url);
    p->prev = NULL;
    p->next = NULL;

    // first page of the tab
    if (t->current == NULL) {
        t->first = p;
        t->current = p;
        return;
    }

    // delete forward history (like real browser)
    struct page *temp = t->current->next;
    while (temp != NULL) {
        struct page *del = temp;
        temp = temp->next;
        free(del);
    }

    t->current->next = p;
    p->prev = t->current;
    t->current = p;
}

void goBack(struct tab *t)
{
    if (t->current->prev == NULL) {
        printf("No previous page\n");
        return;
    }
    t->current = t->current->prev;
    printf("Back to: %s\n", t->current->url);
}

void goForward(struct tab *t)
{
    if (t->current->next == NULL) {
        printf("No next page\n");
        return;
    }
    t->current = t->current->next;
    printf("Forward to: %s\n", t->current->url);
}

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

void freeHistory(struct tab *t)
{
    struct page *temp = t->first;
    while (temp != NULL) {
        struct page *del = temp;
        temp = temp->next;
        free(del);
    }
}