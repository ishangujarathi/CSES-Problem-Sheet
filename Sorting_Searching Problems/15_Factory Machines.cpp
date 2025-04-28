#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool compute(ll mid, vector<ll>&time, ll t){
    ll total = 0;
    for(auto& it:time){
        total += (mid / it);
        if(total >= t){
            return true;
        }
    }
    return false;

}
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

   ll n,t;
   cin>>n>>t;

   vector<ll>time(n);
   for(ll i=0;i<n;i++){
       cin>>time[i];
   }

   sort(time.begin(),time.end());
   ll min_time = 1e18;
   ll left = 1;
   ll right = 1e18;
   while(left <= right){
    ll mid = left + (right - left) / 2;
    if(compute(mid,time,t)){
        min_time = mid;
        right = mid - 1;
    }
    else{
        left = mid + 1;
    }

   }

   cout<<min_time<<endl;
    
}
