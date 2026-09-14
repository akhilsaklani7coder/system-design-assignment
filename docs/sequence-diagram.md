# Sequence Diagram

Required use case: **customer books 1 seat and pays by UPI**.

The source is [`sequence-diagram.puml`](sequence-diagram.puml). The flow validates the requested seat, calculates the price, reserves the seat, creates the `Booking`, creates the selected `Payment` object, performs payment, confirms only after success, and prints the ticket.

If payment returns `false`, the service releases the temporarily reserved seat and does not confirm the booking.
