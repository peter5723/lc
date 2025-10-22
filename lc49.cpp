#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> my_map;
        for (string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            my_map[key].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = my_map.begin();it != my_map.end();it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};
