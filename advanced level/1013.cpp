// 1013 Battle Over Cities (25 分)
#include<iostream>
#include<vector>
using namespace std;

bool map[1001][1001]={false};
bool visited[1001];
int N,M,K;

void dfs(int start){
  visited[start]=true;
  for(int i=1;i<=N;i++){
    if(!visited[i]&&map[start][i]){
      dfs(i);
    }
  }
}

int main(){
  cin>>N>>M>>K;
  //the total number of cities, the number of remaining highways, and the number of cities to be checked
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    map[a][b]=true;
    map[b][a]=true;
  }
  for(int i=0;i<K;i++){
    int isolate;
    cin>>isolate;
    fill(visited,visited+1001,false);
    visited[isolate]=true;
    int count=0;
    for(int j=1;j<=N;j++){
      if(!visited[j]){
        dfs(j);
        count++;
      }
    }
    if(i!=0){
      cout<<"\n";
    }
    cout<<count-1;
  }
}