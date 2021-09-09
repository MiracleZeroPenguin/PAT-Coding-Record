/*
 * @Author: Miracle
 * @LastEditTime: 2021-09-09
 * @Description: 树的中序遍历（inorder: left root right）
 */
#include <bits/stdc++.h>

using namespace std;
struct node{
  struct node *left;
  struct node *right;
  int val;
};

node* newNode(int val){
  node* n=(node*)malloc(sizeof(node));
  n->val=val;
  n->left=NULL;
  n->right=NULL;
  return n;
}

void getInOrder(node* root,vector<int>& Trans){
  if(root->left!=NULL){
    getInOrder(root->left,Trans);
  }
  Trans.push_back(root->val);
  if(root->right!=NULL){
    getInOrder(root->right,Trans);
  }
}

int main(){
  node* root;
  vector<int>trans=vector<int>();
  getInOrder(root,trans);
  for(int i=0;i<trans.size();i++){
    cout<<trans[i]<<" ";
  }
}