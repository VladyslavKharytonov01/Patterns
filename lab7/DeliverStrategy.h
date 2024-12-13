#ifndef DELIVERSTRATEGY_H
#define DELIVERSTRATEGY_H

//interface
class DeliverStrategy {
    
public:
    
    virtual ~DeliverStrategy() = default;
    virtual double calculateCost(double baseCost) const = 0;
    
};

#endif // DELIVERSTRATEGY_H