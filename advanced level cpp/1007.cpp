// 1007 Maximum Subsequence Sum
// 滑动窗口？老leetcode了
//If all the K numbers are negative, then its maximum sum is defined to be 0, 
//and you are supposed to output the first and the last numbers of the whole sequence.
#include<iostream>
#include<vector>
using namespace std;
int main(){
  int num;
  cin>>num;
  vector<int>input=vector<int>(num);
  bool pos_flag=false;
  for(int i=0;i<num;i++){
    cin>>input[i];
    if(input[i]>=0)pos_flag=true;
  }
  if(!pos_flag){
    printf("0 %d %d\n",input[0],input[num-1]);
    return 0;
  }
  int L=0,R=0,sum=0;
  int maxL=0,maxR=0,maxSum=-1;
  for(int i=0;i<num;i++){
    sum=sum+input[i];
    if(sum<0){
      L=i+1;
      R=i+1;
      sum=0;
    }
    else{
      if(sum>maxSum){
        maxL=L;
        maxR=R;
        maxSum=sum;
      }
      R++;
    }
  }
  printf("%d %d %d",maxSum,input[maxL],input[maxR]);

}