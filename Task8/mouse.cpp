#include <iostream>
#include <memory>
#include <list>
#include <stack>
#include <unordered_map>

using namespace std;


void printList(list<int>& numbers)
{
    for (auto num :numbers)
    {
        cout << num << endl;
    }
    cout << "-----------\n";
}
int main()
{
    unordered_map<int, string> hashMap;

    hashMap[99] = "Ninety-nine";

    for (auto p : hashMap)
    {
        cout << p.first << ": " << p.second << endl;
    }

    return 0;
}