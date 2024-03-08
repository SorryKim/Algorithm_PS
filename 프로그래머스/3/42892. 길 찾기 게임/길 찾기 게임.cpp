#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
public:
    int idx;
    int x, y;
    Node* left;
    Node* right;

    Node() {}

    Node(int idx, int x, int y) : idx(idx), x(x), y(y), left(nullptr), right(nullptr) {}

};

bool cmp(const Node& a, const Node& b) {

    return a.y > b.y || (a.y == b.y && a.x < b.x);
}

Node* insert(Node* root, int idx, int x, int y) {

    // nullptr인 경우
    if (!root) {
        return new Node(idx, x, y);
    }

    // left로 들어가는 경우
    if (x < root->x || (x == root->x && y < root->y)) {
        root->left = insert(root->left, idx, x, y);
    }
    // right로 들어가는 경우
    else {
        root->right = insert(root->right, idx, x, y);
    }

    return root;
}

vector<int> pre;

void preorder(Node* root) {
    if (root) {
        pre.push_back(root->idx);
        preorder(root->left);
        preorder(root->right);
    }
}

vector<int> post;

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        post.push_back(root->idx);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node> tree;
    Node* root = nullptr;

    for (int i = 0; i < nodeinfo.size(); i++) {

        int idx = i + 1;
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];

        Node node = Node(idx, x, y);
        tree.push_back(node);
    }

    sort(tree.begin(), tree.end(), cmp);

    for (const auto& node : tree) {
        root = insert(root, node.idx, node.x, node.y);
    }

    preorder(root);
    postorder(root);

    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}