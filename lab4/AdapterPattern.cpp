
#include "Notification.h"
#include "NotificationAdapter.h"
#include <memory>

//calling notification object as send method
void sendNotification(std::shared_ptr<Notification> notification, const std::string& title, const std::string& message) {
    notification->send(title, message);
}

int main() {
    
    auto emailNotification = std::make_shared<EmailNotification>("admin@example.com");
    sendNotification(emailNotification, "Title", "message!");
    
    auto slackNotification = std::make_shared<SlackNotificationAdapter>("userLogin", "api-key-123", "general");
    sendNotification(slackNotification, "Title", "message!");
    
    auto smsNotification = std::make_shared<SMSNotificationAdapter>("+1234567890", "Admin");
    sendNotification(smsNotification, "Title", "message!");

    return 0;
}