#include <cassert>
#include <string>

bool foo(bool) { 
    return true;
}

bool foo(std::string const &) { 
    return false;
}

int main() { 
    assert(foo("oh no"));
}