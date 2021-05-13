#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"

items Inventory[255];
int MAX_COUNT;

void initStorage() {
    char* buff = calloc(255, sizeof(char));
    FILE* inv = fopen(invFile, "r+");
    int ctr = -1;

    while (fgets(buff, 255, inv)) {        
        Inventory[++ctr] = addItem(buff); 
    }
    MAX_COUNT = ctr;
}

void showList() {
    for (int i=0; i<MAX_COUNT; i++) {
        if (Inventory[i]) printf("%s %d %ju\n", Inventory[i]->name, Inventory[i]->price, Inventory[i]->stocks);
    }
}

static int getItemInfo(char* name) {
    for (int i=0; i<MAX_COUNT; i++) {
        if (!strcmp(name, Inventory[i]->name)) {

        }
    }
}

static items addItem(char* data) {
    items newItem = malloc(sizeof(struct items_t));
    char* temp = data;
    newItem->name = strdup(strtok(temp, "#"));
    newItem->price = atoi(strtok(NULL, "#"));
    newItem->stocks = (unsigned)atoi(strtok(NULL, "#"));
    return newItem;
}

static void removeItem(char* name) {
    for (int i=0; i<MAX_COUNT; i++) {
        if (!Inventory[i]) continue;
        if (!strcmp(name, Inventory[i]->name)) {
            free(Inventory[i]);
            Inventory[i] = NULL;
            break;
        }
    }
}