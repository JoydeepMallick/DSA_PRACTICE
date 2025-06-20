class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // since its about finding all possiblities and then searching lets perform recursion and BFS
        // BFS is levelwise ensuring the endWord which is found out at lowest level then answer will the 'level' steps only. Since smaller path lead to end hence it will min steps in dfs
        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // startword resides in level 0 since it may or maynot exist in wordList
        unordered_set<string> words;
        for (auto w : wordList)
        {
            words.insert(w);
        }

        while (!q.empty())
        {
            string w = q.front().first;
            int lvl = q.front().second;
            q.pop();
            // if w is the endWord hence found
            if (w == endWord)
                return lvl;

            // search for words, we are searching like
            //  [a|b|...|z] c2 c3..cn
            //  c1 [a|b|...|z] c3..cn
            //  c1 c2 [a|b|...|z] c4..cn
            //..... so on

            for (int i = 0; i < w.size(); i++)
            {
                char original = w[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    w[i] = c;

                    if (words.find(w) != words.end())
                    {
                        words.erase(w); // remove from set
                        q.push({w, lvl + 1});
                    }
                }
                w[i] = original;
            }
        }

        // since beginword not equal end word hence 0 never returned
        // if end word never exist in array then also 0
        return 0;
    }
};