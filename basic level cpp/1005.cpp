//会有一个测试结点出段错误，太烦了不想搞了
//用map记录之后，多了一个正确的节点，但还是有一个边界测试过不了
//太烦了，实在想不出来了
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(){
  int num;
  cin>>num;
  vector<int>inputs=vector<int>(num);
  // bool record[100]={false};
  map<int,bool>record;
  for(int i=0;i<num;i++){
    cin>>inputs[i];
    record[inputs[i]]=false;    
  }
  for(int i=0;i<num;i++){
    int input=inputs[i];
    if(record[input]==false){
      while(input!=1){
        if(input%2==0){
          input=input/2;
          if(record[input]==true){
            break;
          }
          record[input]=true;
        }else{
          input=(input*3+1)/2;
          if(record[input]==true){
            break;
          }
          record[input]=true;
        }
      }
    }
  }
  sort(inputs.begin(),inputs.end());
  bool flag=false;
  for(int i=num-1;i>0;i--){
    if(record[inputs[i]]==false){
      if(!flag){
        flag=true;
        cout<<inputs[i];
      }
      else{
        cout<<" "<<inputs[i];
      }
    }
  }

}