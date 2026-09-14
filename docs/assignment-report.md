# TCS-504 System Design — Assignment 1
## Movie Ticket Booking System

**Student:** Akhil Saklani  
**Program:** B.Tech. CSE  
**Semester:** 5  
**Subject:** System Design (TCS-504)  
**Submission date:** 07-September-2026

## A. Requirement Analysis

### Functional Requirements

| ID | Functional requirement | Acceptance condition |
|---|---|---|
| FR1 | The system shall list all movies currently playing with title, language and duration. | A valid Movies selection prints every configured movie. |
| FR2 | For a selected movie, the system shall list every available show with screen number and start time. | A valid movie selection displays its configured shows. |
| FR3 | For a selected show, the system shall display every seat with seat number, seat type and AVAILABLE/BOOKED status. | Seat layout reflects the current show-seat state. |
| FR4 | A customer shall select one or more seats; if any selected seat is already BOOKED, the entire booking shall be rejected without changing seat state. Booking is confirmed only after successful payment. | Attempting an occupied seat produces rejection and no partial booking. |
| FR5 | The system shall calculate the booking amount from seat type: SILVER ₹150, GOLD ₹250 and PLATINUM ₹400. | The displayed total equals the sum of selected seat prices. |
| FR6 | Exactly one payment method (UPI/Card/Cash) shall be used per booking. If payment fails, the booking shall not be confirmed and selected seats shall be released. | A failed payment leaves all selected seats AVAILABLE. |
| FR7 | After successful payment, the system shall print a ticket containing booking ID, customer, movie, screen, time, seat numbers, total amount and status. | A confirmed booking produces a complete formatted ticket. |
| FR8 | A customer shall be able to cancel a confirmed booking, after which all seats in that booking become AVAILABLE again. | Cancellation changes booking status to CANCELLED and releases its seats. |

### Non-Functional Requirements

1. **Modularity:** each class is maintained in its own `.cpp` file, with clear responsibility boundaries and no header files, matching the course rule.
2. **Extensibility:** payment methods depend on the abstract `Payment` contract, so a new method can be added as another derived class without editing existing payment implementations.
3. **Robust validation:** invalid menu choices, invalid seat numbers, duplicate seats and already-booked seats are rejected with clear messages and without crashing.
4. **Maintainability:** intention-revealing names, constants for prices, small methods and separation of pricing, payment, printing and booking orchestration are used.

## B. Noun–Verb Analysis

| Noun found | Keep as class? | Reason |
|---|---|---|
| Movie | Yes | Has its own identity and movie metadata. |
| Seat | Yes | Represents one physical seat with number and type. |
| Seat layout | No | It is a view of a show's seats, so it belongs in a print/display method. |
| Screen | Yes | Represents one auditorium and owns physical seats. |
| Cinema | Yes | Represents the theatre and owns its screens. |
| Show | Yes | Represents one movie screening on a screen at a time. |
| ShowSeat | Yes | Separates physical seat identity from per-show booking status. |
| Customer | Yes | Represents the person making bookings. |
| Booking | Yes | Represents a booking transaction and its lifecycle state. |
| Payment | Yes (abstract) | Defines a common payment contract. |
| UPI/Card/Cash payment | Yes | Each method has its own implementation. |
| Price | No | Price is derived from seat type; no independent identity is needed. |
| Ticket | No | Assignment requires ticket printing, not a separate ticket lifecycle/entity; `TicketPrinter` handles formatting. |
| Booking service | Yes | Orchestrates the end-to-end booking workflow. |
| Ticket printer | Yes | Owns only ticket formatting/printing behaviour. |

### Verb mapping

| Verb | Method / responsibility |
|---|---|
| list movies | `main()` movie listing |
| list shows | `chooseShow()` |
| display seats | `Show::printSeatLayout()` |
| validate seats | `BookingService::validateSeats()` |
| book | `BookingService::book()` |
| calculate price | `PriceCalculator::calculate()` |
| pay | `Payment::pay()` |
| print ticket | `TicketPrinter::print()` |
| cancel | `BookingService::cancel()` |
| release seats | `ShowSeat::cancelSeat()` |

## C. Classes and Responsibilities

| Class | Knows | Does | Must NOT do |
|---|---|---|---|
| `Movie` | title, language, duration | exposes movie data | manage seats, payments or bookings |
| `Seat` | number, seat type | exposes seat identity/type | track show-specific booking state |
| `Screen` | screen number, owned seats | creates/owns physical seats | book or price seats |
| `Cinema` | name, owned screens | manages screens | process bookings/payments |
| `Show` | movie, screen, start time, show seats | finds/displays seats | process payment |
| `ShowSeat` | physical seat + status | book/cancel one seat | calculate booking totals |
| `Customer` | name, phone | exposes customer data | manage booking workflow |
| `Booking` | ID, customer, show, selected seats, amount, status | maintain booking lifecycle | calculate price or print itself |
| `Payment` | payment contract | defines `pay(amount)` | know about movies/seats |
| concrete payments | payment-specific input | perform payment simulation | modify booking state |
| `PriceCalculator` | price constants | calculate total | reserve/book seats |
| `TicketPrinter` | no persistent domain state | format/print ticket | change booking/seat state |
| `BookingService` | pricing/printer services, bookings | orchestrate validation, reservation, payment and cancellation | own concrete payment implementations |

## C. Relationships — Lifetime Test

| Pair | Relationship | Justification |
|---|---|---|
| Cinema — Screen | Composition | Screens are owned by the cinema and created as part of its setup; destroying the cinema removes its screen objects. |
| Screen — Seat | Composition | Physical seats belong to their screen; `Screen` constructs and owns them. |
| Show — Movie | Aggregation | A movie exists independently and can be associated with multiple shows. |
| Show — Screen | Association | A show uses an existing screen; the screen has an independent lifetime. |
| Show — ShowSeat | Composition | `Show` constructs its show-specific seat-status objects. |
| Booking — Customer | Association | The customer exists independently of any booking. |
| Booking — ShowSeat | Aggregation | A booking references existing show-seat objects; it does not create them. |
| Booking — Payment | Association | Payment is supplied for a transaction and is not owned by `Booking`. |
| Payment — Upi/Card/Cash | Inheritance | Each concrete payment class is a subtype of the abstract `Payment` contract. |
| BookingService — Booking | Aggregation | The service retains confirmed booking objects for lookup/cancellation. |

## D. Class Diagram

See [`class-diagram.puml`](class-diagram.puml) and [`class-diagram.md`](class-diagram.md). The diagram contains every required class, attributes, methods, visibility, multiplicities and the abstract payment hierarchy.

## E. Sequence Diagram

Required use case: **customer books one seat and pays by UPI**. See [`sequence-diagram.puml`](sequence-diagram.puml). The sequence contains the required lifelines, synchronous calls, return messages, activation bars and object creation messages.

## F. Modular Code + Demo

The implementation follows the course rule of **one class per file** and **no header files**. `main.cpp` includes the class implementation files in dependency order.

Build:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o movie_booking
```

Verified scenarios are documented in [`test-plan.md`](test-plan.md) and [`demo-output.txt`](demo-output.txt): successful booking, failed payment with seat release, already-booked seat rejection, cancellation, invalid seat input and invalid menu input.

## G. SOLID Mapping

- **S — Single Responsibility:** pricing, ticket printing, payment and booking orchestration are separated.
- **O — Open/Closed:** a new payment method can implement `Payment` without editing existing payment classes.
- **L — Liskov Substitution:** every concrete payment works through `Payment&`.
- **I — Interface Segregation:** the payment contract contains only operations needed by this assignment.
- **D — Dependency Inversion:** `BookingService` receives `Payment&` instead of constructing a concrete payment.

### Deliberately NOT implemented

Real payment gateways, databases, authentication, Redis, Kafka, distributed locking, microservices and production observability were deliberately excluded because the assignment is scoped to a single-cinema console application. The design keeps an extension point through `Payment` without pretending the academic simulator is production infrastructure.

## Clean-Code Checklist

- Intention-revealing names
- No number-series variable names
- Focused functions
- Named pricing constants instead of magic numbers
- No booking side effects in display methods
- Duplicate/invalid/occupied seat validation
- Payment failure releases selected seats
- Cancellation releases all seats in a confirmed booking
- No header files, as required by the course
