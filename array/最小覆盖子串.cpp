#include<iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    map<char,int> window;
    map<char,int> tFreq;
    string minWindow(string s, string t) {
        string minstr="";
        string windowstr="";
        int minLen=s.length()+1;
        int i=0;
        int distance=0;//window中满足target的个数
        string totalstr=t+s;
        for(int i=0;i<totalstr.length();i++)
        {
            window[totalstr[i]]=0;//对window进行map
            tFreq[totalstr[i]]=0;
        }
        for(int i=0;i<t.length();i++){
            tFreq[t[i]]++;
        }
        int begin=0;
        for(int j=0;j<s.length();j++)
        {
            //in window
            // windowstr=windowstr+s[j];//window右移一个字符
            if(window[s[j]]<tFreq[s[j]])
                distance++;//如果window将要加的这个字符，是满足要求的，那么distance就添加1；
                           //如果window要加的这个字符已经满足target要求了，那么distance加不加都无所谓
            window[s[j]]+=1;//window的map为这个字符添加标识符
            while (distance==t.length())//判断window中的字符是否满足target
            {
                if(minLen>j-i+1)
                {   
                    begin=i;
                    minLen=j-i+1;
                }
                // windowstr.erase(0,1);//删掉windowstr的第一个字符，window左移
                if(window[s[i]]==tFreq[s[i]])
                {
                    distance--;
                }//如果要window要移走的这个不满足target的要求了，那就distacen减掉
                window[s[i]]-=1;
                i++;
            }
            
        }
        if(minLen==s.length()+1)
            return "";
        else
        {
            return s.substr(begin,minLen);
        }

    }
};
int main(){
    Solution solution;
    string s="ADOBECODEBANC";
    string t="ABC";
    cout<<solution.minWindow(s,t);
}