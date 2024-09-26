class MyCalendar {
public:
    unordered_map<int, int> um;
    MyCalendar() {
        
    }
    
    bool book(int x, int y) {
        for(auto& val : um) {
            int a = val.first, b = val.second;

       
            if(a < y && b > x) {
                return false;
            }

            
            if(x < b && y > a) { 
                return false;
            }

            
            if(a <= x && y <= b) {
                return false;
            }

            
            if(x<a && b<y){
                return false;
            }

        }
        um[x] = y;
        return true;
    }
};