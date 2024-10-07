class Solution {
public:
    int minLength(std::string s) {
        while (true) {
            int pos;
             pos = s.find("AB");
            if (pos != std::string::npos) {
                s.erase(pos, 2);
            } else {
                pos = s.find("CD");
                if (pos != std::string::npos) {
                    s.erase(pos, 2);
                } else {
                    break;
                }
            }
        }
        return s.length();
    }
};
