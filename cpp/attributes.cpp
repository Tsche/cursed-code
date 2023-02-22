//Standard: C++20
//Flags (GCC): -Wno-attributes=custom::

#include <source_location>
#include <bit>
#include <cstdint>
#include <cstdio>

struct EvilAttr {
    EvilAttr(std::source_location loc = std::source_location::current()){
        printf("Doing evil stuff in line %d!\n", loc.line());
    }
};

#define evil(name) _]] \
EvilAttr evil_##name{}; \
[[custom::_

[[custom::evil(arbitrary)]] float isqrt(float n){
    auto i = std::bit_cast<uint32_t>(n) >> 1;
    [[custom::evil(y)]] auto y = std::bit_cast<float>(0x5f3759df - i);
    return y * (1.5f - (n * 0.5f * y * y));
}


int main(){
    printf("isqrt(34) = %f\n", isqrt(34.f));
}