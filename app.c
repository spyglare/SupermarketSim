#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "libs\custServices.h"
#include "libs\inventory.h"

int main() {
  // initMembership();
  items userCart[50] = {0}; // 50 stack items a.k.a 50 jenis items
  initStorage();
  showList();
  removeItem("tamago");
  appendItem("Weedo", 15000, 420);
  buyItem(userCart, "Weedo");
  unsigned paid = checkout(userCart);
  printf("%ju\n", paid);
}