#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

// -------- Approach 1: Using Map (add your logic) --------
vector<int> unionUsingMap(int arr1[], int n, int arr2[], int m)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr1[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        mp[arr2[i]]++;
    }
    vector<int> result;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        result.push_back(i->first);
    }
    return result;
}

// -------- Approach 2: Using Set (add your logic) --------
vector<int> unionUsingSet(int arr1[], int n, int arr2[], int m)
{
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        st.insert(arr2[i]);
    }
    vector<int> result;
    for (auto i = st.begin(); i != st.end(); i++)
    {
        result.push_back(*i);
    }
    return result;
}

// -------- Approach 3: Two-Pointer Optimal (add your logic) --------
vector<int> unionUsingTwoPointer(int arr1[], int n, int arr2[], int m)
{
    vector<int> result;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            if (result.empty() || result.back() != arr1[i])
                result.push_back(arr1[i]);
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            if (result.empty() || result.back() != arr2[j])
                result.push_back(arr2[j]);
            j++;
        }
        else
        {
            if (result.empty() || result.back() != arr1[i])
                result.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    while (i < n)
    {
        if (result.empty() || result.back() != arr1[i])
            result.push_back(arr1[i]);
        i++;
    }

    while (j < m)
    {
        if (result.empty() || result.back() != arr2[j])
            result.push_back(arr2[j]);
        j++;
    }

    return result;
}

int main()
{
    int n, m;
    cout << "Enter size of arr1: ";
    cin >> n;

    cout << "Enter size of arr2: ";
    cin >> m;

    int arr1[n], arr2[m];

    cout << "Enter elements of arr1: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter elements of arr2: ";
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    vector<int> u1 = unionUsingMap(arr1, n, arr2, m);
    vector<int> u2 = unionUsingSet(arr1, n, arr2, m);
    vector<int> u3 = unionUsingTwoPointer(arr1, n, arr2, m);

    cout << "Union Using Map";
    for (int i = 0; i < u1.size(); i++)
    {
        cout << u1[i] << " ";
    }

    cout << "Union Using Set";
    for (int i = 0; i < u2.size(); i++)
    {
        cout << u2[i] << " ";
    }

    cout << "Union Using 2 Pointer";
    for (int i = 0; i < u3.size(); i++)
    {
        cout << u3[i] << " ";
    }

    return 0;
}
