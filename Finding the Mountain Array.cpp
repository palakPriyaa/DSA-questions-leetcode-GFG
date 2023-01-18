class Solution {
public:
    int findAns(int n,int k){
        if(n==1)return 0;
        else
        return (findAns(n-1,k)+k)%n;
    }
    int findTheWinner(int n, int k) {
        return findAns(n,k)+1;
        
    }
};
