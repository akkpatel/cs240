#include <stdio.h>
#include "callstack.h"

void customer3(int food) {
  int forBad = 0xBEEF4;
  badguy(forBad);
  printf("customer3: I get %X\n", food);
}

void customer2(int food) {
  int forC3 = 0xBEEF3;
  customer3(forC3);
  printf("customer2: I get %X\n", food);
}

void customer1(int food) {
  int forC2 = 0xBEEF2;
  customer2(forC2);
  printf("customer1: I get %X\n", food);
}

int main() {
  int forC1 = 0xBEEF1;
  customer1(forC1);
  return 0;
}
