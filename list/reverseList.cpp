#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head==NULL)
            return NULL;
        stack<ListNode*> reverList;
        while(head!=NULL){
            reverList.push(head);
            head=head->next;
        }
        ListNode * newHead=NULL;
        ListNode * lnode=reverList.top();
        lnode->next=NULL;
        newHead=lnode;
        reverList.pop();
        while(!reverList.empty()){
            lnode->next= reverList.top();
            lnode=lnode->next;
            lnode->next=NULL;
            reverList.pop();
        }
        return newHead;
    }
};

int main(){
    
}