#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

int calculateHeight(Node* root){
    if(root == NULL) return 0;

    int lHeiht = calculateHeight(root->left);
    int rHeiht = calculateHeight(root->right);

    return max(lHeiht, rHeiht) + 1;
}

int calDiameter(Node *root){

    if(root==NULL) return 0;

    int lHeight = calculateHeight(root->left);
    int rHeight = calculateHeight(root->right);
    int currDiameter = lHeight + rHeight +1;

    int lDiameter = calDiameter(root->left);
    int rDiameter = calDiameter(root->right);

    return max(currDiameter,max(lDiameter,rDiameter));

}

int calcDiameter(Node *root,int* height){

    if(root == NULL){
        *height = 0;
        return 0;
    }

    int lh=0,rh=0;
    int lDiameter = calcDiameter(root->left,&lh);
    int rDiameter = calcDiameter(root->right,&rh);

    int currDiameter = lh + rh +1;
    *height = max(lh,rh) +1;

    return max(currDiameter, max(lDiameter,rDiameter));
}

void sumReplace(Node* root){

    if(root ==NULL){ return; }

    sumReplace(root->left);
    sumReplace(root->right);

    if(root->left !=NULL){
        root->data += root->left->data;
    }
    if(root->right !=NULL){
        root->data += root->right->data;
    }

}

void preOrder(struct Node* root){

    if(root==NULL) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){

    //      1
    //    /   \
    //   2      3
    //  / \    / \
    // 4   5  6   7

    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // cout<<calDiameter(root)<<endl;
    // cout<<calculateHeight(root)<<endl;

    // int height = 0 ;
    // cout<<calcDiameter(root,&height)<<endl;

    preOrder(root);cout<<endl;
    sumReplace(root);
    preOrder(root);
    return 0;
}