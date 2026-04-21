# Flight Booking System

You've been assigned to develop a part of a flight booking system for a small airline. The airline operates several flights a day, each with a limited number of seats. To efficiently manage the booking and cancellation of seats across multiple flights, a custom data structure named `FlightBookingSystem` is implemented.

## Data Structure: FlightBookingSystem
The `FlightBookingSystem` manages a series of flights, where each flight has a limited number of seats. Each flight is represented as an array within a node of a linked list, with each element of the array corresponding to a seat booking status (booked/unbooked).

## Methods Implemented
1. **FlightBookingSystem():** Initializes the booking system.
2. **void bookSeat(String passengerName):** Books a seat for a passenger by adding their name to the last available seat of the last flight in the system. If the last flight is fully booked, a new flight (node) is created, and the passenger is booked on this new flight.
3. **void cancelBooking(int seatIndex):** Cancels the booking for the seat at the global index (across all flights) seatIndex. This operation should not leave empty slots in the arrays (flights). Therefore, subsequent bookings must be shifted left, possibly across different flights.
4. **void displaySystem():** Displays the current booking status of all flights, with each flight's bookings shown on a new line.
5. **String getPassenger(int seatIndex):** Returns the name of the passenger booked at the global seat index seatIndex.

## Algorithm Explanation
- **Booking a Seat:** When booking a seat, the system checks if there's space in the last flight. If yes, it adds the passenger to the last flight. If the last flight is fully booked, a new flight is created, and the passenger is added to it.
- **Canceling a Booking:** When canceling a booking, the system removes the passenger from the specified seat index, ensuring no empty slots are left. It shifts subsequent bookings leftward, possibly across different flights.
- **Displaying System Status:** The system displays the current booking status of all flights, with each flight's bookings shown on a new line.
- **Getting Passenger at Seat Index:** This function retrieves the passenger's name at the specified seat index across all flights.

## Example Operations
1. Bookings are initially empty.
2. `bookSeat("Sergiu")` adds Sergiu to the first flight.
3. `bookSeat("Ana")` adds Ana to the same flight as Sergiu.
4. `displaySystem()` shows the booking status across all flights.
5. `getPassenger(0)` returns "Sergiu".
6. `cancelBooking(0)` removes Sergiu from the first flight, shifts Ana to the first seat, and moves subsequent bookings accordingly.
7. `displaySystem()` reflects the updated booking status.

## Problem Requirements
- The maximum number of seats per flight is 5.
- Implement the FlightBookingSystem class with the specified methods.
- Ensure the cancelBooking method shifts passengers correctly without leaving empty seats.
- Handle edge cases, such as cancelling a booking when there are no bookings or trying to book a seat when all flights are fully booked.
