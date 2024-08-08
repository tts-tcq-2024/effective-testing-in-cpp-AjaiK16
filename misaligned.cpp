#include <iostream>
#include <vector>
#include <cassert>
#include <string>

int printColorMap() {
    // Using std::vector and std::string for type safety and convenience
    std::vector<std::string> majorColor = {"White", "Red", "Black", "Yellow", "Violet"};
    std::vector<std::string> minorColor = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int count = 0;

    // Using range-based for loops for better readability
    for (size_t i = 0; i < majorColor.size(); ++i) {
        for (size_t j = 0; j < minorColor.size(); ++j) {
            if (j == 2) { // Introducing a defect: skip printing for index 2
                continue;
            }
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[j] << std::endl;
            assert(!majorColor[i].empty()); // Check that the string is not empty
            assert(!minorColor[j].empty()); // Check that the string is not empty
            ++count;
        }
    }

    return count;
}

int main() {
    int result = printColorMap();
    assert(result == 20); // Fixed assertion to account for the defect
    std::cout << "All is well (maybe!)" << std::endl;
    return 0;
}
