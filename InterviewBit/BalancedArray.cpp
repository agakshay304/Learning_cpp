int Solution::solve(vector<int> &A) {
    int n = A.size();
        int result = 0;
        int even = 0;
        int odd =0;
        
        for(int i = 0 ; i < A.size() ; i++){
            if(i%2 == 0)
                even += A[i];
            else
                odd += A[i];
        }
        
        int keven = 0;
        int kodd =0;
        
        for(int i = 0 ; i < A.size() ; i++){
            if(i%2 == 0){
                if((even - (A[i]+keven) + kodd) == ((odd-kodd) + keven))
                    result += 1;
                keven += A[i];    
            }
            else{
                if((odd - (A[i]+kodd) + keven) == (kodd + (even-keven)))
                    result += 1;
                kodd += A[i];    
            }
        }
        
        return result;
}
