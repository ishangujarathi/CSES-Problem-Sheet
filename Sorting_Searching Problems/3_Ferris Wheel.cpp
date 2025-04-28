#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,x;
    cin>>n>>x;

    vector<ll>wt(n);
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }

    sort(wt.begin(),wt.end());
    ll left = 0;
    ll right = n-1;
    ll count = 0;
    while(left <= right){
        if(wt[left] + wt[right] <= x){
            count++;
            left++;
            right--;
        }
        else{
            count++;
            right--;
        }
    }
    cout<<count<<endl;
    return 0;
}