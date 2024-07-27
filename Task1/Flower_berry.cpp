#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


/**
 * largestNumber - find the largest number in an array
 * $numbers - It's the array
 * $num - The length of the array
 * 
 * returns the largest number
 */
int largestNumber(int *numbers, int num)
{
    int largest = numbers[0];

    for(int i = 1; i < num; i++)
    {
        if (largest < numbers[i])
        largest = numbers[i];
    }
    return largest;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int num =0, value = 0;

    cin >> num;
    int numbers[num];

    for (int i = 0; i < num; i++)
    {
        cin >> value;
        numbers[i] = value;
    }
    
    cout << largestNumber(numbers, num) << endl;
    return 0;
}
