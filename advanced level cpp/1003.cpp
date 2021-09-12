//图论
//非常麻烦的Dijkstra
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N, M, c1, c2;
  int map[501][501], weight[501], dis[501], num[501], w[501];
  bool visit[501];
  const int inf = 99999999;
  scanf("%d%d%d%d", &N, &M, &c1, &c2);
  for(int i = 0; i < N; i++)
      scanf("%d", &weight[i]);
  fill(map[0], map[0] + 501 * 501, inf);
  fill(dis, dis + 501, inf);
  int a, b, c;
  for(int i = 0; i < M; i++) {
      scanf("%d%d%d", &a, &b, &c);
      map[a][b] = map[b][a] = c;
  }
  dis[c1] = 0;
  w[c1] = weight[c1];
  num[c1] = 1;
  for(int i = 0; i < N; i++) {
      int u = -1, minn = inf;
      for(int j = 0; j < N; j++) {
          if(visit[j] == false && dis[j] < minn) {
              u = j;
              minn = dis[j];
          }
      }
      if(u == -1) break;
      visit[u] = true;
      for(int v = 0; v < N; v++) {
          if(visit[v] == false && map[u][v] != inf) {
              if(dis[u] + map[u][v] < dis[v]) {
                  dis[v] = dis[u] + map[u][v];
                  num[v] = num[u];
                  w[v] = w[u] + weight[v];
              } else if(dis[u] + map[u][v] == dis[v]) {
                  num[v] = num[v] + num[u];
                  if(w[u] + weight[v] > w[v])
                      w[v] = w[u] + weight[v];
              }
          }
      }
  }
  printf("%d %d", num[c2], w[c2]);
  return 0;
}