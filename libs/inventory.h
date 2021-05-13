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
    extern void buyItem(items* cart, items name);
    extern void returnItem(items* cart, items name); 
    extern void removeItem(char* name);
    extern void appendItem(char* name, int price, unsigned qty);
    static items addItem(char* data);
    static void getItemInfo(items obj);
    static void updateStorage();
#endif