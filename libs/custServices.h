#ifndef __CX_CUSTSERV__
    #define __CX_CUSTSERV__

    struct member_t {
        char* name;
        char* id;
        char* points;
    };
    typedef struct member_t* member;
    extern void initMembership();
    extern int* getChanges(int money);
    extern int isMember(char* name);
    extern void usePoint(char* name);
    extern void addPoint(char* name);
    extern void registerMember(char* name);
    extern void revokeMmeber(char* name);
    static void loadMembership();

#endif
