#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "custServices.h"

member memberList[100];

void initMembership() {
    char* buff = calloc(255, sizeof(char));
    FILE* mbr = fopen(memberFile, "r+");
    int ctr = -1;

    while (fgets(buff, 255, mbr)) {
        addMember(buff);
    }
}

void usePoint(char* name, int used) {
    int hashVal = isMember(name);
    if (hashVal == -1) printf("Not a member (yet)!");
    else {
        int temp = memberList[hashVal]->points;
        if (temp - used <= 0) printf("Not Enough Point!");
        else memberList[hashVal]->points -= used;
    }
}

void addPoint(char* name, int added) {
    int hashVal = isMember(name);
    if (hashVal == -1) printf("Not a member (yet)!");
    else memberList[hashVal]->points += added;
}

void registerMember(char* name) {
    char* data = calloc(255, sizeof(char));
    snprintf(data, 255, "%s#0", name);
    addMember(data);
    updateMembership();
    memberStatus(name);
    free(data);
}

void revokeMember(char* name) {
    int hashVal = isMember(name);
    if (hashVal == -1) printf("Not a member!");
    else {
        memberList[hashVal] = NULL;
        updateMembership();
    }
}

static int isMember(char* name) {
    int hashVal = generateHash(name);
    return (memberList[hashVal]) != NULL ? hashVal : -1;
}

static void addMember(char* data) {
    member newMem = malloc(sizeof(struct member_t));
    char* temp = data;
    int hashVal = 0;
    newMem->name = strdup(strtok(data,"#"));
    hashVal = generateHash(newMem->name);
    newMem->points = atoi(strtok(NULL, "#"));
    if (!memberList[hashVal]) memberList[hashVal] = newMem;
}

static void memberStatus(char* name) {
    int hashVal = isMember(name);
    if (hashVal == -1) printf("Not a member (yet)!");
    printf("┬─ %s\n├ ID: %d\n└ Point: %d\n", 
            memberList[hashVal]->name,
            hashVal,
            memberList[hashVal]->points);
}

static void updateMembership() {
    FILE *mbr = fopen(memberFile, "w+");

    for (int i=0; i<100; i++) {
        if (!memberList[i]) continue;
        member temp = memberList[i];
        fprintf(mbr, "%s#%d", temp->name, temp->points);
    }
    fclose(mbr);
}

static int generateHash(char* name) {
    int val = 0;
    unsigned long ctr = 0;
    for (int i=0; i<strlen(name)-1; i++) {
        ctr += i+1 < 10 ? (int) name[i]*10 + 1+1 : (int)name[i]*100 + i+1;
    }
    ctr = (unsigned long)pow(ctr, 2);
    while(length(ctr) > 2) {
        val += ctr%10;
        ctr = ctr/10;
    }
    return val;
}

static unsigned length(const unsigned long num) {
    if (num < 10) return 1;
    return 1 + length(num/10);
}