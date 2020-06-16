class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // 利用map进行计数
        map<string, int> m;
        for(auto & e : words)
        {
            m[e]++;
        }

        // 将数字降序排序
        multimap<int, string, greater<int>> mm;
        for(auto & e : m)
        {
            // 这里的first和seconds换个位置
            mm.insert(make_pair(e.second, e.first));
        }

        // 这个来接收最大的k个字符串
        vector<string> v;
        for(auto & e : mm)
        {
            if(k == 0)
            {
                break;
            }
            v.push_back(e.second);
            k--;
        }
        return v;
    }
};
