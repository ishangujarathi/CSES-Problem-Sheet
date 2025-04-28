#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll compute(multiset<ll>&mst, ll k){
    ll mid = 0;
    auto itr = next(mst.begin(),mst.size() / 2);  //just used to move the iterator to the middle of the multiset
    if(k % 2 == 1){   //if multiset has odd number of elements, middle element is the mid
        mid = *itr;
    }
    else{
        mid = *prev(itr);  //if even number of elements, then the previous element of mid is the mid
    }

    ll mincost = 0;
    for(auto& it:mst){
        mincost += abs(it - mid);
    }
    return mincost;
}
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n,k;
    cin>>n>>k;

    vector<ll>nums(n);
    for(ll i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<ll>mincosts;
    multiset<ll>mst;
    ll left = 0;
    ll right = 0;
    while(right < n){
        mst.insert(nums[right]);
        if(right - left + 1 == k){
            ll cost = compute(mst,k);
            mincosts.push_back(cost);
            mst.erase(mst.find(nums[left]));
            left++;
        }
        right++;
    }

    for(ll& cost:mincosts){
        cout<<cost<<" "<<endl;
    }

    return 0;

}
