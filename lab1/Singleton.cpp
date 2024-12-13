
#include "StorageManager.h"
#include "Storage.h"
#include <iostream>
#include <memory>

int main() {
    StorageManager* storageManager = StorageManager::getInstance();

    std::shared_ptr<Storage> localStorage = std::make_shared<LocalStorage>();
    std::shared_ptr<Storage> s3Storage = std::make_shared<S3Storage>();

    storageManager->setStorage(localStorage);
    std::cout << "Using Local Storage:" << std::endl;
    storageManager->getStorage()->connect(); 
    storageManager->saveFile("local_file.txt");
    storageManager->loadFile("local_file.txt");

    storageManager->setStorage(s3Storage);
    std::cout << "\nUsing S3 Storage:" << std::endl;
    storageManager->getStorage()->connect(); 
    storageManager->saveFile("s3_file.txt");
    storageManager->loadFile("s3_file.txt");

    return 0;
}
