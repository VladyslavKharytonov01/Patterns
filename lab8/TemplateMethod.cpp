#include <iostream>
#include <string>
#include <sstream> 

// template that defines algoritm of updating entity
class EntityUpdater {
    
public:
    
    void updateEntity() {
        fetchEntity();
        validateEntity();
        prepareSaveRequest();
        auto response = sendSaveRequest();
        handleResponse(response);
    }

protected:
    
    virtual void fetchEntity() {
        std::cout << "Fetching entity data..." << std::endl;
    }

    virtual void validateEntity() {
        std::cout << "Validating entity..." << std::endl;
    }

    virtual void prepareSaveRequest() {
        std::cout << "Preparing save request..." << std::endl;
    }

    virtual std::string sendSaveRequest() {
        std::cout << "Sending save request..." << std::endl;
        return "200 OK";
    }

    virtual void handleResponse(const std::string& response) {
        std::cout << "Handling response: " << response << std::endl;
    }
};

// product validation logic
class ProductUpdater : public EntityUpdater {
    
protected:
    
    void validateEntity() override {
        std::cout << "Validating Product..." << std::endl;
        bool valid = true; // Validation simulate
        if (!valid) {
            notifyAdmin("Product validation failed.");
        }
    }
//failing validation alerts admin
    void notifyAdmin(const std::string& message) {
        std::cout << "Sending notification to admin: " << message << std::endl;
    }
};

// User validation logic
//not allowing to modify email
class UserUpdater : public EntityUpdater {
    
private:
    
    std::string currentEmail = "user@example.com"; // Simulate current state
    std::string newEmail = "user@example.com"; // Simulate update

protected:
    
    void validateEntity() override {
        std::cout << "Validating User..." << std::endl;
        if (newEmail != currentEmail) {
            std::cout << "Error: Email modification is not allowed!" << std::endl;
            return;
        }
        std::cout << "User validation passed." << std::endl;
    }
};

// Order logic
class OrderUpdater : public EntityUpdater {
    
protected:
    
    std::string sendSaveRequest() override {
        std::cout << "Sending save request for Order..." << std::endl;//send request
        return "{\"status\": \"success\", \"code\": 200, \"order\": {\"id\": 1, \"product\": \"Pizza\", \"quantity\": 2}}";//get json-like result
    }

    //output response
    //calls method for parse response data
    void handleResponse(const std::string& response) override {
        std::cout << "Handling response: " << response << std::endl;
        parseJSONResponse(response);
    }
//parsing imitation
    void parseJSONResponse(const std::string& response) {
        std::cout << "Parsing JSON-like response manually..." << std::endl;
        std::istringstream stream(response); // parse string as data flow
        std::string line;
        //line-by-line reading strings
        while (std::getline(stream, line)) { 
            std::cout << line << std::endl;
        }
    }
};

int main() {
    std::cout << "--- Updating Product ---\n";
    ProductUpdater productUpdater;
    productUpdater.updateEntity();

    std::cout << "\n--- Updating User ---\n";
    UserUpdater userUpdater;
    userUpdater.updateEntity();

    std::cout << "\n--- Updating Order ---\n";
    OrderUpdater orderUpdater;
    orderUpdater.updateEntity();

    return 0;
}
