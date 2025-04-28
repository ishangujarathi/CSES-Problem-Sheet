#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    multiset<ll>mst;
    for(ll i=0;i<n;i++){
        auto idx = mst.upper_bound(arr[i]);
        if(idx != mst.end()){
            mst.erase(idx);
        }
        mst.insert(arr[i]);
    }

    cout<<mst.size()<<endl;
    return 0;

}
