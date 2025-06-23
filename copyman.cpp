#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to detect cycle
bool hasCycle(ListNode *head) {
    if (!head || !head->next) return false;

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (slow != fast) {
        if (!fast || !fast->next) return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n == 0) {
        cout << "List is empty. No cycle.\n";
        return 0;
    }

    vector<ListNode*> nodes(n);
    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nodes[i] = new ListNode(val);
        if (i > 0) {
            nodes[i - 1]->next = nodes[i]; // Link previous node
        }
    }

    ListNode* head = nodes[0];

    int pos;
    cout << "Enter position to create cycle (-1 for no cycle): ";
    cin >> pos;

    if (pos != -1 && pos >= 0 && pos < n) {
        nodes[n - 1]->next = nodes[pos]; // Create cycle
    }

    bool result = hasCycle(head);
    if (result) {
        cout << "Cycle detected in the linked list.\n";
    } else {
        cout << "No cycle in the linked list.\n";
    }

    // Optional: free memory only if no cycle
    if (!result) {
        for (int i = 0; i < n; i++) {
            delete nodes[i];
        }
    }

    return 0;
}
