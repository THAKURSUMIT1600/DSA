#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreater(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            result[i] = st.top();
        }
        st.push(nums[i]);
    }

    return result;
}

int main()
{
    vector<int> A = {4, 5, 2, 25, 26};

    vector<int> result = nextGreater(A);

    cout << "Next Greater Elements: ";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}