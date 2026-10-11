#ifndef TABS_H
#define TABS_H

void openTab(char url[]);
void displayTabs(void);
void closeTab(int tabId);
void switchTab(int tabId);
void restoreClosedTab(void);

#endif