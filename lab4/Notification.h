
#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <string>
#include <iostream>

//abstract interface
class Notification {
    
public:
   
    virtual void send(const std::string& title, const std::string& message) = 0; //virtual function
    virtual ~Notification() = default;
    
};

//interfce implimentation
class EmailNotification : public Notification {
    
private:
    
    std::string adminEmail;

public:
    
    EmailNotification(const std::string& email) : adminEmail(email) {}

    void send(const std::string& title, const std::string& message) override {
        
        std::cout << "Sent email with title '" << title << "' to '" << adminEmail
                  << "' that says '" << message << "'.\n";
    }
    
};

#endif // NOTIFICATION_H