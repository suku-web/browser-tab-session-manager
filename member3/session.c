// LL07 - Browser Tab and Session Manager
// Stack for Recently Closed Tabs

#include <stdio.h>
#include <string.h>
#include "session.h"

#define MAX_CLOSED_TABS 100

struct ClosedTab {
    int tabId;
    char url[100];
};

struct ClosedTab stack[MAX_CLOSED_TABS];
int top = -1;

int isEmpty(void) {
    return top == -1;
}

void pushClosedTab(int tabId, char url[]) {
    if (top == MAX_CLOSED_TABS - 1) {
        printf("Closed tab stack is full!\n");
        return;
    }

    top++;
    stack[top].tabId = tabId;
    snprintf(stack[top].url, sizeof(stack[top].url), "%s", url);
}

int popClosedTab(int *tabId, char url[]) {
    if (isEmpty()) {
        return 0;
    }

    *tabId = stack[top].tabId;
    strcpy(url, stack[top].url);
    top--;

    return 1;
}