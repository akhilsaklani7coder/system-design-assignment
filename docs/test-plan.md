# Test Plan

| Test | Scenario | Expected result | Status |
|---|---|---|---|
| T01 | List movies | 3 Idiots and Interstellar are displayed | PASS |
| T02 | Select movie and show | Correct screen/time options are displayed | PASS |
| T03 | Display seat layout | 12 seats show type and availability | PASS |
| T04 | Book available Silver seat with successful UPI | Booking confirmed and ticket printed for ₹150 | PASS |
| T05 | Book already-booked seat | Whole booking rejected; no partial state change | PASS |
| T06 | Failed UPI payment | Booking not confirmed; selected seats released | PASS |
| T07 | Cancel confirmed booking | Booking becomes CANCELLED and seats become AVAILABLE | PASS |
| T08 | Invalid seat number | Clear validation message; program continues | PASS |
| T09 | Invalid menu choice | Clear validation message; no crash | PASS |
| T10 | Duplicate seat in one request | Booking rejected before any seat is changed | PASS |

Build command:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o movie_booking
```
