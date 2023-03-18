// Word Ladder(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    int steps = 0;
    unordered_set<string> words;
    for (auto val : wordList)
        words.insert(val);
    auto itr = words.find(endWord);
    if (itr == words.end())
    {
        return 0;
    }
    queue<string> q;
    // WordList hmko de rakha hai.
    q.push(beginWord);
    while (q.size() > 0)
    {
        steps++;
        int sz = q.size();
        for (int i = 0; i < sz; ++i)
        {
            auto currWord = q.front();
            q.pop();
            for (int i = 0; i < currWord.size(); ++i)
            {
                char temp = currWord[i];
                for (char ch = 'a'; ch <= 'z'; ++ch)
                {
                    currWord[i] = ch;
                    if (currWord == endWord)
                        return steps + 1;
                    auto itr = words.find(currWord);
                    if (itr != words.end())
                    {
                        q.push((*itr));
                        words.erase(itr);
                    }
                }
                currWord[i] = temp;
            }
        }
    }
    return 0;
}
