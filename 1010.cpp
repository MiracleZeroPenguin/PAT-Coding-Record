//读题不清导致的修bug
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
int main(){
  string input;
  getline(cin,input);
  stringstream input_str;
  input_str << input;
  vector<int>ans;
  while(!input_str.eof()){
    int a,b;
    input_str>>a>>b;
    if(b!=0){
      ans.push_back(a*b);
      ans.push_back(b-1);
    }
  }
  for(int i=0;i<ans.size();i++){
    if(i==0){
      cout<<ans[i];
    }else{
      cout<<" "<<ans[i];
    }
  }
  if(ans.size()==0){
    cout<<"0 0";
  }

}