#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	vector<int> answer;
	unordered_map<string, string> parent;  // <자식, 부모>
	unordered_map<string, int> cost;	   // <판매자, 수익>
	parent["root"] = "root";
	for (int i = 0; i < enroll.size(); i++) {
		if (referral[i] == "-") {  // 추천인 없는 경우
			parent[enroll[i]] = "root";
		} else {  // 추천인 있는 경우
			parent[enroll[i]] = referral[i];
		}
	}

	for (int i = 0; i < seller.size(); i++) {
		string current = seller[i];
		int currentAmount = amount[i] * 100;
		while (current != "root" && currentAmount > 0) {
			int commission = currentAmount / 10;		  // 수수료
			cost[current] += currentAmount - commission;  // 현재 판매자 수익
			currentAmount = commission;					  // 다음 추천인에게 전달할 돈
			current = parent[current];					  // 다음 추천인으로 이동
		}
	}

	for (auto& iter : enroll) {
		answer.push_back(cost[iter]);
	}
	return answer;
}