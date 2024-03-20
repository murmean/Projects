#include "InventoryManager.h"

int main() {
    InventoryManager manager("new_list.csv");
    manager.ProcessCommand();
    return 0;
}
