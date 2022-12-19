#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        int t;
        while(i<=j){
            t=(i+j)/2;
            if (target>nums[t])
            {
                i=t+1;
            }
            else if (target<nums[t])
            {
                j=t-1;
            }
            else
                return t;            
        }
        return -1;
    }
};
int main(){

}