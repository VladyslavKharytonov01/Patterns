
#ifndef NOTIFICATIONADAPTER_H
#define NOTIFICATIONADAPTER_H
#include "Notification.h"
#include <iostream>

//translates own methods into Notification interface
class SlackNotificationAdapter : public Notification {
    
private:
    
    std::string login;
    std::string apiKey;
    std::string chatId;

public:

    SlackNotificationAdapter(const std::string& login, const std::string& apiKey, const std::string& chatId)
        : login(login), apiKey(apiKey), chatId(chatId) {}

    void send(const std::string& title, const std::string& message) override {
        
        std::cout << "Sent Slack message to chat '" << chatId << "' with title '" << title
                  << "' and message '" << message << "'.\n";
    }
    
};


class SMSNotificationAdapter : public Notification {
    
private:
    
    std::string phone;
    std::string sender;

public:
    
    SMSNotificationAdapter(const std::string& phone, const std::string& sender)
        : phone(phone), sender(sender) {}

    void send(const std::string& title, const std::string& message) override {
        
        std::cout << "Sent SMS from '" << sender << "' to '" << phone << "' with title '" << title
                  << "' and message '" << message << "'.\n";
    }
    
};

#endif // NOTIFICATIONADAPTER_H
