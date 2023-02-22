#include <stdio.h>

int main() {
    puts("poof"), typeid(decltype(std)).name();
    puts("where'd the poof go?");
}