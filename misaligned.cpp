#include <iostream>
#include <sstream>
#include <cassert>
#include <string>

std::string getColorPair(int majorIndex, int minorIndex) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    return std::to_string(majorIndex * 5 + minorIndex) + " | " + majorColor[majorIndex] + " | " + minorColor[minorIndex];
}

void printColorMap(std::ostream& os) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            os << getColorPair(i, j) << "\n";
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

void testPrintColorMap() {
    // Capture the output
    std::ostringstream actualOutputStream;
    printColorMap(actualOutputStream);
    std::string actualOutput = actualOutputStream.str();

    // Generate the expected output programmatically
    std::ostringstream expectedOutputStream;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            expectedOutputStream << getColorPair(i, j) << "\n";
        }
    }
    std::string expectedOutput = expectedOutputStream.str();

    // Compare outputs
    assert(actualOutput == expectedOutput);
}

int main() {
    testColorPair();
    testPrintColorMap();
    printColorMap(std::cout);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
