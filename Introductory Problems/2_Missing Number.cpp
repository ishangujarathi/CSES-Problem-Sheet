#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<int> st;
    
    for (int i = 0; i < n-1; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }

    for (int i = 1; i <= n; i++) {
        if (st.find(i) == st.end()) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
