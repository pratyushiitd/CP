// https://www.hackerrank.com/challenges/no-prefix-set/problem
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'noPrefix' function below.
 *
 * The function accepts STRING_ARRAY words as parameter.
 */
struct node{
    bool leaf;
    node* child[26];
    node(){
        leaf = false;
        for(int i(0); i<26; i++)child[i] = NULL;
    }
};

void add(string s, node* root){
    node* tmp = root;
    for(int i = 0; i < (int)s.length(); i++){
        if (tmp->child[s[i] - 'a'] == NULL)tmp->child[s[i]-'a'] = new node();
        tmp = tmp->child[s[i]-'a'];
    }
    tmp->leaf = true;
}

bool check(string s, node* root){
    node *tmp = root;
    for(int i = 0; i < (int)s.length(); i++){
        if (tmp->child[s[i]-'a'] == NULL){
            if (tmp->leaf)return false;
            else return true;
        }
        tmp = tmp->child[s[i]-'a'];
    }
    return false;
}
void noPrefix(vector<string> words) {
    node* root = new node();
    for(string w: words){
        if (!check(w, root)){
            cout << "BAD SET\n" << w << endl;return; 
        }
        add(w, root);
    }
    cout << "GOOD SET\n";
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    noPrefix(words);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
