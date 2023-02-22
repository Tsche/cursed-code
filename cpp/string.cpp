#include <string>
#include <cassert>
#include <iostream>

int main() {
    std::string string {1, 'b'};
    assert(string.length() == 2);

    for (auto const& c : string)
        std::cout << +c << " ";

    std::string string2 (1, 'b');
    assert(string2.length() == 1);
}