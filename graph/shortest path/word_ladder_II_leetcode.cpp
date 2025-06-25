//Memeory exceeded error
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);

        int lvl = 0;
        vector<vector<string>> posSeq;

        while(!q.empty()){
            vector<string> order = q.front();
            q.pop();
            //remove all last words in order from set
            if(order.size() > lvl){
                lvl++;
                for(auto s : usedOnLevel){
                    wordset.erase(s);
                }
            }

            //pick last word of order
            string lastword = order.back();
            if(lastword == endWord){
                if(posSeq.size() == 0) posSeq.push_back(order);
                else if(order.size() == posSeq[0].size()) posSeq.push_back(order);
            }

            //check all possible combinations
            for (int i = 0; i < lastword.size(); i++){
                char original = lastword[i];
                for(int c = 'a'; c <= 'z'; c++){
                    lastword[i] = c;
                    if(wordset.find(lastword) != wordset.end()){
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



//most optimized solution
