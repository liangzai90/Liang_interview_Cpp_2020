https://leetcode-cn.com/problems/longest-valid-parentheses/solution/32-zui-chang-you-xiao-gua-hao-by-henryheliang/

dp填表，寻找 【状态转移方程】


class Solution {
public:

//TODO:没有做出来，这里参考的是题解的代码

    int longestValidParentheses(string s) {
        int maxans = 0,n=s.length();
        vector<int> dp(n,0);
        for(int i=1;i<n;i++)
        {
            if(s[i]==')')
            {
                // ()   ()()
                if(s[i-1]=='(')
                {
                    //TODO:状态转移方程！！！
                    dp[i] = (i>2 ? dp[i-2]:0)+2;
                }
                // (())
                else if(i-dp[i-1]>0 && s[i-dp[i-1]-1] =='(')
                {
                    //TODO:状态转移方程！！！
                    dp[i] = dp[i-1] + ((i-dp[i-1])>=2 ? dp[i-dp[i-1]-2]:0)+2;
                }
                maxans = max(maxans,dp[i]);
            }
        }
        return maxans;
    }
};

作者：henryheliang
链接：https://leetcode-cn.com/problems/longest-valid-parentheses/solution/32-zui-chang-you-xiao-gua-hao-by-henryheliang/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

