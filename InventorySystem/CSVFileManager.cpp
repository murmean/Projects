//
// Created by mtarn on 6/17/2023.
//

#include "CSVFileManager.h"
#include <iostream>
#include <fstream>
#include<sstream>

CSVFileManager::CSVFileManager(std::string filename) : filename(std::move(filename)) {}

void CSVFileManager::WriteToFile(const Inventory& inventory) {
    std::ofstream file(filename);
    file << "ID,Name,Description,Price,Quantity\n";
    for(const auto& product: inventory.GetProducts()) {
        file << product.getID() << ","
             << product.getName() << ","
             << product.getDescription() << ","
             << product.getPrice() << ","
             << product.getQuantity() << "\n";
    }
    file.close();
}

Inventory CSVFileManager::ReadFromFile() {
    std::ifstream file(filename);
    if(!file) {
        std::cerr << "Unable to open file: " << filename << ", creating a new one.\n";

        ///// create new file with header
        std::ofstream newFile(filename);
        newFile << "ID,Name,Description,Price,Quantity\n";
        newFile.close();

        /// since the file is empty, return an empty inventory
        return Inventory();
    }
    Inventory inventory;

    std::string line;
    // if the csv file has a header skips it
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);

        int id;
        std::string name;
        std::string description;
        double price;
        int quantity;

        std::getline(ss, line, ',');
        id = std::stoi(line);

        std::getline(ss, name, ',');

        std::getline(ss, description, ',');

        std::getline(ss, line, ',');
        price = std::stod(line);

        std::getline(ss, line, ',');
        quantity = std::stoi(line);

        Product product(id, name, description, price, quantity);
        inventory.AddProduct(product);
    }

    file.close();

    return inventory;
}