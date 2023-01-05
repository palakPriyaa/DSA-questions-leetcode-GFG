
#define ll long long
class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<string> p;
        for(int i = 0; i < t.size(); ++i){
            if(t[i] == "+"){
                ll x = stol(p.top()); p.pop();
                ll y = stol(p.top()); p.pop();
                p.push(to_string(y + x));
            }
            else
            if(t[i] == "-"){
                ll x = stol(p.top()); p.pop();
                ll y = stol(p.top()); p.pop();
                p.push(to_string(y - x));
            }
            else
            if(t[i] == "*"){
                ll x = stol(p.top()); p.pop();
                ll y = stol(p.top()); p.pop();
                p.push(to_string(y * x));
            }else
            if(t[i] == "/"){
                ll x = stol(p.top()); p.pop();
                ll y = stol(p.top()); p.pop();
                p.push(to_string(y / x));
            }else
                p.push(t[i]);
        }

        return stol(p.top());
    }
};