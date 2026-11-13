#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int val) { data = val; left = right = nullptr; }
};

// 1. Insertion (BST)
TreeNode* insertBST(TreeNode* root, int value) {
    if (root == nullptr) return new TreeNode(value);
    if (value < root->data) root->left = insertBST(root->left, value);
    else root->right = insertBST(root->right, value);
    return root;
}

// 2. Search
bool searchBST(TreeNode* root, int value) {
    if (root == nullptr) return false;
    if (root->data == value) return true;
    if (value < root->data) return searchBST(root->left, value);
    return searchBST(root->right, value);
}

// Helper function for deletion: Find minimum value node in a tree
TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) root = root->left;
    return root;
}

// 3. Deletion
TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == nullptr) return root;
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        // Node with two children: Get inorder successor
        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// 4. Traversal (In-order)
void inorder(TreeNode* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    TreeNode* root = nullptr;
    root = insertBST(root, 50); 
    insertBST(root, 30); 
    insertBST(root, 70); 
    insertBST(root, 20); 
    insertBST(root, 40);

    cout << "Tree (In-order): "; 
    inorder(root); 
    cout << endl;
    
    cout << "Search for 40: " << (searchBST(root, 40) ? "Found" : "Not Found") << endl;
    
    cout << "Deleting 30..." << endl;
    root = deleteNode(root, 30);
    
    cout << "Tree after deletion: "; 
    inorder(root); 
    cout << endl;
    
    return 0;
}