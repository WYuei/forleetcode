#include<iostream>
#include<stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    stack<int> originstack,minstack;
    void push(int x) {
        originstack.push(x);
        if (minstack.empty()|| minstack.top()>=x )
        {
            minstack.push(x);
        }
    }
    
    void pop() {
        int t=originstack.top();
        originstack.pop();
        if (t==minstack.top())
            minstack.pop();
    }
    
    int top() {
        return originstack.top();
    }
    
    int min() {
        return minstack.top();
    }
};

int main(){
    MinStack* obj = new MinStack();
    int x=3;
    obj->push(x);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->min();
    cout<<param_3<<" "<<param_4;
}