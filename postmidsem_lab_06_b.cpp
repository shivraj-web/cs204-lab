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

class hash_chain
{
    public:
     lli m;
     vector<list<string>> v;
      
     hash_chain(lli p)
     {
         m=p;
         v.assign(p,list<string>());
     }

     lli hash_value(string s)
     {
         lli p=33;
         lli value=0;
         lli p_pow=1;
         for(char c: s)
         {
             value = (value + (c-'A'+1)*p_pow)%m;
             p_pow = (p_pow*p)%m;
         }
      return value;
     }
    void insertItem(string x)
         {
             lli p=hash_value(x);
             v[p].push_front(x);
         }

         void deleteItem(string x)
         {
             lli p=hash_value(x);
             list<string>::iterator i;
             for(i=v[p].begin();i!=v[p].end();i++)
             {
                 if(*i==x)
                 {
                     v[p].erase(i);
                     break;
                 }
             }
         }

         bool find(string x)
         {
            lli p=hash_value(x);
            for(auto i: v[p])
                if(i==x)
                    return true;
            return false;
         }

         void display()
         {
             for(int i=0;i<m;i++)
             {
                 if(!v[i].empty())
                 {
                     cout<<i<<" : ";
                     for(auto j:v[i])
                     cout<<j<<" ";
                     cout<<endl;
                 }
             }
         }
};

int main()
{
    lli n;
    cin>>n;
    hash_chain h(n);
    lli flag=0;
    string p;
    REP(i,0,n)
    {
        cin>>p;
        string q=p;
        reverse(q.begin(),q.end());
        if(p!=q)
        {
            if(h.find(q)==1)
            flag=1;
            h.insertItem(p);
        }
    }
    if(flag==0)
    cout<<"NO"<<endl;
    else
    cout<<"YES"<<endl;
   
    
}