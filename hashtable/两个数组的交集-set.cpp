#include<iostream>
#include<set>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> record(nums1.begin(),nums1.end());
        set<int> result;
        for(int i=0;i<nums2.size();i++)
            if(record.find(nums2[i])!=record.end())
                result.insert(nums2[i]);
        vector<int> resvec(result.begin(),result.end());
        return resvec;
    }
};
int main(){
    Solution solution;
    vector<int> a(7,3);
    vector<int> b(6,2);
    solution.intersection(a,b);
}