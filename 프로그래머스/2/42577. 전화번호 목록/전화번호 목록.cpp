#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;
    set<string> book(phone_book.begin(), phone_book.end());
    for (auto &iter : phone_book)
        book.insert(iter);

    while (book.size() > 1)
    {
        auto iter = book.begin();
        string temp = *iter;
        iter = book.erase(iter);
        if (iter->compare(0, temp.size(), temp) == 0)
        {
            answer = false;
            return answer;
        }
    }
    return answer;
}