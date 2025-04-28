#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;

    multiset<int>mst;  //stores ticket prices in sorted order and handles duplicates as well
    for(ll i=0;i<n;i++){
        ll price;
        cin>>price;
        mst.insert(price);
    }


    for(ll i=0;i<m;i++){
        ll maxprice;
        cin>>maxprice;

        auto idx = mst.upper_bound(maxprice);  //give first index price greater than maxprice, so we have to go back one index
        if(idx == mst.begin()){
            cout<<-1<<endl;
        }
        else{
            idx--;
            cout<<*idx<<endl;
            mst.erase(idx);  //remove the price of ticket from the multiset
        }
    }
    return 0;
}
