#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
	string name;
	int price;

public:
	Product() {}

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

void findCheapestProduct(vector<Product> products) {
	int min = 100000000;
	for (int i = 0; i < 10; i++)
	{
		if (products[i].getPrice() < min)
			min = products[i].getPrice();
	}
	cout << "\nNajtanszy produkt = " << min;
}

int main() {
	vector<Product> products = getProductsFromUser();
	//vector<Product> products2 = { 1, 325, 23432, 24, 24, 15, 32534, 346, 23, 189 };
	findCheapestProduct(products);
	return 0;
}