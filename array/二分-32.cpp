#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
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
                return nums;            
        }
        return nums;
    }
    int searchFirst(vector<int>& nums,int target){//找不大于target的元素
        int i=0,j=nums.size()-1;
        int t;
        int firstborder=-2;
        while(i<=j){
            t=(i+j)/2;
            if (target>nums[t])
            {
                i=t+1;
            }
            else if (target<=nums[t])
            {
                j=t-1;
                firstborder=j;
            }           
        }
        return firstborder;
    }
    int searchSecond(vector<int>& nums,int target){//找大于target的第一个元素
        int left = 0;
        int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
        int rightBorder = -2; // 记录一下rightBorder没有被赋值的情况
        while (left <= right) { // 当left==right，区间[left, right]依然有效
            int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target 在左区间，所以[left, middle - 1]
            } else { // 当nums[middle] == target的时候，更新left，这样才能得到target的右边界
                left = middle + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }
};
int main(){

}