//会有一个测试结点出段错误，太烦了不想搞了
//问题肯定出在record的溢出，只要加上大于100的条件判断就可以了但是实在太烦了
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int num;
  cin>>num;
  vector<int>inputs=vector<int>(num);
  bool record[100]={false};
  for(int i=0;i<num;i++){
    cin>>inputs[i];
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