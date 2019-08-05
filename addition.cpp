#include <bits/stdc++.h>



using namespace std;


int main()

{
   
 

    int i,m,t;
   
 
 string A,B;
 
 
   cin >> t;
   
 
while(t--){
   
 
 cin >> A;
 

 cin >> B;
 

 int sum=0,
 carry=0 ;
 

 int a = A.size();
 

 int b = B.size();
 

 reverse (A.begin(),A.end());

 
 reverse (B.begin(),B.end());

 
 
 if (a>=b){m=a;}else{m=b;}

 
 int C[(m+1)];
 

 
 if (a>=b){
 
    
    
    A[a]='0';
   
 
  
    for(i=b;i<=a;i++){
 
       
        
        B[i]='0';
  
      
    }
   
 
  
    for (i=0;i<a+1;i++){
   
     
        
        sum = (A[i]-'0')+(B[i]-'0');
    
    
        C[i]=((sum+carry)%10);
    
    
        carry = ((sum+carry)/10);
 
       
    }
    
  
 
    
    for (i=a;i>=0;i--){
   

     
        
       cout << C[i] ;
  
     
    }
  
  
cout << endl ;


 }
 

 else

 
{
  
  
B[b]='0';


for(i=a;i<=b;i++){
 
   
        A[i]='0';
    
    
    }
   
 
    for (i=0;i<=b;i++){
   
     
        
        sum = (A[i]-'0')+(B[i]-'0');
 
       
        C[i]=((sum+carry)%10);
      
  
        
        carry = ((sum+carry)/10);
 
       
    }
   
 
    for (i=b;i>=0;i--){
      
  
        
       cout << C[i] ;
  
     
    }
  
  


cout << endl ;


}










}




	return 0;


}