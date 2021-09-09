// 1008 Elevator
#include<iostream>
using namespace std;
int main(){
  int num;
  cin>>num;
  int pre_floor=0,next_floor;
  int tot=0;
  for(int i=0;i<num;i++){
    cin>>next_floor;
    if(next_floor>pre_floor){
      tot+=6*(next_floor-pre_floor)+5;
    }else{
      tot+=4*(pre_floor-next_floor)+5;
    }
    pre_floor=next_floor;
  }
  cout<<tot;
}