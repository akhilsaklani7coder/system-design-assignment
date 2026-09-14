class CardPayment : public Payment {
private:
    string lastFourDigits;
public:
    explicit CardPayment(const string& lastFourDigits) : lastFourDigits(lastFourDigits) {}
    bool pay(double amount) override {
        cout << "Card payment of Rs." << fixed << setprecision(2) << amount << " processed for card ending " << lastFourDigits << ".\n";
        int pin; cout << "Enter card PIN (1234 = success): "; cin >> pin;
        return pin == 1234;
    }
    string methodName() const override { return "CARD"; }
};
