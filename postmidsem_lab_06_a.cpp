#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mod 1000000007
#define mod1 998244353
#define lli long long int
#define plli pair<lli,lli>
#define REP(i,a,b) for(lli i=a;i<b;i++)
#define REPI(i,a,b) for(lli i=b-1;i>=a;i--)
#define F first
#define S second
#define PB push_back
#define DB pop_back
#define MP make_pair
#define MT make_tuple
#define G(a,b) get<a>(b)
typedef vector<plli> vii;
typedef vector<lli> vi;

int main()
{
    lli n;
    cin>>n;
    set<string> s;
    string p;
    lli flag=0;
    REP(i,0,n)
    {
        cin>>p;
        string q=p;
        reverse(q.begin(),q.end());
        if(q!=p)
        {
           if(s.find(q)!=s.end())
           flag=1; 
           s.insert(p);
        }
    }
    if(flag==1)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl; 
}