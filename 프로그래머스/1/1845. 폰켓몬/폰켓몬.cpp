#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int N = nums.size();
    set<int> table;
    
    for(auto a : nums)
        table.insert(a);
    
    answer = min((N / 2), (int)table.size());
    
    return answer;
}