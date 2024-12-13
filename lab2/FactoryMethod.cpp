#include "Publisher.h"

int main() {
    // Facebook factory
    FacebookPublisher facebookPublisher;
    auto facebookClient = facebookPublisher.createClient("fb_user123", "fb_password");
    facebookClient->publish("Facebook publish!");

    // LinkedIn factory
    LinkedInPublisher linkedInPublisher;
    auto linkedInClient = linkedInPublisher.createClient("linkedin_user@example.com", "linkedin_password");
    linkedInClient->publish("Linkedin publish!");

    return 0;
}
