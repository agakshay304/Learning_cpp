#include <iostream>
#include <stack>
using namespace std;

class queue
{
    stack<int> s1;
    stack<int> s2;

    public:
    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        while(s1.empty() && s2.empty())
        {
            cout<<"Queue Empty"<<endl;
            return -1;
        }

        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int top=s2.top();
        s2.pop();
        return top;
    }

    bool empty()
    {
        if(s1.empty() && s2.empty())
        {
            return true;
        }
        return false;   
    }

};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.empty()<<endl;
    cout<<q.pop();
    cout<<q.pop();
    cout<<q.pop();
    cout<<q.pop();
    cout<<q.pop();
    cout<<q.empty()<<endl;
}