/*Створити клас машина, що має поля: марка авто, число циліндрів, потужність. +
Визначити конструктори, деструктор і функцію друку. +
Створити похідний клас - вантажівки, що має поле вантажопідйомність кузова. 
Визначити конструктори за замовчуванням та із різним числом параметрів, деструктори, функцію друку. 
Визначити функції перепризначення марки та вантажопідйомності.
Написати програму тестування всіх можливостей цього класу.*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>

using namespace std;

class Car
{
protected:
    string brand;
    int cylinders;
    int power;

public:
    Car() //конструктор без параметрів
    {
        brand = "default";
        cylinders = 0;
        power = 0;
        cout << "Default constructor Car" << endl;
    }

    Car(string s, int c, int p) //конструктор з параметрами
    {
        brand = s;
        cylinders = c;
        power = p;
        cout << "Consstructor Car" << endl;
    }

    Car(const Car& car) //конструктор копіювання
    {
        brand = car.brand;
        cylinders = car.cylinders;
        power = car.power;
    }

    ~Car() //деструктор
    {
        cout << "Destructor Car" << endl;
    }

    string getBrand() 
    {
        return brand;
    }

    int getCylinders()
    {
        return cylinders;
    }

    int getPower()
    {
        return power;
    }

    void setBrand(string b)
    {
        brand = b;
    }

    void setCylinders(int c)
    {
        if(c >= 4 && c <= 12) 
            cylinders = c;
        else 
            cout << "Cylinders" << c << "not allow, cylinders is " << cylinders << endl;
    }

    void setPower(int p)
    {
        if(p <= 70 || p > 500)
            power = p;
        else 
            cout << "Power" << p << "not exist, power is " << power << endl;
    }

    Car& operator=(const Car& cr) //перевантаження оператора присвоювання
    {
        if(&cr == this) return *this;
        brand = cr.brand;
        cylinders = cr.cylinders;
        power = cr.power;
        return *this;
    }



   /* string toString()
    {
        string b, c, p;
        c = to_string(cylinders);
        p = to_string(power);
        b = "Brand:" + brand + "Cylinders:" + c + "Power:" + p;
        return b;
    }

    void Input()
    {
        cout << "Input brand:";
        cin >> brand;

        cout << "Input cylinders:";
        while(!(cin >> cylinders) || (cylinders >= 4 && cylinders <= 12))
        {
            cin.clear();
            cin.ignore(MAXSHORT, '\n');
            fflush(stdin);
            cout << "bad input cylinders is 4 to 12" << endl;
        }

        cout << "Input power:";
        while(!(cin >> power) || (power >= 70 && power <= 500))
        {
            cin.clear();
            cin.ignore(MAXSHORT, '\n');
            fflush(stdin);
            cout << "bad input power is 70 to 500" << endl;
        }
    }*/

    friend ostream& operator<<(ostream &os, const Car& cr);
    friend istream& operator>>(istream &is, Car& cr);
};

ostream& operator<<(ostream &os, const Car& cr)
{
    os << "\nBrand:" << cr.brand;
    os << "\nCylinders:" << cr.cylinders;
    os << "\nPower:" << cr.power;
    return os;
}

istream& operator>>(istream &is, Car& cr)
{
    cout << "\nBrand: ";
    is >> cr.brand;
    cout << "\nCylinders: ";
    is >> cr.cylinders;
    cout << "\nPower: ";
    is >> cr.power;
    return is;
}

class Trucks : public Car
{
    int capacity;
public:
    Trucks()
    {
        capacity = 0;
        cout << "Default constructor" << endl;
    }

    Trucks(string s, int c, float p, int cp) : Car(s, c, p)
    {
        capacity = cp;
        cout << "Constructor Trucks(string s, int c, float p, int cp)" << endl;
    }

    Trucks(const Trucks& tr)
    {
        brand = tr.brand;
        cylinders = tr.cylinders;
        power = tr.power;
        capacity = tr.capacity;
    }

    ~Trucks()
    {
        cout << "Destuctor Trucks" << endl;
    }

    int getCapacity()
    {
        return capacity;
    }

    void setCapacity(int cp)
    {
        if(cp >= 0 && cp <= 20)
            capacity = cp;
        else
            capacity = 0;
    }

    Trucks& operator=(const Trucks& t)
    {
        if(&t == this) return *this;
        brand = t.brand;
        cylinders = t.cylinders;
        power = t.power;
        capacity = t.capacity;
        return *this;
    }

    friend ostream& operator<<(ostream &os, const Trucks& t);
    friend istream& operator>>(istream &is, Trucks& t);



   /* string toString()
    {
        string scapasity;
        scapasity = to_string(capacity);
        string s = Car::toString() + "Capacity:" + scapasity + "\n";
        return s;
    }

    void Input()
    {
        Car::Input();
        cout << "Input tone" << endl;
        while (!(cin >> capacity) || capacity < 0 ) 
        {
            cin.clear();
            cin.ignore(MAXSHORT, '\n');
            fflush(stdin);
            cout << "bad input ID \n";
        }
    }*/
};

ostream& operator<<(ostream &os, const Trucks& t)
{
    os << "\nBrand:" << t.brand;
    os << "\nCylinders:" << t.cylinders;
    os << "\nPower:" << t.power;
    os << "\nCapacity:" << t.capacity;
    return os;
}

istream& operator>>(istream &is, Trucks& t)
{
    cout << "\nBrand: ";
    is >> t.brand;
    cout << "\nCylinders: ";
    is >> t.cylinders;
    cout << "\nPower: ";
    is >> t.power;
    cout << "\nCapacity: ";
    is >> t.capacity;
    return is;
}

void f1(Car& cr)
{
    cr.setBrand("BMW");
    cout << cr;
}

int main()
{
    Car a;
    cin >> a;
    cout << a;
}