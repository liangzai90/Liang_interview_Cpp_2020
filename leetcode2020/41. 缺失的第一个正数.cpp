解题思路
hash表存放正数，然后从1~n遍历，找不到的数，就是缺失的。
要注意特殊的边界情况，

例如下面2个测试用例：

[2]

[1,2,3,4]





class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>  hashMap;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                hashMap[nums[i]] = nums[i];
            }
        }

        int iLength = hashMap.size();
        int MinNum = hashMap.size()+1;
        for(int i=1;i<=iLength;i++)
        {
            if(hashMap.find(i) == hashMap.end())
            {
                MinNum = i;
                return MinNum;
            }
        }
        return MinNum;
    }
};

作者：henryheliang
链接：https://leetcode-cn.com/problems/first-missing-positive/solution/41-que-shi-de-di-yi-ge-zheng-shu-by-henryheliang/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
