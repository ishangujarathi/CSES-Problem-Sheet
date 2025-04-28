#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n;
    cin>>n;

    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    stack<pair<ll,ll>>st;
    vector<ll>ans;
    for(ll i=0;i<n;i++){
        if(st.empty()){
            ans.push_back(0);
        }
        else if(!st.empty() && st.top().first < arr[i]){
            ans.push_back(st.top().second + 1);
        }

        else if(!st.empty() && st.top().first >= arr[i]){
            while(!st.empty() && st.top().first >= arr[i]){
                st.pop();
            }

            if(st.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(st.top().second + 1);
            }
        }

        st.push({arr[i],i});
    }

    for(ll i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
