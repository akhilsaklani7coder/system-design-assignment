enum class SeatStatus { AVAILABLE, BOOKED };

class ShowSeat {
private:
    Seat* seat;
    SeatStatus status; // Encapsulation: status is private and changed through validation methods.
public:
    explicit ShowSeat(Seat* seat) : seat(seat), status(SeatStatus::AVAILABLE) {}
    const Seat& getSeat() const { return *seat; }
    bool isAvailable() const { return status == SeatStatus::AVAILABLE; }
    bool bookSeat() { if (!isAvailable()) return false; status = SeatStatus::BOOKED; return true; }
    void cancelSeat() { status = SeatStatus::AVAILABLE; }
    string statusName() const { return isAvailable() ? "AVAILABLE" : "BOOKED"; }
};
