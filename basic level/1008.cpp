#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<int>nums=vector<int>(n);
  for(int i=0;i<n;i++){
    cin>>nums[(i+m)%n];
  }
  for(int i=0;i<n;i++){
    if(i==0)
      cout<<nums[i];
    else
      cout<<" "<<nums[i];
  }

}