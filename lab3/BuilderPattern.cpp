#include "PSQLBuilder.h"
#include "MySQLBuilder.h"
#include <iostream>
#include <memory>

void executeQuery(const std::shared_ptr<QueryBuilder>& builder) {
    // chained call for sequence
    builder->select("*")
           .where("count = 1")
           .limit(5);

    std::cout << "Generated SQL: " << builder->getSQL() << std::endl;
    
}

int main() {
    
    std::shared_ptr<QueryBuilder> postgresBuilder = std::make_shared<PSQLBuilder>();
    std::cout << "PostgreSQL Query:" << std::endl;
    executeQuery(postgresBuilder);


    std::shared_ptr<QueryBuilder> mysqlBuilder = std::make_shared<MySQLBuilder>();
    std::cout << "\nMySQL Query:" << std::endl;
    executeQuery(mysqlBuilder);

    return 0;
}