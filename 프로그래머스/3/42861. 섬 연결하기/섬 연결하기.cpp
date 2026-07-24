#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// x 정점의 부모 정점 찾기
int getRoot(vector<int>& parent, int x) {
    if (parent[x] == x) 
        return x;
    return parent[x] = getRoot(parent, parent[x]);
}

// 부모가 같은, 같은 그룹으로 두 정점을 병합
void unionParent(vector<int>& parent, int a, int b) {
    int parent_a = getRoot(parent, a);
    int parent_b = getRoot(parent, b);
    if (parent_a < parent_b)
        parent[parent_b] = parent_a;
    else
        parent[parent_a] = parent_b;
}

// 두 정점이 같은 부모를 가졌는지 확인
bool find(vector<int>& parent, int a, int b) {
    int parent_a = getRoot(parent, a);
    int parent_b = getRoot(parent, b);
    if (parent[parent_a] == parent[parent_b])
        return true;
    else
        return false;
}

// 비용 오름차순 정렬
bool compare(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;   
    sort(costs.begin(), costs.end(), compare);

    vector<int> parent(n);
    for (int i = 0; i < parent.size(); ++i) 
        parent[i] = i;
    
    for (int i = 0; i < costs.size();++i) {
        if (!find(parent, costs[i][0], costs[i][1])) {
            unionParent(parent, costs[i][0], costs[i][1]);
            answer += costs[i][2];
        }
    }

    return answer;
}