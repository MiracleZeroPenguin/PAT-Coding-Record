//1018 Public Bike Management
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//Cmax(≤100), always an even number, is the maximum capacity of each station; 
//N (≤500), the total number of stations; 
//Sp, the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); 
//M, the number of roads.
int Cmax,N,Sp,M;

int bikes[502];
int map[502][502];

int dist[502];
bool visited[502];

vector<int> pre[502];
void Dijkstra(){
  fill(visited,visited+502,false);
  for(int i=0;i<=N;i++){
    dist[i]=map[0][i];//初始化
    if(dist[i]!=INT_MAX-1){
      pre[i].push_back(0);
    }
  }
  visited[0]=true;
  int next=0;
  for(int i=1;i<=N;i++){
    int min=INT_MAX;
    for(int j=0;j<=N;j++){
      if(!visited[j]&dist[j]<min){
        min=dist[j];
        next=j;
      }
    }
    visited[next]=true;
    for(int j=0;j<=N;j++){
      if(!visited[j]&&dist[next]+map[next][j]<dist[j]){
        dist[j]=dist[next]+map[next][j];
        pre[j].clear();
        pre[j].push_back(next);
      }else if(!visited[j]&&dist[next]+map[next][j]==dist[j]){
        pre[j].push_back(next);
      }
    }
  }
}

int minsend=INT_MAX-1,minback=INT_MAX;
vector<int>tmppath,path;

void dfs(int root){
  if(root!=0){
    tmppath.push_back(root);
    for(int i=0;i<pre[root].size();i++){
      int x=pre[root][i];
      dfs(x);
    }
    tmppath.pop_back();
    return;
  }else{
    tmppath.push_back(0);
    int minSendTmp=0,minBackTmp=0;
    for(int i=tmppath.size()-2;i>=0;i--){
      int tnode=tmppath[i];
      if(minBackTmp+bikes[tnode]<Cmax/2){
        minSendTmp+=Cmax/2-(minBackTmp+bikes[tnode]);
        minBackTmp=0;
      }else{
        //多了车
        minBackTmp=minBackTmp+bikes[tnode]-Cmax/2;
      }
    }
    if(minSendTmp<minsend){
      minsend=minSendTmp;
      path=tmppath;
    }
    if(minSendTmp==minsend&&minBackTmp<minback){
      minback=minBackTmp;
      path=tmppath;
    }
    tmppath.pop_back();
    return;
  }
}

int main(){
  // fill(map,map+sizeof(map),INT_MAX);
  // memset(map,INT_MAX,sizeof(map));
  fill(map[0],map[0]+502*502,INT_MAX-1);
  cin>>Cmax>>N>>Sp>>M;
  map[0][0]=0;
  for(int i=0;i<N;i++){
    cin>>bikes[i+1];
    map[i+1][i+1]=0;
  }
  for(int i=0;i<M;i++){
    int start,end,cost;
    cin>>start>>end>>cost;
    map[start][end]=cost;
    map[end][start]=cost;
  }
  //0->Sp最短路径
  Dijkstra();
  dfs(Sp);
  cout<<minsend<<" 0";
  for(int i=path.size()-2;i>=0;i--){
    cout<<"->"<<path[i];
  }
  cout<<" "<<minback;
}