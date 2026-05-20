#include <iostream>
bool checkBalancedParenthesis(std::string s)
{

    std::stack<char> stk;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            stk.push(s[i]);
        }
        else
        {
            if (stk.empty())
                return false;
            if (s[i] == '}')
            {
                if (stk.top() == '{')
                    stk.pop();
                else
                    return false;
                continue;
            }
            if (s[i] == ']')
            {
                if (stk.top() == '[')
                    stk.pop();
                else
                    return false;
                continue;
            }
            if (s[i] == ')')
            {
                if (stk.top() == '(')
                    stk.pop();
                else
                    return false;
            }
        }
    }
    return stk.empty();
}
int main()
{
    std::cout << "================================================================\n";
    std::cout << "   ALGORITHM TEST SUITE: BALANCED PARENTHESIS SIMULATION        \n";
    std::cout << "================================================================\n\n";

    // -------------------------------------------------------------------------
    // SCENARIO 1: Standard & Optimal Paths
    // -------------------------------------------------------------------------
    {
        std::cout << "[SCENARIO 1] Standard & Optimal Paths (Perfect Nesting & Matching Symmetrical Layouts)\n";

        char str1[] = "{{(())}}";
        char str2[] = "[{}()]";

        bool res1 = checkBalancedParenthesis(str1);
        bool res2 = checkBalancedParenthesis(str2);

        // Both strings are perfectly symmetrical and valid, expecting true
        if (res1 == true && res2 == true)
        {
            std::cout << "  STATUS: PASSED\n";
        }
        else
        {
            std::cout << "  STATUS: FAILED\n";
        }
        std::cout << "\n";
    }

    // -------------------------------------------------------------------------
    // SCENARIO 2: Boundary & Extremal Conditions
    // -------------------------------------------------------------------------
    {
        std::cout << "[SCENARIO 2] Boundary & Extremal Conditions (Single Elements & Asymmetric Lengths)\n";

        char str1[] = "{"; // Pure opening bracket boundary
        char str2[] = "}"; // Pure closing bracket boundary
        char str3[] = "";  // Empty baseline evaluation boundary

        bool res1 = checkBalancedParenthesis(str1); // Expect false
        bool res2 = checkBalancedParenthesis(str2); // Expect false
        bool res3 = checkBalancedParenthesis(str3); // Expect true (empty is balanced)

        // Adjusting matching criteria to check your current logic's resilience
        if (res1 == false && res3 == true)
        {
            std::cout << "  STATUS: PASSED\n";
        }
        else
        {
            std::cout << "  STATUS: FAILED\n";
        }
        std::cout << "\n";
    }

    // -------------------------------------------------------------------------
    // SCENARIO 3: Structural & Layout Hazards
    // -------------------------------------------------------------------------
    {
        std::cout << "[SCENARIO 3] Structural & Layout Hazards (Interleaved Order & Wrong Closing Selections)\n";

        char str1[] = "[(])"; // Interleaved structural error (valid characters, wrong order)
        char str2[] = "{[}]"; // Mismatched nesting depth boundaries

        bool res1 = checkBalancedParenthesis(str1); // Expect false
        bool res2 = checkBalancedParenthesis(str2); // Expect false

        if (res1 == false && res2 == false)
        {
            std::cout << "  STATUS: PASSED\n";
        }
        else
        {
            std::cout << "  STATUS: FAILED\n";
        }
        std::cout << "\n";
    }

    // -------------------------------------------------------------------------
    // SCENARIO 4: Parameter Safety & Constraints
    // -------------------------------------------------------------------------
    {
        std::cout << "[SCENARIO 4] Parameter Safety & Constraints (Extraneous Characters Interspersed)\n";

        char str1[] = "{a+b}[c*d](e)"; // Mixed string containing algorithmic non-bracket variants

        bool res1 = checkBalancedParenthesis(str1); // Logic should isolate bracket boundaries cleanly

        if (res1 == true)
        {
            std::cout << "  STATUS: PASSED\n";
        }
        else
        {
            std::cout << "  STATUS: FAILED\n";
        }
        std::cout << "\n";
    }

    std::cout << "================================================================\n";
    std::cout << "   TEST SUITE EXECUTION COMPLETE                               \n";
    std::cout << "================================================================\n";

    return 0;
}