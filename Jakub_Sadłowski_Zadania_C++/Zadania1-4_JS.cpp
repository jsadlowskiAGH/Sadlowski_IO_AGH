#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Exercise001{
    void printOddNumbers(){
        for (int i = 301; i <= 1200; i++) {
            if (i % 400 == 0) {
                cout << i << endl;
            }
            if (i % 100 == 0) {
                cout << " *** ";
            } else if(i % 2 == 1){
                cout << i << " ";
            }
        }
    }

public:
    void execute(){
        printOddNumbers();
    }
};

class Exercise002{
    int AA[10];
    int* BB;
    int countNegative = 0;
    int countSkipped = 0;

    void createArray(){
        cout << "Enter 10 numbers:\n";

        for (int i = 0; i < 10; ++i) {
            cin >> AA[i];
            if (AA[i] < 0) {
                countNegative++;
            }
        }
    }

    void countNegativeAndSkipped(){
        BB = new int[countNegative];
        int j = 0;
        for (int i = 0; i < 10; ++i) {
            if (AA[i] < 0) {
                BB[j] = AA[i];
                j++;
            } else {
                countSkipped++;
            }
        }
    }

    void printNumbers(){
        cout << "Negative numbers: ";
        for (int i = 0; i < countNegative; ++i) {
            cout << BB[i] << " ";
        }
        cout << "\nCount of negative numbers: " << countNegative << endl;
        cout << "Count of skipped numbers: " << countSkipped << endl;
    }

public:
    void execute(){
        createArray();
        countNegativeAndSkipped();
        printNumbers();
        delete[] BB;
    }
};

class Exercise003{
    double changeKilometersToLandMiles(double kilometers){
        //1 mila lądowa = 1,609 kilometra
        return kilometers / 1.609;
    }

    double changeKilometersToNauticalMiles(double kilometers){
        //1 mila morska = 1,852 kilometra
        return kilometers / 1.852;
    }

    double getKilometersFromUser(){
        double input;
        cin >> input;
        return input;
    }

public:
    void execute(){
        cout << "Podaj liczbe w kilometrach: ";
        double kilometers = getKilometersFromUser();
        double landMiles = changeKilometersToLandMiles(kilometers);
        double nauticalMiles = changeKilometersToNauticalMiles(kilometers);
        cout << "\nPodana liczba w kilometrach po przeliczeniu:" << endl << "Mile ladowe: " << landMiles << endl
        << "Mile morskie: " << nauticalMiles;
    }
};

class Exercise004{

    struct Product {
        string name;
        int price;

    public:
        Product() {
            name = "";
            price = 0;
        }

        Product(const string &name, int price) : name(name), price(price) {}

        void setName(string name) {
            this->name = name;
        }

        void setPrice(int price) {
            this->price = price;
        }

        int getPrice() {
            return price;
        }
    };

    vector<Product> getProductsFromUser() {
        vector<Product> products;
        string name;
        int price;
        for (int i = 0; i < 10; i++) {
            Product product;
            products.push_back(product);
            cout << "Podaj nazwe produktu " << i << ":" << endl;
            cin >> name;
            products[i].setName(name);
            cout << "Podaj cene produktu " << i << ":" << endl;
            cin >> price;
            products[i].setPrice(price);
        }
        return products;
    }

    vector<Product> sortFromExpensiveToCheapest(vector<Product> products) {
        sort(products.begin(), products.end(), [](Product a, Product b){return a.getPrice() > b.getPrice(); });
        return products;
    }

    void with_separator(const vector<Product>& vec, string sep = " ")
    {
        for (auto elem : vec) {
            cout << elem.getPrice() << sep;
        }

        cout << endl;
    }

public:
    void execute(){
        //vector<Product> products = getProductsFromUser();
        vector<Product> products = {Product("ok" , 2), Product("ok" , 5), Product("ok" , 10),
                                    Product("ok" , 1), Product("ok" , 3), Product("ok" , 6),
                                    Product("ok" , 9), Product("ok" , 25), Product("ok" , 71),
                                    Product("ok" , 90)};
        vector<Product> sortedProducts = sortFromExpensiveToCheapest(products);
        with_separator(sortedProducts, ",");
    }
};


int main() {
    try
    {
        Exercise001 exercise001;
        Exercise002 exercise002;
        Exercise003 exercise003;
        Exercise004 exercise004;

        cout << "Prosze podac numer zadania 1, 2, 3, 4: ";
        int exerciseNo = 0;
        cin >> exerciseNo;
        switch (exerciseNo)
        {
            case 1:
                exercise001.execute();
                break;
            case 2:
                exercise002.execute();
                break;
            case 3:
                exercise003.execute();
                break;
            case 4:
                exercise004.execute();
                break;
            default:
                cout << "Niepoprawny numer zadania";
        }
        return 0;
    }
    catch (std::logic_error& e)
    {
        std::cout << e.what() << endl;
    }
    return 0;
}