#include <string>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            s[i] = std::tolower(s[i]);
            if (!std::isalnum(s[i]))
            {
                s.erase(i, 1);
                i--;
            }
        }

        int i = 0;
        int j = s.size() - 1;
        for (; i <= j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }
};
