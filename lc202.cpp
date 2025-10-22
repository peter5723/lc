#include<vector>
#include<sstream>
#include<string>
#include<map>
#include <unordered_map>
using namespace std;

//https://leetcode.cn/problems/happy-number/?envType=study-plan-v2&envId=top-interview-150

// 希望由这道题学习处理循环的算法
// 快慢指针法
// 这个方法很简单又很聪明，判断是否会存在循环：
// 让快指针走两步，慢指针走一步
// 如果在循环中，则一定会相遇
// 证明：他们的相对速度为 1。
// 反之，快指针就会到达终点
class Solution {
public:

    int nextsum(int n) {
        int res = 0;
        int ge = 0;
        while (n != 0) {
            ge = n % 10;
            res += ge * ge;
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        int slowpoint = nextsum(n);
        int fastpoint = nextsum(nextsum((n)));
        while (fastpoint != 1 && slowpoint != fastpoint) {
            slowpoint = nextsum(slowpoint);
            fastpoint = nextsum(nextsum(fastpoint));
        }

        return fastpoint == 1;
    }
};


int main() {
    Solution s;
    s.isHappy(2);
    return 0;
}
