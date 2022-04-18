// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb33e/00000000009e762e#problem

#include <bits/stdc++.h>

using namespace std;

bool check_palin(string s){
    int n = s.length();
    for(int i = 0; i < n/2; i++){
        if (s[i] != s[n-i-1])return false;
    }
    return true;
}
void gen_all_str(int n, int arr[], vector<string> &vec, int i, string check)
{
    if (i == n){
        string temp = "";
        for(int j = 0; j < n; j++){
            temp+=to_string(arr[j]);
        }
        for(int j = 0; j < n; j++){
            if (check[j] == '?' || check[j] == temp[j])continue;
            return;
        }
        if (!check_palin(temp))
        vec.push_back(temp);
        return;
    }
    arr[i] = 0;
    gen_all_str(n, arr, vec, i+1,check);
    arr[i] = 1;
    gen_all_str(n, arr, vec, i+1,check);
}
void solve(int t){
    
    int n; cin >> n; string str; cin >> str;
    bool ans = true;
    if (str.length() >= 5){
        vector<string> prev, next;
        string check = str.substr(0,5);
        int arr[5];
        memset(arr, 0, sizeof(arr));
        gen_all_str(5, arr, prev, 0, check);
        bool valid = true;
        for(int i = 0; i < n; i++){
            //odd
            int len = 1;
            int p1 = i-1, p2 = i+1;
            if (str[i] != '?')
            while(p1 >= 0 && p2 < n && len < 5){
                if (str[p1] == str[p2] && str[p1] != '?'){
                    len+=2;
                    p1--;p2++;
                }else break;
            }
            if (len >= 5){
                valid = false;
                break;
            }
            //even
            len = 0;
            p1 = i, p2 = i+1;
            while(p1 >= 0 && p2 < n && len < 5){
                if (str[p1] == str[p2] && str[p1] != '?'){
                    len+=2;
                    p1--;p2++;
                }else break;
            }
            if (len >= 5){
                valid = false;
                break;
            }
        }
        if (prev.size() == 0 || !valid)ans = false;
        else{
            for(int i = 5; i < n; i++){
                // for(auto x : prev)cout << x << ' ';
                // cout << endl;
                for(string x: prev){
                    string new_str = x.substr(1);
                    if (str[i] == '?'){
                        string s1 = new_str+"1";
                        string s2 = new_str+"0";
                        if (!check_palin(s1) && !check_palin(x+"1")){
                            next.push_back(s1);
                        }
                        if (!check_palin(s2) && !check_palin(x+"0")){
                            next.push_back(s2);
                        }
                    }else{
                        new_str+=str[i];
                        if (!check_palin(new_str) && !check_palin(x+str[i])){
                            next.push_back(new_str);
                        }
                    }
                }
                    prev = next;
                    next.clear();
                            if (prev.size() == 0){
                    ans = false;
                    break;
                }
            }
        }
    }else ans = true;
    
    if (!ans)
    printf("Case #%d: %s\n", t, "IMPOSSIBLE");
    else printf("Case #%d: %s\n", t, "POSSIBLE");
}
// 10000, 10010, 10011
// 00001, 00101, 00111, 00110
// 00010, 01100
// 11000
int main(int argc, char** argv)
{
    int t; cin >> t;
    for(int i = 1; i <= t; i++)solve(i);
    return 0;
}
