#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Room class to store room details
class Room {
public:
    int roomNumber;
    string host;
    string startTime;
    string endTime;
    int availableChairs;
    bool isBooked;

    // Constructor to initialize room details
    Room(int roomNumber, int availableChairs) {
        this->roomNumber = roomNumber;
        this->availableChairs = availableChairs;
        this->isBooked = false;  // Initially, the room is not booked
    }

    // Function to book the room
    void bookRoom(string host, string startTime, string endTime) {
        if (!isBooked) {
            this->host = host;
            this->startTime = startTime;
            this->endTime = endTime;
            this->isBooked = true;
            cout << "Room " << roomNumber << " has been booked successfully!" << endl;
        } else {
            cout << "Room " << roomNumber << " is already booked!" << endl;
        }
    }

    // Function to cancel the room booking
    void cancelBooking() {
        if (isBooked) {
            this->host = "";
            this->startTime = "";
            this->endTime = "";
            this->isBooked = false;
            cout << "Room " << roomNumber << " booking has been canceled!" << endl;
        } else {
            cout << "Room " << roomNumber << " is not booked yet!" << endl;
        }
    }

    // Function to display room details
    void displayRoomDetails() {
        cout << "Room Number: " << roomNumber << endl;
        if (isBooked) {
            cout << "Host: " << host << endl;
            cout << "Start Time: " << startTime << endl;
            cout << "End Time: " << endTime << endl;
            cout << "Available Chairs: " << availableChairs << endl;
        } else {
            cout << "The room is available for booking." << endl;
        }
    }
};

// RoomBookingSystem class to manage the booking system
class RoomBookingSystem {
private:
    vector<Room> rooms;

public:
    // Constructor to initialize rooms with room numbers and available chairs
    RoomBookingSystem(int totalRooms, int chairsPerRoom) {
        for (int i = 1; i <= totalRooms; i++) {
            rooms.push_back(Room(i, chairsPerRoom));
        }
    }

    // Function to book a specific room
    void bookRoom(int roomNumber, string host, string startTime, string endTime) {
        if (roomNumber > 0 && roomNumber <= rooms.size()) {
            rooms[roomNumber - 1].bookRoom(host, startTime, endTime);
        } else {
            cout << "Invalid room number!" << endl;
        }
    }

    // Function to cancel a room booking
    void cancelBooking(int roomNumber) {
        if (roomNumber > 0 && roomNumber <= rooms.size()) {
            rooms[roomNumber - 1].cancelBooking();
        } else {
            cout << "Invalid room number!" << endl;
        }
    }

    // Function to check the status of a specific room
    void checkRoomStatus(int roomNumber) {
        if (roomNumber > 0 && roomNumber <= rooms.size()) {
            rooms[roomNumber - 1].displayRoomDetails();
        } else {
            cout << "Invalid room number!" << endl;
        }
    }

    // Function to display all rooms' statuses
    void displayAllRooms() {
        for (Room &room : rooms) {
            room.displayRoomDetails();
            cout << "----------------------------" << endl;
        }
    }
};

// Helper function to display menu
void displayMenu() {
    cout << "\nRoom Allotment and Booking System\n";
    cout << "1. Book a Room\n";
    cout << "2. Cancel a Room Booking\n";
    cout << "3. Check Room Status\n";
    cout << "4. Display All Room Statuses\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int totalRooms, chairsPerRoom;

    // Get room configuration from the user
    cout << "Enter the total number of rooms: ";
    cin >> totalRooms;
    cout << "Enter the number of chairs per room: ";
    cin >> chairsPerRoom;

    // Create the RoomBookingSystem object with the given configuration
    RoomBookingSystem system(totalRooms, chairsPerRoom);

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            int roomNumber;
            string host, startTime, endTime;

            cout << "Enter room number: ";
            cin >> roomNumber;
            cout << "Enter host name: ";
            cin.ignore();
            getline(cin, host);
            cout << "Enter start time: ";
            getline(cin, startTime);
            cout << "Enter end time: ";
            getline(cin, endTime);

            system.bookRoom(roomNumber, host, startTime, endTime);
            break;
        }
        case 2: {
            int roomNumber;
            cout << "Enter room number to cancel booking: ";
            cin >> roomNumber;
            system.cancelBooking(roomNumber);
            break;
        }
        case 3: {
            int roomNumber;
            cout << "Enter room number to check status: ";
            cin >> roomNumber;
            system.checkRoomStatus(roomNumber);
            break;
        }
        case 4:
            system.displayAllRooms();
            break;
        case 5:
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again!" << endl;
        }

    } while (choice != 5);

    return 0;
}
