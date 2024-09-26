#include <iostream>
#include <sqlite_orm/sqlite_orm.h>
using namespace sqlite_orm;

struct User {
    int id;
    std::string name;
};

// Create storage
auto init_storage() {
    return make_storage("example.db",
                        make_table("users",
                                   make_column("id", &User::id, primary_key().autoincrement()),
                                   make_column("name", &User::name)
                        )
    );
}

int main() {
    auto storage = init_storage();
    storage.sync_schema();  // Create the table if it doesn't exist

    // Insert a user
    User user{0, "Alice"};
    storage.insert(user);

    std::cout << "Inserted user with name: " << user.name << std::endl;
    return 0;
}