#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int N;
    cin >> N;
    string beginStr;
    string endStr;
    cin >> beginStr >> endStr;
    unordered_set<string> strList;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        strList.insert(s);
    }

    unordered_map<string, int> visitMap;
    visitMap.insert({beginStr, 1});
    queue<string> que;
    que.push(beginStr);
    while (!que.empty()) {
        string word = que.front();
        que.pop();
        for (int i = 0; i < word.size(); i++) {
            string newword = word;
            for (int j = 0; j < 26; j++) {
                newword[i] = j + 'a';
                if (newword == endStr) {
                    cout << visitMap[word] + 1 << endl;
                    return 0;
                }
                if (strList.find(newword) != strList.end() &&
                    visitMap.find(newword) == visitMap.end()) {
                    visitMap.insert({newword, visitMap[word] + 1});
                    que.push(newword);
                }
            }
        }
    }
    cout << 0 << endl;
}