#include <iostream>
#include "LinkedList.h"

using namespace std;

void returnError(const string str) {
    cerr << str << endl;
    exit(1);
}

struct Flight {
    int N;
    string *flightSeats;

public:

    static Flight createFlight(int n) {
        if (n < 1 || n > 5)
            returnError("Invalid number of seats");
        Flight newFlight;
        newFlight.N = n;
        newFlight.flightSeats = new string[n];
        for (int i = 0; i < 5; i++) {
            newFlight.flightSeats[i] = "";
        }
        return newFlight;
    }

    static Flight createFlight() {
        return createFlight(5);
    }
};

class FlightBookingSystem {
private:
    LinkedList<Flight> flights;
public:

    FlightBookingSystem() {
        Flight flight = Flight::createFlight();
        flights.addFirst(flight);
    }

    ~FlightBookingSystem() {};

    void bookSeat(const string &passenger) {
        bool booked = false;
        for (Node<Flight> *current = flights.pfirst; current != nullptr; current = current->next) {
            Flight &flight = current->info;
            if (!isFlightFullyBooked(&flight)) {
                for (int i = 0; i < flight.N; i++) {
                    if (flight.flightSeats[i].empty()) {
                        flight.flightSeats[i] = passenger;
                        return;
                    }
                }
            }
        }

        cout << "Creating new flight..." << endl;
        Flight newFlight = Flight::createFlight();
        newFlight.flightSeats[0] = passenger;
        flights.addLast(newFlight);
    }


    void cancelBooking(int seatIndex) {
        int totalSeats = 0;
        for (Node<Flight> *current = flights.pfirst; current != nullptr; current = current->next) {
            Flight &flight = current->info;
            totalSeats += flight.N;
            if (seatIndex < totalSeats) {
                seatIndex -= (totalSeats - flight.N);
                for (int i = seatIndex; i < flight.N - 1; i++) {
                    flight.flightSeats[i] = flight.flightSeats[i + 1];
                }
                flight.flightSeats[flight.N - 1] = "";
                return;
            }
        }
        cerr << "Invalid seat index" << endl;
    }


    void displaySystem() {
        int flightNumber = 1;
        for (Node<Flight> *current = flights.pfirst; current != nullptr; current = current->next) {
            Flight &flight = current->info;
            cout << "Flight " << flightNumber++ << ":" << endl;
            for (int i = 0; i < flight.N; i++) {
                cout << "Seat " << i << ": " << flight.flightSeats[i] << endl;
            }
        }
    }

    string getPassenger(int seatIndex) {
        int totalSeats = 0;
        for (Node<Flight> *current = flights.pfirst; current != nullptr; current = current->next) {
            Flight &flight = current->info;
            totalSeats += flight.N;
            if (seatIndex < totalSeats) {
                seatIndex -= (totalSeats - flight.N);
                return flight.flightSeats[seatIndex];
            }
        }
        return "";
    }


    void addFlight() {
    }

private:


    bool isFlightFullyBooked(Flight *flight) {
        for (int i = 0; i < flight->N; i++) {
            if (flight->flightSeats[i] == "")
                return false;
        }
        return true;
    }
};