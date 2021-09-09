/*
 * @Author: Miracle
 * @LastEditTime: 2021-09-09
 * @Description: 树的前序遍历（preorder: root, left, right）
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

void getPreOrder(node* root,vector<int>& Trans){
  Trans.push_back(root->val);
  if(root->left!=NULL){
    getPreOrder(root->left,Trans);
  }
  if(root->right!=NULL){
    getPreOrder(root->right,Trans);
  }
}

int main(){
  node* root;
  vector<int>trans=vector<int>();
  getPreOrder(root,trans);
  for(int i=0;i<trans.size();i++){
    cout<<trans[i]<<" ";
  }
}