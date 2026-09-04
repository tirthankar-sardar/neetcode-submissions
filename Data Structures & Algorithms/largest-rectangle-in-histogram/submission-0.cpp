#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> nextSmallerElement(vector<int>& arr, int n) {
        stack<int> st;
        st.push(-1);

        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];

            while (st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }


    vector<int> prevSmallerElement(vector<int>& arr, int n) {
        stack<int> st;
        st.push(-1);

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int curr = arr[i];

            while (st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);   // Push index, not value
        }

        return ans;
    }


    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);

        int area = 0;

        for (int i = 0; i < n; i++) {

            if (next[i] == -1) {
                next[i] = n;
            }

            int length = heights[i];
            int breadth = next[i] - prev[i] - 1;

            int newArea = length * breadth;

            area = max(area, newArea);
        }

        return area;
    }
};