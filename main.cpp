// refactor: 1014
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
struct window{
  int windowID;
  int endTime;
  deque<int>waiting=deque<int>();//waiting中的人出队的时间
};

bool cmp(struct window w1,struct window w2){
  if(w1.endTime<w2.endTime){
    return true;
  }
  if(w1.endTime==w2.endTime&&w1.windowID<w2.windowID){
    return true;
  }
  return false;
}

int main(){
  //  N (≤20, number of windows)
  //  M (≤10, the maximum capacity of each line inside the yellow line)
  //  K (≤1000, number of customers)
  //  Q (≤1000, number of customer queries)
  int N,M,K,Q;
  cin>>N>>M>>K>>Q;
  vector<int>cost=vector<int>(K);
  vector<int>time=vector<int>(K);
  struct window windows[21];
  for(int i=0;i<K;i++){
    cin>>cost[i];
  }
  for(int i=0;i<N;i++){
    windows[i].windowID=i;
    windows[i].endTime=0;
  }
  int customer=0;
  for(customer;customer<N*M&&customer<K;customer++){
    if(windows[customer%N].waiting.size()==0){
      windows[customer%N].waiting.push_back(cost[customer]);
      time[customer]=cost[customer];
    }else{
      windows[customer%N].waiting.push_back(windows[customer%N].waiting[0]+cost[customer]);
      time[customer]=windows[customer%N].waiting[0]+cost[customer];
    }
  }
  M=M-1;
  while(customer<K){
    sort(windows,windows+N,cmp);
    windows[0].endTime=windows[0].waiting[0];
    windows[0].waiting.pop_front();
    if(windows[0].waiting.size()==0){
      time[customer]=windows[0].endTime+cost[customer];
      windows[0].waiting.push_back(time[customer]);
    }else{
      time[customer]=windows[0].waiting[windows[0].waiting.size()-1]+cost[customer];
      windows[0].waiting.push_back(time[customer]);
    }
    customer++;
  }
  for(int i=0;i<Q;i++){
    int target;
    cin>>target;
    if(i!=0)cout<<endl;
    if(time[target]-cost[target]>=450){
      cout<<"Sorry";
    }else{
      printf("%02d:%02d",8+time[target]/60,time[target]%60);
    }
  }
}