//https://leetcode.cn/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150 

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <ctime>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if(my_map.find(val)==my_map.end()){
            my_arr.push_back(val);
            top++;
            my_map.insert(make_pair(val, top));
            return true;
        } else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(my_map.find(val)!= my_map.end()){

            my_map[my_arr[top]] = my_map[val];
            swap(my_arr[my_map[val]], my_arr[top]);
            my_map.erase(val);
            my_arr.pop_back();
            top--;
            return true;
            
            
        } else{
            return false;
        }
    }
    
    int getRandom() {
        if(my_arr.empty()){
            return 0;
        }
        int num_index = rand() %  my_arr.size();
        return my_arr[num_index];
    }

private:
    map<int, int> my_map;
    vector<int> my_arr;
    int top = -1;
};

int main() {
    RandomizedSet* obj = new RandomizedSet();
    bool param_1 = obj->insert(1);
    bool param_2 = obj->remove(1);
    int param_3 = obj->getRandom();
}