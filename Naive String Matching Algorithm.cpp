#include <bits/stdc++.h>
using namespace std;

// Naive String Matching Algorithm

int main() {
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++) {
        int j;

        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }

        if (j == m)
            cout << "Pattern found at index " << i << endl;
    }

    return 0;
}
