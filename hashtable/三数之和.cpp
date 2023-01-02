#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                return result;
            if(i>=1 && nums[i]==nums[i-1])
                continue;
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==0){
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    result.push_back(tmp);
                    left++;
                }
                else
                    if(sum>0)
                        right--;
                    else
                        left++;
                while(left>i+1&& left<right && nums[left]==nums[left-1])
                {
                    left++;
                }
                while(right<nums.size()-1 && left<right && nums[right]==nums[right+1]){
                    right--;
                }
            }
        }
        return result;
    }
};
int main(){
    Solution solution;
    int a[6]={-1,0,1,2,-1,-4};
    vector<int> nums(a,a+6);
    solution.threeSum(nums);
}