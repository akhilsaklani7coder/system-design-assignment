enum class BookingStatus { PENDING, CONFIRMED, CANCELLED, FAILED };

class Booking {
private:
    static int nextBookingId; // Static member: shared unique ID generator.
    string bookingId;
    Customer* customer;
    Show* show;
    vector<ShowSeat*> seats;
    double bookingAmount;
    BookingStatus status;
public:
    Booking(Customer* customer, Show* show, const vector<ShowSeat*>& seats, double amount)
        : customer(customer), show(show), seats(seats), bookingAmount(amount), status(BookingStatus::PENDING) {
        bookingId = "BK" + to_string(nextBookingId++);
    }
    string getBookingId() const { return bookingId; }
    Customer* getCustomer() const { return customer; }
    Show* getShow() const { return show; }
    const vector<ShowSeat*>& getSeats() const { return seats; }
    double getBookingAmount() const { return bookingAmount; }
    BookingStatus getStatus() const { return status; }
    void confirm() { status = BookingStatus::CONFIRMED; }
    void fail() { status = BookingStatus::FAILED; }
    void cancel() { status = BookingStatus::CANCELLED; }
    string statusName() const {
        switch (status) { case BookingStatus::CONFIRMED: return "CONFIRMED"; case BookingStatus::CANCELLED: return "CANCELLED"; case BookingStatus::FAILED: return "FAILED"; default: return "PENDING"; }
    }
};
int Booking::nextBookingId = 1001;
