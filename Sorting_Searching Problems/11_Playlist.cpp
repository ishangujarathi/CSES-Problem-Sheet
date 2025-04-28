#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n;
    cin>>n;

    vector<ll>songs(n);
    for(ll i=0;i<n;i++){
        cin>>songs[i];
    }


    ll left = 0;
    ll right = 0;
    ll maxlen = 0;
    set<ll>st;

    while(right < n){
        while(st.find(songs[right]) != st.end()){
            st.erase(songs[left]);
            left++;
        }
        st.insert(songs[right]);
        maxlen = max(maxlen,right-left+1);
        right++;
    }
    cout<<maxlen<<endl;
    return 0;
    
}
