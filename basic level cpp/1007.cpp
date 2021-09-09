#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n;
  int ans=0;
  cin>>n;
  vector<bool>record=vector<bool>(n+1,true);
  for(int i=2;i<n;i++){
    if(record[i]){
      for(int j=i*2;j<=n;j+=i){
        record[j]=false;
      }
    }
  }
  for(int i=2;i<=n-2;i++){
    if(record[i]&&record[i+2]){
      ans++;
    }
  }
  cout<<ans;
}