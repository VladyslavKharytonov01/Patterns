#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include "Storage.h"
#include <memory>

// Singleton class for storage managing
class StorageManager {
    
private:
    
    std::shared_ptr<Storage> currentStorage;
    static StorageManager* instance;
    
    StorageManager() : currentStorage(nullptr) {}

public:
    
    static StorageManager* getInstance() {
        if (!instance)
            instance = new StorageManager();
        return instance;
    }

    void setStorage(std::shared_ptr<Storage> storage) {
        currentStorage = storage;
    }

    std::shared_ptr<Storage> getStorage() {
        return currentStorage;
    }

    void saveFile(const std::string& filename) {
        if (currentStorage)
            currentStorage->saveFile(filename);
        else
            std::cout << "Storage not defiined" << std::endl;
    }

    void loadFile(const std::string& filename) {
        if (currentStorage)
            currentStorage->loadFile(filename);
        else
            std::cout << "Storage not defined" << std::endl;
    }
    
};

// Initialize static member
StorageManager* StorageManager::instance = nullptr;

#endif // STORAGEMANAGER_H
