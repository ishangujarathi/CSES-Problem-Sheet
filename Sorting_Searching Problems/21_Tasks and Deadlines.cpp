#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n;
    cin>>n;
    vector<pair<ll,ll>>tasks(n);
    for(ll i=0;i<n;i++){
        ll duration;
        ll deadline;
        cin>>duration>>deadline;
        tasks[i]= {duration,deadline};
    }

    sort(tasks.begin(),tasks.end());
    ll maxReward = 0;
    ll startTime = 0;
    for(auto& it:tasks){
        ll finishTime = startTime + it.first;
        maxReward += it.second - finishTime;
        startTime = finishTime;
    }

    cout<<maxReward<<endl;
    return 0;
}
