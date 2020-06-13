private:
    vector<pair<int,int>> booked, doublebooked;
public:
    MyCalendarTwo() {
        
    }
    
    bool doublebook(int start, int end, int& record) {
        pair<int,int> times = {start, end};
        
        if (doublebooked.empty()) {
            doublebooked.push_back(times);
            return true;
        } else {
            for (int i = 0; i < doublebooked.size(); ++i) {
                if (start < doublebooked[i].second && end > doublebooked[i].first) {
                    return false;
                }
            }
            
            doublebooked.push_back(times);
            record++;
            return true;
        }
    }
    
    bool book(int start, int end) {
        pair<int,int> times = {start, end};
        bool test = true;
        int record = 0;
        
        if (booked.empty()) {
            booked.push_back(times);
            return true;
        } else {
            for (int i = 0; i < booked.size(); ++i) {
                if (start < booked[i].second && end > booked[i].first) {
                    if (start < booked[i].first && end > booked[i].second) {
                        test = test && doublebook(booked[i].first, booked[i].second, record);
                    } else if (start >= booked[i].first && end <= booked[i].second) {
                        test = test && doublebook(start, end, record);
                    } else if (start < booked[i].first && end <= booked[i].second) {
                        test = test && doublebook(booked[i].first, end, record);
                    } else {
                        test = test && doublebook(start, booked[i].second, record);
                    }
                    
                    if (!test) {
                        while (record--) {
                            doublebooked.pop_back();
                        }
                        return false;
                    }
                    
                }
            }
            
            
            booked.push_back(times);
            return true;
        }
    }
