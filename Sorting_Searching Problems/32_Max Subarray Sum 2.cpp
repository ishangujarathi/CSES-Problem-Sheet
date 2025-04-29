#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n,a,b;
    cin>>n>>a>>b;

    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    ll maxsum = LLONG_MIN;
    ll cursum = 0;
    ll left = 0;
    ll right = 0;
    while(right < n){
        cursum += arr[right];
        while(right-left+1 > b){
            cursum -= arr[left];
            left++;
        }
        if(right-left+1 >= a){
            maxsum = max(maxsum,cursum);
        }
        right++;
    }

    cout<<maxsum<<endl;
    return 0;
}
