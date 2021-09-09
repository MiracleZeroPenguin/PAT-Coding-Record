// 1011 World Cup Betting
#include<iostream>
#include<cmath>
using namespace std;
int main(){
  double ans=1;
  for(int i=0;i<3;i++){
    double W,T,L,amax;
    cin>>W>>T>>L;
    if(W>max(T,L)){
      cout<<"W"<<" ";
      ans=ans*W;
    }else if(T>max(W,L)){
      cout<<"T"<<" ";
      ans=ans*T;
    }else{
      cout<<"L"<<" ";
      ans=ans*L;
    }
  }
  printf("%.2f",(ans*0.65-1)*2);
}