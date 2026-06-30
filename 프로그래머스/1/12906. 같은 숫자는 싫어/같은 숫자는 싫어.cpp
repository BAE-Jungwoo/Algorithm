#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    stack<int> s;
    for(int i = 0; i < arr.size(); i++) {
        if(s.empty()) {
            s.push(arr[i]);
            continue;
        }
	    if(arr[i] == s.top()) continue;
	    s.push(arr[i]);
    }
    
    vector<int> answer(s.size(), 0);
    for(int i = s.size() - 1; i >= 0; i--) {
	    answer[i] = s.top();
	    s.pop();
    }
    
    return answer;
}