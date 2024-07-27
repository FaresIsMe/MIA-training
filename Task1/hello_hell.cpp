#include <stdio.h>
#include <iostream> 

/**
 * prototypes
 */
void print_array(int array[3][3]);

using namespace std;


int main()
{
    int number = 0;
    int array[3][3];

    for (int i = 0; i < 3; i++)
    {
        number += 1;

        for (int j = 0; j < 3; j++)
        {
            array[i][j] = number;
        }
    }
    print_array(array);
    return 0;
}
/**
 * it prints 3x3 arrays only LOL
 */

void print_array(int array[3][3])
{
        for (int l = 0; l < 3; l++)
    {
        for (int k = 0; k < 3; k++)
        {
            cout << array[l][k] << " ";
        }
        cout << endl;
    }
}


