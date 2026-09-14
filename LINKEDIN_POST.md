# LinkedIn Post Draft

🎬 **From a UML assignment to a complete Movie Ticket Booking System**

My System Design (TCS-504) assignment asked us to design a UML-based movie ticket booking system and implement it as a small menu-driven C++ console program.

Instead of stopping at the diagrams, I completed the full workflow and focused on keeping the design clean, modular and testable.

### Built with
- C++17
- Object-Oriented Design
- UML Class Diagram
- UML Sequence Diagram
- SOLID principles
- Modular class-per-file structure

### Core features
🎞️ Movie and show listing  
💺 Seat layout with AVAILABLE / BOOKED state  
🎟️ Multi-seat booking  
💰 Silver ₹150 · Gold ₹250 · Platinum ₹400 pricing  
💳 UPI · Card · Cash payment simulation  
🧾 Ticket generation  
❌ Booking cancellation and seat release  
🛡️ Validation for invalid, duplicate and already-booked seats

### The design decision I focused on most
A booking should **never become confirmed before payment succeeds**.

The flow validates every requested seat first, calculates the price, temporarily books the seats, performs payment through the abstract `Payment` interface, and confirms the booking only after success. If payment fails, the seats are released and the booking is not confirmed.

I also separated responsibilities across `BookingService`, `PriceCalculator`, `TicketPrinter`, and the payment implementations instead of putting everything into one large class.

### What I learned
Good system design is not just about drawing boxes and arrows. It is about deciding **who should own what, who should be responsible for what, and how objects collaborate without becoming unnecessarily coupled.**

This assignment helped me practice:
- Encapsulation and abstraction
- Inheritance and runtime polymorphism
- Composition, aggregation and association
- SOLID principles
- Edge-case handling and clean code

The complete project and documentation are available on GitHub:
https://github.com/akhilsaklani7coder/system-design-assignment

#SystemDesign #CPlusPlus #OOP #UML #SOLID #SoftwareEngineering #BTech #ComputerScience #LearningInPublic
