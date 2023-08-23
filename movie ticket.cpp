#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 5;
const int COLS = 10;

// Function to display seating arrangement
void displaySeats(bool seats[][COLS]) {
    cout << "   Seats\n";
    cout << "  ";
    for (int i = 0; i < COLS; ++i)
        cout << setw(2) << i + 1;
    cout << "\n";

    for (int i = 0; i < ROWS; ++i) {
        cout << char('A' + i) << " ";
        for (int j = 0; j < COLS; ++j) {
            if (seats[i][j])
                cout << "  ";
            else
                cout << " X";
        }
        cout << "\n";
    }
}

int main() {
    bool seats[ROWS][COLS] = {true}; // Initialize all seats as available

    string movies[] = {"Movie 1", "Movie 2", "Movie 3"};
    double prices[] = {80, 90, 100};

    cout << "Welcome to the Movie Ticket Booking System!\n";

    while (true) {
        cout << "\nSelect a movie:\n";
        for (int i = 0; i < 3; ++i)
            cout << i + 1 << ". " << movies[i] << " (Rs" << prices[i] << ")\n";

        int movieChoice;
        cin >> movieChoice;

        if (movieChoice < 1 || movieChoice > 3) {
            cout << "Invalid choice.\n";
            continue;
        }

        cout << "\nAvailable seats for " << movies[movieChoice - 1] << ":\n";
        displaySeats(seats);

        char row;
        int col;
        cout << "Enter the seat (row and column): ";
        cin >> row >> col;
        int rowIdx = row - 'A';

        if (rowIdx < 0 || rowIdx >= ROWS || col < 1 || col > COLS) {
            cout << "Invalid seat.\n";
            continue;
        }

        if (!seats[rowIdx][col - 1]) {
            cout << "Seat already booked. Please select another seat.\n";
            continue;
        }

        seats[rowIdx][col - 1] = false;
        cout << "Seat booked successfully!\n";

        double totalCost = prices[movieChoice - 1];
        cout << "Total cost: Rs" << totalCost << "\n";

        char choice;
        cout << "Do you want to make another booking? (Y/N): ";
        cin >> choice;
        if (choice != 'Y' && choice != 'y')
            break;
    }

    cout << "Thank you for using the Movie Ticket Booking System!\n";

    return 0;
}
