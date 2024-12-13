
#ifndef PAGE_H
#define PAGE_H

#include "Product.h"
#include "Renderer.h"
#include <memory>

//abstract base class
class Page {
    
protected:
    
    std::shared_ptr<Renderer> renderer;

public:
    
    Page(std::shared_ptr<Renderer> renderer) : renderer(renderer) {}
    virtual ~Page() = default;
    virtual std::string render() const = 0;
};

//uses Renderer to render content and title
class SimplePage : public Page {
    std::string title;
    std::string content;

public:
    
    SimplePage(const std::string& title, const std::string& content, std::shared_ptr<Renderer> renderer)
        : Page(renderer), title(title), content(content) {}

    std::string render() const override {
        return renderer->renderTitle(title) + "\n" + renderer->renderContent(content);
    }
};

//uses Renderer to render product detail
class ProductPage : public Page {
    Product product;

public:
    
    ProductPage(const Product& product, std::shared_ptr<Renderer> renderer)
        : Page(renderer), product(product) {}

    std::string render() const override {
        return renderer->renderProduct(product.getName(), product.getDescription(), product.getImage(), product.getId());
    }
    
};

#endif // PAGE_H
