#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <list>
using namespace std;

list<int> filter(int input[], int len, int filterSize)
{
    list<int> output;
    int sum;
    for (int i = 0; i < len - (filterSize - 1); i++)
    {
        int j = filterSize;
        sum = 0;
        while (j > 0)
        {
            sum = sum + input[i + (j - 1)];
            j--;
        }
        output.push_back(sum / filterSize);
    }
    return output;
}

void testIfExpectedFilteredArrayLengthIsEqualToFilteredNoiseArrayLength()
{
    int inputArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int inputLen = sizeof(inputArray) / sizeof(inputArray[0]);
    int filterSize = 3;

    list<int> output = filter(inputArray, inputLen, filterSize);

    assert(output.size() == (inputLen - (filterSize - 1)));
}

int main(int argc, char *argv[])
{
    int arrLen = atoi(argv[1]);
    int filterSize = atoi(argv[2]);

    int input[arrLen];

    for (int i = 0; i < arrLen; i++)
    {
        input[i] = rand();
    }

    int len = sizeof(input) / sizeof(input[0]);

    list<int> filteredNoiseArray = filter(input, len, filterSize);

    list<int>::iterator it;
    for (it = filteredNoiseArray.begin(); it != filteredNoiseArray.end(); ++it)
    {
        cout << " " << *it;
    }

    testIfExpectedFilteredArrayLengthIsEqualToFilteredNoiseArrayLength();

    return 0;
}