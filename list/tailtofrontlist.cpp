#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        while(head!=NULL){
            result.push_back(head->val);
            head=head->next;
        }
        int len=result.size();
        for(int i=0;i<=result.size()/2;i++){
            swap(result[i],result[len-i-1]);
        }
        return result;
    }
    };

int main(){
    
}