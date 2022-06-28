#include <iostream>
#include <assert.h>

int GetPairNumber(int majorColorIndex, int minorColorIndex) {
    return (majorColorIndex * 5 + minorColorIndex + 1);
}

const char* GetMajorColor(int majorColorIndex, int minorColorIndex, const char* majorColor[]) {
    int pairNumber = GetPairNumber(majorColorIndex, minorColorIndex);
    int majorColorFromPairNumber = (pairNumber - 1) / 5;

    return majorColor[majorColorFromPairNumber];
}
const char* GetMinorColor(int majorColorIndex, int minorColorIndex, const char* minorColor[]) {
    int pairNumber = GetPairNumber(majorColorIndex, minorColorIndex);
    int minorColorFromPairNumber = (pairNumber -1) % 5;

    return minorColor[minorColorFromPairNumber];
}
const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };

bool TestPairAligment(int majorNum, int minorNum, const char* majorColorVal, const char* minorColorVal)
{

    if (GetMajorColor(majorNum, minorNum, majorColor) == majorColorVal && GetMinorColor(majorNum, minorNum, minorColor) == minorColorVal)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int printColorMap() {
    
    int i = 0, j = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            std::cout << (i * 5 + j) +1 << " | " << majorColor[i] << " | " << minorColor[j] << "\n";
            if (!(TestPairAligment(i, j, majorColor[i], minorColor[j])))
            {
                break;
            }
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
