解题思路
执行用时：8 ms, 在所有 C++ 提交中击败了34.04%的用户
内存消耗：8.2 MB, 在所有 C++ 提交中击败了100.00%的用户

dp填表，寻找状态转移方程。这次是自己独立完成的。

//dp[i][j] = dp[i][j-1] + dp[i-1][j];

为了方便计算，我们添加了第0行和第0列。
obstacleGrid 里面的数组是从0开始计数，dp是从1开始累计。

如果 obstacleGrid[i-1][j-1]==1 ,说明此路不通，dp[i][j]设置为0；
当obstacleGrid[i-1][j-1]==0时，开始我们的状态转移方程。
dp[i][j]的值，表示在数组 obstacleGrid 的 (i-1,j-1)的地方，有多少种可能的结果。

这里，需要添加若干特殊判断。
可能有更加优雅的判断，我这里是比较简单粗暴的直接判断。
例如，对这个测试用例 [[1]] 的判断
还有，在for循环的时候，dp[1][1]不需要再去赋值，因为外部已经赋值了。

对于这种特殊情况，我代码处理的不是很优雅。。。

代码

作者：henryheliang
链接：https://leetcode-cn.com/problems/unique-paths-ii/solution/63-bu-tong-lu-jing-ii-by-henryheliang/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。







class Solution {
public:

//dp[i][j] = dp[i][j-1] + dp[i-1][j];

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==0 || obstacleGrid[0].size()==0)
        {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dpv(m+1, vector<int>(n+1));
        for(int i=0;i<=m;i++)
        {
            dpv[i][0] = 0;
        }
        for(int i=0;i<=n;i++)
        {
            dpv[0][i] = 0;
        }
        dpv[1][1] =obstacleGrid[0][0]==1?0:1;
        if(dpv[1][1] == 0)
        {
            return 0;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==1 && j==1)
                {
                    continue;
                }
                if(obstacleGrid[i-1][j-1]==1)
                {
                    dpv[i][j]=0;
                }
                else
                {
                    dpv[i][j] = dpv[i][j-1]+dpv[i-1][j];
                    printf("(%d,%d),value[%d]\r\n",i,j, dpv[i][j]);
                    printf("(%d,%d),value[%d]\r\n",i,j-1, dpv[i][j-1]);
                    printf("(%d,%d),value[%d]\r\n",i-1,j, dpv[i-1][j]);
                    printf("============\r\n");
                }
            }
        }
        return dpv[m][n];
    }
};

作者：henryheliang
链接：https://leetcode-cn.com/problems/unique-paths-ii/solution/63-bu-tong-lu-jing-ii-by-henryheliang/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
