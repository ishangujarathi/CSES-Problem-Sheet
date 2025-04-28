#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n,x;
    cin>>n>>x;

    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<ll,ll>mp;
    mp[0] = 1;
    ll prefixsum = 0;
    ll count = 0;
    for(ll num=0;num<n;num++){
        prefixsum += arr[num];
        ll target = prefixsum - x;
        if(mp.find(target) != mp.end()){
            count += mp[target];
        }
        mp[prefixsum]++;
    }

    cout<<count<<endl;  
    return 0;
    
}
