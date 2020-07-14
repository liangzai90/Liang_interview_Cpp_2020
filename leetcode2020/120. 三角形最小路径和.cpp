解法1：二维dp求解
执行用时：8 ms, 在所有 C++ 提交中击败了92.88%的用户
内存消耗：8.8 MB, 在所有 C++ 提交中击败了100.00%的用户

一层一层的分析这个数组。
举例：
[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]

动手画图：
如果只有1层，结果为2
如果有2层，则第2层为（5,6），最小值为5，结果为5
如果有3层，则第3层为(11,10,13)，最小值为10，结果为10
在动手画图的过程中，我们会发现规律。
除去最左边和最右边的特殊情况。其他情况下，
下面一层的数字，和他上面一层，以及上面一层偏左的位置有关系（题目限定了，只能向下或向右移动）。
我们用i,j坐标表示第i层的第j个数，那么有公式：
dp[i][j] = dp[i-1][j-1]+triangle[i][j]
dp[i][j] = dp[i-1][j]+triangle[i][j]
然后，取这2个数里面的最小的。

作者：henryheliang
链接：https://leetcode-cn.com/problems/triangle/solution/120-san-jiao-xing-zui-xiao-lu-jing-he-by-henryheli/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0));
        int iRow = triangle.size();
        dp[0][0]=triangle[0][0];
        for(int i=1;i<iRow;++i)
        {
            for(int j=0;j<triangle[i].size();++j)
            {
                if(j ==0)
                {
                    dp[i][j] = dp[i-1][j]+triangle[i][j];
                }
                else if(j==triangle[i].size()-1)
                {
                    dp[i][j]=dp[i-1][j-1] + triangle[i][j];
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j-1]+triangle[i][j], dp[i-1][j]+triangle[i][j]);
                }
            }
        }
        int iMinNum = dp[iRow-1][0];
        for(int i=0;i<dp[iRow-1].size();++i)
        {
            if(dp[iRow-1][i]<iMinNum)
            {
                iMinNum = dp[iRow-1][i];
            }
        }

        // printf("========================dp============\r\n");
        // for(int i=0;i<dp.size();++i)
        // {
        //     for(int j=0;j<dp[i].size();++j)
        //     {
        //         printf("%d,",dp[i][j]);
        //     }
        //     printf("\r\n");
        // }
        // printf("========================dp============\r\n");

        return  iMinNum;
    }
};

作者：henryheliang
链接：https://leetcode-cn.com/problems/triangle/solution/120-san-jiao-xing-zui-xiao-lu-jing-he-by-henryheli/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。




解法2：一维dp求解
执行用时：8 ms, 在所有 C++ 提交中击败了92.88%的用户
内存消耗：8.4 MB, 在所有 C++ 提交中击败了100.00%的用户

二维转一维，最大的问题，是如何动态的更新历史的那个数值，如何保持那个数值。

比如，遍历到j的时候，我们需要知道历史的dp[j],dp[j-1];
在这里，用2个int来存放这2个历史数据。

在进入for循环的时候，更新 iNew的值，循环末尾，更新iOld的值。
这样就实现了iNew比iOld新，而且两个数在交替更新中。

作者：henryheliang
链接：https://leetcode-cn.com/problems/triangle/solution/120-san-jiao-xing-zui-xiao-lu-jing-he-by-henryheli/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()<=0)
        {
            return 0;
        }
        vector<int> dp(triangle.size(), 0);
        int iRow = triangle.size();
        dp[0]=triangle[0][0];
        for(int i=1;i<iRow;++i)
        {
            int iOld = dp[0];
            int iNew = dp[0];
            for(int j=0;j<triangle[i].size();++j)
            {
                iNew = dp[j];
                if(j ==0)
                {
                    dp[j] = dp[j]+triangle[i][j];
                }
                else if(j==triangle[i].size()-1)
                {
                    dp[j]=iOld + triangle[i][j];
                }
                else
                {
                    dp[j] = min(iOld + triangle[i][j], iNew + triangle[i][j]);
                }
                iOld = iNew;
            }
        }
        int iMinNum =dp[0];
        for(int i=0;i<dp.size();++i)
        {
            if(dp[i]<iMinNum)
            {
                iMinNum = dp[i];
            }
        }
        // printf("==========dp============\r\n");
        // for(int i=0;i<dp.size();++i)
        // {
        //     printf("%d,",dp[i]);
        // }

        return  iMinNum;
    }
};

作者：henryheliang
链接：https://leetcode-cn.com/problems/triangle/solution/120-san-jiao-xing-zui-xiao-lu-jing-he-by-henryheli/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
