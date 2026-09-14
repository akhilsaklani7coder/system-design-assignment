#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
using namespace std;

#include "01_Movie.cpp"
#include "02_Seat.cpp"
#include "03_Screen.cpp"
#include "04_Cinema.cpp"
#include "06_ShowSeat.cpp"
#include "05_Show.cpp"
#include "07_Customer.cpp"
#include "08_Booking.cpp"
#include "09_Payment.cpp"
#include "10_UpiPayment.cpp"
#include "11_CardPayment.cpp"
#include "12_CashPayment.cpp"
#include "13_PriceCalculator.cpp"
#include "14_TicketPrinter.cpp"
#include "15_BookingService.cpp"

// TCS-504 Assignment 1 — Movie Ticket Booking System.
// OOP concepts are intentionally demonstrated in the corresponding class files.

static void seedCinema(Cinema& cinema, vector<Movie>& movies, vector<Show>& shows) {
    cinema.addScreen(1); cinema.addScreen(2);
    movies.emplace_back("3 Idiots", "Hindi", 170);
    movies.emplace_back("Interstellar", "English", 169);
    shows.emplace_back(1, &movies[0], &cinema.getScreens()[0], "06:00 PM");
    shows.emplace_back(2, &movies[0], &cinema.getScreens()[1], "09:00 PM");
    shows.emplace_back(3, &movies[1], &cinema.getScreens()[0], "03:00 PM");
}

static Show* chooseShow(vector<Show>& shows, int movieIndex) {
    vector<Show*> options;
    for (Show& show : shows) if (show.getMovie()->getTitle() == (movieIndex == 1 ? "3 Idiots" : "Interstellar")) options.push_back(&show);
    if (options.empty()) return nullptr;
    cout << "\nShows:\n";
    for (size_t i = 0; i < options.size(); ++i) cout << i + 1 << ". Screen-" << options[i]->getScreen()->getScreenNumber() << " | " << options[i]->getStartTime() << "\n";
    int choice; cout << "Choose show: "; if (!(cin >> choice) || choice < 1 || choice > static_cast<int>(options.size())) { cin.clear(); cin.ignore(10000, '\n'); cout << "Invalid show choice.\n"; return nullptr; }
    return options[choice - 1];
}

static void runBooking(BookingService& service, Customer& customer, vector<Show>& shows) {
    int movieChoice; cout << "\n1. 3 Idiots  2. Interstellar\nChoose movie: ";
    if (!(cin >> movieChoice) || movieChoice < 1 || movieChoice > 2) { cin.clear(); cin.ignore(10000, '\n'); cout << "Invalid movie choice.\n"; return; }
    Show* show = chooseShow(shows, movieChoice); if (!show) return;
    show->printSeatLayout();
    int count; cout << "How many seats? "; if (!(cin >> count) || count < 1 || count > 5) { cin.clear(); cin.ignore(10000, '\n'); cout << "Invalid seat count.\n"; return; }
    vector<string> seatNumbers; for (int i = 0; i < count; ++i) { string seat; cout << "Seat " << i + 1 << ": "; cin >> seat; seatNumbers.push_back(seat); }
    int method; cout << "Pay by: 1.UPI  2.Card  3.Cash\nChoose: "; if (!(cin >> method) || method < 1 || method > 3) { cin.clear(); cin.ignore(10000, '\n'); cout << "Invalid payment method.\n"; return; }
    if (method == 1) { string upi; cout << "UPI ID: "; cin >> upi; UpiPayment payment(upi); service.book(customer, *show, seatNumbers, payment); }
    else if (method == 2) { string card; cout << "Last 4 card digits: "; cin >> card; CardPayment payment(card); service.book(customer, *show, seatNumbers, payment); }
    else { CashPayment payment; service.book(customer, *show, seatNumbers, payment); }
}

int main() {
    Cinema cinema("Akhil Cinemas"); vector<Movie> movies; vector<Show> shows; seedCinema(cinema, movies, shows);
    Customer customer("Akhil Saklani", "9876543210"); BookingService service;
    while (true) {
        cout << "\n===== MOVIE TICKET BOOKING =====\n1. Movies  2. Book  3. Cancel  4. My tickets  0. Exit\nChoose: ";
        int choice; if (!(cin >> choice)) { cin.clear(); cin.ignore(10000, '\n'); cout << "Invalid menu choice.\n"; continue; }
        if (choice == 0) break;
        if (choice == 1) { for (size_t i = 0; i < movies.size(); ++i) cout << "[" << i + 1 << "] " << movies[i].getTitle() << " | " << movies[i].getLanguage() << " | " << movies[i].getDurationMinutes() << " min\n"; }
        else if (choice == 2) runBooking(service, customer, shows);
        else if (choice == 3) { string id; cout << "Booking ID: "; cin >> id; service.cancel(id); }
        else if (choice == 4) service.printTickets();
        else cout << "Invalid menu choice.\n";
    }
    cout << "Goodbye!\n"; return 0;
}
