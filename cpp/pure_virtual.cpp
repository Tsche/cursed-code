#include <cassert>

struct Base {
    virtual ~Base() = default;

    virtual bool foo() = 0;
};

bool Base::foo(){
    return true;
}

struct Derived : Base {
    bool foo() override {
        return Base::foo();
    }
};


int main(){
    auto ohno = Derived{};
    
    assert(ohno.foo());
}