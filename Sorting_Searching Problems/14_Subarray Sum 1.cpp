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

    ll left = 0;
    ll right = 0;
    ll cursum = 0;
    ll count = 0;
    while(right < n){
        
        cursum += arr[right];
        while(cursum > x){
            cursum -= arr[left];
            left++;
        }

        if(cursum == x){
            count++;
        }

        right++;
    }

    cout<<count<<endl;
    return 0;
    
}
