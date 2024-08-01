#include <iostream>
#include <cassert>
#include <string>

std::string getColorPair(int majorIndex, int minorIndex) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    return std::to_string(majorIndex * 5 + minorIndex) + " | " + majorColor[majorIndex] + " | " + minorColor[minorIndex];
}

void printColorMap() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            std::cout << getColorPair(i, j) << "\n";
        }
    }
}

void testColorPair() {
    assert(getColorPair(0, 0) == "0 | White | Blue");
    assert(getColorPair(0, 1) == "1 | White | Orange");
    assert(getColorPair(1, 0) == "5 | Red | Blue");
    assert(getColorPair(2, 4) == "14 | Black | Slate");
    assert(getColorPair(4, 4) == "24 | Violet | Slate");
}

int main() {
    testColorPair();
    printColorMap();
    std::cout << "All is well (maybe!)\n";
    return 0;
}
