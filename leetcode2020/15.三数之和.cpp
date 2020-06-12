题目地址：
https://leetcode-cn.com/problems/3sum/

题目描述：

给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。

示例：
给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


解题思路
此处撰写解题思路

1.先从小到大排序
2.参考官方的结题思路，先固定一个数，然后左右两个指针开始查找；
3.注意iLeft, iRight的边界条件，不要越界
4.while循环中， nums[iRight]<0 就不必再继续判断了，节省时间，提高效率。（因为最右边的数都是最大的数，如果这个数小于0，那么3个数的和肯定小于0）
5.在找到了一个解之后，需要继续查找
6.在继续查找的时候，为了避免重复的结果，需要过滤 iLeft和他旁边的值，如果是重复的，跳过；iRight也是类似

作者：henryheliang
链接：https://leetcode-cn.com/problems/3sum/solution/15-san-shu-zhi-he-by-henryheliang/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。





class Solution {
public:

//一顿操作猛如虎，代码调试一下午；边界条件很多坑.
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>  vecRet;
        if(nums.size()<3)
            return vecRet;

        std::sort(nums.begin(), nums.end());

        for(int i=0;i<=nums.size()-3;i++)
        {
            if(i>=1 && nums[i-1] == nums[i])
            {
                continue;
            }
            int iLeft = i+1;
            int iRight = nums.size()-1;
            while(iLeft<iRight && iLeft<=nums.size()-2 && iRight>=2)
            {
                //提前结束，减少不必要的判断
                if(nums[iRight]<0)
                {
                    break;
                }
                int iTemp1 = nums[i] + nums[iLeft] + nums[iRight];
                if(iTemp1>0)
                {
                    iRight--;
                }
                else if(iTemp1<0)
                {
                    iLeft++;
                }
                else{
                    // find one.
                    vector<int> vecTemp;
                    vecTemp.push_back(nums[i]);
                    vecTemp.push_back(nums[iLeft]);
                    vecTemp.push_back(nums[iRight]);
                    vecRet.push_back(vecTemp);
                    vecTemp.clear();
                    iRight--;
                    iLeft++;
                  //去重(chong)判断  [-4, -2,-2,-2,-1, 0,0,1,2,2,2]
                    while(iLeft<iRight && iLeft<=nums.size()-2 && iRight>=2)
                    {
                        if(nums[iLeft]==nums[iLeft-1])
                        {
                            iLeft++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    while(iLeft<iRight && iLeft<=nums.size()-2 && iRight>=2)
                    {
                        if(nums[iRight]==nums[iRight+1])
                        {
                            iRight--;
                        }
                        else
                        {
                            break;
                        }
                    }               
                }
            }//end while
        }//end for
        return vecRet;
    }
};

作者：henryheliang
链接：https://leetcode-cn.com/problems/3sum/solution/15-san-shu-zhi-he-by-henryheliang/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
