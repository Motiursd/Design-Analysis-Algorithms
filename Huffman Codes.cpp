#include <bits/stdc++.h>
using namespace std;


struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};


struct compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};


void printCodes(Node* root, string code) {
    if (!root) return;
    
    if (root->ch != '$') {
        cout << root->ch << " : " << code << endl;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    string str = "ABACCDA";

    
    map<char, int> freq;
    for (char c : str) freq[c]++;

    
    priority_queue<Node*, vector<Node*>, compare> pq;

    for (auto it : freq) {
        pq.push(new Node(it.first, it.second));
    }

    
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    
    Node* root = pq.top();
    printCodes(root, "");

    return 0;
}
