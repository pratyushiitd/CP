/*************************************************************
 
    Following is the Binary Tree node structure:

    template <typename T>

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

void getRightView(BinaryTreeNode<int>* root, vector<int> &r_view, int level){
    if (root==NULL)return;
    if (r_view.size() == level)r_view.push_back(root->data);
    getRightView(root->right, r_view, level+1);
    getRightView(root->left, r_view, level+1);
}
vector<int> printRightView(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<int> r_view = {};
    getRightView(root, r_view, 0);
    return r_view
;}
