class Screen {
private:
    int screenNumber;
    vector<Seat> seats; // Composition: Screen owns its physical seats.
public:
    explicit Screen(int screenNumber) : screenNumber(screenNumber) { buildSeats(); }
    int getScreenNumber() const { return screenNumber; }
    vector<Seat>& getSeats() { return seats; }
    const vector<Seat>& getSeats() const { return seats; }
    void buildSeats() {
        const vector<string> rows = {"A", "B", "C"};
        for (const string& row : rows) {
            for (int col = 1; col <= 4; ++col) {
                SeatType type = col <= 2 ? SeatType::SILVER : (col == 3 ? SeatType::GOLD : SeatType::PLATINUM);
                seats.emplace_back(row + to_string(col), type);
            }
        }
    }
};
