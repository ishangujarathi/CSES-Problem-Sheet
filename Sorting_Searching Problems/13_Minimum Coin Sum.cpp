#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n;
    cin>>n;

    vector<ll>coins(n);
    for(ll i=0;i<n;i++){
        cin>>coins[i];
    }

    sort(coins.begin(),coins.end());

    ll sum = 1;
    for(ll i=0;i<n;i++){
        if(coins[i] > sum){
            break;
        }
        sum += coins[i];
    }

    cout<<sum<<endl;
    return 0;
    
}
