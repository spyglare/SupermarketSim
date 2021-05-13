#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"

items Inventory[255];
char* itemList[255];
int MAX_COUNT;

void initStorage() {
    char* buff = calloc(255, sizeof(char));
    FILE* inv = fopen(invFile, "r+");
    int ctr = -1;

    while (fgets(buff, 255, inv)) {        
        Inventory[++ctr] = addItem(buff); 
        itemList[ctr] = Inventory[ctr]->name;
    }
    MAX_COUNT = ctr;
    fclose(inv);
}

static void updateStorage() {
    FILE* inv = fopen(invFile, "w+");
    
    for (int i=0; i<=MAX_COUNT; i++) {
        if (!Inventory[i]) continue;
        items temp = Inventory[i];
        fprintf(inv, "%s#%d#%ju\n", temp->name, temp->price, temp->stocks);
    }
    fclose(inv);
}

void showList() {
    for (int i=0; i<MAX_COUNT; i++) {
        if (Inventory[i]) getItemInfo(Inventory[i]);
    }
}

static void getItemInfo(items obj) {
    printf("┬─ %s\n├ Rp. %d,00\n└ Qty: %d\n",
            obj->name,
            obj->price,
            obj->stocks);
}

static items addItem(char* data) {
    items newItem = malloc(sizeof(struct items_t));
    char* temp = data;
    newItem->name = strdup(strtok(temp, "#"));
    newItem->price = atoi(strtok(NULL, "#"));
    newItem->stocks = (unsigned)atoi(strtok(NULL, "#"));
    return newItem;
}

void removeItem(char* name) {
    for (int i=0; i<MAX_COUNT; i++) {
        if (!Inventory[i]) continue;
        if (!strcmp(name, Inventory[i]->name)) {
            free(Inventory[i]);
            Inventory[i] = NULL;
            updateStorage();
            break;
        }
    }
}

void buyItem(items* cart, items name) {
    for (int i=0; i<50; i++) {
        if (cart[i]) {
            if (!strcmp(cart[i]->name, name->name)) cart[i]->stocks++;
            else continue;
        } else {
            cart[i] = name;
            cart[i]->stocks = 1;
        }
    }
}

void returnItem(items* cart, items name) {
    for (int i=0; i<50; i++) {
        if (cart[i] && !strcmp(cart[i]->name, name->name)) {
            cart[i] = NULL;
        }
    }
}