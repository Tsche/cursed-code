//Standard: C++23
//Compiler: GCC

#include <vector>
#include <cassert>

template <typename T>
class PleaseHelpPeople {
public:
    constexpr auto operator[]() {
        // nonstandard: GCC compound literals
        // problematic, the returned object is copyable
        return (struct {
            std::vector<T>& vector;
            
            constexpr void operator=(T const& val) && { 
                vector.push_back(val);
            }

            constexpr void operator=(T&& val) && {
                vector.push_back(std::move(val));
            }
        }){vector};
    }

    constexpr auto& operator[](std::size_t idx) { 
        return vector[idx];
    }

    constexpr auto size() const noexcept { 
        return vector.size(); 
    }

private:
    std::vector<T> vector;
};

int main() {
    PleaseHelpPeople<int> php;

    auto a = 3;   
    php[] = a;
    assert(php.size() == 1);
    assert(php[0] == 3);

    php[] = 8;
    assert(php.size() == 2);
    assert(php[1] == 8);

    constexpr auto compile_time = [] consteval {
        PleaseHelpPeople<int> php;
        auto a = 3;   
        php[] = a;
        php[] = 8;
        return php.size();
    }();
    assert(compile_time == 2);
}