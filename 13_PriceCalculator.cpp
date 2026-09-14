class PriceCalculator {
private:
    static constexpr double SILVER_PRICE = 150.0;
    static constexpr double GOLD_PRICE = 250.0;
    static constexpr double PLATINUM_PRICE = 400.0;
public:
    double calculate(const vector<ShowSeat*>& seats) const {
        double total = 0.0;
        for (const ShowSeat* showSeat : seats) {
            switch (showSeat->getSeat().getType()) {
                case SeatType::SILVER: total += SILVER_PRICE; break;
                case SeatType::GOLD: total += GOLD_PRICE; break;
                case SeatType::PLATINUM: total += PLATINUM_PRICE; break;
            }
        }
        return total;
    }
    static double priceFor(SeatType type) {
        if (type == SeatType::SILVER) return SILVER_PRICE;
        if (type == SeatType::GOLD) return GOLD_PRICE;
        return PLATINUM_PRICE;
    }
};
