#include <cassert>

int main(){
    int array[10];
    
    []{return 3;}()[array] = 4;
    assert(array[3] == 4);

    array[+[]{return 4;}()] = 5;
    assert(array[4] == 5);

    // error: two consecutive '[' shall only introduce an attribute before '[' token
    //array[[]{return 5;}()] = 6;
}