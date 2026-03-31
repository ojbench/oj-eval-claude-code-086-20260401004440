#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int left;
    int right;
    int depth;
};

vector<Node> tree;
vector<int> result;

void calculateDepths(int nodeIndex, int depth) {
    if (nodeIndex == -1) return;

    tree[nodeIndex].depth = depth;
    calculateDepths(tree[nodeIndex].left, depth + 1);
    calculateDepths(tree[nodeIndex].right, depth + 1);
}

void swapAtDepth(int nodeIndex, int k) {
    if (nodeIndex == -1) return;

    // If this node's depth is a multiple of k, swap its children
    if (tree[nodeIndex].depth % k == 0) {
        swap(tree[nodeIndex].left, tree[nodeIndex].right);
    }

    // Recursively process children
    swapAtDepth(tree[nodeIndex].left, k);
    swapAtDepth(tree[nodeIndex].right, k);
}

void inorderTraversal(int nodeIndex) {
    if (nodeIndex == -1) return;

    inorderTraversal(tree[nodeIndex].left);
    result.push_back(nodeIndex);
    inorderTraversal(tree[nodeIndex].right);
}

int main() {
    int n;
    cin >> n;

    // Initialize tree with n+1 nodes (1-indexed)
    tree.resize(n + 1);
    tree[0].left = tree[0].right = -1;
    tree[0].depth = 0;

    // Read tree structure
    for (int i = 1; i <= n; i++) {
        int left, right;
        cin >> left >> right;
        tree[i].left = left;
        tree[i].right = right;
        tree[i].depth = 0;
    }

    // Calculate depths (root is node 1)
    calculateDepths(1, 1);

    // Read number of queries
    int t;
    cin >> t;

    // Process each query
    for (int i = 0; i < t; i++) {
        int k;
        cin >> k;

        // Swap all nodes at depths that are multiples of k
        swapAtDepth(1, k);

        // Get inorder traversal
        result.clear();
        inorderTraversal(1);

        // Output result
        for (size_t j = 0; j < result.size(); j++) {
            cout << result[j];
            if (j < result.size() - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
