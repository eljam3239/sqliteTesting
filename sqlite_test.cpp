#include <iostream>
#include <sqlite3.h>

int main() {
    sqlite3* db;
    int exit = 0;

    // Create/Open the database
    exit = sqlite3_open("test.db", &db);

    if (exit) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return -1;
    } else {
        std::cout << "Database opened successfully!" << std::endl;
    }

    // SQL statement to create a table
    std::string sql = "CREATE TABLE IF NOT EXISTS PERSON("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "NAME           TEXT    NOT NULL, "
                      "AGE            INT     NOT NULL);";

    // Execute SQL statement
    char* errMsg;
    exit = sqlite3_exec(db, sql.c_str(), nullptr, 0, &errMsg);

    if (exit != SQLITE_OK) {
        std::cerr << "Error creating table: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Table created successfully!" << std::endl;
    }

    // Close the database connection
    sqlite3_close(db);
    std::cout << "Database connection closed." << std::endl;

    return 0;
}
