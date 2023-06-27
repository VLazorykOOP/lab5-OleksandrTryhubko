#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Завдання 1: Класи транспортних засобів

class Transport {
public:
    Transport(const string& name) : name(name) {}

    void printInfo() const {
        cout << "Transport: " << name << endl;
    }

    virtual ~Transport() {
        cout << name << " object deleted" << endl;
    }

private:
    string name;
};

class Car : public Transport {
public:
    Car(const string& name, const string& model) : Transport(name), model(model) {}

    void printInfo() const {
        Transport::printInfo();
        cout << "Model: " << model << endl;
    }

private:
    string model;
};

class Truck : public Transport {
public:
    Truck(const string& name, int capacity) : Transport(name), capacity(capacity) {}

    void printInfo() const {
        Transport::printInfo();
        cout << "Capacity: " << capacity << endl;
    }

private:
    int capacity;
};

class Steamboat : public Transport {
public:
    Steamboat(const string& name, int year) : Transport(name), year(year) {}

    void printInfo() const {
        Transport::printInfo();
        cout << "Year: " << year << endl;
    }

private:
    int year;
};

// Завдання 3: Класи векторів

class Vector {
public:
    Vector(double x, double y) : x(x), y(y) {}

    virtual void print() const {
        cout << "Vector: (" << x << ", " << y << ")" << endl;
    }

    virtual ~Vector() {
        cout << "Vector object deleted" << endl;
    }

protected:
    double x;
    double y;
};

class SafeVector : public Vector {
public:
    SafeVector(double x, double y, double lowerBound, double upperBound) : Vector(x, y), lowerBound(lowerBound), upperBound(upperBound) {}

    void print() const {
        Vector::print();
        cout << "Bounds: [" << lowerBound << ", " << upperBound << "]" << endl;
    }

private:
    double lowerBound;
    double upperBound;
};

int main() {
    int choice;

    cout << "Choose an example: " << endl;
    cout << "1. Transport Vehicles" << endl;
    cout << "2. Skip" << endl;
    cout << "3. Vectors" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    switch (choice) {
    case 1: {
        Car car("Car", "Sedan");
        Truck truck("Truck", 5000);
        Steamboat steamboat("Steamboat", 1950);

        car.printInfo();
        truck.printInfo();
        steamboat.printInfo();

        break;
    }
    case 3: {
        Vector vector(2.5, 3.7);
        SafeVector safeVector(1.2, 4.6, 0.0, 5.0);

        vector.print();
        safeVector.print();

        break;
    }
    default:
        cout << "Invalid choice." << endl;
    }

    return 0;
}
