int Solution::solve(vector<int> &A) {
    int n=A.size();
    vector<int> right(n);
    int ans=0;

    //For suffix right side
    for(int i=n-1;i>=0;i--)
    {
        if(i==n-1)
        {
            right[i]=A[i];
        }
        else
        right[i]=max(right[i+1],A[i]);
    }

    //for left side
    set<int>s;
    s.insert(A[0]);

    for(int i=1;i<n;i++)
    {
        s.insert(A[i]);
        auto it=s.find(A[i]);

        if(it!=s.begin() && right[i]!=A[i])
        {
            ans=max(ans,(*--it)+A[i]+right[i]);
        }
    }
    return ans;

    }
