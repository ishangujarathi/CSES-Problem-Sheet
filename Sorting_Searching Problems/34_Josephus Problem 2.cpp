#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n,k;
    cin>>n>>k;

    deque<ll>dq;
    for(ll i=1;i<=n;i++){
        dq.push_back(i);
    }

    vector<ll>sequence;
    while(!dq.empty()){
        for(ll i=1;i<=k;i++){
            dq.push_back(dq.front());
            dq.pop_front();
        }
        sequence.push_back(dq.front());
        dq.pop_front();
    }

    for(auto& seq:sequence){
        cout<<seq<<" ";
    }
    cout<<endl;
    return 0;   
}
