#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;

        if(visited.count(head)) return visited[head];

        Node* cloneNode = new Node(head->val);
        visited[head] = cloneNode;

        cloneNode->next = copyRandomList(head->next);
        cloneNode->random = copyRandomList(head->random);
        return cloneNode;
    }
    
};