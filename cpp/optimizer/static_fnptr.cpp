//Compiler: clang

#include <cstdio>

static void(*foo)();

static void boom() {
  puts("oh no");
}

void never_called() {
  foo = boom;  
}

int main() {
  foo();
}