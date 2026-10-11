#ifndef SESSION_H
#define SESSION_H

void pushClosedTab(int tabId, char url[]);
int popClosedTab(int *tabId, char url[]);
int isEmpty(void);

#endif