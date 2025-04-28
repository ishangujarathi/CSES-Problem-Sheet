#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n;
    cin>>n;

    vector<ll>books(n);
    for(ll i=0;i<n;i++){
        cin>>books[i];
    }

    ll total_time = accumulate(books.begin(),books.end(),0LL);
    ll maxbooktime = *max_element(books.begin(),books.end());
    cout<<max(total_time, 2 * maxbooktime) << endl;
    return 0;

}
