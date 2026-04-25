#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, p;
    cin >> s >> p;
    int n = s.size(), m = p.size();
    vector<int> lps(m, 0);
    for (int i = 1; i < m; i++)
    {
        int j = lps[i - 1];
        while (j > 0 && p[i] != p[j])
        {
            j = lps[j - 1];
        }
        if (p[i] == p[j])
        {
            j++;
        }
        lps[i] = j;
    }
    int i = 0, j = 0;
    while (i < n)
    {
        if (s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
        if (j == m)
        {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }
    }
    return 0;
}