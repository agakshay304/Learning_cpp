#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;


vector<int> stockspan(vector<int> prices)
{
    vector<int> ans;
    stack<pair<int,int> > st;

    for(int i=0;i<prices.length();i++)
    {
        int days=1;
        while(!st.empty && st.top().first<=prices[i])
        {
            days+=st.top().second;
            st.pop();
        }
        st.push({prices,days});
        ans.push_back(days);
    }
    return ans;
}

int main()
{
    vector <int> prices;
    prices.push_back(100);
    prices.push_back(80);
    prices.push_back(60);
    prices.push_back(70);
    prices.push_back(60);
    prices.push_back(75);
    prices.push_back(85);
    vector <int> ans=stockspan(prices);
    for(int i=0;i<ans.length();i++)
    {
        cout<<ans[i]<<" ";
    }
}