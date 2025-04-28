#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n;
    cin>>n;
    vector<vector<ll>>customers(n,vector<ll>(3)); //arrival, departure, index
    for(ll i=0;i<n;i++){
        ll arrive, depart;
        cin>>arrive>>depart;
        customers[i] = {arrive, depart, i};
    }

    sort(customers.begin(),customers.end()); //sorting on the basis of arrival time
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq; //departure time, index
    vector<ll>rooms(n);
    ll room_count = 0;
    for(ll i=0;i<n;i++){
        ll arrival = customers[i][0];
        ll departure = customers[i][1];
        ll index = customers[i][2];

        if(!pq.empty() && pq.top().first < arrival){
            ll roomidx = pq.top().second;
            rooms[index] = roomidx; //assigning room number to the customer
            pq.pop();
            pq.push({departure,roomidx});
        }

        else{
            room_count++;
            rooms[index] = room_count;
            pq.push({departure, room_count});
        }
    }

    cout<<room_count<<endl;
    for(auto& room:rooms){
        cout<<room<<" ";
    }
    cout<<endl; 
    return 0;

}
