// https://www.hackerrank.com/challenges/contacts/problem
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'contacts' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_STRING_ARRAY queries as parameter.
 */

struct node{
    int freq;
    node* child[26];
    node(){
        freq = 0;
        for(int i = 0; i < 26; i++)child[i] = NULL;
    }  
};

void add(string s, node* root){
    node* tmp = root;
    root->freq++;
    for(int i = 0; i < (int)s.size(); i++){
        if (tmp->child[s[i]-'a'] == NULL){
            tmp->child[s[i]-'a'] = new node();
        }
        tmp = tmp->child[s[i]-'a'];
        tmp->freq++;
    }
}
int get_count(string s, node* root){
    node* tmp = root;
    for(int i = 0; i < (int)s.size(); i++){
        if (tmp->child[s[i] - 'a'] == NULL)return 0;
        tmp=tmp->child[s[i] - 'a'];
    }
    return tmp->freq;
}
vector<int> contacts(vector<vector<string>> queries) {
    node* root = new node();
    vector<int> ans;
    for(auto q: queries){
        if (q[0] == "add"){
            add(q[1], root);
        }else{
            ans.push_back(get_count(q[1], root));
        }
    }
    return ans;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string queries_rows_temp;
    getline(cin, queries_rows_temp);

    int queries_rows = stoi(ltrim(rtrim(queries_rows_temp)));

    vector<vector<string>> queries(queries_rows);

    for (int i = 0; i < queries_rows; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            string queries_row_item = queries_row_temp[j];

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> result = contacts(queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
