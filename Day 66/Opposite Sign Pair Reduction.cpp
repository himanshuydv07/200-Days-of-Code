class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
         vector<int> st;

    for (int x : arr) {
        bool alive = true;

        while (!st.empty() && alive && ((st.back() > 0 && x < 0) || (st.back() < 0 && x > 0))) {
            int y = st.back();

            if (abs(y) == abs(x)) {
                st.pop_back();
                alive = false;
            } 
            else if (abs(y) > abs(x)) {
                alive = false;
            } 
            else {
                st.pop_back();
            }
        }

        if (alive) st.push_back(x);
    }

    return st;
    }
};
