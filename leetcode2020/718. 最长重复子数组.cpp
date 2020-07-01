解题思路
执行用时：244 ms, 在所有 C++ 提交中击败了91.94%的用户
内存消耗：108.3 MB, 在所有 C++ 提交中击败了33.33%的用户

dp迭代公式：

A[i]==B[j]时，dp[i][j]=1
dp[i][j] = dp[i-1][j-1]+1 and A[i]==B[j] and dp[i-1][j-1]>0

当然，这里的迭代公司，还是可以进一步压缩和优化的。

作者：henryheliang
链接：https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/solution/718-zui-chang-zhong-fu-zi-shu-zu-by-henryheliang/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。




class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if(A.size() ==0 || B.size()==0)
        {
            return 0;
        }
        int** dp = new int*[A.size()];
        for(int i=0;i<A.size();i++)
        {
            dp[i] = new int[B.size()];
            memset(dp[i], 0, B.size());
        }
        int iMaxLength = 0;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<B.size();j++)
            {
                if(A[i]==B[j])
                {
                    dp[i][j]=1;
                    if(iMaxLength<1)
                    {
                        iMaxLength = 1;
                    }
                    //TODO:进一步优化dp公式
                    if(i>0 && j>0 && dp[i-1][j-1]>0)
                    {
                        dp[i][j]=dp[i-1][j-1]+1;
                        if(iMaxLength<dp[i][j])
                        {
                            iMaxLength = dp[i][j];
                        }
                    }
                }
            }
        }
        for(int i=0;i<A.size();i++)
        {
            delete[] dp[i];
        }
        delete [] dp;
        return iMaxLength;
    }
};

作者：henryheliang
链接：https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/solution/718-zui-chang-zhong-fu-zi-shu-zu-by-henryheliang/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
