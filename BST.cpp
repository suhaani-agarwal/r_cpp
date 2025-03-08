#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *insertIntoBST(node *root, int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }
    if(data>root->data){
        root->right = insertIntoBST(root->right,data);
    }
    else{
        root->left = insertIntoBST(root->left,data);
    }
    return root;
}


void take_input(){
    node *root = NULL;
    int data;
    cin>>data;
    while(data!=-1){
        insertIntoBST(root,data);
        cin>>data;
    }
}

//Search:
//recursive way:
bool searchInBST(node *root, int x){
    if(root==NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }
    if(root->data>x){
        return searchInBST(root->left,x);
    }
    if(root->data<x){
        return searchInBST(root->right,x);
    }
}
//iterative way:
bool searchInBST_i(node *root, int x){
    node * temp = root;
    while(temp!=NULL){
        if(temp->data == x){
            return true;
        }
        if(temp->data>x){
            temp = temp->left;
        }
        if(temp->data<x){
            temp = temp->right;
        }
    }
}


//maxVal in binary tree
node* maxVal(node *root){
    node *temp = root;
    while(temp!=NULL){
        temp = temp->left;
    }
    return temp;
}

//minVal in binary tree
node *minVal(node*root){
    node *temp = root;
    while(temp!=NULL){
        temp = temp->right;
    }
    return temp;
}

//deletion in BST
node *deleteFromBST(node *root, int val){
    if(root == NULL){
        return root;
    }
    if(root->data == val){
        //0 child
        if(root->left == NULL and root->right == NULL){
            delete root;
            return root;
        }
        //1 child
        if(root->left == NULL and root->right!=NULL){
            node *temp = root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL and root->right==NULL){
            node *temp = root->left;
            delete root;
            return temp;

        }
        //2 child
        if(root->right!=NULL and root->left!=NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right,mini);
        }
    }
}

node *BSTfromPreorderSolve(vector<int> &preorder, int mini, int maxi, int &i){
    if(i>=preorder.size()){
        return NULL;
    }
    if(preorder[i]<mini || preorder[i]>maxi){
        return NULL;
    }
    node *root = new node(preorder[i++]);
    root->left = BSTfromPreorderSolve(preorder,mini,root->data,i);
    root->right = BSTfromPreorderSolve(preorder,root->data,maxi,i);

    return root;
}

node *BSTfromPreorder(vector<int> &preorder){
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return BSTfromPreorderSolve(preorder, mini, maxi, i);
}

