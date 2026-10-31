class WordDictionary {
public:
    struct trieNode {
        bool endofword;
        //string word;
        trieNode* children[26];
    };
    trieNode* root;
    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->endofword = false;
        //newNode->word = "";
        for(int i=0; i<26; i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    WordDictionary() {
        root = getNode();
    }
    
    //write the insert function using crawler
    void addWord(string word) {
        trieNode* crawler = root;
        for(int i=0; i<word.length(); i++){
            char ch = word[i];

            if(crawler->children[ch-'a'] == NULL){
                crawler->children[ch-'a'] = getNode();
            }
            crawler = crawler->children[ch-'a'];
        }
        crawler->endofword = true;
        //crawler->word = word;
    }

    bool searchWord(string& word, int index, trieNode* crawler){
        if(index == word.size()){
            return crawler->endofword;
        }
        char ch = word[index];
        if(ch == '.'){
            for(int i=0; i<26; i++){
                if(crawler->children[i] != NULL){
                    if(searchWord(word, index+1, crawler->children[i])){
                        return true;
                    }
                }
            }
            return false;
        }
        if(crawler->children[ch-'a'] == NULL){
            return false;
        }
        return searchWord(word, index+1, crawler->children[ch-'a']);
    }
    bool search(string word) {
        return searchWord(word, 0, root);
    }
};