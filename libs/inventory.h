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
    extern void buyItem(items cart, char* name);
    extern void returnItem(items cart, char* name); 
    static items addItem(char* data);
    static void removeItem(char* name);
    static int getItemInfo(char* name);
#endif