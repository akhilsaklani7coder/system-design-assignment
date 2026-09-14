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

| Concept | Where it appears |
|---|---|
| Encapsulation | Private state in domain classes |
| Abstraction | Abstract `Payment` class |
| Inheritance | `UpiPayment`, `CardPayment`, `CashPayment` |
| Runtime polymorphism | `Payment&` dispatches to concrete `pay()` implementations |
| Compile-time polymorphism | Overloaded `Movie` constructors |
| Static member | `Booking::nextBookingId` |
| Composition | `Cinema → Screen`, `Screen → Seat`, `Show → ShowSeat` |
| Aggregation | `Show → Movie`, `Booking → ShowSeat` |

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

The assignment requires **one class per file** and **no header files**. `main.cpp` includes the class implementation files in dependency order.

## ▶️ Build & Run

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o movie_booking
./movie_booking
```

## 🧪 Verification

Verified scenarios include successful UPI booking, failed payment with seat release, already-booked seat rejection, cancellation with seat release, duplicate seat rejection, invalid seat handling and invalid menu input. A GitHub Actions build check is included.

## 📐 Documentation

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

This is an academic **single-cinema console application**, not a production distributed booking platform. Real payment gateways, databases, authentication, Redis, Kafka, distributed locks, microservices and production observability are intentionally excluded because they are outside the required scope.

## 📚 Academic Context

Prepared for **TCS-504 System Design — Assignment 1**, Semester 5.  
**Author:** Akhil Saklani
