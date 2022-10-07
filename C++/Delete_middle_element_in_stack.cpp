#include<bits/stdc++.h>
using namespace std;

class Solution{
  public: 
    void solve(stack<int> &s, int k){
            if(k==1){
                s.pop();
                return;
            }
            int t = s.top();
            s.pop();
            solve(s,k-1);
            s.push(t);
        }

    void deleteMid(stack<int>&s, int sizeOfStack)
        {
         
            if(sizeOfStack==0)
                return;
            solve(s,sizeOfStack/2 + 1);

        }
};

int main(){
  stack<int> mystack = {4, 2, 6, 0, 3, 8, 9};
  Solution ob;
  ob.deleteMid(mystack, mystack.size());
  while(!mystack.empty()){
    cout<<mystack.top();
    mystack.pop();
  }
  cout<<endl;
  return 0;
}
