#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {1, 3, 4, 5, 6, 7, 8};
    int k = 3;
    int windowsum = 0;
    for (int i = 0; i < k; i++)
    {
        windowsum += arr[i];
    }
    cout<<"Window Sum"<<windowsum<<endl;
    for(int i=k;i<arr.size();i++){
        windowsum+=arr[i]-arr[i-k];
        cout<<"Window Sum"<<windowsum<<endl;
    }
    return 0;
}