#include <bits/stdc++.h>
using namespace std;
#define ll long long

static bool cmp(pair<ll,ll>&a, pair<ll,ll>&b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n;
    cin>>n;

    vector<pair<ll,ll>>movies;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        movies.push_back({a,b});
    }

    sort(movies.begin(),movies.end(),cmp);  //sorting movies based on end time allows us to watch maximum movies
    ll count = 0;
    ll prev_end = 0;  //denotes the end time of previous movie

    for(ll i=0;i<n;i++){
        if(movies[i].first >= prev_end){
            count++;
            prev_end = movies[i].second;
        }
    }

    cout<<count<<endl;
    return 0;
}
