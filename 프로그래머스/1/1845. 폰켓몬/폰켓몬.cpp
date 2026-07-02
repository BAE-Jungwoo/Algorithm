#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> s(nums.begin(), nums.end());
    if (s.size() <= (nums.size() / 2)) answer = s.size();
    else if (s.size() > (nums.size() / 2)) answer = nums.size() / 2;
    return answer;
}