#include <iostream>
#include <cassert>

char determineSize(int cms) {
    if(cms < 38) {
        return 'S';
    } else if(cms > 38 && cms < 42) {
        return 'M';
    } else {
        return 'L';
    }
}

void testDetermineSize() {
    assert(determineSize(37) == 'S');
    assert(determineSize(38) == 'M'); 
    assert(determineSize(40) == 'M');
    assert(determineSize(42) == 'L');  
    assert(determineSize(43) == 'L');
}

int main() {
    testDetermineSize();
    std::cout << "All is well (maybe!)\n";
    return 0;
}
