#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ; 
    cin>>t; 

    while(t--){
        int n , m ; 

        cin>>n >> m ; 
        vector<int> freq(m+1, 0);
        for(int i = 0 ; i < n ;i++){
            int x ;
            cin >> x ; 
            freq[x]++;
        }
        vector<int> suffix(m+2, 0);
        for (int i = m; i >= 1; i--) {
            suffix[i] = suffix[i + 1] + freq[i];
        }
        int ans = 0 ; 
        for(int y = 1 ; y <= m ; y++){
        int curr = freq[y]+ suffix[y+1];
        if(2*y <= m ){
            curr+= freq[2*y];
        }
        ans = max(ans , curr);

        }
        
        cout<<ans<<"\n";

    }


    return 0;
}