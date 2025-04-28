#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){

    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    ll maxsum = INT_MIN;
    ll cursum = 0;

    for(ll i=0;i<n;i++){
        cursum += arr[i];
        if(cursum > maxsum){
            maxsum = cursum;
        }

        if(cursum < 0){
            cursum = 0;
        }
    }

    cout<<maxsum<<endl;
    return 0;
}