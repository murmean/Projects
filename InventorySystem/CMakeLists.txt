cmake_minimum_required(VERSION 3.24)
project(prog_proj_fin)

set(CMAKE_CXX_STANDARD 17)

add_executable(prog_proj_fin main.cpp Product.cpp Product.h Inventory.cpp Inventory.h CSVFileManager.cpp CSVFileManager.h InventoryManager.cpp InventoryManager.h)
