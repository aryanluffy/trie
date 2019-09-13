// Do not initialize root with NULL
#include <bits/stdc++.h>
#define lli long long int
#define pb push_back
#define mod 1000000007
#pragma GCC optimize ("-O2")
#define mod2 998244353
#define MAXN 1000000000
#define v32 vector<int>
#define v64 vector<lli>
#define v1024 vector <vector <int>>
#define v4096 vector <vector <lli>>
#define vt vector
#define f(x, y, z) for (lli x = y; x < z; x++)
#define fd(x, y, z) for (lli x = y; x > z; x--)
#define lb lower_bound
#define ld long double
#define m64 map<lli,lli>
#define m32 map<int,int>
#define m64it map<lli,lli>::iterator
#define m32it map<int,int>::iterator
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ist insert
#define endl "\n"
#include <ext/pb_ds/assoc_container.hpp>
#define p_q priority_queue 
#define min_p_q priority_queue <int,vt <int>,greater <int>>
using namespace std;
using namespace __gnu_pbds; 
struct node{
  node* arr[26]={NULL};
  bool is_end_of_word=false;
};
void insert(node* root,string val){
   int i=0;
   node* traverse=root;
   while(i!=val.size()){
      
      if(traverse->arr[val[i]-'a']==NULL){
        f(j,i,val.size()){
          if(j!=val.size()-1)
          {
            traverse->arr[val[j]-'a']=new node;
            traverse=traverse->arr[val[j]-'a'];
          }
          else {
            traverse->arr[val[j]-'a']=new node;
            traverse=traverse->arr[val[j]-'a'];
            traverse->is_end_of_word=true;
          }
        }
        break;
      }
      else traverse=traverse->arr[val[i]-'a'];
      i++;
   }
}
bool search(node* root,string val){
   int i=0;
   node* traverse=root;
   while(i!=val.size()){
      
      if(traverse->arr[val[i]-'a']==NULL){
        return false;
      }
      else traverse=traverse->arr[val[i]-'a'];
      i++;
   }
   return traverse->is_end_of_word;
   
}
int main() 
{  
  //fastio;
  node* root=new node;
  int n;cin>>n;
  f(i,0,n){
    string s;cin>>s;
    insert(root,s);
  }
  while (1)
  {
    string temp;cin>>temp;
    if(search(root,temp)==1)cout<<"present\n";
    else cout<<"not present\n";
  }
  
  return 0; 	
}
