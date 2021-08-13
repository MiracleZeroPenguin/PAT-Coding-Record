#include<iostream>
#include<vector>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int>a=vector<int>(5,0);
  vector<int>n=vector<int>(5,0);
  for(int i=0;i<N;i++){
    int input;
    cin>>input;
    switch(input%5){
      case 0: 
        {
          if(input%2==0){
            a[0]+=input;
            n[0]++;
          }
        break;
        }
      case 1: 
        {
          if(n[1]%2==0){
            a[1]+=input;
          }else{
            a[1]-=input;
          }
          n[1]++;
          break;
        }
      case 2: 
        {
          a[2]++;n[2]++;break;
        }
      case 3: 
        {
          a[3]+=input;
          n[3]++;
          break;
        }
      case 4:
        {
          a[4]=input>a[4]?input:a[4];
          n[4]++;
          break;
        }
      default:break;
    }
  }
  for(int i=0;i<5;i++){
    if(i==0){
      if(n[i]==0)cout<<"N";
      else cout<<a[i];
    }
    else if(i==3){
      if(n[i]==0)cout<<" "<<"N";
      else { 
        cout<<" ";
        float ans=a[i]*1.0/n[i];
        printf("%.1f",ans);
      }
    }
    else{
      if(n[i]==0)cout<<" "<<"N";
      else cout<<" "<<a[i];
    }
  }
}