//
// Created by mtarn on 6/17/2023.
//

#ifndef PROG_PROJ_FIN_PRODUCT_H
#define PROG_PROJ_FIN_PRODUCT_H
#pragma once
#include <string>

class Product {
private:
    int id;
    std::string name;
    std::string description;
    double price;
    int quantity;

public:
    Product(int id, const std::string& name, const std::string& description, double price, int quantity);

    int getID() const;
    std::string getName() const;
    std::string getDescription() const;
    double getPrice() const;
    int getQuantity() const;
    void setPrice(double newPrice);
};


#endif //PROG_PROJ_FIN_PRODUCT_H
