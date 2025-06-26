#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

ListNode* createList(int n){
    if (n==0) return nullptr;

    int val;
    cout<<"Enter "<<n<<" values: ";
    cin>>val;
    ListNode* head = new ListNode(val);
    ListNode* curr = head;
    for(int i=1; i<n; ++i){
        cin>>val;
        curr->next = new ListNode(val);
        curr = curr->next;
    }
    return head;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    if(!headA || !headB) return nullptr;
    ListNode*ptrA = headA;
    ListNode*ptrB = headB;

    while(ptrA != ptrB){
        ptrA = ptrA ? ptrA->next : headB;
        ptrB = ptrB ? ptrB->next : headA;
    }
    return ptrA;
}

void printList(ListNode* head){
    while(head){
        cout<<head->val<<" -> ";
        head = head->next;
    }
    cout<<"NULL\n";
}

int main(){
    int n1, n2, c;
    cout<<"Enter number of nodes in List A: ";
    cin>>n1;
    ListNode* headA = createList(n1);

    cout<<"Enter number of nodes in List B: ";
    cin>>n2;
    ListNode* headB = createList(n2);

    cout<<"Enter number of nodes in common (intersection): ";
    cin>>c;

    ListNode* commonHead = nullptr;
    if(c>0){
        cout<<"Enter "<<c<<" values for the commoon part: ";
        int val;
        cin>>val;
        commonHead = new ListNode(val);
        ListNode* curr = commonHead;
        for(int i = 1; i<c; ++i){
            cin>>val;
            curr->next = new ListNode(val);
            curr = curr->next;
        }

        ListNode* temp = headA;
        while(temp && temp->next) temp = temp->next;
        if(temp) temp->next = commonHead;

        temp = headB;
        while(temp && temp->next) temp = temp->next;
        if(temp) temp->next = commonHead;
    }

    cout<<"\nList A: ";
    printList(headA);
    cout<<"List B: ";
    printList(headB);

    ListNode* result = getIntersectionNode(headA, headB);
    if(result){
        cout<<"Intersection at node with value: "<<result->val<<endl;
    }else{
        cout<<"No intersection.\n";
    }

    return 0;
}