
#include <bits/stdc++.h>
using namespace std;

//test function 
template<typename T>
void print(T wlist){
    for(auto it : wlist){
        cout << it << " ";
    }
    cout << endl;
}

//not needed to be added

vector<vector<string>> findSequences(string startWord, string targetWord, vector<string> &wordList){
    unordered_set<string>   wlist(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({startWord});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(startWord);
    int level = 0;

    vector<vector<string>> ans;

    while(!q.empty()){
        vector<string> v = q.front();
        q.pop();


/* cout << "Current poped element : ";print(v); */

        //erase all words that have been used in previous levels to transform
        if((int)v.size() > level){
            level++;
/* cout << "Level " << level << " complete\n"; */
            for(auto it : usedOnLevel){
                wlist.erase(it);
            }

/* cout << "Updated wlist : "; print(wlist); */
        }

        //pick up the last word from current sequence 
        string word = v.back();

        if(word == targetWord){
            if(ans.size() == 0){
                //first entry 
                ans.push_back(v);
            }
            else if(ans[0].size() == v.size()){
               ans.push_back(v);//else it wont be minimum length sequence      
            }
        }

        for(int i = 0; i < (int)word.size(); i++){
            char originalchar = word[i];
            for(char c = 'a'; c <= 'z'; c++){
                word[i] = c;
                if(wlist.find(word) != wlist.end()){
                    v.push_back(word);
                    q.push(v);
                    //mark word as visited on the level 
                    usedOnLevel.push_back(word);
                    v.pop_back();//remove the last element
                }
                word[i] = originalchar;
            }
        }
    }

    return ans;

}

int main(){
    string startWord = "hit", targetWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    // hit --> hot --> dot --> dog --> cog
    //          |                       ^ 
    //          v                       |
    //          lot -------> log -------- 
    cout << "\n\nPossible sequences :-\n";
    for(auto seqn : findSequences(startWord, targetWord, wordList)){
        for(auto word : seqn) cout << word << " ";
        cout << endl;
    }

    startWord = "der", targetWord = "dfs";
    vector<string> wordList2 = {"des", "der", "dfr", "dgt", "dfs"};
/* der dfr dfs */
/* der des dfs */
    
    cout << "\n\nPossible sequences :-\n";
    for(auto seqn : findSequences(startWord, targetWord, wordList2)){
        for(auto word : seqn) cout << word << " ";
        cout << endl;
    }

    return 0;
}
