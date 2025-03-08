#include <iostream>
#include <queue>
// #include <pair>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};


node *buildTree(node*root){
    int data;
    cout<<"enter data : "<<endl;
    cin>>data;
    root = new node(data);
    if(data==-1){
        return NULL;
    }

    cout<<"enter data to enter at the left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"enter data to enter at the right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}


void printInorder(node *root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void levelOrderPrint(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

    }
}



int height(node *root){
    if(root == NULL){
        return 0;
    }
    int leftsubtree = height(root->left);
    int rightsubtree = height(root->right);
    return (max(leftsubtree,rightsubtree)+1);
}


int diameter(node *root){
    if(root = NULL){
        return 0;
    }
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right) + 1;
    int ans = max(op1 , max(op2,op3));
    return ans;
}


pair<int,int> diameterFast(node *root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second,right.second)+1;

    return ans;

}

bool isBalanced(node *root){
    if(root == NULL){
        return true;
    }
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool difference = height(root->left) - height(root->right) <= 1;

    if(difference && left && right){
        return true;
    }else{
        return false;
    }

}


pair<bool,int> isBalancedFast(node *root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    pair <bool,int> left = isBalancedFast(root->left);
    pair <bool,int> right = isBalancedFast(root->right);

    bool leftans = left.first;
    bool rightans = right.first;

    bool diff = abs( left.second - right.second) <=1;

    pair<bool,int> ans;
    
    ans.second = max(left.second,right.second) + 1;
    if(leftans && rightans && diff){
        ans.first = true;
    }

    return ans;
}

int main(){
    node *root = NULL;
    root = buildTree(root);
    printInorder(root);
    cout<<"level order print is:"<<endl;
    levelOrderPrint(root);
    cout<<(height(root))<<endl;

    cout<<diameter(root)<<endl;

}


