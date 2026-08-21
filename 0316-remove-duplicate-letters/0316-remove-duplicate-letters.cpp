#include <string>
using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        string answer;
        while (s.length() > 0)
        {
            // 중복이 없으면 push
            if (answer.find(s.front()) == string::npos)
            {
                answer += s.front();
                s.erase(s.begin(), s.begin() + 1);
            }
            else
            {
                int idx = answer.find(s.front());
                bool move = false;

                // 중복을 빼면 그 자리를 누가 차지하는지 확인
                for (int i = idx + 1; i < answer.size(); i++)
                {
                    if (answer[i] < s.front())
                    {
                        move = true;
                        break;
                    }
                    if (s.find(answer[i]) == string::npos)
                        break;
                }
                if (move)
                {
                    answer.erase(idx, 1);
                    answer += s.front();
                }
                s.erase(s.begin(), s.begin() + 1);
            }
        }
        return answer;
    }
};