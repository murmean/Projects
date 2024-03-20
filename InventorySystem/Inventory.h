//
// Created by mtarn on 6/17/2023.
//

#ifndef PROG_PROJ_FIN_INVENTORY_H
#define PROG_PROJ_FIN_INVENTORY_H

#include <vector>
#include "Product.h"
class Inventory {
private:
    std::vector<Product> products;

public:
    void AddProduct(const Product& product);
    void RemoveProduct(int id);
    void ChangePrice(int id, double newPrice);
    void SetPrice(int id, double price);
    Product* SearchByID(int id);
    void DisplayInventory() const;
    const std::vector<Product>& GetProducts() const;
};


#endif //PROG_PROJ_FIN_INVENTORY_H
