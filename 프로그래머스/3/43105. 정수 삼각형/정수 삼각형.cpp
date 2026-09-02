#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int dp[501][501];

int dfs(int startX, int startY, const vector<vector<int>>& triangle)
{
    // 이미 계산한 곳이면 바로 반환
    if (dp[startY][startX] != -1)
        return dp[startY][startX];

    // 마지막 행이면 현재 값을 dp에 저장
    if (startY == triangle.size() - 1)
        return dp[startY][startX] = triangle[startY][startX];

    // 현재 위치 + 왼쪽 아래/오른쪽 아래 중 큰 값
    dp[startY][startX] =
        triangle[startY][startX] +
        max(
            dfs(startX, startY + 1, triangle),
            dfs(startX + 1, startY + 1, triangle)
        );

    return dp[startY][startX];
}

int solution(vector<vector<int>> triangle)
{
    memset(dp, -1, sizeof(dp));

    return dfs(0, 0, triangle);
}