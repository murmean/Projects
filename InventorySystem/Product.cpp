//
// Created by mtarn on 6/17/2023.
//

#include "Product.h"
Product::Product(int id, const std::string& name, const std::string& description, double price, int quantity)
        : id(id), name(name), description(description), price(price), quantity(quantity) {}

int Product::getID() const { return id; }
std::string Product::getName() const { return name; }
std::string Product::getDescription() const { return description; }
double Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }
void Product::setPrice(double newPrice) { price = newPrice; }