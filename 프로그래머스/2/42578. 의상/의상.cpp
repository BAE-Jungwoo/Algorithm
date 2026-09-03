#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
	map<string, vector<string>> c_map;
	for (int i = 0; i < clothes.size(); i++) 
        c_map[clothes[i][1]].push_back(clothes[i][0]);

	for (auto& it : c_map)
		answer *= (it.second.size() + 1);
	return answer - 1;
}