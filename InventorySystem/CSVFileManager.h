//
// Created by mtarn on 6/17/2023.
//

#ifndef PROG_PROJ_FIN_CSVFILEMANAGER_H
#define PROG_PROJ_FIN_CSVFILEMANAGER_H

#include <string>
#include "Inventory.h"

class CSVFileManager {
private:
    std::string filename;

public:
    explicit CSVFileManager(std::string filename);
    void WriteToFile(const Inventory& inventory);
    Inventory ReadFromFile();
};


#endif //PROG_PROJ_FIN_CSVFILEMANAGER_H
