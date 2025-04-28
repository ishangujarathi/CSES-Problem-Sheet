#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){

    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n,x;
    cin>>n>>x;

    vector<int>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    unordered_map<int,int>mp;
    int idx1 = -1;
    int idx2 = -1;

    for(int i=0;i<n;i++){
        if(mp.find(x-arr[i]) != mp.end()){
            idx1 = mp[x-arr[i]];
            idx2 = i;
            break;
        }
        mp[arr[i]] = i;
    }

    if(idx1 == -1 && idx2 == -1){
        cout<<"IMPOSSIBLE"<<endl;
    }

    else{
        cout<<idx1+1<<" "<<idx2+1<<endl;
    }

    return 0;

}