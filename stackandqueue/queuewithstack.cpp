#include<iostream>
#include<stack>
using namespace std;



class CQueue {
public:
    stack<int> instack,outstack;
    CQueue() {

    }
    
    void appendTail(int value) {
        instack.push(value);
    }
    
    int deleteHead() {
        if(instack.empty())
            return -1; //如果队列中没有元素，则直接返回-1
            //否则将instack中的数值倒过来
        while (!instack.empty())
        {
            outstack.push(instack.top());
            instack.pop();
        }
        int head=outstack.top();
        outstack.pop();
        while (!outstack.empty())
        {
            instack.push(outstack.top());
            outstack.pop();
        }
        
        return head;        
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
//  * CQueue* obj = new CQueue();
//  * obj->appendTail(value);
//  * int param_2 = obj->deleteHead();
 */
int main(){
    CQueue* obj = new CQueue();
    obj->appendTail(3);
    int param_2 = obj->deleteHead();
    cout<<param_2;
    return 0;
}