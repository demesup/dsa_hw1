#include <iostream>
#include <string>
#include "FlightBookingSystem.h"

using namespace std;
int main() {
    FlightBookingSystem bookingSystem;

    bookingSystem.bookSeat("Sergiu");
    bookingSystem.bookSeat("Ana");
    bookingSystem.bookSeat("FAna");
    bookingSystem.bookSeat("Afna");
    bookingSystem.bookSeat("An0fa");
    bookingSystem.bookSeat("Jldshnfjsd");
    bookingSystem.displaySystem();
    cout << "Passenger at seat 0: " << bookingSystem.getPassenger(0) << endl;
    bookingSystem.cancelBooking(0);
    bookingSystem.bookSeat("JLjdlshnfejsdhb");
    bookingSystem.bookSeat("ksdjljsfd");
    bookingSystem.bookSeat("jahkfcdjsf");


    bookingSystem.displaySystem();
    bookingSystem.cancelBooking(3);
    bookingSystem.displaySystem();

    return 0;
}
