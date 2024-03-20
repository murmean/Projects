//
// Created by mtarn on 6/17/2023.
//

#ifndef PROG_PROJ_FIN_INVENTORYMANAGER_H
#define PROG_PROJ_FIN_INVENTORYMANAGER_H

#include "CSVFileManager.h"

class InventoryManager {
private:
    Inventory inventory;
    CSVFileManager fileManager;

public:
    explicit InventoryManager(std::string filename);
    void ProcessCommand();
    void PrintOptions() const;
};

#endif //PROG_PROJ_FIN_INVENTORYMANAGER_H
