解题思路
有思路，但是提交之后多次都超时了。
2个数，是一种特殊情况，可以针对这种特殊情况，做特殊判断处理。将二维转为一维。

shorter 如果是i个，那么loger就是k-i个，就不需要从0开始累计上一次的计算结果了。直接跳到最后一种情况，计算结果。

作者：henryheliang
链接：https://leetcode-cn.com/problems/diving-board-lcci/solution/mian-shi-ti-1611-tiao-shui-ban-by-henryheliang-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



class Solution {

/*****************************

测试用例：
特别注意，此处的测试用例中的3个数字，不能写在一行。。不信你实时看。
1 
1 
10

1 
2 
3

0 
0 
10

0 
0 
0

0 
1 
2

0 
1 
0

0
1
4

超出时间限制...最主要，是k的大小.
666
777
888

这题最最大的问题，是时间限制！！！！
这题最最大的问题，是时间限制！！！！
这题最最大的问题，是时间限制！！！！

******************************/

// public:
//     vector<int> divingBoard(int shorter, int longer, int k) {
//         time_t beginT = time(NULL);
//         printf("beginT:%lld \r\n",beginT);
//         vector<int> result;
//         result.clear();
//         if(k>0 && longer<=0)
//         {
//             result.push_back(0);
//             return result;
//         }
//         else if(k<=0)
//         {
//             return result;
//         }

//         //TODO:记得给dp提前分配空间，否则无法直接使用dp[0]范文vector的元素
//         vector<unordered_map<int,int>> dp(k+1);
//         dp[0][0] =0;
//         dp[1][shorter]=1;
//         dp[1][longer]=1;
//         for(int i=1;i<=k;++i)
//         {
//             for(auto it1 = dp[i-1].begin(); it1 != dp[i-1].end();++it1)
//             {
//                 auto val = it1->first;
//                 //printf("index:%d,val:%d \r\n",i, val);
//                 dp[i][val+shorter]=1;
//                 dp[i][val+longer]=1;
//             }
//             //printf("--------------------index:%d,dp[%d].size()=%d\r\n",i,i,dp[i].size());
//         }

//         for(auto it2 = dp[k].begin();it2!=dp[k].end();++it2)
//         {
//             result.push_back(it2->first);
//         }
//         if(result.size()>=2)
//         {
//             sort(result.begin(), result.end());
//         }
//         printf("EndT:%lld \r\n",time(NULL));
//         printf("cost=%lld \r\n",time(NULL)-beginT);
//         return result;
//     }



public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> result;
        result.clear();
        unordered_map<int,int> hashMap;
        if(k>0 && longer<=0)
        {
            result.push_back(0);
            return result;
        }
        else if(k<=0)
        {
            return result;
        }
        for(int i=0;i<=k;++i)
        {
            hashMap[i*shorter + (k-i)*longer] = 1;
        }
        for(auto it = hashMap.begin(); it!=hashMap.end();++it)
        {
            result.push_back(it->first);
        }
        if(result.size()>=2)
        {
            sort(result.begin(),result.end());
        }
        return result;
    }




};

作者：henryheliang
链接：https://leetcode-cn.com/problems/diving-board-lcci/solution/mian-shi-ti-1611-tiao-shui-ban-by-henryheliang-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
