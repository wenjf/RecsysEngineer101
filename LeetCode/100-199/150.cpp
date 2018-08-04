class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> my_s;
        for(auto s: tokens){
            if(s == "/"||s == "*"||s == "-"||s == "+"){
                int b = my_s.top();
                my_s.pop();
                int a = my_s.top();
                my_s.pop();
                int res = 0;
                if(s == "/")
                    res = a/b; 
                else if(s == "*")
                    res = a*b; 
                else if(s == "+")
                    res = a+b; 
                else if(s == "-")
                    res = a-b; 
                my_s.push(res);
            }
            else{
                my_s.push(atoi(s.c_str()));
            }
        }
        return my_s.top();
    }
};