private:
    vector<pair<int,int>> booked;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int,int> times = {start, end};
        
        if (booked.empty()) {
            booked.push_back(times);
            return true;
        } else {
            for (int i = 0; i < booked.size(); ++i) {
                if (start < booked[i].second && end > booked[i].first) {
                    return false;
                }
            }
            
            booked.push_back(times);
            return true;
        }
    }
