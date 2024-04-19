class TrieNode{
    public:
    vector<TrieNode*> v;
    bool is_word;
    

    TrieNode(){
        v.assign(26,nullptr);
        is_word=false;
       
    }

};
class Solution {
public:
    void search(TrieNode*root,string & word,string & ans){
        int n=word.size();
        string t;
        for(int i=0;i<n;i++){
            if(root->v[word[i]-'a']==nullptr){
                ans.append(word);
                return;
            }
            t+=word[i];
            root=root->v[word[i]-'a'];
            if(root->is_word){
                ans.append(t);
                return;
            }
        }
        ans.append(word);
    }
    void insert(TrieNode*root,string & word){
        int n=word.size();
        for(int i=0;i<n;i++){
            if(root->v[word[i]-'a']==nullptr){
                root->v[word[i]-'a']=new TrieNode();
              
            }
            
            root=root->v[word[i]-'a'];
        }
        root->is_word=true;
       
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode*root=new TrieNode();
        for(auto & x:dictionary){
            insert(root,x);
        }
        string ans="";
        string t;
        for(char c:sentence){
            if(c==' '){
                search(root,t,ans);
                ans+=' ';
                t.clear();
            }else{
                t+=c;
            }
        }
        search(root,t,ans);
        return ans;

    }
};