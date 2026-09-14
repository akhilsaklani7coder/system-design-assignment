class BookingService {
private:
    PriceCalculator priceCalculator;
    TicketPrinter ticketPrinter;
    vector<Booking*> bookings;

    bool validateSeats(Show& show, const vector<string>& seatNumbers, vector<ShowSeat*>& selected) const {
        if (seatNumbers.empty()) return false;
        set<string> uniqueSeats;
        for (const string& number : seatNumbers) {
            if (!uniqueSeats.insert(number).second) { cout << "Duplicate seat selected: " << number << "\n"; return false; }
            ShowSeat* showSeat = show.findSeat(number);
            if (!showSeat) { cout << "Invalid seat number: " << number << "\n"; return false; }
            if (!showSeat->isAvailable()) { cout << "Seat " << number << " is already BOOKED. Booking rejected; nothing changed.\n"; return false; }
            selected.push_back(showSeat);
        }
        return true;
    }
public:
    ~BookingService() { for (Booking* booking : bookings) delete booking; }

    Booking* book(Customer& customer, Show& show, const vector<string>& seatNumbers, Payment& payment) {
        vector<ShowSeat*> selected;
        if (!validateSeats(show, seatNumbers, selected)) return nullptr;
        double total = priceCalculator.calculate(selected);
        cout << "TOTAL: Rs." << fixed << setprecision(2) << total << "\n";
        for (ShowSeat* seat : selected) seat->bookSeat();
        Booking* booking = new Booking(&customer, &show, selected, total);
        if (payment.pay(total)) {
            booking->confirm();
            bookings.push_back(booking);
            cout << "Payment successful. Booking confirmed.\n";
            ticketPrinter.print(*booking);
            return booking;
        }
        for (ShowSeat* seat : selected) seat->cancelSeat();
        booking->fail();
        cout << "Payment failed. Booking NOT confirmed; seats released.\n";
        delete booking;
        return nullptr;
    }

    bool cancel(const string& bookingId) {
        for (Booking* booking : bookings) {
            if (booking->getBookingId() == bookingId && booking->getStatus() == BookingStatus::CONFIRMED) {
                for (ShowSeat* seat : booking->getSeats()) seat->cancelSeat();
                booking->cancel();
                cout << "Booking " << bookingId << " cancelled. Seats are AVAILABLE again.\n";
                return true;
            }
        }
        cout << "Booking not found or not cancellable.\n";
        return false;
    }
    void printTickets() const {
        if (bookings.empty()) { cout << "No confirmed bookings.\n"; return; }
        for (const Booking* booking : bookings) ticketPrinter.print(*booking);
    }
};
