#include<iostream>
#include<cmath>
using namespace std;
//Creating a structure named point so that the x-coordinate and y-coordinate are together
struct point
{
  int a;//X-Coordinate
  int b;//Y-Coordinate
};
//Creating a struct named node for creation of a linked list
struct node
{
  struct point pt;
  struct node* ptr;
};
//Creating a class named Linked_List from implementing Linked List
class Linked_List
{
public:
    struct node* head;
  Linked_List()
  {
    head=NULL;
  }
  //This function adds a  point containing ‘x’ as x-coordinate and ‘y’  as y-coordinate 
  // at the start of the linked list
  void AddFirst(int x,int y)
  {
    struct point P;
    P.a= x   ;  P.b= y;
    struct node* next =new node;
    struct node* tmp;
    next->pt=P;
    tmp=head;
    head=next;
    next->ptr=tmp;
  }
// This function deletes the first element in the linked list.
// If it is not in the list or list is empty, print -1
  void DelFirst()
  { int c=-1;
    if(head==NULL) cout<<c<<endl;
    else
    {
      struct node* tmp;
      tmp=head->ptr;
      head=tmp;
      free(tmp);
      delete(tmp);
    }
  }
//   This function deletes the node with point containing ‘a’ as x-coordinate and ‘b’ as y-coordinate.
// If it is not in the list or list is empty,  print -1
  void Del(int x,int y)
  {
    struct node* next;
    struct node* prev;
    int count=-1;
    if(head==NULL){count==-1;}
    else{next=head;
    	prev=NULL;
    while(next!=NULL)
    {
    			if( (next->pt.a==x)&&(next->pt.b==y)&&prev!=NULL )
    			{
    				prev->ptr=next->ptr
    		;
    				free(next);delete(next);
            count++;

    				break;
    			}
    			else if((next->pt.a==x)&&(next->pt.b==y)&&prev==NULL)
    			{
    				struct node* tmp;
    				tmp=head->ptr;
    				head=tmp;
    				free(tmp);
    				delete(tmp);
            count++;
            break;
    			}
    			else{
    				prev=next;
    				next=next->ptr;}
    }}

if(count==-1)cout<<count<<endl;
  }
 //This function finds the distance of a point p from ORIGIN
float  Distance(struct point p)
  {
    int x,y;
    x=p.a;
    y=p.b;
    float d=sqrt(x*x+y*y);
    return d;
  }
 //  This function gives all the points that are present at atmost ‘d’ distance (Euclidean)
// from  the origin.
// If such points exist, print the number of such points.
// Else print  -1 
int Search(float d)
{ int x,y,count=0;
  struct node* next;
  if(head==NULL){cout<<"No Linked List";}
  else
  {next=head;
  while(next!=NULL)
  {
  x=next->pt.a;y=next->pt.b;
  if(  Distance(next->pt)<=d){
count++;
  next=next->ptr;
  }
else{next=next->ptr;}

}}
if(count==0)count=-1;
return count;
}
//  This function prints True
// if there exists a point with ‘a’ as x-coordinate and ‘b’ as y-coordinate in the linked list.
// Else it prints False
 bool Search(int x,int y)
  { int count=0;
    struct node* next;
    ;
  if(head==NULL){return -1;}
next=head;
  while(next!=NULL)
  {
  if( (next->pt.a==x)&&(next->pt.b==y) )
      {
          count=count+1;
          next=next->ptr;

      }
        else{  next=next->ptr;}
}
if(count==0)return false;
else return true;}
//This function prints the length of the linked list
  int Length()
  {
    int count=0;
      struct node* next;
          if(head==NULL){return 0;}
      next=head;
      while(next!=NULL)
      {
        count++;
next=next->ptr;

     }
    return count;
  }
};
//MAIN FUNCTION
int main()
{
  int T;
  Linked_List list;
  //INPUTS THE NUMBER OF TEST CASES TO BE VERIFIED
  cin>>T;
  while(T--)
  { int f;
    cin>>f;
    if(f==1)
    { int a,b;
      cin>>a>>b;
      list.AddFirst(a,b);
    }
    if(f==2)
    {
  list.DelFirst();
    }
    if(f==3)
    { int p,q;
      cin>>p>>q;
    list.Del(p,q);
    }
    if(f==4)
    { int e;
      cin>>e;
      cout<<list.Search(e)<<endl;
    }
    if(f==5)
    {
      int p,q;
        cin>>p>>q;
        if(list.Search(p,q)==true)cout<<"True"<<endl;
        if(list.Search(p,q)==false)cout<<"False"<<endl;
    }
    if(f==6)
    {
      cout<<list.Length()<<endl;
    }
  }
return 0;
}
