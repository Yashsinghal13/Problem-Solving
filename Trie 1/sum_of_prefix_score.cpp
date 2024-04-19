struct Node{
public:
	Node* links[26];
	bool flag=false;
    int cntpref=0;
	bool containskey(char ch){
		return links[ch-'a']!=NULL;
	}
	void put(char ch, Node* node){
		links[ch-'a']=node;
	}
	Node* get(char ch){
		return links[ch-'a'];
	}
    void increasePref(){
        cntpref++;
    }
    int getpref(){
        return cntpref;
    }
};
struct Trie{
public:
	Node* root;
	Trie(){
		root=new Node();
	}
	void insert(string word){
		Node* node=root;
		for(int i=0; i<word.length(); i++){
			if(!node->containskey(word[i])){
				node->put(word[i],new Node());
			}
			node=node->get(word[i]);
            node->increasePref();
		}
	}
    int cnt(string word){
        Node* node=root;
        int ans=0;
        for(int i=0; i<word.size(); i++){
            if(!node->containskey(word[i])){
                return ans;
            }
            node=node->get(word[i]);
            ans+=(node->getpref());
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        Trie *tr=new Trie();
        for(auto it:words){
            tr->insert(it);
        }
        for(auto it:words){
            int chk=tr->cnt(it);
            ans.push_back(chk);
        }
        return ans;
    }
};