/*Створити ієрархію класів меблі й стіл. 
Перевизначити вивід у потік і введення з потоку, 
конструктор копіювання, 
оператор присвоювання через відповідні функції базового класу.*/

#include <iostream>
#include <string>

using namespace std;

class Furniture
{
protected:
    string firm;
    string material;
    double price;
public:
    Furniture() : firm(""), material(""), price(0.0)
    { cout << "Default constructor Furniture" << endl; }

    Furniture(const string& f, const string& m, double p) : firm(f), material(m), price(p)
    { cout << "Constructor Furniture" << endl; }

    Furniture(const Furniture& fur) : firm(fur.firm), material(fur.material), price(fur.price)
    { cout << "Constructor copy Furniture" << endl; }

    ~Furniture(){ cout << "Destructor Furniture" << endl;}

    virtual void print() const
    {
        cout << "Firm: " << firm << endl;
        cout << "Material: " << material << endl;
        cout << "Price: " << price << endl;
    }

    virtual void read()
    {
        cout << "Firm: ";
        getline(cin, firm);
        cout << "Material: ";
        getline(cin, material);
        cout << "Price: ";
        cin >> price;
        cin.ignore();
    }

    Furniture& operator=(const Furniture& fur)
    {
        firm = fur.firm;
        material = fur.material;
        price = fur.price;
        return *this;
    }

    friend istream& operator>>(istream& in, Furniture& f)
    {
        f.read();
        return in;
    }

    friend ostream& operator<<(ostream& out, const Furniture& f)
    {
        f.print();
        return out;
    }
};

class Table : public Furniture
{
protected:
    double length;
    double width;
    double height;
public:
    Table() : Furniture(), length(0.0), width(0.0), height(0.0)
    { cout << "Default constructor Table" << endl; }

    Table(const string& f, const string& m, double p, double l, double w, double h) : Furniture(f, m, p), length(l), width(w), height(h)
    { cout << "Constructor Table" << endl; }

    Table(const Table& table) : Furniture(table), length(table.length), width(table.width), height(table.height)
    { cout << "Constructor copy Table" << endl; }

    ~Table(){ cout << "Destructor Table" << endl;}

    virtual void print() const
    {
        Furniture::print();
        cout << "Table length: " << length << endl;
        cout << "The width of the table: " << width << endl;
        cout << "Table height: " << height << endl;
    }

    virtual void read()
    {
        Furniture::read();
        cout << "Enter the length of the table: ";
        cin >> length;
        cout << "Enter the width of the table: ";
        cin >> width;
        cout << "Enter the height of the table: ";
        cin >> height;
        cin.ignore();
    }

    Table& operator=(const Table& table)
    {
        Furniture::operator=(table);
        length = table.length;
        width = table.width;
        height = table.height;
        return *this;
    }

    friend istream& operator>>(istream& in, Table& t)
    {
        t.read();
        return in;
    }

    friend ostream& operator<<(ostream& out, const Table& t)
    {
        t.print();
        return out;
    }
};

int main()
{
    Furniture f("Yuo", "Wood", 800.0);
    Table t("TY", "Plastic", 100.0, 21.2, 67.9, 90.0);
    
    Furniture f1;

    cout << f << endl;
    cout << t << endl;

    cin >> f1;

    Furniture f2 = f;
    Table t1 = t;

    cout << f2 << endl;
    cout << t1 << endl;

    return 0;
} 