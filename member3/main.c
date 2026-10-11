// LL07 - Browser Tab and Session Manager
// Member 3: Main Menu

#include <stdio.h>
#include "tabs.h"

int main() {
    int choice;
    int tabId;
    char url[100];

    do {
        printf("\n===== Browser Tab and Session Manager =====\n");
        printf("1. Open a New Tab\n");
        printf("2. Close a Tab\n");
        printf("3. Switch Active Tab\n");
        printf("4. Display All Open Tabs\n");
        printf("5. Restore Recently Closed Tab\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%99s", url);
                openTab(url);
                break;

            case 2:
                printf("Enter Tab ID to close: ");
                if (scanf("%d", &tabId) == 1) {
                    closeTab(tabId);
                } else {
                    printf("Invalid Tab ID!\n");
                    while (getchar() != '\n');
                }
                break;

            case 3:
                printf("Enter Tab ID to switch to: ");
                if (scanf("%d", &tabId) == 1) {
                    switchTab(tabId);
                } else {
                    printf("Invalid Tab ID!\n");
                    while (getchar() != '\n');
                }
                break;

            case 4:
                displayTabs();
                break;

            case 5:
                restoreClosedTab();
                break;

            case 6:
                printf("Exiting Browser Tab and Session Manager.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}