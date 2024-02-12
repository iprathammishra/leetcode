/*
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
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        unordered_map<Node *, Node *> map;
        Node *node = head;
        while (node)
        {
            map[node] = new Node(node->val);
            node = node->next;
        }
        node = head;
        while (node)
        {
            map[node]->next = map[node->next];
            map[node]->random = map[node->random];
            node = node->next;
        }
        return map[head];
    }
};