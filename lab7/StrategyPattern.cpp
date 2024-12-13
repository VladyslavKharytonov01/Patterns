
#include "DeliveryContext.h"
#include "DeliveryManage.h"

#include <iostream>
#include <memory>

int main() {
    double baseCost = 100.0; // Base cost
    DeliveryContext context;
    
    context.setStrategy(std::make_shared<PickupDelivery>());
    std::cout << "Cost with pickup delivery: " << context.calculateCost(baseCost) << "\n";
    
    context.setStrategy(std::make_shared<ExternalServiceDelivery>());
    std::cout << "Cost with external service delivery: " << context.calculateCost(baseCost) << "\n";
    
    context.setStrategy(std::make_shared<OwnServiceDelivery>());
    std::cout << "Cost with own service delivery: " << context.calculateCost(baseCost) << "\n";

    return 0;
}
