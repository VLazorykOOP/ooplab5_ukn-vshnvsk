/*Створити клас двигун, що має потужність. +
Визначити конструктори й метод доступу. +
Створити клас машинa, що містить клас двигун. +
Додатково є марка (вказівник на рядок), ціна. +
Визначити конструктори й деструктор. +
Визначити public-похідний клас вантажівка, що має додатково вантажопідйомність. +
Визначити конструктори, деструктори й функцію друку.*/

#include <iostream>
#include <cstring>

using namespace std;

class Engine
{
private: 
    int power;
public:
    Engine()
    { 
        power = 0;
        cout << "Default constructor Engine" << endl; 
    }
    
    Engine(int p)
    { 
        power = p; 
        cout << "Constructor Engine" << endl; 
    }

    int getPower() const { return power; }
};

class Car
{
private:
    char* brand;
    int price;
    Engine engine;

public:
    Car(const char* b, int p, const Engine& e) : price(p), engine(e)  //конструктор з параметрами
    {
        brand = new char[strlen(b) + 1];
        strcpy(brand, b);
        cout << "Constructor Car" << endl;
    }

    Car(const Car& car) : price(car.price), engine(car.engine)  //конструктор копіювання
    {
        brand = new char[strlen(car.brand) + 1];
        strcpy(brand, car.brand);
        cout << "Constructor copy Car" << endl;
    }

    ~Car()
    {
        delete[] brand;
        cout << "Destructor Car" << endl;
    }

    const char* getBrand() const { return brand; }
    int getPrice() const { return price; }
    const Engine& getEngine() const { return engine; }

};

class Truck : public Car
{
private:
    int capacity;
public:
    Truck(const char* b, int p, const Engine& e, int c) : Car(b, p, e), capacity(c)
    { cout << "Constructor Truck" << endl; } 

    Truck(const Truck& tr) : Car(tr), capacity(tr.capacity)
    { cout << "Constructor copy Truck" << endl; }
    
    ~Truck(){ cout << "Destructor Truck" << endl; }

    int gerCapacity() const { return capacity; }
};

void printCar(const Car& car)
{
    cout << "Brand: " << car.getBrand() << endl;
    cout << "Price: " << car.getPrice() << endl;
    cout << "Engine power: " << car.getEngine().getPower() << endl;
}

void printTruck(const Truck& tr)
{
    printCar(tr);
    cout << "Capacity: " << tr.gerCapacity() << endl;
}

int main()
{
    Engine engine(100);
    Car car("BMW", 20000, engine);
    printCar(car);

    Truck tr("Opel", 10000, engine, 3000);
    printTruck(tr);

    return 0;
}