#include<bits/stdc++.h>
using namespace std;

vector<int> buildLPS(string pat) {
    int m = pat.size();
    vector<int> lps(m, 0);

    int len = 0;  
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    int n = text.size();
    int m = pattern.size();

    if (m > n) return 0;

    vector<int> lps = buildLPS(pattern);

    int i = 0; 
    int j = 0; 

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << i - j << " ";
            j = lps[j - 1];
        }
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return 0;
}
