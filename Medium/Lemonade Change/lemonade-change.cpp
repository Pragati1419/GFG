//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int five = 0, ten = 0, twen = 0;
        int n=bills.size();
        for(int i = 0; i<n;i++){
           
            if(bills[i] == 5)
            five++;
            else if(bills[i] == 10){
                ten++;
                if(five<=0)  
                return false;
                five--;
            }
            else if(bills[i]==20){
                twen++;
               if(ten>0){
                   ten--;
                   five--;
               }
              else {
                  five-=3;
              }  
            }
            if(five<0  || ten <0) 
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends