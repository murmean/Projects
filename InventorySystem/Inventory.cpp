//
// Created by mtarn on 6/17/2023.
//

#include "Inventory.h"
#include <algorithm>
#include <iostream>

void Inventory::AddProduct(const Product& product) {
    products.push_back(product);
}

void Inventory::RemoveProduct(int id) {
    products.erase(std::remove_if(products.begin(), products.end(),
                                  [id](const Product& product) { return product.getID() == id; }),
                   products.end());
}

void Inventory::ChangePrice(int id, double newPrice) {
    auto it = std::find_if(products.begin(), products.end(),
                           [id](const Product& product) { return product.getID() == id; });

    if (it != products.end()) {
        it->setPrice(newPrice);
    }
}

void Inventory::SetPrice(int id, double price) {
    auto it = std::find_if(products.begin(), products.end(),
                           [id](const Product& product) { return product.getID() == id; });

    if (it != products.end()) {
        it->setPrice(price);
    }
}

Product* Inventory::SearchByID(int id) {
    auto it = std::find_if(products.begin(), products.end(),
                           [id](const Product& product) { return product.getID() == id; });

    if (it != products.end()) {
        return &(*it);
    }

    return nullptr;
}

void Inventory::DisplayInventory() const {
    std::cout << "Inventory:\n";
    for (const auto& product : products) {
        std::cout << "ID: " << product.getID() << "\n"
                  << "Name: " << product.getName() << "\n"
                  << "Description: " << product.getDescription() << "\n"
                  << "Price: " << product.getPrice() << "\n"
                  << "Quantity: " << product.getQuantity() << "\n"
                  << "---------------------\n";
    }
}

const std::vector<Product>& Inventory::GetProducts() const {
    return products;
}