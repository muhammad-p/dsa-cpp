#include <iostream>
#include <stack>
int main()
{
    std::stack<char> s;
    std::string str = "Macbook-Air M4";
    std::cout << str << "\n";
    int i = 0;
    while (str[i] != '\0')
    {
        s.push(str[i]);
        i++;
    }

    for (int j = 0; !s.empty(); j++)
    {
        str[j] = s.top();
        s.pop();
    }
    std::cout << str << "\n";

    return 0;
}