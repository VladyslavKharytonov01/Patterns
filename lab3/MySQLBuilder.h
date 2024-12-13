#ifndef MYSQLBUILDER_H
#define MYSQLBUILDER_H

#include "QueryBuilder.h"

class MySQLBuilder : public QueryBuilder {
    
private:
    
    std::stringstream query;

public:
    
    MySQLBuilder() {
        query.str("");
    }

    QueryBuilder& select(const std::string& columns) override {
        query << "SELECT " << columns << " ";
        return *this;
    }

    QueryBuilder& where(const std::string& condition) override {
        query << "WHERE " << condition << " ";
        return *this;
    }

    QueryBuilder& limit(int count) override {
        query << "LIMIT " << count << " ";
        return *this;
    }

    std::string getSQL() const override {
        return query.str();
    }
    
};

#endif // MYSQLBUILDER_H
