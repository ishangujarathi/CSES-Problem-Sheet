#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll>arr(n);  //desired size
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<ll>brr(m);  //actual appartment size
    for(ll i=0;i<m;i++){
        cin>>brr[i];
    }

    ll count = 0;
    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());
    for(int i=0,j=0;i<n && j<m;){
        if(arr[i] - k <= brr[j] && arr[i] + k >= brr[j]){
            count++;
            i++;
            j++;
        }
        else if(arr[i] - k > brr[j]){
            j++;
        }
        else{
            i++;
        }
    }

    cout<<count<<endl;
}