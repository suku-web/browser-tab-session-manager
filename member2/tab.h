/*
  tab.h  -  common header file (all 3 members use this)
  Structures, global variables and function declarations are here.
*/

#ifndef TAB_H
#define TAB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10   // max closed tabs we remember

// history node
struct page {
    char url[200];
    struct page *prev;
    struct page *next;
};

// tab node
struct tab {
    int id;
    struct page *first;     // first page of history
    struct page *current;   // page which is open now
    struct tab *prev;
    struct tab *next;
};

// global variables (defined in member1_tabs.c and member3_stack.c)
extern struct tab *head;
extern struct tab *tail;
extern struct tab *active;
extern int idCounter;
extern int totalTabs;

extern struct tab *closedStack[MAX];
extern int top;

// Member 1 functions
void openTab(char url[]);
struct tab *findTab(int id);
void closeTab(int id);
void switchToTab(int id);
void nextTab();
void prevTab();
void showTabs();

// Member 2 functions
void visitUrl(struct tab *t, char url[]);
void goBack(struct tab *t);
void goForward(struct tab *t);
void showHistory(struct tab *t);
void freeHistory(struct tab *t);

// Member 3 functions
void push(struct tab *t);
struct tab *pop();
void restoreTab();
void showClosedTabs();
void freeAll();

#endif
