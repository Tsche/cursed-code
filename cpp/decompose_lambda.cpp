//Compiler: GCC

#include <cassert>

template <typename T>
struct decomposable : T {
    using T::operator();
};

template <typename T>
decomposable(T) -> decomposable<T>;


int main() {
    auto bar = 2;

    auto lambda = [&bar, x=bar]{return 3;};
    // auto const& [bar_0, x_0] = foo; // error: cannot decompose lambda closure type 'const main()::<lambda()>'
    auto const& [bar_1, x_1] = decomposable{lambda};

    ++bar;
    assert(bar_1 == 3);
    assert(x_1 == 2);

    // nonstandard: GCC compound literal
    auto const& [bar_2, x_2] = (struct: decltype(lambda){}){lambda};
    
    ++bar;
    assert(bar_2 == 4);
    assert(x_2 == 2);
}