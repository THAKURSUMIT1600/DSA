#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>diffarr(arr.size());
    diffarr[0]=arr[0];
    for(int i=1;i<arr.size();i++){
        diffarr[i]=arr[i]-arr[i-1];
    }
    cout<<"Difference array"<<endl;
    for(int i=0;i<diffarr.size();i++){
        cout<<diffarr[i]<<" ";
    }
    cout<<endl;
    return 0;

}