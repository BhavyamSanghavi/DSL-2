#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Function to build optimal BST recursively
TreeNode* constructTree(vector<int>& keys, vector<vector<int>>& root, int i, int j) {
    if (i > j) return nullptr;
    int rootIndex = root[i][j];
    TreeNode* rootNode = new TreeNode(keys[rootIndex]);
    rootNode->left = constructTree(keys, root, i, rootIndex - 1);
    rootNode->right = constructTree(keys, root, rootIndex + 1, j);
    return rootNode;
}

// Function to build optimal BST recursively
TreeNode* buildOptimalBSTRecursive(vector<int>& keys, vector<int>& freq, int i, int j) {
    if (i > j) return nullptr;

    int minCost = INT_MAX;
    int rootIndex = -1;

    int freqSum = 0;
    for (int k = i; k <= j; ++k) {
        freqSum += freq[k];
    }

    for (int r = i; r <= j; ++r) {
        int leftCost = (r > i) ? buildOptimalBSTRecursive(keys, freq, i, r - 1)->key : 0;
        int rightCost = (r < j) ? buildOptimalBSTRecursive(keys, freq, r + 1, j)->key : 0;

        int totalCost = freqSum + leftCost + rightCost;

        if (totalCost < minCost) {
            minCost = totalCost;
            rootIndex = r;
        }
    }

    TreeNode* root = new TreeNode(keys[rootIndex]);
    root->left = buildOptimalBSTRecursive(keys, freq, i, rootIndex - 1);
    root->right = buildOptimalBSTRecursive(keys, freq, rootIndex + 1, j);

    return root;
}

// Function to build optimal BST
TreeNode* buildOptimalBST(vector<int>& keys, vector<int>& freq) {
    int n = keys.size();
    vector<vector<int>> root(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        root[i][i] = i;
    }

    return buildOptimalBSTRecursive(keys, freq, 0, n - 1);
}

// Function to perform inorder traversal of BST
void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    vector<int> keys = {10, 12, 20, 24};
    vector<int> freq = {34, 8, 50, 12};
    TreeNode* root = buildOptimalBST(keys, freq);

    cout << "Inorder traversal of constructed BST:" << endl;
    inorderTraversal(root);
    cout << endl;

    return 0;
}
