#include <string>
#include <vector>

using namespace std;

void dfs(const vector<int>& numbers, int target, int& answer, int index, int cnt) {
    if (index == numbers.size()) {
        if (cnt == target) answer++;
        return;
    }
    
    // 선택: +
    dfs(numbers, target, answer, index + 1, cnt + numbers[index]);
    
    // 선택: -
    dfs(numbers, target, answer, index + 1, cnt - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, answer, 0, 0);
    return answer;
}