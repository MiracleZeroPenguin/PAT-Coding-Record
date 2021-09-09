/*
 * @Author: Miracle
 * @LastEditTime: 2021-09-09
 * @Description: 树从上到下的层序遍历
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
