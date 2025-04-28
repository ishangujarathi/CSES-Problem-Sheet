#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n,x;
    cin>>n>>x;

    if(n < 3){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    vector<pair<ll,ll>>arr(n);  //storing origianl value and it's index
    for(ll i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second = i + 1;
    }

    sort(arr.begin(),arr.end());

    for(ll i=0;i<n-2;i++){
        ll target = x - arr[i].first;
        ll left = i+1;
        ll right = n-1;

        while(left < right){
            ll sum = arr[left].first + arr[right].first;
            if(sum == target){
                cout<<arr[i].second<<" "<<arr[left].second<<" "<<arr[right].second<<endl;
                return 0;
            }
            else if(sum < target){
                left++;
            }
            else{
                right--;
            }
        }
    }

    cout<<"IMPOSSIBLE"<<endl;       
    return 0;

}
