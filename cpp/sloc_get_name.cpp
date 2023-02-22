#include <iostream>
#include <source_location>
#include <string_view>
#include <cassert>

class Name {
public:
    std::string_view const name;

    Name(std::source_location location = std::source_location::current())
        : name(extract(location.function_name())) {}   

private:
    std::string_view extract(std::string_view function) {
        auto pos = function.rfind("(");
        if (pos != std::string_view::npos)
            function.remove_suffix(function.size() - pos);

        pos = function.rfind(" ");
        if (pos != std::string_view::npos) function.remove_prefix(pos + 1);

        pos = function.rfind("::");
        if (pos != std::string_view::npos) function.remove_prefix(pos + 2);
        return function;
    }
};

namespace library {
namespace v1 {
struct test : Name {
    test() {}
    void foo() {
        Name info;
        assert(info.name == "foo");
    }
};
}  // namespace v1
}  // namespace library

template <typename T, class... Args>
class test2 {
   public:
    test2() {}
    template <typename F = test2<T>>
    volatile test2<F>* foo(test2<int> const*& a) const {
        Name info;
        assert(info.name == "foo");
        return nullptr;
    }
    Name member;
};

void foo() {
    Name info;
    assert(info.name == "foo");
}

int main() {
    library::v1::test t;
    assert(t.name == "test");
    t.foo();


    test2<library::v1::test, int> t2;
    test2<int> const* dummy = nullptr;
    assert(t2.member.name == "test2");
    t2.foo(dummy);


    foo();
}