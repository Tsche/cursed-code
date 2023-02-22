//Compiler: GCC

#include <cassert>

int main() {
    // nonstandard: gcc compound literals
    const auto bar = (struct {
        int foo;

        auto operator()(int x) const {
            return foo * x;
        }
    }){12}(3);

    assert(bar == 36);
}