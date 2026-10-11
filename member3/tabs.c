// LL07 - Browser Tab and Session Manager
// Doubly Linked List for Browser Tabs

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabs.h"
#include "session.h"

struct Tab {
    int tabId;
    char url[100];
    struct Tab *prev;
    struct Tab *next;
};

struct Tab *head = NULL;
struct Tab *activeTab = NULL;
int nextTabId = 1;

// Open a new browser tab
void openTab(char url[]) {
    struct Tab *newTab = malloc(sizeof(struct Tab));

    if (newTab == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newTab->tabId = nextTabId++;
    snprintf(newTab->url, sizeof(newTab->url), "%s", url);
    newTab->prev = NULL;
    newTab->next = NULL;

    if (head == NULL) {
        head = newTab;
    } else {
        struct Tab *temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newTab;
        newTab->prev = temp;
    }

    activeTab = newTab;

    printf("Tab opened successfully!\n");
    printf("Tab ID: %d | URL: %s\n", newTab->tabId, newTab->url);
}

// Display all open browser tabs
void displayTabs(void) {
    struct Tab *temp = head;

    if (head == NULL) {
        printf("No tabs are currently open.\n");
        return;
    }

    printf("\n===== Open Browser Tabs =====\n");

    while (temp != NULL) {
        printf("Tab ID: %d | URL: %s", temp->tabId, temp->url);

        if (temp == activeTab) {
            printf(" [Active]");
        }

        printf("\n");
        temp = temp->next;
    }
}

// Close a tab and save it to the stack
void closeTab(int tabId) {
    struct Tab *temp = head;

    while (temp != NULL && temp->tabId != tabId) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Tab not found!\n");
        return;
    }

    pushClosedTab(temp->tabId, temp->url);

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (activeTab == temp) {
        activeTab = (temp->prev != NULL) ? temp->prev : head;
    }

    printf("Tab %d closed successfully!\n", temp->tabId);

    free(temp);
}

// Switch the active browser tab
void switchTab(int tabId) {
    struct Tab *temp = head;

    while (temp != NULL && temp->tabId != tabId) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Tab not found!\n");
        return;
    }

    activeTab = temp;

    printf("Switched to Tab %d successfully!\n", activeTab->tabId);
}

// Restore the most recently closed tab
void restoreClosedTab(void) {
    int tabId;
    char url[100];

    if (!popClosedTab(&tabId, url)) {
        printf("No recently closed tabs to restore!\n");
        return;
    }

    struct Tab *newTab = malloc(sizeof(struct Tab));

    if (newTab == NULL) {
        printf("Memory allocation failed!\n");
        pushClosedTab(tabId, url);
        return;
    }

    newTab->tabId = tabId;
    snprintf(newTab->url, sizeof(newTab->url), "%s", url);
    newTab->prev = NULL;
    newTab->next = NULL;

    if (head == NULL) {
        head = newTab;
    } else {
        struct Tab *temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newTab;
        newTab->prev = temp;
    }

    activeTab = newTab;

    printf("Tab restored successfully!\n");
    printf("Tab ID: %d | URL: %s\n", newTab->tabId, newTab->url);
}