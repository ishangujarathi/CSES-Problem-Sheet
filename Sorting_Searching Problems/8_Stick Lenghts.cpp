#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n;
    cin>>n;

    vector<ll>sticks(n); //denotes the length of each stick
    for(ll i=0;i<n;i++){
        cin>>sticks[i];
    }

    sort(sticks.begin(),sticks.end());
    ll mid_idx = n / 2;
    ll len = sticks[mid_idx];
    ll min_cost = 0;

    for(auto& stick:sticks){
        min_cost += abs(stick - len);
    }
    cout<<min_cost<<endl;
}
