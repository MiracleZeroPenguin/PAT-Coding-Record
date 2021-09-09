#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct person{
  int arrive;
  int process;
};

bool cmpArrive(struct person p1,struct person p2){
  return p1.arrive<p2.arrive;
}

const int beginTime=8*3600;
const int endTime=9*3600;
int main(){
  vector<struct person>queue=vector<struct person>();
  int N,M;
  cin>>N>>M;
  vector<int>windows=vector<int>(M,beginTime);
  for(int i=0;i<N;i++){
    struct person p;
    int HH,MM,SS;
    scanf("%d:%d:%d",&HH,&MM,&SS);
    p.arrive=HH*3600+MM*60+SS;
    scanf("%d",&p.process);
    p.process=p.process*60;
    if(p.arrive-beginTime>endTime){
      continue;//晚于5点的不接待
    }
    queue.push_back(p);
  }
  sort(queue.begin(),queue.end(),cmpArrive);
  int totWaiting=0;
  for(int i=0;i<queue.size();i++){
    sort(windows.begin(),windows.end());
    if(windows[0]<=queue[i].arrive){
      //一到就能被服务,无等待
      windows[0]=queue[i].arrive+queue[i].process;
    }else{
      //需等待
      totWaiting+=windows[0]-queue[i].arrive;
      windows[0]=windows[0]+queue[i].process;
    }
  }
  printf("%.1f",(totWaiting*1.0/queue.size())/60);
}