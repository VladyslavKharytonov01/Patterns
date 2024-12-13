#ifndef CLIENTS_H
#define CLIENTS_H

#include <string>
#include <iostream>


class SocialNetworkClient {
    
protected:
    
    std::string login;
    std::string password;

public:
    
    SocialNetworkClient(const std::string& login, const std::string& password)
        : login(login), password(password) {}

    virtual ~SocialNetworkClient() {}

    virtual void publish(const std::string& message) = 0;
};


class FacebookClient : public SocialNetworkClient {
    
public:
    
    FacebookClient(const std::string& login, const std::string& password)
        : SocialNetworkClient(login, password) {}

    void publish(const std::string& message) override {
        std::cout << "[Facebook] Logged as " << login << std::endl;
        std::cout << "Publishing message: " << message << std::endl;
    }
    
};


class LinkedInClient : public SocialNetworkClient {
    
public:
    
    LinkedInClient(const std::string& email, const std::string& password)
        : SocialNetworkClient(email, password) {}

    void publish(const std::string& message) override {
        std::cout << "[LinkedIn] Logged as " << login << std::endl;
        std::cout << "Publishing message: " << message << std::endl;
    }
    
};

#endif // CLIENTS_H
