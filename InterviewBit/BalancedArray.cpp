/*Explanation:-
The first observation is that if you remove an element, all the succeeding elements will become odd if they were even and vice versa. So, after removing we have to account for this while checking.
Another crucial thing is that nothing changes for the preceding elements.

An O(N^2) solution would be to check for every element and calculate new sum for the succeeding elements. But, don’t we already have the sum. If we calculate oddsum and evensum for the entire array. And, store the odd sum and even sum till before the current element (as we will remove the current element) in coddsum and cevensum respectively.
Then we can find the odd sum or even sum for the succeeding elements by using these.

Let me give you an example for an element i, (0<i<n). Let’s assume i is odd, for even it will be similar.
Now if we remove the element all the succeeding elements will become even -> odd and vice versa.
So, we need to calculate both odd sum and even sum for succeeding elements.

What is evensum - cevensum ? it means the sum of all succeeding elements which are even had we not removed the ith element. But we did so now it gives us the sum of all succeeding elements which are “odd”. Since all succeeding elements will shift by one

So, coddsum + evensum - cevensum will give the changed array’s odd sum.

But what about changed array’s even sum?

Simply, oddsum - coddsum will not give the changed array’s succeeding element even sum. Because the oddsum also contain arr[i], the current element, so we have to subtract that.

So, cevensum + oddsum - coddsum - arr[i] will give the changed array’s even sum.

This can be similarly done if i is even.   */
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
