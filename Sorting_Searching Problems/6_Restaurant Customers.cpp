#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){

    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n;
    cin>>n;
    vector<pair<ll,ll>>customers;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        customers.push_back({a,1});  //arrival time, +1
        customers.push_back({b,-1}); //depature time, -1
    }

    sort(customers.begin(),customers.end());
    ll maxcount = 0;
    ll curcount = 0;
    for(auto& customer:customers){
        curcount += customer.second;
        maxcount = max(maxcount,curcount);
    }
    cout<<maxcount<<endl;
    return 0;
}