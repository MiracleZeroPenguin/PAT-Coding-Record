//有一个节点有问题，19/20
//过几天再来思考
#include<iostream>
#include<vector>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  a=a+b;
  if(a<0){
    cout<<"-";
    a=-a;
  }
  if(a<10000){
    cout<<a;
    return 0;
  }
  vector<char>ans=vector<char>();
  int index=0;
  while(a!=0){
    if(index!=0&&index%3==0){
      ans.push_back(',');
    }
    ans.push_back('0'+a%10);
    index++;
    
    a=a/10;
  }
  for(int i=ans.size()-1; i>=0; i--){
    cout<<ans[i];
  }
}