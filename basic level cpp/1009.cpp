#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
  vector<string>inputs=vector<string>(1);
  string input;
  getline(cin,input);
  int index=0;
  for(int i=0;i<input.size();i++){
    if(input[i]!=' '){
      inputs[index]=inputs[index]+input[i];
    }else{
      index++;
      inputs.push_back("");
    }
  }
  for(int i=inputs.size()-1;i>=0;i--){
    if(i==0){
      cout<<inputs[i];
    }else{
      cout<<inputs[i]<<" ";
    }
  }
}