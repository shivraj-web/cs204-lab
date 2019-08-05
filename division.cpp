#include <bits/stdc++.h>
 
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;
using namespace std;

bool isSmaller(string str1, string str2) 
{ 
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
    return true; 
    if (n2 < n1) 
    return false; 
  
    for (int i=0; i<n1; i++) 
    if (str1[i] < str2[i]) 
        return true; 
    else if (str1[i] > str2[i]) 
        return false; 
  
    return true; 
} 

string subtract(string a,string b)
  { 
    if(a==b)
    return "0";
    string ans="";
    int s=0,c=0,ka=a.length()-1,kb=b.length()-1;      // variable c to store carry
    while(ka>=0||kb>=0)                               // string a is bigger than string b so ka >= kb so kb first become zero
    {
        if(ka>=0&&kb>=0)
        {
            s=(a[ka--]-'0')-(b[kb--]-'0')-c;
        }
        else
        if(ka>=0)
        {
            s=(a[ka--]-'0')-c;
        }
        if(s<0)
        {
            s+=10;
            c=1;
        }
        else
           c=0;
        char cc= s+48;                                // to convert integer to character
        ans = cc+ans;
    }
    long k=-1;
    for(int i=0;i<ans.length();i++)
       if(ans[i]=='0')
         k=i;
         else
         break;
     ans.erase(0,k+1);
     return ans;
  }

string multiply(string a,string b)
{   
    string m="";
    lli k=0,kk=0,s=0,c=0;
    lli ans[a.length()+b.length()]={0};
    if(a=="0"||b=="0")
    {
      return "0";
      return 0;
    }
    for(lli i=b.length()-1;i>=0;i--)
    {  
        kk=0;
        c=0;
        for(lli j=a.length()-1;j>=0;j--)
        {
            s=(a[j]-'0')*(b[i]-'0')+ans[k+kk]+c;
            c=s/10;
            s%=10;
            ans[k+kk]=s;
            kk++;
        }
        if(c>0)
        { 
         ans[k+kk]+=c;
         kk++;
        }

        k++;
    }
    lli j=a.length()+b.length()-1;
    while(j>=0&&ans[j]==0)
    j--;
    if(j==-1)
    {
        return "0";
    }
    for(lli i=j;i>=0;i--)
    {
        string cc=to_string(ans[i]);
        m=m+cc;
    }
    return m;
}

vector<string> divide(string a,string b)
{
    string ans="";
    if(isSmaller(a,b))
    {
       return {"0",a};
    }
    string c=b,d="1";
    int i=0;
    while(!isSmaller(a,c))
    {
       c+='0';
       i++;
       d+='0';
    }
    i--;
    string prev;
    d.erase(d.begin()+i+1);
    while(d.length()>0)
    { 
        for(int i=0;i<=10;i++)
        {  
            string f=d;
            f[0]=i+48;
            string p=multiply(b,f);
            if(!isSmaller(p,a))
            {    
                char c=i+47;
                ans=ans+c;
                a=subtract(a,prev);
                break;
            }
            prev=p;
        }
        d.erase(d.begin()+d.length()-1);
    }
    return {ans,a};
}
int main()
{   int t;
    cin>>t;
    while(t--)
    { 
        string a,b;
        cin>>a>>b;
        vector<string> ans=divide(a,b);
        cout<<ans[0]<<"\n"<<ans[1]<<endl;
    }
}
