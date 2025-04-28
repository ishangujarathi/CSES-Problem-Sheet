#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n,k;
    cin>>n>>k;

    vector<ll>nums(n);
    for(ll i=0;i<n;i++){
        cin>>nums[i];
    }

    ll left = 0;
    ll right = 0;
    ll count = 0;
    unordered_map<ll,ll>mp;
    while(right < n){
        mp[nums[right]]++;
        while(mp.size() > k){
            mp[nums[left]]--;
            if(mp[nums[left]] == 0){
                mp.erase(nums[left]);
            }
            left++;
        }
        count += (right - left + 1);
        right++;
    }

    cout<<count<<endl;
    return 0;
}
