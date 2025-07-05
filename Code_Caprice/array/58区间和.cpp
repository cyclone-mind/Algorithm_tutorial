#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, a, b;
    cin >> n;
    vector<int> vec(n);
    vector<int> p(n);
    int persum = 0;
    for (int i = 0; i < n; i++)
    {
        // cin >> vec[i];
        scanf_s("%d",&vec[i]);
        persum += vec[i];
        p[i] = persum;
    }
    while (cin >> a >> b)
    {
        int sum;
        if (a == 0)
            sum = p[b];
        else
            sum = p[b] - p[a - 1];
        // cout << sum << endl;
        printf("%d\n",sum);
    }
}