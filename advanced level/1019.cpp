//1019 General Palindromic Number
#include<iostream>
#include<vector>
using namespace std;

int main(){
  int in,r;
  cin>>in>>r;
  vector<int>e;
  while(in!=0){
    e.push_back(in%r);
    in=in/r;
  }
  int isP=true;
  for(int i=0;i<e.size()/2;i++){
    if(e[i]!=e[e.size()-1-i]){
      isP=false;
      break;
    }
  }
  if(isP)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  for(int i=e.size()-1;i>=0;i--){
    cout<<e[i];
    if(i!=0)cout<<" ";
  }
}