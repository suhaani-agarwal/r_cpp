#include <iostream>
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

node*buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;

}

int findPositionInorder(int in[], int element, int n) {
    for (int i = 0; i < n; i++) {
        if (in[i] == element) {
            return i;
        }
    }
    return -1;
}

node* findBinTree(int in[], int pre[], int& indexPre, int inorderStart, int inorderEnd, int n) {
    // Base case
    if (indexPre >= n || inorderStart > inorderEnd) {
        return NULL;
    }

    // Pick the current element from preorder
    int element = pre[indexPre++];
    node* root = new node(element);

    // Find the position of this element in inorder array
    int positionInorder = findPositionInorder(in, element, n);

    // Recursive calls to build left and right subtrees
    root->left = findBinTree(in, pre, indexPre, inorderStart, positionInorder - 1, n);
    root->right = findBinTree(in, pre, indexPre, positionInorder + 1, inorderEnd, n);

    return root;
}

void printPost(node* root) {
    if (root == NULL) {
        return;
    }
    printPost(root->left);
    printPost(root->right);
    cout << root->data << " ";
}

node * lowestCommonAncestor(node * root, int a, int b){
    if(root == NULL){
        return NULL;
    }
    if(root->data == a or root->data == b){
        return root;
    }
    node *leftans = lowestCommonAncestor(root->left,a,b);
    node *rightans = lowestCommonAncestor(root->right,a,b);

    if(leftans!=NULL and rightans!=NULL){
        return root;
    }
    if(leftans!=NULL){
        return leftans;
    }
    return rightans;
}


class Pair{
    public:
    int branchSum;
    int maxSum;
    Pair(){
        branchSum = 0;
        maxSum = 0;

    }


};

Pair maxSumPath(node *root){
    Pair p;
    if(root == NULL){
        return p;
    }
    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath(root->right);
    int op1 = root->data;
    int op2 = left.branchSum + root->data;
    int op3 = right.branchSum + root->data;
    int op4 = left.branchSum + right.branchSum + root->data;

    int current_ans_through_root = max(op1,max(op2,max(op3,op4)));

    p.branchSum = max(left.branchSum,max(right.branchSum,0)) + root->data;
    p.maxSum = max(left.maxSum,max(right.maxSum,current_ans_through_root));
    return p;

}

//finding out level i,e distance of key node from root node or any other given node
int searchLevel(node *root, int key, int level){
    if(root == NULL){
        return -1;
    }
    if(root->data == key){
        return level;
    }

    int leftlevel = searchLevel(root->left, key, level+1);
    if(leftlevel!=-1){
        return leftlevel;
    }
    return searchLevel(root->right,key,level+1);
}

//shortest distance between two nodes
int shortestDistance(node *root, int a, int b){
    node *lca_node = lowestCommonAncestor(root,a,b);
    int l1 = searchLevel(lca_node,a,0);
    int l2 = searchLevel(lca_node,b,0);
    return l1+l2;
}

int main() {
    int in[] = {3, 1, 4, 0, 5, 2};
    int pre[] = {0, 1, 3, 4, 2, 5};
    int n = sizeof(in) / sizeof(int);

    node *root = buildTree();

    int indexPre = 0; // This tracks the index in the preorder array
    node* foundBin = findBinTree(in, pre, indexPre, 0, n - 1, n);

    cout << "Post-order traversal: ";
    printPost(foundBin);

    node *lca = lowestCommonAncestor(root,8,9);
    cout<<lca->data<<endl;

    return 0;
}
