
#ifndef DELIVERYCONTEXT_H
#define DELIVERYCONTEXT_H

#include "DeliverStrategy.h"
#include <memory>

//sends calculation to choosen strategy
//not contains any calculation logic
class DeliveryContext {
    
private:
    
    std::shared_ptr<DeliverStrategy> strategy;

public:
    //dynamicaly sets deliver strategy
    void setStrategy(std::shared_ptr<DeliverStrategy> newStrategy) {
        strategy = newStrategy;
    }

    double calculateCost(double baseCost) const {
        if (strategy) {
            return strategy->calculateCost(baseCost);
        }
        return baseCost;
    }
    
};

#endif // DELIVERYCONTEXT_H