//Author: Steen

#include <iostream>

struct Application {
    
    //GCC specific?
    int definitely_not_main(char* argv[]) __asm__("main");
};

int Application::definitely_not_main(char* argv[]) {
    int argc = reinterpret_cast<std::size_t>(this);

    for (int i = 0; i < argc; ++i)
        std::cout << argv[i] << ' ';
    
    return 0;
}