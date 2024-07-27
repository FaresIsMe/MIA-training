#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


/**

 */
string WhoIsWinning(int heros[100][100], int villains[100][100], int row, int col)
{
    int heroScore = 0;
    int villainScore = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (heros[i][j] > villains[i][j])
            heroScore++;
            else if (heros[i][j] < villains[i][j])
            villainScore++;
        }
    }

    if (heroScore > villainScore)
    return "Justice League";
    else if (villainScore > heroScore)
    return "Villains";
    else return "Tie";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int row, col, value, i, j;

    cin >> row >> col;
    int heros[100][100];
    int villains[100][100];

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cin >> value;
            heros[i][j] = value;
        }
    }
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cin >> value;
            villains[i][j] = value;
        }
    }
    //cout << heros[1][2] << "<<<--Heros ||| Villains:-->>> " <<villains[1][2] << endl;

    cout << WhoIsWinning(heros, villains, row, col) << endl;
    return 0;
}