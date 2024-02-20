#include <bits/stdc++.h>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string> &wordList){
    queue<pair<string ,int>> q;// pair {string, level}
    q.push({startWord, 1});
    
    unordered_set<string> wlist(wordList.begin(), wordList.end());
    wlist.erase(startWord);

    while(!q.empty()){
        string word = q.front().first;
        int level = q.front().second;
        q.pop();
        if(word == targetWord) return level;

        for(int i = 0; i < (int)word.length() ;i++){
            char originalchar = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;//create new word 
                // if word exists in set then perform further 
                if(wlist.find(word) != wlist.end()){
                    wlist.erase(word);
                    q.push({word ,level+1});
                }
            }
            word[i] = originalchar;//restoring actual word again 
        }
    }

    return 0;// occurs only when no valid sequence is possible to reach target
}

int main(){
    string startWord = "hit", targetWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    // hit --> hot --> dot --> dog --> cog
    //          |                       ^ 
    //          v                       |
    //          lot -------> log -------- 
    cout << "Word Ladder length is " << wordLadderLength(startWord, targetWord, wordList) << endl;
    
    startWord = "der", targetWord = "dfs";
    vector<string> wordList2 = {"des", "der", "dfc", "dgt", "dfs"};
    // der ---> dfr ---> dfs
    cout << "Word Ladder length is " << wordLadderLength(startWord, targetWord, wordList2) << endl;
    return 0;
}
