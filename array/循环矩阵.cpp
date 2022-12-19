#include<iostream>
#include<vector>
using namespace std;
int main(){
    // Solution solution;
    // solution.generateMatrix(5);
    int n=7;
    vector<vector<int> > result;
    result.resize(n,vector<int>(n));

    int i=0,j=0;
    int startx=0,starty=0;
    int count=1;
    int offset=0;
    for(int loop=0;loop<=n/2;loop++){
        i=startx;
        j=starty;
        for(;j<n-offset-1;j++)
            result[i][j]=count++;
        for(;i<n-offset-1;i++)
            result[i][j]=count++;
        for(;j>offset;j--)
            result[i][j]=count++;
        for(;i>offset;i--)
            result[i][j]=count++;
        offset++;
        startx++;
        starty++;
    }
    if(n%2!=0)
        result[startx-1][starty-1]=count;
    
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
}