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

    virtual ~Car() {}  // Virtual destructor

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
            cout << model << " (ID: " << id << ") returned. Total cost: Rs. "
                 << days * dailyRate << "\n";
        } else {
            cout << model << " (ID: " << id << ") is already available.\n";
        }
    }

    void display() const {
        cout << "ID: " << id << ", Model: " << model << ", Rate: Rs. " << dailyRate
             << ", Available: " << (isAvailable ? "Yes" : "No") << "\n";
    }

    int getId() const { return id; }
    bool isCarAvailable() const { return isAvailable; }
};


// Derived class: MaintainedCar
class MaintainedCar : public Car {
    string lastServiceDate;
    int mileage;

public:
    MaintainedCar(int carId, string carModel, double rate, string serviceDate, int carMileage)
        : Car(carId, carModel, rate), lastServiceDate(serviceDate), mileage(carMileage) {}

    void display() const {
        Car::display();
        cout << "Last Service Date: " << lastServiceDate << ", Mileage: " << mileage << " km\n";
    }
};

// Main function
int main() {
    const int MAX_CARS = 5;
    Car* cars[MAX_CARS];
    int carCount = 0;

    // Adding cars
    cars[carCount++] = new Car(1, "Toyota Corolla", 1400);
    cars[carCount++] = new Car(2, "Honda Civic", 1500);
    cars[carCount++] = new MaintainedCar(3, "Ford Mustang", 2000, "2024-01-15", 12000);
    cars[carCount++] = new MaintainedCar(4, "Chevrolet Camaro", 2500, "2024-02-10", 15000);

    int choice;
    do {
        cout << "\n1. View Cars\n2. Rent a Car\n3. Return a Car\n4. Search by ID\n5. Check Availability\n6. View Maintenance Info\n7. Exit\nChoose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < carCount; ++i) {
                    cars[i]->display();
                }
                break;

            case 2: {
                int id;
                cout << "Enter Car ID to rent: ";
                cin >> id;
                bool found = false;
                for (int i = 0; i < carCount; ++i) {
                    if (cars[i]->getId() == id) {
                        cars[i]->rentCar();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Car with ID " << id << " not found.\n";
                break;
            }

            case 3: {
                int id, days;
                cout << "Enter Car ID to return: ";
                cin >> id;
                cout << "Enter number of rental days: ";
                cin >> days;
                bool found = false;
                for (int i = 0; i < carCount; ++i) {
                    if (cars[i]->getId() == id) {
                        cars[i]->returnCar(days);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Car with ID " << id << " not found.\n";
                break;
            }

            case 4: {
                int id;
                cout << "Enter Car ID to search: ";
                cin >> id;
                bool found = false;
                for (int i = 0; i < carCount; ++i) {
                    if (cars[i]->getId() == id) {
                        cars[i]->display();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Car with ID " << id << " not found.\n";
                break;
            }

            case 5: {
                int id;
                cout << "Enter Car ID to check availability: ";
                cin >> id;
                bool found = false;
                for (int i = 0; i < carCount; ++i) {
                    if (cars[i]->getId() == id) {
                        cout << "Car ID " << id << " is "
                             << (cars[i]->isCarAvailable() ? "Available.\n" : "Not Available.\n");
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Car with ID " << id << " not found.\n";
                break;
            }

            case 6: {
                cout << "Maintenance Info for All Cars:\n";
                for (int i = 0; i < carCount; ++i) {
                    MaintainedCar* maintainedCar = dynamic_cast<MaintainedCar*>(cars[i]);
                    if (maintainedCar) {
                        maintainedCar->display();
                    }
                }
                break;
            }

            case 7:
                cout << "Exiting program. Thank you!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    // Clean up dynamically allocated memory
    for (int i = 0; i < carCount; ++i) {
        delete cars[i];
    }

    return 0;
}
