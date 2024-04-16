#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int key;
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int k, int v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

// Function to construct a height-balanced BST from sorted keys
TreeNode* constructBalancedBST(const vector<pair<int, int>>& sorted_keys, int start, int end) {
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(sorted_keys[mid].first, sorted_keys[mid].second);
    root->left = constructBalancedBST(sorted_keys, start, mid - 1);
    root->right = constructBalancedBST(sorted_keys, mid + 1, end);

    return root;
}

// Function to create height-balanced BST from key-value pairs
TreeNode* createHeightBalancedBST(const map<int, int>& keyValuePairs) {
    vector<pair<int, int>> sorted_keys;
    for (const auto& pair : keyValuePairs) {
        sorted_keys.push_back(pair);
    }
    return constructBalancedBST(sorted_keys, 0, sorted_keys.size() - 1);
}

// Function to perform inorder traversal of BST
void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << "(" << root->key << ", " << root->value << ") ";
        inorderTraversal(root->right);
    }
}

void levelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            cout << "(" << node->key << ", " << node->value << ") ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of key-value pairs: ";
    cin >> n;

    map<int, int> keyValuePairs;
    cout << "Enter key-value pairs:" << endl;
    for (int i = 0; i < n; ++i) {
        int key, value;
        cout << "Enter key and value separated by space: ";
        cin >> key >> value;
        keyValuePairs[key] = value;
    }

    TreeNode* root = createHeightBalancedBST(keyValuePairs);

    cout << "Inorder traversal of constructed BST:" << endl;
    inorderTraversal(root);
    cout<<endl;
    levelOrder(root);
    cout << endl;

    return 0;
}
