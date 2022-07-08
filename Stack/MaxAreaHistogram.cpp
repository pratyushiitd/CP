// https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = heights[0];
        stack<int> st;
        st.push(-1);
        int i = 0;
        int n = heights.size();
        while(i < n){
            while(st.top()>=0 && heights[st.top()] >= heights[i]){
                int ht = st.top();
                st.pop();
                area = max(area, heights[ht]*(i-st.top()-1));
                cout << area << endl;
            }
            st.push(i++);
        }
        while(st.top()>= 0) {
            int ht = st.top();
            cout << ht;
            st.pop();
            area = max(heights[ht]*(n - st.top()-1), area);
            cout << '*' << area << endl;
        }
        return area;
    }
};
