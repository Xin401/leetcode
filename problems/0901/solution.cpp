class StockSpanner {
public:
    stack<pair<int,int>> s;
    StockSpanner() {
    }
    
    int next(int price) {
        int ret=1;
        while(!s.empty()&&price>=s.top().first)
        {
            ret+=s.top().second;
            s.pop();
        }
        s.push({price,ret});
        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */