// https://www.codingninjas.com/codestudio/problems/valid-parentheses_8230714?challengeSlug=striver-sde-challenge&leftPanelTab=1

bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> stk;
    for (auto ch: expression){
        if (ch=='(' || ch=='{' || ch=='['){
            stk.push(ch);
        }
        else{
            if (stk.empty())return false;
            if (stk.top()=='(' && ch!=')')return false;
            else if (stk.top() == '{' && ch != '}')return false;
            else if (stk.top()== '[' && ch!=']')return false;
            else stk.pop();
        }
    }
    return (stk.empty());
}
