#include<string>
#include<stack>
#include<iostream>
using namespace std;

string add_fun(string a,string b)
{
	string out = "";
	int c=0;

	stack<int> s1;
	stack<int> s2;
	stack<int> ans;


	if(a.size()>=b.size())
	{
		int n1 = a.size();
		int n2 = b.size();
		for(int i=0;i< n1;i++)
		{
			s1.push(a[i]-'0');
		}
		for(int i = 0; i < n2; ++i)
		{
			s2.push(b[i]-'0');
		}
	}
	else
	{
		int n1 = b.size();
		int n2 = a.size();
		for(int i=0;i<n1;i++)
		{
			s1.push(b[i]-'0');
		}
		for(int i = 0; i <n2; ++i)
		{
			s2.push(a[i]-'0');
		}
	}


	int n1 = s1.size();
	int n2 = s2.size();


	int k;
	while(s2.size()!=0)
	{
		k = s1.top()+s2.top();
		if(c==1)
		{
			k++;
			c=0;
		}
		if(k>9)
			c=1;
		ans.push(k%10);
		s1.pop();s2.pop();
	}
	while(s1.size()!=0)
	{
		k = s1.top();
		if(c==1)
		{
			k++;
			c=0;
		}
		if(k>9)
			c=1;
		ans.push(k%10);
		s1.pop();
	}

	if(c==1)
	{
		ans.push(1);
	}


	while(ans.size()!=0)
	{
		string s(1,'0'+ans.top());
		out.append(s);
		ans.pop();
	}
	return out;

}

string multiply_func(string a,string b)
{
	string out = "";
	int c=0;

	stack<int> s1;
	stack<int> s2;
	stack<int> ans;

	int n1=a.size();
	int n2=b.size();
	string x3="0";	
	for(int i=(n2-1);i>=0;i--)
	{
		int bpart=b[i]-'0';
		stack<int> x1;
		stack<int> x2;
		int carry;
		string result;
		for(int u=(n1-1);u>=0;u--)
		{			
			int apart=a[u]-'0';						
			int rem;			
			if(u==(n1-1))
			{
			rem=(apart*bpart)%10;			
			x1.push(rem);
			carry=(apart*bpart)/10;
			}			
			else
			{
			rem=((apart*bpart)+carry)%10;			
			x1.push(rem);			
			carry=((apart*bpart)+carry)/10;}		
		}
		if(carry!=0)
		{x1.push(carry);}		
		while(x1.size()!=0)
		{
			x2.push(x1.top());
			x1.pop();
		}
		for(int t=(n2-1-i);t>0;t--)
		{
			x2.push(0);
		}
		
		while(x2.size()!=0)
		{
			x1.push(x2.top());
			x2.pop();
		}
				
		while(x1.size()!=0)
		{
			string s(1,'0'+x1.top());
			result.append(s);
			x1.pop();
		}
		
		x3=add_fun(x3,result);
		
	}
return x3;
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
	Output.append(multiply_func(a,b));
	Output.append("\n");
	}
	cout<<Output;
}

		
			
		
	
	


