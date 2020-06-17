解题思路
此处撰写解题思路

执行用时 : 128 ms , 在所有 C++ 提交中击败了 60.93% 的用户
内存消耗 : 37.2 MB , 在所有 C++ 提交中击败了 25.00% 的用户

拷贝的官方内容。发布题解，只是为了做一个记录，方便日后查看。

官方题解
我们回过头来看得分公式，我们可以将其拆分成 A[i]+i 和 A[j]-j两部分，
这样对于统计景点 j 答案的时候，由于 A[j]-j是固定不变的，因此最大化 A[i]+i+A[j]-j 的值
其实就等价于求 [0,j-1] 中 A[i]+i 的最大值 mx，景点 j 的答案即为 mx+A[j]-j。
而 mx 的值我们只要从前往后枚举 j 的时候同时维护即可，（这个mx就是关键中的关键）
这样每次枚举景点 j 的时候，寻找使得得分最大的 i 就能从 O(n) 降至 O(1) 的时间复杂度，
总时间复杂度就能从 O(n^2) 降至 O(n)。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/best-sightseeing-pair/solution/zui-jia-guan-guang-zu-he-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。




class Solution {
public:

// //简单粗暴，超时了
//     int maxScoreSightseeingPair(vector<int>& A) {
//         int iMax=0;
//         for(int i=0;i<A.size()-1;i++)
//         {
//             for(int j=i+1;j<A.size();j++)
//             {
//                 int iVal = A[j]+A[i]+i-j;
//                 if(iVal>iMax)
//                 {
//                     iMax = iVal;
//                 }
//             }
//         }
//         return iMax;
//     }

//链接：https://leetcode-cn.com/problems/best-sightseeing-pair/solution/zui-jia-guan-guang-zu-he-by-leetcode-solution/
    int maxScoreSightseeingPair(vector<int>& A) {
        int ans = 0, mx = A[0] + 0;
        for (int j = 1; j < A.size(); ++j) {
            ans = max(ans, mx + A[j] - j);
            // 边遍历边维护
            mx = max(mx, A[j] + j);
        }
        return ans;
    }


};

作者：henryheliang
链接：https://leetcode-cn.com/problems/best-sightseeing-pair/solution/1014-zui-jia-guan-guang-zu-he-by-henryheliang/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
