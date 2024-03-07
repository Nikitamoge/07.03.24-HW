#include <iostream>
#include <string>

using namespace std;

class Transport {
protected:
    string model;
    int year;

public:
    Transport(string m, int y) : model(m), year(y) {}

    virtual void output() = 0; 
    virtual double FuelExpense() = 0;
};


class FighterJet : public Transport {
private:
    int MaxSpeed;
    int wings;

public:
    FighterJet(string m, int y, int alt, int eng) : Transport(m, y), MaxSpeed(alt), wings(eng) {}

    void output() {
        cout << "Fighter jet: " << model << endl << "Year: " << year << endl << "Max speed: " << MaxSpeed << endl << "Amount of wings: " << wings << endl;
    }

    double FuelExpense() {
        return wings * 5.0; 
    }
};


class Ship : public Transport {
private:
    double distance;
    int employees;

public:
    Ship(string m, int y, double dist, int pass) : Transport(m, y), distance(dist), employees(pass) {}

    void output() {
        cout << "Ship: " << model << endl << "Year: " << year << endl << "Distance: " << distance << endl << "Employees: " << employees << endl;
    }

    double FuelExpense() {
        return distance / 100.0;
    }
};


class Truck : public Transport {
private:
    int capacity;

public:
    Truck(string m, int y, int cap) : Transport(m, y), capacity(cap) {}

    void output() {
        cout << "Truck: " << model << endl << "Year: " << year << endl << "Capacity: " << capacity << endl;
    }

    double FuelExpense() {
        return capacity * 0.2; 
    }
};


class Bicycle : public Transport {
private:
    int Wheels;

public:
    Bicycle(string m, int y, int wh) : Transport(m, y), Wheels(wh) {}

    void output() {
        cout << "Bicycle: " << model << endl << "Year: " << year << endl << "Gear: " << endl << "Amount of wheels: " << Wheels << endl;
    }

    double FuelExpense() {
        return 0.0; 
    }
};


class Car : public Transport {
private:
    int doors;
    bool Energy;

public:
    Car(string m, int y, int d, bool e) : Transport(m, y), doors(d), Energy(e) {}

    void output() {
        cout << "Car: " << model << endl << "Year: " << year << endl << "Doors: " << doors << endl << "Electric: " << (Energy ? "Yes" : "No") << endl;
    }

    double FuelExpense() {
        return Energy ? 0.0 : 6.5; 
    }
};


int main() {
    Transport* transport = nullptr;
    int choice;

    cout << "Select type of transport:\n1. Fighter jet\n2. Ship\n3. Truck\n4. Bicycle\n5. Car\n";
    cin >> choice;
    switch (choice) {
    case 1:
        transport = new FighterJet("F-32", 2006, 3500, 2);
        break;
    case 2:
        transport = new Ship("Aircraft carrier", 2002, 5000, 500);
        break;
    case 3:
        transport = new Truck("M939", 1993, 2000);
        break;
    case 4:
        transport = new Bicycle("Military bicycle", 1950, 2);
        break;
    case 5:
        transport = new Car("Cyberturck", 2023, 4, true);
        break;
    default:
        cout << "ERROR!" << endl;
        return 1;
    }

    transport->output();
    cout << "Fuel expense: " << transport->FuelExpense() << endl;
}
