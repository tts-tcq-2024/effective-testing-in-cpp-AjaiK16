#include <iostream>
#include <cassert>

char size(int cms) {
    char sizeName = '\0';
    if (cms < 38) {
        sizeName = 'S';
    } else if (cms >= 38 && cms <= 42) {  // Fixed the boundary condition
        sizeName = 'M';
    } else if (cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

void testSizeFunction() {
    // Edge cases
    assert(size(37) == 'S');  // Small size boundary
    assert(size(38) == 'M');  // Medium size lower boundary
    assert(size(40) == 'M');  // Medium size middle
    assert(size(42) == 'M');  // Medium size upper boundary
    assert(size(43) == 'L');  // Large size lower boundary
    
    // These tests will fail due to the bugs in the implementation
    assert(size(38) == 'M');
    assert(size(42) == 'M');

    // Tests to ensure invalid conditions are handled (for negative sizes)
    assert(size(-1) == '\0');
    assert(size(0) == 'S');
}

int main() {
    testSizeFunction();
    std::cout << "All is well (maybe!)\n";
    return 0;
}
