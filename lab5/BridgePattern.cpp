
#include "Renderer.h"
#include "Page.h"
#include <iostream>

int main() {

    std::shared_ptr<Renderer> htmlRenderer = std::make_shared<HTMLRenderer>();
    std::shared_ptr<Renderer> jsonRenderer = std::make_shared<JsonRenderer>();


    SimplePage simplePage("Welcome", "This is a simple page.", htmlRenderer);
    Product product("Headphones", "In-ear headphones.", "headphones.jpg", 123);
    ProductPage productPage(product, jsonRenderer);


    std::cout << "HTML Simple Page:\n" << simplePage.render() << "\n\n";
    std::cout << "JSON Product Page:\n" << productPage.render() << "\n";

    return 0;
}