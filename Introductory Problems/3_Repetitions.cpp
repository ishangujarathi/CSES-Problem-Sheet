#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    long long cur_len = 1;
    long long max_len = 1;

    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            cur_len++;
        } else {
            cur_len = 1;
        }

        max_len = max(max_len, cur_len);
    }

    cout << max_len << endl;
    return 0;
}
