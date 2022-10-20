#include <iostream>
#include <assert.h>
#include <stdio.h>
using namespace std;

int *filter(int input[], int len, int filterSize)
{
    int *output = new int[len];
    int sum;
    for (int i = 0; i < len - 2; i++)
    {
        int j = filterSize;
        sum = 0;
        while (j > 0)
        {
            sum = sum + input[i + (j - 1)];
            j--;
        }
        output[i] = sum / filterSize;
    }
    return output;
}

void test(int *filteredNoiseArray,int len)
{
    assert(sizeof(filteredNoiseArray) == len - 2);
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

    int *filteredNoiseArray = filter(input, len, filterSize);

    for (int i = 0; i < sizeof(filteredNoiseArray); i++)
    {
        cout << filteredNoiseArray[i] << " ";
    }

    test(filteredNoiseArray, len);

    return 0;
}