#include <bits/stdc++.h>
#include <math.h>
 
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define enl "\n"
#define INF std::numeric_limits<ll>::max()
#define F first
#define S second
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ldb;
typedef vector<long long> vll;
typedef pair<long long,long long> pll;
 
ll greatestSubarraySum(ll array[], ll n);
ll powerrr(ll a, ll b);
void swapp(ll *a, ll*b);
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);
ll min(ll a, ll b);
ll max(ll a, ll b);
ll search(ll arr[], ll n, ll k);
string findSum(string str1, string str2);
 
 
 
 
 
 
string findSum(string str1, string str2) 
{ 
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) {
        string s = str1;
        str1=str2;
        str2=s;
    }
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        // Calculate carry for next step 
        carry = sum/10; 
    } 
  
    // Add remaining digits of larger number 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 
 
 
 
ll search(ll arr[], ll n, ll k){
    
    ll u = k;
    ll l = 0;
 
    
    while(u>=l){
        
        if(arr[(u+l)/2] == n){
            
            return (u+l)/2;
            
        } else if(arr[(u+l)/2] > n){
            
            u = (u+l)/2 - 1;
            
        } else {
            
            l = (u+l)/2 + 1;
            
        }
        
        
    }
    
    return -1;
    
    
}
 
ll greatestSubarraySum(ll array[], ll n){
 
    ll best = 0, sum = 0;
    for (ll k = 0; k < n; k++) {
        sum = max(array[k],sum+array[k]);
        best = max(best,sum);
    }
 
    return best;
}
 
ll powerrr(ll a, ll b){
 
    ll ans = 1;
 
    for(ll i = 0; i < b; i++){
 
 
        ans*= a;
 
 
    }
 
    return ans;
 
 
}
 
void swapp(ll *a, ll*b){
 
    ll temp = *a;
    *a = *b;
    *b = temp;
 
 
}
 
 
 
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    
    return gcd(b%a, a);
}
 
ll lcm(ll a, ll b)  
{  
    return (a*b)/gcd(a, b);  
} 
 
ll min(ll a, ll b){
    if(a < b)return a;  
    return b;
}
 
ll max(ll a, ll b){
    if(a > b)return a;
    return b;
}

set<char> signs;

ll flagl;

stack<char> brac;

struct node{

    char a;
    ll b;
    struct node *left;
    struct node *right;


};

struct node *createNode(){

    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->a='n';
    temp->b=-1928;

    return temp;

}

ll evaluate(struct node *start){

    if(start->a != 'n'){

        if(start->a == '^'){

            return powerrr(evaluate(start->left), evaluate(start->right));

        } else if(start->a == '*'){

            return evaluate(start->left)*evaluate(start->right);

        } else if(start->a == '/'){


            return evaluate(start->left)/evaluate(start->right);


        } else if(start->a=='+'){

            return evaluate(start->left)+evaluate(start->right);

        } else {

            return evaluate(start->left)-evaluate(start->right);

        }

    } else {

        return start->b;

    }


}

void build(string s, struct node *start){

    REP(i,0,s.length()){

        if(signs.find(s[i]) == signs.end()){

            flagl=1;
            return;

        }

    }

    if(s[0]=='-'){

        start->b=stoll(s);

        return;


    }

    for(ll i=s.length()-1; i>=0; i--){

        //cout<<'a'<<endl;

        if(signs.find(s[i]) == signs.end()){

            flagl=1;
            return;

        }

        if(s[i] == ')')brac.push(s[i]);
        if(s[i] == '(')brac.pop();

        if(!(brac.empty()))continue;

        if(s[i]=='+' || s[i]=='-'){

            //cout<<i<<"tatd"<<endl;

            start->a=s[i];
            string b=s.substr(0,i);
            string c=s.substr(i+1, s.length()-1-i);

            //cout<<"a"<<b<<" "<<c<<endl;

            start->left=createNode();
            start->right=createNode();
            build(b, start->left);
            build(c, start->right);

            return;

        }


    }

    for(ll i=s.length()-1; i>=0; i--){

        //cout<<'b'<<endl;

        if(signs.find(s[i]) == signs.end()){

            flagl=1;
            return;

        }

        if(s[i] == ')')brac.push(s[i]);
        if(s[i] == '(')brac.pop();

        if(!(brac.empty()))continue;

        if(s[i]=='*' || s[i]=='/'){

            


            start->a=s[i];
            string b=s.substr(0,i);
            string c=s.substr(i+1, s.length()-1-i);

            //cout<<"b"<<b<<" "<<c<<endl;


            start->left=createNode();
            start->right=createNode();
            build(b, start->left);
            build(c, start->right);

            return;

        }


    }

    REP(i,0,s.length()){

        //cout<<'c'<<endl;

        if(signs.find(s[i]) == signs.end()){

            flagl=1;
            return;

        }

        if(s[i] == '(')brac.push(s[i]);
        if(s[i] == ')')brac.pop();

        if(!(brac.empty()))continue;

        if(s[i]=='^'){

            start->a='^';
            string b=s.substr(0,i);
            string c=s.substr(i+1, s.length()-1-i);

            //cout<<"c"<<b<<" "<<c<<endl;


            start->left=createNode();
            start->right=createNode();
            build(b, start->left);
            build(c, start->right);

            return;

        }

    }

    REP(i,0,s.length()){

        //cout<<'d'<<endl;

        if(signs.find(s[i]) == signs.end()){

            flagl=1;
            return;

        }

        if(s[i]=='('){

            stack<char> flag;
            flag.push('(');

            REP(j, i+1, s.length()){

                if(s[j]=='(')flag.push('(');

                if(s[j]==')'){

                    flag.pop();
                    

                }

                if(flag.empty()){
                    string b=s.substr(i+1, j-1-i);

                    //cout<<'d'<<" "<<b<<endl;

                    build(b, start);
                    return;
                }

            }



        }

    }

    start->b=stoll(s);



}


int main(){
 
    io
 
    signs.insert('^');
    signs.insert('+');
    signs.insert('*');
    signs.insert('-');
    signs.insert('/');
    signs.insert('(');
    signs.insert(')');
    signs.insert('0');
    signs.insert('1');
    signs.insert('2');
    signs.insert('3');
    signs.insert('4');
    signs.insert('5');
    signs.insert('6');
    signs.insert('7');
    signs.insert('8');
    signs.insert('9');



    ll n;
    cin>>n;

    while(n--){

        ll q;
        cin>>q;

        while(q--){
            flagl=0;

            string s;
            cin>>s;
            struct node *start=createNode();

            build(s, start);
            ll x=evaluate(start);
            if(flagl)cout<<"CANT BE EVALUATED"<<endl;
            else cout<<x<<endl;
        }
    }

  
}
