
/*Problem Statement:
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/


class Solution {
public:
    bool isValid(string s) {
        int i;
        stack<char> st;
        for(i=0;s[i]!='\0';++i) {
            if(s[i]=='(' || s[i] =='{' || s[i] == '[')
                st.push(s[i]);
            if(s[i] == ')' || s[i] =='}' ||s[i] == ']') {
                if(st.empty())
                    return false;
                else {
                    char top = st.top();
                    if( isMatchingPair(top,s[i])) {
                        st.pop();
                    }
                    else
                        return false;
                }
            }
        }
        if(!st.empty())
            return false;
      return true;  
    }
    bool isMatchingPair(char c1, char c2) {
        if(c1=='(' && c2 == ')')
            return true;
        else if (c1=='{' && c2 =='}')
                return true;
        else if (c1 == '[' && c2 ==']')
                return true;
        return false;        
    }
    
};



/*Main function*/
int main() {
    	string s="()";
    	Solution s1;
    	cout<<s1.isValid(s);
    }

