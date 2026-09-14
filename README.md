# 🎬 Movie Ticket Booking System — TCS-504 System Design Assignment 1

> **B.Tech. CSE · Semester 5 · System Design · TCS-504**

A clean, modular **C++17 console-based movie ticket booking system** developed for Assignment 1. The implementation follows the assignment's single-cinema scope and demonstrates object-oriented design, UML modelling, SOLID principles, validation, and booking-state handling.

## 👨‍💻 Student

**Akhil Saklani**  
B.Tech. Computer Science & Engineering · Semester 5

## 🎯 Assignment Objective

Build a small movie ticket booking system for a **single cinema** as a menu-driven C++ console program. A customer can browse movies, select a show, inspect seat availability, book seats, pay, receive a ticket, and cancel a booking.

## ✨ Features

- 🎞️ List currently playing movies
- 🕐 List shows by movie with screen and start time
- 💺 Display per-show seat layout and availability
- 🎟️ Book one or more seats atomically
- 💰 Seat-based pricing: Silver ₹150 · Gold ₹250 · Platinum ₹400
- 💳 UPI, Card and Cash payment simulations
- 🧾 Print a formatted ticket with booking details
- ❌ Cancel confirmed bookings and release seats
- 🛡️ Reject invalid, duplicate and already-booked seats
- 🔁 Failed payment never confirms a booking
- 🆔 Static booking ID generation

## 🧠 Design Highlights

### OOP

| Concept | Where it appears |
|---|---|
| Encapsulation | Private state in `Movie`, `Seat`, `ShowSeat`, `Booking`, etc. |
| Abstraction | Abstract `Payment` class |
| Inheritance | `UpiPayment`, `CardPayment`, `CashPayment` |
| Runtime polymorphism | `Payment&` dispatches to concrete `pay()` implementations |
| Compile-time polymorphism | Overloaded `Movie` constructors |
| Static member | `Booking::nextBookingId` |
| Composition | `Cinema → Screen`, `Screen → Seat`, `Show → ShowSeat` |
| Aggregation | `Show → Movie/Screen`, `Booking → ShowSeat` |

### SOLID

- **S — Single Responsibility:** pricing, ticket printing and booking orchestration are separated.
- **O — Open/Closed:** new payment methods can extend `Payment` without changing existing payment classes.
- **L — Liskov Substitution:** all concrete payment classes work through `Payment&`.
- **I — Interface Segregation:** the payment contract contains only payment operations required by this scope.
- **D — Dependency Inversion:** `BookingService` receives the `Payment` abstraction instead of constructing a concrete payment internally.

## 📁 Project Structure

```text
system-design-assignment/
├── 01_Movie.cpp
├── 02_Seat.cpp
├── 03_Screen.cpp
├── 04_Cinema.cpp
├── 05_Show.cpp
├── 06_ShowSeat.cpp
├── 07_Customer.cpp
├── 08_Booking.cpp
├── 09_Payment.cpp
├── 10_UpiPayment.cpp
├── 11_CardPayment.cpp
├── 12_CashPayment.cpp
├── 13_PriceCalculator.cpp
├── 14_TicketPrinter.cpp
├── 15_BookingService.cpp
├── main.cpp
├── TCS-504_Assignment_1_Akhil_Saklani.pdf
├── LINKEDIN_POST.md
├── docs/
│   ├── assignment-report.md
│   ├── class-diagram.md
│   ├── class-diagram.puml
│   ├── sequence-diagram.md
│   ├── sequence-diagram.puml
│   ├── demo-output.txt
│   └── test-plan.md
└── .github/workflows/build.yml
```

The assignment requires **one class per file** and **no header files**. Therefore `main.cpp` is the single compilation entry point and includes the class implementation files in dependency order.

## ▶️ Build & Run

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o movie_booking
./movie_booking
```

## 🧪 Verification

The implementation was compiled with warnings enabled and verified with successful booking, failed payment, already-booked seat rejection, cancellation, invalid seat handling, and invalid menu input.

### Example successful transaction

```text
TOTAL: Rs.400.00
UPI payment of Rs.400.00 initiated for akhil@upi.
Enter UPI confirmation code (1234 = success): 1234
Payment successful. Booking confirmed.

================ TICKET ================
Booking ID : BK1001
Customer   : Akhil Saklani
Movie      : 3 Idiots
Screen     : Screen-1
Time       : 06:00 PM
Seats      : A1, B1
Amount     : Rs.400.00
Status     : CONFIRMED
=========================================
```

### Failure-path invariant

```text
Payment failed. Booking NOT confirmed; seats remain AVAILABLE.
```

## 📐 UML Documentation

- [Assignment Report](docs/assignment-report.md)
- [Class Diagram](docs/class-diagram.md)
- [Sequence Diagram](docs/sequence-diagram.md)
- [PlantUML Class Diagram Source](docs/class-diagram.puml)
- [PlantUML Sequence Diagram Source](docs/sequence-diagram.puml)
- [Demo / Edge-Case Transcript](docs/demo-output.txt)
- [Test Plan](docs/test-plan.md)
- [Completed Assignment PDF](TCS-504_Assignment_1_Akhil_Saklani.pdf)
- [LinkedIn Post Draft](LINKEDIN_POST.md)

## 🔒 Deliberate Scope Boundary

This is an academic **single-cinema console application**, not a production distributed booking platform. Real payment gateways, databases, authentication, Redis, Kafka, distributed locks, microservices, and observability are intentionally excluded because they are outside the assignment's required scope.

## 📚 Academic Context

Prepared for **TCS-504 System Design — Assignment 1**, Semester 5.  
**Author:** Akhil Saklani
