#include<iostream>
#include<vector>
using namespace std;
string spell[10]={
"zero","one","two","three","four","five","six","seven","eight","nine"
};
int main(){
  string input;
  int ans=0;
  cin>>input;
  for(int i=0;i<input.length();i++){
    ans+=input[i]-'0';
  }
  vector<int>ans_list(0);
  while(ans!=0){
    ans_list.push_back(ans%10);
    ans=ans/10;
  }
  for(int i=ans_list.size()-1;i>=0;i--){
    if(i==ans_list.size()-1){
      cout<<spell[ans_list[i]];
    }else{
      cout<<" "<<spell[ans_list[i]];
    }
  }
  if(ans_list.size()==0)cout<<"zero";//特殊用例：0
}