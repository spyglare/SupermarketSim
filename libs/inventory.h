#ifndef __CX_INV__
    #define __CX_INV__
    #define invFile "inventory.data"

    struct items_t {
        char* name;
        unsigned price;
        int stocks;
    };
    typedef struct items_t* items;

    extern void initStorage();
    extern void showList();
    extern int checkout(items* cart);
    extern void removeItem(char* name);
    extern void appendItem(char* name, int price, unsigned qty);
    extern void buyItem(items* cart, char* name);
    extern void returnItem(items* cart, char* name); 
    static void addItem(char* data);
    static void getItemInfo(char* name);
    static void updateStorage();
    static int generateHash(char* name);
    static unsigned length(const unsigned long num);
#endif