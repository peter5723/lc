#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        // idea is to find every word and then reverse.
        // or just use 2 pointers. i, j.

        int i, j;

        string res;
        j = s.size() - 1;
        while (j >= 0)
        {
            if (s[j] == ' ')
            {
                j--;
                continue;
            }
            // now j at the end of the word
            i = j;
            while (i>=0 && s[i] != ' ')
            // i>=0 should first.
            {
                i--;
            }
            // now i is at the beginning of the word
            // the word is from i+1 to j
            res += (s.substr(i + 1, j - (i + 1) + 1) + " ");
            j = i;
        }
        // remove final space
        return res.substr(0,res.size()-1);
    }
};

int main(){
    Solution s;
    string q = "  hello world  ";
    printf(s.reverseWords(q).c_str());
}
