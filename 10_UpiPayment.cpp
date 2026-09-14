class UpiPayment : public Payment {
private:
    string upiId;
public:
    explicit UpiPayment(const string& upiId) : upiId(upiId) {}
    bool pay(double amount) override {
        cout << "UPI payment of Rs." << fixed << setprecision(2) << amount << " initiated for " << upiId << ".\n";
        string code; cout << "Enter UPI confirmation code (1234 = success): "; cin >> code;
        return code == "1234";
    }
    string methodName() const override { return "UPI"; }
};
