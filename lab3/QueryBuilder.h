#ifndef QUERYBUILDER_H
#define QUERYBUILDER_H

#include <string>
#include <sstream>

// general interface
class QueryBuilder {
    
public:
    
    virtual ~QueryBuilder() {}

    virtual QueryBuilder& select(const std::string& columns) = 0;
    virtual QueryBuilder& where(const std::string& condition) = 0;
    virtual QueryBuilder& limit(int count) = 0;
    virtual std::string getSQL() const = 0;
    
};

#endif // QUERYBUILDER_H