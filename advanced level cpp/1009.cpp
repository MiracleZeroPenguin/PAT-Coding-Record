//1009 Product of Polynomials
//我竟然会写结构体了好感动
#include<iostream>
#include<vector>
using namespace std;
struct number{
  int exp;
  double coe;
};
int main(){
  int num1,num2;
  cin>>num1;
  vector<struct number>input1=vector<struct number>(num1);
  for(int i=0;i<num1;i++){
    cin>>input1[i].exp>>input1[i].coe;
  }
  cin>>num2;
  vector<struct number>input2=vector<struct number>(num2);
  for(int i=0;i<num2;i++){
    cin>>input2[i].exp>>input2[i].coe;
  }
  double ans[2001]={0};
  for(int i=0;i<num1;i++){
    for(int j=0;j<num2;j++){
      ans[input1[i].exp+input2[j].exp]+=input1[i].coe*input2[j].coe;
    }
  }
  vector<struct number>tot=vector<struct number>();
  for(int i=2000;i>=0;i--){
    if(ans[i]!=0){
      struct number num_valid;
      num_valid.exp=i;
      num_valid.coe=ans[i];
      tot.push_back(num_valid);
    }
  }
  cout<<tot.size();
  for(int i=0;i<tot.size();i++){
    printf(" %d %.1f",tot[i].exp,tot[i].coe);
  }
}