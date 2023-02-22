#include <source_location>
#include <fstream>
#include <iostream>
int main() {
    std::ifstream stream(std::source_location::current().file_name());
    std::cout << stream.rdbuf();
}