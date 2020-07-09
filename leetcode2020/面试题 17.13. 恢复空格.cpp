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







/*******************************下面的for循环+递归，也超时了。不过，可以学习代码的结题思路。这是我自己写的。
测试用例：
["potimzz"]
"potimzzpotimzz"

边界条件不可少
[]
""

[]
"abc"

["a"]
""

解答错误了

["aaysaayayaasyya","yyas","yayysaaayasasssy","yaasassssssayaassyaayaayaasssasysssaaayysaaasaysyaasaaaaaasayaayayysasaaaa","aya","sya","ysasasy","syaaaa","aaaas","ysa","a","aasyaaassyaayaayaasyayaa","ssaayayyssyaayyysyayaasaaa","aya","aaasaay","aaaa","ayyyayssaasasysaasaaayassasysaaayaassyysyaysaayyasayaaysyyaasasasaayyasasyaaaasysasy","aaasa","ysayssyasyyaaasyaaaayaaaaaaaaassaaa","aasayaaaayssayyaayaaaaayaaays","s"]
"asasayaayaassayyayyyyssyaassasaysaaysaayaaaaysyaaaa"


["ouf","uucuocucoouoffcpuuf","pf","o","fofopupoufuofffffocpocfccuofuupupcouocpocoooupcuu","cf","cffooccccuoocpfupuucufoocpocucpuouofffpoupu","opoffuoofpupcpfouoouufpcuocufo","fopuupco","upocfucuucfucofufu","ufoccopopuouccupooc","fffu","uuopuccfocopooupooucfoufop","occ","ppfcuu","o","fpp","o","oououpuccuppuococcpoucccffcpcucoffupcoppoc","ufc","coupo","ufuoufofopcpfoufoouppffofffuupfco","focfcfcfcfpuouoccupfccfpcooup","ffupfffccpffufuuo","cufoupupppocou","upopupopccffuofpcopouofpoffopcfcuooocppofofuuc","oo","pccc","oupupcccppuuucuuouocu","fuop","ppuocfuppff","focofooffpfcpcupupuuooufu","uofupoocpf","opufcuffopcpcfcufpcpufuupffpp","f","opffp","fpccopc"]
"fofopupoufuofffffocpocfccuofuupupcouocpocoooupcuufffufffufpccopc"

*******************************/
// 从长到短，排序dic里面的字符数组
static bool sortDic(string& A, string& B)
{
    if(A.length()> B.length())
    {
        return true;
    }
    else
    {
        return false;
    }
}
class Solution {
public:
    //寻找非#字符个数
    int getSentenceLength(string str)
    {
        int index = 0;
        int iLength = 0;
        while(index<str.length())
        {
            if(str[index]!='#')
            {
                iLength++;
            }
            index++;
        }
        return iLength;
    }

    void mathCore(vector<string>& dictionary, string sentence,int index, int& MinNums)
    {
        if(index>=dictionary.size())
        {
            if(MinNums> getSentenceLength(sentence))
            {
                MinNums = getSentenceLength(sentence);
                printf("size(%d),str:%s \r\n",getSentenceLength(sentence), sentence.c_str());
            }
            return;
        }
        size_t Found = sentence.find(dictionary[index]);
        if(Found != string::npos)
        {
            //printf("str(%s),DicIndex:%d,Found Pos:%d\r\n",dictionary[index].c_str(),index, Found);
            //printf("=====out:%s \r\n",sentence.substr(Found,dictionary[index].size()).c_str());
            sentence.replace(sentence.begin()+Found,sentence.begin()+Found+dictionary[index].size(),"#");
            mathCore(dictionary,sentence,index,MinNums);
        }
        mathCore(dictionary,sentence,index+1,MinNums);
    }

    int respace(vector<string>& dictionary, string sentence) {
        if(dictionary.empty())
        {
            return sentence.length();
        }
        if(sentence.length() ==0)
        {
            return 0;
        }
        if(dictionary.size()>=2)
        {
            sort(dictionary.begin(), dictionary.end(), sortDic);
        }
        // printf("===============print sorted dic=============\r\n");
        // for(int i=0;i<dictionary.size();++i)
        // {
        //     printf("Dic[%d]:(%s)\r\n",i,dictionary[i].c_str());
        // }
        // printf("===============print sorted dic End =============\r\n");
        int iMinNums = sentence.length();
        for(int i=0;i<dictionary.size();++i)
        {
            //  mathCore(dictionary,sentence,i,iMinNums);
        }
        mathCore(dictionary,sentence,0,iMinNums);
        return iMinNums;
    }
};
