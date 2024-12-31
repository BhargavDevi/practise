#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Car {
protected:
    int id;
    string model;
    double dailyRate;
    bool isAvailable;

public:
    Car(int carId = 0, string carModel = "Unknown", double rate = 0.0)
        : id(carId), model(carModel), dailyRate(rate), isAvailable(true) {}

    virtual ~Car() {}  
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

    string getLastServiceDate() const { return lastServiceDate; }
    int getMileage() const { return mileage; }
};

void saveData(Car* cars[], int carCount) {
    ofstream outFile("cars_data.txt");
    if (outFile.is_open()) {
        outFile << carCount << "\n";
        for (int i = 0; i < carCount; ++i) {
            MaintainedCar* maintainedCar = dynamic_cast<MaintainedCar*>(cars[i]);
            if (maintainedCar) {
                outFile << "MaintainedCar " << cars[i]->getId() << " " << cars[i]->isCarAvailable() << " "
                        << maintainedCar->getLastServiceDate() << " "
                        << maintainedCar->getMileage() << "\n";
            } else {
                outFile << "Car " << cars[i]->getId() << " " << cars[i]->isCarAvailable() << " ";
            }
        }
        outFile.close();
    } else {
        cout << "Error saving data to file.\n";
    }
}

void loadData(Car* cars[], int& carCount) {
    ifstream inFile("cars_data.txt");
    if (inFile.is_open()) {
        inFile >> carCount;
        string type;
        for (int i = 0; i < carCount; ++i) {
            inFile >> type;
            if (type == "MaintainedCar") {
                int id, isAvailable, mileage;
                double rate;
                string model, lastServiceDate;
                inFile >> id >> isAvailable >> rate;
                inFile.ignore();
                getline(inFile, model, '\n');
                inFile >> lastServiceDate >> mileage;
                cars[i] = new MaintainedCar(id, model, rate, lastServiceDate, mileage);
                if (!isAvailable) {
                    cars[i]->rentCar();  
                }
            } else if (type == "Car") {
                int id, isAvailable;
                double rate;
                string model;
                inFile >> id >> isAvailable >> rate;
                inFile.ignore();
                getline(inFile, model, '\n');
                cars[i] = new Car(id, model, rate);
                if (!isAvailable) {
                    cars[i]->rentCar(); 
                }
            }
        }
        inFile.close();
    } else {
        cout << "No saved data found. Starting with default cars.\n";
    }
}

int main() {
    const int MAX_CARS = 5;
    Car* cars[MAX_CARS];
    int carCount = 0;

    loadData(cars, carCount);

    int choice;
    while (true) {
        cout << "\n1. View Cars\n2. Rent a Car\n3. Return a Car\n4. Search by ID\n5. Check Availability\n6. View Maintenance Info\n7. Add a Car\n8. Exit\nChoose: ";
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
                        saveData(cars, carCount);  
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
                        saveData(cars, carCount); 
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

            case 7: {
                int id;
                string model;
                double rate;
                cout << "Enter Car ID: ";
                cin >> id;
                cout << "Enter Car Model: ";
                cin.ignore();
                getline(cin, model);
                cout << "Enter Daily Rate: ";
                cin >> rate;

                cars[carCount++] = new Car(id, model, rate);
                cout << "Car added successfully.\n";
                saveData(cars, carCount); 
                break;
            }

            case 8:
                cout << "Exiting program. Thank you!\n";
                saveData(cars, carCount); 
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

}