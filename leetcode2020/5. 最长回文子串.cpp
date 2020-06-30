解题思路
执行用时：224 ms, 在所有 C++ 提交中击败了46.30%的用户
内存消耗：54.6 MB, 在所有 C++ 提交中击败了54.76%的用户

参考的别人的题解思路，用dp填表完成。

第 1 步：定义状态
dp[i][j] 表示子串 s[i..j] 是否为回文子串，这里子串 s[i..j] 定义为左闭右闭区间，可以取到 s[i] 和 s[j]。

第 2 步：思考状态转移方程
在这一步分类讨论（根据头尾字符是否相等），根据上面的分析得到：

dp[i][j] = (s[i] == s[j]) and dp[i + 1][j - 1]

作者：liweiwei1419
链接：https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zhong-xin-kuo-san-dong-tai-gui-hua-by-liweiwei1419/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    string longestPalindrome(string s) {    
    //TODO:二维数组的 new 也是很讲究的
        bool** dp = new bool*[s.length()];
        for(int i=0;i<s.length();i++)
        {
            dp[i] = new bool[s.length()];
        }
        for(int i=0;i<s.length();i++)
        {
            dp[i][i] = true;
        }
        int MaxLength = 1;
        int iStart =0;
        int iEnd = 0;
        //TODO:注意这里的循环，j在外层，从1开始。i在内存，i<j
        for(int j=1;j<s.length();j++)
        {
            for(int i=0;i<j;i++)
            {
                if(s[i] == s[j])
                {
                    //TODO：判定为true的条件
                    if(j-i<3)
                    {
                        dp[i][j]=true;
                    }
                    else
                    {
                        // 迭代 公式
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                else
                {
                    dp[i][j] = false;
                }

                //TODO:记录最大长度和相应位置
                if(dp[i][j])
                {
                    if(j-i+1>MaxLength)
                    {
                        MaxLength = j-i+1;
                        iStart = i;
                        iEnd = j;
                    }
                }
            }
        }

        //TODO:一定要记得释放内存空间，养成良好习惯
        for(int i=0;i<s.length();i++)
        {
            delete[] dp[i];
        }
        delete[] dp;

        printf("iStart:%d, iEnd:%d.Maxlentth:%d\r\n",iStart,iEnd,MaxLength);
        return s.substr(iStart,iEnd-iStart+1);
    }
};

作者：henryheliang
链接：https://leetcode-cn.com/problems/longest-palindromic-substring/solution/5-zui-chang-hui-wen-zi-chuan-by-henryheliang/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
