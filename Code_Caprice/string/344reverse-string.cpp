#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char> &s)
{
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
    {
        s[i] ^= s[j];
        s[j] ^= s[i];
        s[i] ^= s[j];
    }
}

int main()
{
    vector<char> xx = {'a', 'l', 'e', 'x'};
    reverseString(xx);
    for (char i : xx)
    {
        std::cout << i << " ";
    }
}