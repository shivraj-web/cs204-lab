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

int main(){
    sexy;
    ll x,y,z,p,q,r,k;
    ll a,b,c;
    cin>>m>>n>>c;
    ll ar[m+1][n+1];
    memset(ar, -1LL, sizeof(a));
    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=n;j++){
            cin>>k;
            ar[i][j]=k;
            make_set(index(i,j));
        }
    }
    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=n;j++){
            if(ar[i][j]==ar[i-1][j]){
                union_sets(index(i,j),index(i-1,j));
            }
            if(ar[i][j]==ar[i][j-1]){
                union_sets(index(i,j),index(i,j-1));
            }
        }
    }
    ll maxi=-1,color=-1;
    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=n;j++){
            ll f=find_set(index(i,j));
            if(size[f]>maxi){
                maxi=size[f];
                color=ar[i][j];
            }
        }
    }
    cout<<maxi<<" "<<color<<endl;
    return 0;
}
