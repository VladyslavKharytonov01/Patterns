#ifndef PUBLISHERS_H
#define PUBLISHERS_H

#include "Client.h"
#include <memory>

// Basic factory class
class SocialNetworkPublisher {
public:
    virtual ~SocialNetworkPublisher() {}

    virtual std::shared_ptr<SocialNetworkClient> createClient(
        const std::string& login, const std::string& password) = 0;
};

// Factory Facebook (createClient for facebook)
class FacebookPublisher : public SocialNetworkPublisher {
public:
    std::shared_ptr<SocialNetworkClient> createClient(
        const std::string& login, const std::string& password) override {
        return std::make_shared<FacebookClient>(login, password);
    }
};

// Factory Linkedin (createClient for linkedin)
class LinkedInPublisher : public SocialNetworkPublisher {
public:
    std::shared_ptr<SocialNetworkClient> createClient(
        const std::string& login, const std::string& password) override {
        return std::make_shared<LinkedInClient>(login, password);
    }
};

// Easily adding another social networks with creating subclass for example TwitterPublisher with corresponding logic

#endif // PUBLISHERS_H
