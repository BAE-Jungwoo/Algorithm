#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    unordered_map<string, string> parent;
    unordered_map<string, string> emailToName;

    // 부모 설정 및 이름 찾는 역할
    string Find(string &name)
    {
        if (parent.find(name) == parent.end())
        {
            parent[name] = name;
            return name;
        }
        if (parent[name] == name)
            return name;
        return parent[name] = Find(parent[name]);
    }

    // 두 이름을 합치는 역할
    void Union(string &nameX, string &nameY)
    {
        string rootX = Find(nameX);
        string rootY = Find(nameY);
        if (rootX != rootY)
        {
            parent[rootY] = rootX;
        }
    }

    // 계정 병합
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            string name = accounts[i][0];
            string firstEmail = accounts[i][1];
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string email = accounts[i][j];
                emailToName[email] = name;
                Union(firstEmail, email);
            }
        }

        /*
        for (auto &eTN : emailToName)
        {
            cout << "email: " << eTN.first << ", name: " << eTN.second << endl;
        }
        */

        unordered_map<string, vector<string>> mergedAccount;
        for (auto &eTN : emailToName)
        {
            string email = eTN.first;
            string rootEmail = Find(email);
            mergedAccount[rootEmail].push_back(email);
        }

        /*
        for (auto &mA : mergedAccount)
        {
            cout << "rootEmail: " << mA.first << ", emails: ";
            for (auto &email : mA.second)
            {
                cout << email << " ";
            }
            cout << endl;
        }
        */

        vector<vector<string>> result;
        for (auto &mA : mergedAccount)
        {
            string rootEmail = mA.first;
            string name = emailToName[rootEmail];

            vector<string> account;
            account.push_back(name);

            for (auto &email : mA.second)
            {
                account.push_back(email);
            }
            sort(account.begin() + 1, account.end());
            result.push_back(account);
        }

        return result;
    }
};