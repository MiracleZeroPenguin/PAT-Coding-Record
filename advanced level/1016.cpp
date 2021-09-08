// 1016 Phone Bills
#include<map>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int cost[24];
int dayCost=0;
struct time{
  //MM:dd:HH:mm
  int MM,dd,HH,mm;
};
struct record{
  vector<struct time>on,off;
};
bool cmp(struct time t1,struct time t2){
  if(t1.MM==t2.MM){
    if(t1.dd==t2.dd){
      if(t1.HH==t2.HH){
        return t1.mm<t2.mm;
      }else{
        return t1.HH<t2.HH;
      }
    }else{
      return t1.dd<t2.dd;
    }
  }else{
    return t1.MM<t2.MM;
  }
}

int countMinut(struct time t1,struct time t2){
  int m1,m2;
  m1=t1.dd*24*60+t1.HH*60+t1.mm;
  m2=t2.dd*24*60+t2.HH*60+t2.mm;
  return m2-m1;
}

double countCost(struct time t){
  double ans=0;
  ans=t.dd*dayCost+1.0*cost[t.HH]*t.mm;
  for(int i=0;i<t.HH;i++){
    ans+=60*cost[i];
  }
  return ans;
}

int main(){
  map<string,struct record>persons;
  int month;
  for(int i=0;i<24;i++){
    cin>>cost[i];
    dayCost+=cost[i]*60;
  }
  int num;
  cin>>num;
  for(int i=0;i<num;i++){
    string name;
    struct time tmp;
    cin>>name;
    scanf("%d:%d:%d:%d",&tmp.MM,&tmp.dd,&tmp.HH,&tmp.mm);
    month=tmp.MM;
    string on2off;
    cin>>on2off;
    if(on2off=="on-line"){
      persons[name].on.push_back(tmp);
    }else{
      persons[name].off.push_back(tmp);
    }
  }
  map<string,struct record>::iterator iter;
  //某些用户没有任何一段记录是合法的，则什么都不需要输出！如果不提前特判，那么2和3这两个测试点过不了！
  for(iter=persons.begin();iter!=persons.end();iter++){
    bool infoFlag=true;
    sort(iter->second.on.begin(),iter->second.on.end(),cmp);
    sort(iter->second.off.begin(),iter->second.off.end(),cmp);
    int onIndex=0,offIndex=0;
    int totTime=0;
    double totCost=0;
    struct record r=iter->second;
    while(onIndex<r.on.size()&&offIndex<r.off.size()){
      if(cmp(r.on[onIndex],r.off[offIndex])){
        if((onIndex<r.on.size()-1)&&cmp(r.on[onIndex+1],r.off[offIndex])){
          onIndex++;
          continue;
        }
        if(infoFlag){
          infoFlag=false;
          cout<<iter->first;
          printf(" %02d\n",month);
        }
        printf("%02d:%02d:%02d ",r.on[onIndex].dd,r.on[onIndex].HH,r.on[onIndex].mm);
        printf("%02d:%02d:%02d ",r.off[offIndex].dd,r.off[offIndex].HH,r.off[offIndex].mm);
        int pTime=countMinut(r.on[onIndex],r.off[offIndex]);
        printf("%d ",pTime);
        totTime+=pTime;
        double pCost=(countCost(r.off[offIndex])-countCost(r.on[onIndex]))/100;
        printf("$%.2f\n",pCost);
        totCost+=pCost;
        onIndex++;
        offIndex++;
      }else{
        offIndex++;
      }
    }
    if(!infoFlag)printf("Total amount: $%.2f\n",totCost);
  }
  
}