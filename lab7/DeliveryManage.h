
#ifndef DELIVERYMANAGE_H
#define DELIVERYMANAGE_H

#include "DeliverStrategy.h"
//delivery options

class PickupDelivery : public DeliverStrategy {
    
public:
    
    double calculateCost(double baseCost) const override {
        return baseCost;
    }
    
};


class ExternalServiceDelivery : public DeliverStrategy {
    
public:
    
    double calculateCost(double baseCost) const override {
        return baseCost + 50.0;
    }
    
};


class OwnServiceDelivery : public DeliverStrategy {
    
public:
    
    double calculateCost(double baseCost) const override {
        return baseCost + 30.0;
    }
    
};

#endif // DELIVERYMANAGE_H
