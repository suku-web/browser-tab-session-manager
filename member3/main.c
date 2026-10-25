
/*
  main.c
  MEMBER 3 : MAIN MENU
  Joins the work of all 3 members
*/

#include "../member1/tab.h"

void menu()
{
    printf("\n------ BROWSER TAB MANAGER ------\n");
    printf("1.  Open new tab\n");
    printf("2.  Close tab\n");
    printf("3.  Switch to tab (by id)\n");
    printf("4.  Next tab\n");
    printf("5.  Previous tab\n");
    printf("6.  Visit URL in active tab\n");
    printf("7.  Back\n");
    printf("8.  Forward\n");
    printf("9.  Restore closed tab\n");
    printf("10. Show all tabs\n");
    printf("11. Show history of active tab\n");
    printf("12. Show closed tabs\n");
    printf("0.  Exit\n");
    printf("Enter choice: ");
}

int main()
{
    int choice, id;
    char url[200];

    do {
        menu();

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            break;
        }

        switch (choice) {
        case 1:
            printf("Enter URL: ");
            scanf("%199s", url);
            openTab(url);
            break;

        case 2:
            printf("Enter tab id: ");
            scanf("%d", &id);
            closeTab(id);
            break;

        case 3:
            printf("Enter tab id: ");
            scanf("%d", &id);
            switchToTab(id);
            break;

        case 4:
            nextTab();
            break;

        case 5:
            prevTab();
            break;

        case 6:
            if (active == NULL) {
                printf("No active tab\n");
            } else {
                printf("Enter URL: ");
                scanf("%199s", url);
                visitUrl(active, url);
                printf("Opened %s in tab %d\n", url, active->id);
            }
            break;

        case 7:
            if (active == NULL)
                printf("No active tab\n");
            else
                goBack(active);
            break;

        case 8:
            if (active == NULL)
                printf("No active tab\n");
            else
                goForward(active);
            break;

        case 9:
            restoreTab();
            break;

        case 10:
            showTabs();
            break;

        case 11:
            if (active == NULL)
                printf("No active tab\n");
            else
                showHistory(active);
            break;

        case 12:
            showClosedTabs();
            break;

        case 0:
            printf("Bye\n");
            break;

        default:
            printf("Wrong choice\n");
        }

    } while (choice != 0);

    freeAll();
    return 0;
}

