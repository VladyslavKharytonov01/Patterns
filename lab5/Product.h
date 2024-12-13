
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
    std::string name;
    std::string description;
    std::string image;
    int id;

public:
    
    Product(const std::string& name, const std::string& description, const std::string& image, int id)
        : name(name), description(description), image(image), id(id) {}
//accessing attributes
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    std::string getImage() const { return image; }
    int getId() const { return id; }
    
};

#endif // PRODUCT_H