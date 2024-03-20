//
// Created by mtarn on 6/17/2023.
//

#include "InventoryManager.h"
#include <iostream>

InventoryManager::InventoryManager(std::string filename) : fileManager(std::move(filename)) {
    this->inventory = fileManager.ReadFromFile();
}

void InventoryManager::ProcessCommand() {
    char choice;
    do {
        PrintOptions();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case '1': {
                int id, quantity;
                std::string name, description;
                double price;

                std::cout << "Enter product ID: ";
                std::cin >> id;
                std::cout << "Enter product name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter product description: ";
                std::getline(std::cin, description);
                std::cout << "Enter product price: ";
                std::cin >> price;
                std::cout << "Enter product quantity: ";
                std::cin >> quantity;

                Product newProduct(id, name, description, price, quantity);
                inventory.AddProduct(newProduct);
                fileManager.WriteToFile(inventory);
                std::cout << "Product added successfully!\n";
                break;
            }
            case '2': {
                int id;
                std::cout << "Enter product ID to remove: ";
                std::cin >> id;
                inventory.RemoveProduct(id);
                fileManager.WriteToFile(inventory);
                std::cout << "Product removed successfully!\n";
                break;
            }
            case '3': {
                int id;
                double newPrice;
                std::cout << "Enter product ID: ";
                std::cin >> id;
                std::cout << "Enter new price: ";
                std::cin >> newPrice;
                inventory.ChangePrice(id, newPrice);
                fileManager.WriteToFile(inventory);
                std::cout << "Price changed successfully!\n";
                break;
            }
            case '4': {
                int id;
                double price;
                std::cout << "Enter product ID: ";
                std::cin >> id;
                std::cout << "Enter price: ";
                std::cin >> price;
                inventory.SetPrice(id, price);
                fileManager.WriteToFile(inventory);
                std::cout << "Price set successfully!\n";
                break;
            }
            case '5': {
                int id;
                std::cout << "Enter product ID to search: ";
                std::cin >> id;
                Product *foundProduct = inventory.SearchByID(id);
                if (foundProduct != nullptr) {
                    std::cout << "Product found:\n";
                    std::cout << "ID: " << foundProduct->getID() << "\n"
                              << "Name: " << foundProduct->getName() << "\n"
                              << "Description: " << foundProduct->getDescription() << "\n"
                              << "Price: " << foundProduct->getPrice() << "\n"
                              << "Quantity: " << foundProduct->getQuantity() << "\n";
                } else {
                    std::cout << "Product not found!\n";
                }
                break;
            }
            case '6': {
                inventory.DisplayInventory();
                break;
            }
            case 'Q':
            case 'q':
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }

        std::cout << "\n";
    } while (choice != 'Q' && choice != 'q');
}
void InventoryManager::PrintOptions() const {
    std::cout << "Inventory Management System\n";
    std::cout << "1. Add Product\n";
    std::cout << "2. Remove Product\n";
    std::cout << "3. Change Price\n";
    std::cout << "4. Set Price\n";
    std::cout << "5. Search by ID\n";
    std::cout << "6. Display Inventory\n";
    std::cout << "Q. Quit\n";
}