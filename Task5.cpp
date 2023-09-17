//MOVIE TICKET BOOKING SYSTEM
/*Develop a program that simulates a movie ticket booking system.Allow users to view movie listings, select seats, make bookings,
  and calculate the total cost. Consider implementing seat availability and seat selection validation.*/
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
using namespace std;

// Deleration of number of rows and seats per row
const int NUM_ROWS = 5;
const int SEATS_PER_ROW = 10;

// Class to represent a Movie
class Movie {
public:
    string title;
    string time;
    double price;

    Movie(string t, string tm, double p) : title(t), time(tm), price(p) {}
};

// Class to represent a Seat
class Seat {
public:
    int row;
    int seatNumber;
    bool isBooked;

    Seat(int r, int s) : row(r), seatNumber(s), isBooked(false) {}
};

// Function to display the available movies
void displayMovies(const vector<Movie>& movies) {
    cout << "Available Movies:\n";
    cout << "-----------------\n";
    for (size_t i = 0; i < movies.size(); ++i) {
        cout << i + 1 << ". " << movies[i].title << " - " << movies[i].time << " - $" << fixed << setprecision(2) << movies[i].price << endl;
    }
    cout << endl;
}

// Function to display the seating chart
void displaySeatingChart(const vector<vector<Seat>>& seats) {
    cout << "Seating Chart:\n";
    cout << "-----------------\n";
    for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < SEATS_PER_ROW; ++j) {
            if (seats[i][j].isBooked) {
                cout << "X ";
            } else {
                cout << "O ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Function to book a seat
void bookSeat(vector<vector<Seat>>& seats, int row, int seatNumber) {
    seats[row][seatNumber].isBooked = true;
}

int main() {
    // Create some sample movies
    vector<Movie> movies;
    movies.push_back(Movie("Movie 1", "10:00 AM", 30.0));
    movies.push_back(Movie("Movie 2", "2:00 PM", 40.0));
    movies.push_back(Movie("Movie 3", "5:00 PM", 50.0));

    // Initialize the seating chart
    vector<vector<Seat>> seats(NUM_ROWS, vector<Seat>(SEATS_PER_ROW, Seat(0, 0)));

    int choice;
    do {
        cout << "Movie Ticket Booking System\n";
        cout << "---------------------------\n";
        displayMovies(movies);
        cout << "Enter the movie number (0 to exit): ";
        cin >> choice;

        if (choice >= 1 && choice <= movies.size()) {
            int selectedRow, selectedSeat;
            displaySeatingChart(seats);
            cout << "Enter row and seat number (e.g., 1 5): ";
            cin >> selectedRow >> selectedSeat;

            if (selectedRow >= 1 && selectedRow <= NUM_ROWS && selectedSeat >= 1 && selectedSeat <= SEATS_PER_ROW) {
                if (!seats[selectedRow - 1][selectedSeat - 1].isBooked) {
                    bookSeat(seats, selectedRow - 1, selectedSeat - 1);
                    double totalPrice = movies[choice - 1].price;
                    cout << "Booking successful! Total cost: $" << fixed << setprecision(2) << totalPrice << endl;
                } else {
                    cout << "Seat is already booked. Please select another seat.\n";
                }
            } else {
                cout << "Invalid row or seat number. Please try again.\n";
            }
        } else if (choice != 0) {
            cout << "Invalid movie number. Please try again.\n";
        }
    } while (choice != 0);

    cout << "Thank you for using the Movie Ticket Booking System!\n";

    return 0;
}