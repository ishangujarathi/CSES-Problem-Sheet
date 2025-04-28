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

    ll count = 0;
    ll prefixsum = 0;
    unordered_map<ll,ll>mp;
    mp[0] = 1;

    for(ll i=0;i<n;i++){
        prefixsum += arr[i];
        ll target = prefixsum % n;
        if(target < 0){
            target += n;
        }

        if(mp.find(target) != mp.end()){
            count += mp[target];
        }
        mp[target]++;
    }

    cout<<count<<endl;
    return 0;
}
