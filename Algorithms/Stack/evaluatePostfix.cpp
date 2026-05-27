#include<bits/stdc++.h>
#define endl char(10)

using namespace std;

typedef long long ll;

int evaluatePostfix(string str)
{
    stack <string> s;
    for (int i = 0; i < str.size(); i++)
    {
        if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' )
        {
            string opr2=s.top();
            s.pop();
            string opr1=s.top();
            s.pop();
            


        }
        else
        {
            s.push(str[i]);
        }
    }
    return s.top();
    
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   

   return 0;
}
