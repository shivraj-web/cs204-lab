
#include<string>
#include<stack>
#include<iostream>
using namespace std;


string subtract_fun(string a,string b)
{

	if(a=="0"&&b.length()==1){return "Error : The output is not a Natural Number.";} 	
	string out = "";
	int c=0;

	stack<int> s1;
	stack<int> s2;
	stack<int> ans;


	int n1 = a.size();
	int n2 = b.size();


	for(int i=0;i< n1;i++)
	{
		if(s1.size()!=0 || a[i]!='0') s1.push(a[i]-'0');
	}
	for(int i = 0; i < n2; ++i)
	{
    if(s2.size()!=0 || b[i]!='0') s2.push(b[i]-'0');
	}


	int k;
	while(s2.size()!=0)
	{
		k = s1.top()-s2.top();
		if(c==1)
		{
			k--;
			c=0;
		}
		if(k<0)
    {
      c=1;
      k+=10;
    }
		ans.push(k);
		s1.pop();s2.pop();
	}
	while(s1.size()!=0)
	{
		k = s1.top();
		if(c==1)
		{
			k--;
			c=0;
		}
    if(k<0)
    {
      c=1;
      k+=10;
    }

		ans.push(k);
		s1.pop();
	}
  while((ans.top()==0)&&(ans.size()!=1)){ans.pop();}


	if(c==1)
	{
    return "Error : The output is not a Natural Number.";
	}


	while(ans.size()!=0)
	{
		string s(1,'0'+ans.top());
		out.append(s);
		ans.pop();
	}
  
  if (out=="") return "0";
  else return out;

}



int main()
{
	string a,b;
	int T;
	cin>>T;
	string Output="";
	for(int z=0;z<T;z++)	
	{	
	cin>>a;
	cin>>b;
	if(a.length()<b.length()){Output.append("Error : The output is not a Natural Number.");Output.append("\n");}
	else	
	{	
	Output.append(subtract_fun(a,b));
	Output.append("\n");
	}
	}
	cout<<Output;
	
}
