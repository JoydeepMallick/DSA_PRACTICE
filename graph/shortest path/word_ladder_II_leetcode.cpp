// Memeory exceeded error
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);

        int lvl = 0;
        vector<vector<string>> posSeq;

        while (!q.empty())
        {
            vector<string> order = q.front();
            q.pop();
            // remove all last words in order from set
            if (order.size() > lvl)
            {
                lvl++;
                for (auto s : usedOnLevel)
                {
                    wordset.erase(s);
                }
            }

            // pick last word of order
            string lastword = order.back();
            if (lastword == endWord)
            {
                if (posSeq.size() == 0)
                    posSeq.push_back(order);
                else if (order.size() == posSeq[0].size())
                    posSeq.push_back(order);
            }

            // check all possible combinations
            for (int i = 0; i < lastword.size(); i++)
            {
                char original = lastword[i];
                for (int c = 'a'; c <= 'z'; c++)
                {
                    lastword[i] = c;
                    if (wordset.find(lastword) != wordset.end())
                    {
                        order.push_back(lastword);
                        q.push(order);
                        usedOnLevel.push_back(lastword);
                        order.pop_back();
                    }
                }
                lastword[i] = original;
            }
        }
        return posSeq;
    }
};

// most optimized solution

class Solution
{
private:
    vector<vector<string>> ans;

    void dfs(string word, map<string, int> &mp, vector<string> &seq)
    {
        int steps = mp[word];
        if (steps == 0)
        {
            // begin word found hence seq complete
            ans.push_back(seq);
            // the actual seq is from begin to end not the reverse
            reverse(ans.back().begin(), ans.back().end());
            return;
        }
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (mp.count(word) > 0       // if word exists in map
                    && mp[word] == steps - 1 // if stepcount is one less
                )
                {
                    seq.push_back(word);
                    dfs(word, mp, seq);
                    seq.pop_back(); // return to original state
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<string> q;
        q.push(beginWord);
        map<string, int> mp;
        unordered_set<string> st(wordList.begin(), wordList.end()); // used for checking
        st.erase(beginWord);                                        // alreadu accounted in map
        mp[beginWord] = 0;
        while (!q.empty())
        {
            string word = q.front();
            int steps = mp[word];
            q.pop();
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word) > 0)
                    {
                        q.push(word);
                        st.erase(word); // remove from set as used
                        mp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }

        for (auto it : mp)
            cout << it.first << " " << it.second << endl;

        if (mp.find(endWord) != mp.end())
        {
            // we found one way and stored in map the order
            vector<string> seq;
            // always starts from endword
            seq.push_back(endWord);
            dfs(endWord, mp, seq);
        }
        // global variable but private
        return ans;
    }
};