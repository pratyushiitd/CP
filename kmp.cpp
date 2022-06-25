vector<int> lps_array(string pat)
{
    vector<int> vec(pat.length());
    int i = 1, j = 0;
    vec[0] = 0;
    while(i < pat.length()){
        if (pat[j] != pat[i]){
            if (j > 0)j = vec[j-1];
            else {
                vec[i] = 0;
                i ++;
                j = 0;
            }
        }else{
            vec[i] = j+1;
            j++; i++;
        }
    }
    return vec;
}
vector<int> kmp(string s, string pat){
    vector<int> vec = lps_array(pat);
    int i = 0, j = 0;
    vector<int> ans;
    while(i < s.length()){
        if (s[i] == pat[j]){
            i++; j++;
        }else{
            if (j)j = vec[j-1];
            else {
                i++;
            }
        }
        if (j==pat.length()){
            ans.push_back(i-j);
            j = vec[j-1];
        }
    }
    return ans;
}
int main() {
    string a, b; cin >> a >> b;
    for(auto x: kmp(a,b))cout << x << ' ' << a.substr(x, b.length()) << endl;
}
