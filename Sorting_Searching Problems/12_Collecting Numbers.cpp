#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

   ll n;
   cin>>n;

   vector<ll>arr(n+1);
   vector<ll>position(n+1,0);
   for(ll i=1;i<=n;i++){
       cin>>arr[i];
       position[arr[i]] = i;
   }

   ll rounds = 1;
   for(ll i=2;i<=n;i++){
    if(position[i] < position[i-1]){
        rounds++;
    }
}

   cout<<rounds<<endl;
   return 0;

}
