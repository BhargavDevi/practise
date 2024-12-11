#include <iostream>
#include <string>
using namespace std;

// Base class: Car
class Car {
protected:
    int id;
    string model;
    double dailyRate;
    bool isAvailable;

public:
    Car(int carId = 0, string carModel = "Unknown", double rate = 0.0)
        : id(carId), model(carModel), dailyRate(rate), isAvailable(true) {}

    void rentCar() {
        if (isAvailable) {
            isAvailable = false;
            cout << model << " (ID: " << id << ") rented.\n";
        } else {
            cout << model << " (ID: " << id << ") is already rented.\n";
        }
    }

    void returnCar(int days) {
        if (!isAvailable) {
            isAvailable = true;
            cout << model << " (ID: " << id << ") returned. Total cost: Rs." << days * dailyRate << "\n";
        } else {
            cout << model << " (ID: " << id << ") is already available.\n";
        }
    }

    void display() const {
        cout << "ID: " << id << ", Model: " << model << ", Rate: Rs." << dailyRate
             << ", Available: " << (isAvailable ? "Yes" : "No") << "\n";
    }

    int getId() const { return id; }
    bool isCarAvailable() const { return isAvailable; }
};

// New class: LuxuryFeature
class LuxuryFeature {
protected:
    string feature;

public:
    LuxuryFeature(string luxuryFeature = "Standard") : feature(luxuryFeature) {}

    void showFeature() const {
        cout << "Luxury Feature: " << feature << "\n";
    }
};

// Derived class: LuxuryCar (hybrid inheritance from Car and LuxuryFeature)
class LuxuryCar : public Car, public LuxuryFeature {
public:
    LuxuryCar(int carId, string carModel, double rate, string luxuryFeature)
        : Car(carId, carModel, rate), LuxuryFeature(luxuryFeature) {}

    void display() const {
        Car::display();       // Display basic car details
        showFeature();        // Display luxury feature
    }
};

// CarRentalSystem class to manage cars
class CarRentalSystem {
private:
    static const int MAX_CARS = 10;
    Car* cars[MAX_CARS];
    int carCount;

public:
    CarRentalSystem() : carCount(0) {}

    void addCar(Car* car) {
        if (carCount < MAX_CARS) {
            cars[carCount++] = car;
        } else {
            cout << "No space to add more cars.\n";
        }
    }

    void displayAvailableCars() const {
        for (int i = 0; i < carCount; ++i) {
            if (cars[i]->isCarAvailable()) {
                cars[i]->display();
            }
        }
    }

    void rentCarById(int id) {
        for (int i = 0; i < carCount; ++i) {
            if (cars[i]->getId() == id) {
                cars[i]->rentCar();
                return;
            }
        }
        cout << "Car with ID " << id << " not found.\n";
    }

    void returnCarById(int id, int days) {
        for (int i = 0; i < carCount; ++i) {
            if (cars[i]->getId() == id) {
                cars[i]->returnCar(days);
                return;
            }
        }
        cout << "Car with ID " << id << " not found.\n";
    }
};

// Main function
int main() {
    CarRentalSystem system;

    // Adding both regular and luxury cars
    system.addCar(new Car(1, "Toyota Corolla", 1400));
    system.addCar(new Car(2, "Honda Civic", 1500));
    system.addCar(new LuxuryCar(3, "BMW 7 Series", 15000, "Massage Seats"));
    system.addCar(new LuxuryCar(4, "Mercedes S-Class", 20000, "Heated Seats"));

    int choice;
    do {
        cout << "\n1. View Available Cars\n2. Rent a Car\n3. Return a Car\n4. Exit\nChoose: ";
        cin >> choice;

        if (choice == 1) {
            system.displayAvailableCars();
        } else if (choice == 2) {
            int id;
            cout << "Enter Car ID to rent: ";
            cin >> id;
            system.rentCarById(id);
        } else if (choice == 3) {
            int id, days;
            cout << "Enter Car ID to return: ";
            cin >> id;
            cout << "Enter number of rental days: ";
            cin >> days;
            system.returnCarById(id, days);
        }

    } while (choice != 4);

    return 0;
}
