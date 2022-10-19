#include <iostream>
#include <assert.h>
using namespace std;

int *filter(int input[], int len, int filterSize)
{
    int *output = new int[len];
    int sum;
    for (int i = 0; i < len - 2; i++)
    {
        sum = input[i] + input[i + 1] + input[i + 2];
        output[i] = sum / filterSize;
    }
    return output;
}

int main()
{
    int n, filterSize;
    cout << "Enter size of the array: ";
    cin >> n;
    cout << "Enter filter size: ";
    cin >> filterSize;
    int input[n];

    for (int i = 0; i < n; i++)
    {
        input[i] = rand();
    }

    int len = sizeof(input) / sizeof(input[0]);

    int *filteredNoiseArray = filter(input, len, filterSize);

    for (int i = 0; i < sizeof(filteredNoiseArray); i++)
    {
        cout << filteredNoiseArray[i] << " ";
    }

    assert(sizeof(filteredNoiseArray) == len-2);

    return 0;
}