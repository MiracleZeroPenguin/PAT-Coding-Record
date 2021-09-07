//1014 Waiting in Line (30 分)
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

struct node{
  int windowID;
  int firstTime;
};

bool cmp(struct node window1,struct node window2){
  if(window1.firstTime<window2.firstTime){
    return true;
  }
  if(window1.firstTime==window2.firstTime){
    if(window1.windowID==window2.windowID){
      return true;
    }
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
  vector<int>cost=vector<int>(K);//每个顾客所需的时间
  vector<int>time=vector<int>(K);//每个顾客滚蛋的时间
  vector<deque<int> >windows=vector<deque<int> >(N,deque<int>());//每个窗口的等待队伍中，每个人滚蛋的时间
  struct node first[21];//每个窗口第一个客户滚蛋的时间
  for(int i=0;i<K;i++){
    cin>>cost[i];
  }
  int customer;
  M--;
  for(customer=0;customer<N&&customer<K;customer++){
    struct node temp;
    temp.firstTime=cost[customer];
    temp.windowID=customer;
    first[customer]=temp;
    time[customer]=cost[customer];
  }
  int j=0;
  for(customer;customer<K;customer++){
    bool insert=false;
    for(j;j<N;j=(j+1)%N){
      if(windows[j].size()<M){
        if(windows[j].size()==0){
          windows[j].push_back(first[j].firstTime+cost[customer]);
          time[customer]=windows[j][windows[j].size()-1];
        }else{
          windows[j].push_back(windows[j][windows[j].size()-1]+cost[customer]);
          time[customer]=windows[j][windows[j].size()-1];
        }
        insert=true;
        j=(j+1)%N;
        break;
      }else{
        if(j==N-1)break;
      }
    }
    if(!insert){
      break;
    }
  }
  for(;customer<K;customer++){
    sort(first,first+N,cmp);
    int targetID=first[0].windowID;
    first[0].firstTime=windows[targetID][0];//等待中的第一个人到窗口
    windows[targetID].pop_front();
    if(windows[targetID].size()==0){
      windows[targetID].push_back(first[0].firstTime+cost[customer]);
      time[customer]=first[0].firstTime+cost[customer];
    }else{
      windows[targetID].push_back(windows[targetID][windows[targetID].size()-1]+cost[customer]);
      time[customer]=windows[targetID][windows[targetID].size()-1];
    }
  }
  for(int i=0;i<Q;i++){
    if(i!=0)cout<<endl;
    int target;
    cin>>target;
    target--;
    //timestamp: time[target]
    //start:08:00
    //如果一个顾客正在被服务，但是银行下班了，那么应该继续为该顾客服务，直到顾客完成需求。
    if(time[target]-cost[target]>=540){
      cout<<"Sorry";
    }else{
      printf("%02d:%02d",time[target]/60+8,time[target]%60);
    }
  }

}