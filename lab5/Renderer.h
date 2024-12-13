
#ifndef RENDERER_H
#define RENDERER_H

#include <string>

//implementation
//
class Renderer {
    
public:
    
    virtual ~Renderer() = default;
    //virtual methods
    virtual std::string renderTitle(const std::string& title) const = 0;
    virtual std::string renderContent(const std::string& content) const = 0;
    virtual std::string renderProduct(const std::string& name, const std::string& description, const std::string& image, int id) const = 0;

};

//implementation of Renderer for rendering as HTML
class HTMLRenderer : public Renderer {
    
public:
    
    std::string renderTitle(const std::string& title) const override {
        return "<h1>" + title + "</h1>";
    }

    std::string renderContent(const std::string& content) const override {
        return "<p>" + content + "</p>";
    }

    std::string renderProduct(const std::string& name, const std::string& description, const std::string& image, int id) const override {
        return "<div><h1>" + name + "</h1><p>" + description + "</p><img src='" + image + "'/><p>ID: " + std::to_string(id) + "</p></div>";
    }
    
};

//as JSON
class JsonRenderer : public Renderer {
    
public:
    
    std::string renderTitle(const std::string& title) const override {
        return "{\"title\": \"" + title + "\"}";
    }

    std::string renderContent(const std::string& content) const override {
        return "{\"content\": \"" + content + "\"}";
    }

    std::string renderProduct(const std::string& name, const std::string& description, const std::string& image, int id) const override {
        return "{\"product\": {\"name\": \"" + name + "\", \"description\": \"" + description + "\", \"image\": \"" + image + "\", \"id\": " + std::to_string(id) + "}}";
    }
    
};

#endif // RENDERER_H

