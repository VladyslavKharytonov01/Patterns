#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include <iostream>


class Storage {
    
public:
    
    virtual ~Storage() {}
    
    virtual void connect() = 0;

    virtual void saveFile(const std::string& filename) = 0;
    virtual void loadFile(const std::string& filename) = 0;
    
};


class LocalStorage : public Storage {
    
public:
    
    void connect() override {
        std::cout << "Connecting to local storage..." << std::endl;
    }

    void saveFile(const std::string& filename) override {
        std::cout << "Saving file to local disk: " << filename << std::endl;
    }

    void loadFile(const std::string& filename) override {
        std::cout << "Loading file from local disk: " << filename << std::endl;
    }
    
};


class S3Storage : public Storage {
    
public:
    
    void connect() override {
        std::cout << "Connecting to Amazon S3..." << std::endl;
    }

    void saveFile(const std::string& filename) override {
        std::cout << "Saving file to Amazon S3: " << filename << std::endl;
    }

    void loadFile(const std::string& filename) override {
        std::cout << "Loading file from Amazon S3: " << filename << std::endl;
    }
    
};

#endif // STORAGE_H
