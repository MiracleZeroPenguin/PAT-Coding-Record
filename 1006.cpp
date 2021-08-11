#include<iostream>
using namespace std;
int main(){
  int num;
  cin>>num;
  int hundred=num/100;
  int ten=(num/10)%10;
  int one=num%10;
  for(int i=0;i<hundred;i++){
    cout<<"B";
  }
  for(int i=0;i<ten;i++){
    cout<<"S";
  }
  for(int i=1;i<=one;i++){
    cout<<i;
  }
}