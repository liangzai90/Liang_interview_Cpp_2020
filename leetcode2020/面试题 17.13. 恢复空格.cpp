解题思路
执行用时：132 ms, 在所有 C++ 提交中击败了78.14%的用户
内存消耗：154.3 MB, 在所有 C++ 提交中击败了100.00%的用户

【官方题解】
https://leetcode-cn.com/problems/re-space-lcci/solution/hui-fu-kong-ge-by-leetcode-solution/



class Trie {
public:
    Trie* next[26] = {nullptr};
    bool isEnd;
    
    Trie() {
        isEnd = false;
    }

    void insert(string s) {
        Trie* curPos = this;

        for (int i = s.length() - 1; i >= 0; --i) {
            int t = s[i] - 'a';
            if (curPos->next[t] == nullptr) {
                curPos->next[t] = new Trie();
            }
            curPos = curPos->next[t];
        }
        curPos->isEnd = true;
    }
};

//字典树
class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        int n = sentence.length(), inf = 0x3f3f3f3f;

        Trie* root = new Trie();
        for (auto& word: dictionary) {
            root->insert(word);
        }

        vector<int> dp(n + 1, inf);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;

            Trie* curPos = root;
            for (int j = i; j >= 1; --j) {
                int t = sentence[j - 1] - 'a';
                if (curPos->next[t] == nullptr) {
                    break;
                } else if (curPos->next[t]->isEnd) {
                    dp[i] = min(dp[i], dp[j - 1]);
                }
                if (dp[i] == 0) {
                    break;
                }
                curPos = curPos->next[t];
            }
        }
        return dp[n];
    }
};



////=====超时了。。不过思路是非常好的。
// class Solution {
// public:
//     int respace(vector<string>& dictionary, string sentence) {
//         if(sentence.length()<=0)
//         {
//             return 0;
//         }
//         set<string> dict;
//         for(auto val : dictionary)
//         {
//             dict.insert(val);
//             //printf("dic----:%s\r\n", val.c_str());
//         }
//         //printf("=============\r\n");
//         int n = sentence.length();
//         int* dp = new int[n+1];
//         memset(dp,0, sizeof(dp));
//         for(int i=1;i<=n;++i)
//         {
//             dp[i] = dp[i-1]+1;
//             for(int idx=0;idx<i;++idx)
//             {
//                 //printf("(%d,%d),%s\r\n",idx,i,sentence.substr(idx,i-idx).c_str());
//                 if(dict.find(sentence.substr(idx,i-idx))!=dict.end())
//                 {
//                     //printf("===find one.(%d,%d),%s\r\n",idx,i,sentence.substr(idx,i).c_str());
//                     dp[i] = min(dp[i], dp[idx]);
//                 }
//             }
//             //printf("===============\r\n\r\n");
//         }
//         return dp[n];
//     }
// };


作者：henryheliang
链接：https://leetcode-cn.com/problems/re-space-lcci/solution/mian-shi-ti-1713-hui-fu-kong-ge-by-henryheliang/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

