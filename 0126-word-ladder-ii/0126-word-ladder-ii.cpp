class Solution {
  unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string bWord;

    void dfs(string word, vector<string>& seq) {
        if (word == bWord) {
            vector<string> path = seq;
            reverse(path.begin(), path.end());
            ans.push_back(path);
            return;
        }

        int steps = mpp[word];
        int sz = word.size();

        for (int i = 0; i < sz; ++i) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                word[i] = ch;
                // Only move to adjacent nodes that lie on the shortest path back to beginWord
                if (mpp.find(word) != mpp.end() && mpp[word] == steps - 1) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set<string> st(wordList.begin(), wordList.end());
        
        // Return early if destination is unreachable
        if (st.find(endWord) == st.end()) return {};

        bWord = beginWord;
        queue<string> q;
        
        q.push(beginWord);
        mpp[beginWord] = 1;
        st.erase(beginWord);

        int sz = beginWord.size();

        // Step 1: BFS to find the shortest distance to each word
        while (!q.empty()) {
            string word = q.front();
            int steps = mpp[word];
            q.pop();

            if (word == endWord) break;

            for (int i = 0; i < sz; ++i) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    word[i] = ch;
                    if (st.count(word)) {
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }

        // Step 2: DFS from endWord back to beginWord to collect all paths
        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;  
    }
};