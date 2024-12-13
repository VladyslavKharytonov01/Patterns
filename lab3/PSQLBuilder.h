#ifndef PSQLBUILDER_H
#define PSQLBUILDER_H

#include "QueryBuilder.h"

class PSQLBuilder : public QueryBuilder {
    
private:
    
    std::stringstream query;

public:
    
    PSQLBuilder() {
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

#endif // PSQLBUILDER_H