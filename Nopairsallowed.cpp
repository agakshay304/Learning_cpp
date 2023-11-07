#include <iostream>
#include <string>
#include <vector> 
using namespace std;

vector<int> nopair(vector<string> words)
{
    vector<int> ans;

    for(int i=0;i<words.size();i++)
    {
        string word=words[i];
        int count=0;
        for(int j=0;j<word.size();j++)
        {
            if(word[j]==word[j+1])
            {
                count++;
                j++;
            }
        }
        ans.push_back(count);
    }

    return ans;

}

int main()
{
    vector<string> words;
    words.push_back("add");
    words.push_back("booook");
    words.push_back("break");

    vector<int> ans=nopair(words);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}