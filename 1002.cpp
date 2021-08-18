#include<iostream>
using namespace std;
const int max_size=1001;
int main(){
  double ans[max_size]={0};
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int exp;
    float coe;
    cin>>exp>>coe;
    ans[exp]=coe;
  }
  cin>>n;
  for(int i=0;i<n;i++){
    int exp;
    float coe;
    cin>>exp>>coe;
    ans[exp]+=coe;
  }
  int tot=0;
  for(int i=0;i<max_size;i++){
    if(ans[i]!=0)tot++;
  }
  cout<<tot;
  for(int i=max_size-1;i>=0;i--){
    if(ans[i]!=0){
      cout<<" "<<i<<" ";
      printf("%.1f",ans[i]);
    }
  }
}