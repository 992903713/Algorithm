class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        unordered_map<string,int> M;
        queue<string> Q;
        M[beginWord] = 1;
        Q.push(beginWord);
        while(!Q.empty()){
            string curWord = Q.front();
            Q.pop();
            //a��z�滻curWord��ÿһλ
            for(int i=0; i<curWord.size(); ++i){
                string newWord = curWord;
                for(char ch = 'a'; ch <= 'z'; ++ch){
                    newWord[i] = ch;
                    if(dict.count(newWord) && newWord == endWord) return M[curWord] + 1;
                    //�ڼ�����ȴû�б����ʹ�
                    if(dict.count(newWord) &&  !M.count(newWord)){
                        Q.push(newWord);
                        M[newWord] = M[curWord] + 1;
                    }
                }
            }
        }
        return 0;
    }
};
