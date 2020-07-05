class Cashier {
public:
    unordered_map<int, int> tags;
    int c, x;
    double d;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        c = 0;
        x = n;
        d = (100.0 - discount) / 100.0;
        for (int i = 0; i < products.size(); ++i) {
            tags[products[i]] = prices[i];
        }
    }

    double getBill(vector<int> product, vector<int> amount) {
        c++;
        double ans(0.0);
        for (int i = 0; i < product.size(); ++i) {
            ans += tags[product[i]] * amount[i];
        }
        return c % x ? ans : ans * d;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
