#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define st string
#define sexy ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007

const ll N = 1e6 + 5005;
ll parent[N];
ll size[N];

ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(ll v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
ll m,n;
ll index(ll i,ll j){
    return  i+(j*m);
}

bool compare(pair<ll,ll> x,pair<ll,ll> y){
    if(x.second==y.second){
        return x.first<y.first;
    }else{
        return x.second<y.second;
    }
}

int main(){
    sexy;
    ll x,y,z,p,q,r,k;
    ll a,b,c;
    cin>>m>>n;
    cin>>k;
    vector <pair<ll,ll>> v;
    for(ll i=0;i<k;i++){
        cin>>x>>y;
        v.push_back({x,y});
        make_set(index(x,y));
    }
    sort(v.begin(),v.end());
    for(ll i=0;i<(k-1);i++){
        if(v[i].first==v[i+1].first&&((v[i].second+1)==v[i+1].second)){
            union_sets(index(v[i].first,v[i].second),index(v[i+1].first,v[i+1].second));
        }
    }
    sort(v.begin(),v.end(),compare);
    for(ll i=0;i<(k-1);i++){
        if(((v[i].first+1)==v[i+1].first)&&(v[i].second==v[i+1].second)){
            union_sets(index(v[i].first,v[i].second),index(v[i+1].first,v[i+1].second));
        }
    }
    ll maxi=-1;
    for(ll i=0;i<k;i++){
        ll j=find_set(index(v[i].first,v[i].second));
        maxi=max(maxi,size[j]);
    }
    cout<<maxi<<endl;
    return 0;
}
