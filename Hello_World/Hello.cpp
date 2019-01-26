#include<iostream>
#include<vector>
#include<unistd.h>

using namespace std;

int main()
{
    cout<<"Hello VS Code!"<<endl;
    vector<int> v;
    for(int i=10;i>0;i--)
        v.push_back(i);
    cout<<"The elements in vector:"<<endl;
    for(auto e :v)
        cout<<" "<<e;
    cout<<endl;

    return 0;
}
