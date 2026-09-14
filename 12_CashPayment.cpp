class CashPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "Cash payment of Rs." << fixed << setprecision(2) << amount << " accepted.\n";
        return true;
    }
    string methodName() const override { return "CASH"; }
};
