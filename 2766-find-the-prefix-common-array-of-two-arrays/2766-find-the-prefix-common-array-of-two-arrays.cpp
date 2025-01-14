class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        vector<int> C(n);
        int k = 0; int ans =0;
        set<int>s1;
        set<int>s2;
        
        for(int i =0;i<n;i++){
            s1.insert(A[i]);
            s2.insert(B[i]);
            
            if(s1.count(B[i]) && B[i] != A[i])
                ans+= 1;
            
            if(s2.count(A[i])){
                ans+= 1;
            }
            
            C[i] = ans;
            
            
        }
        return C;
        
    }
};
