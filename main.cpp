#include <iostream>
#include <sqlite_orm/sqlite_orm.h>


struct User {
    int id;
    std::string name;
};

// Create storage
auto init_storage() {
    using namespace sqlite_orm;

    return make_storage("example.db",
                        make_table("users",
                                   make_column("id", &User::id, primary_key().autoincrement()),
                                   make_column("name", &User::name)
                        )
    );
}

void createUser(const std::string &name) {
    // Insert a user
    auto storage = init_storage();
    storage.sync_schema();
    User user{0, name};
    storage.insert(user);
    std::cout << "Inserted user with name: " << user.name << std::endl;
}

void listAllUsers(decltype(init_storage()) & storage) {

    auto allUsers = storage.get_all<User>();
    std::cout << "allUsers (" << allUsers.size() << "):" << std::endl;
    for (auto &user: allUsers) {
        std::cout << storage.dump(user)
                  << std::endl; //  dump returns std::string with json-like style object info. For example: { id : '1', first_name : 'Jonh', last_name : 'Doe', birth_date : '664416000', image_url : 'https://cdn1.iconfinder.com/data/icons
    }

}


int main() {
    using namespace std;
    // Create the table if it doesn't exist

    auto storage = init_storage();
   // createUser("Marius");

    listAllUsers(storage);


//    auto allUsers = storage.get_all<User>();
//    cout << "allUsers (" << allUsers.size() << "):" << endl;
//    for(auto &user : allUsers) {
//        cout << storage.dump(user) << endl; //  dump returns std::string with json-like style object info. For example: { id : '1', first_name : 'Jonh', last_name : 'Doe', birth_date : '664416000', image_url : 'https://cdn1.iconfinder.com/data/icons/man-icon-set/100/man_icon-21-512.png', type_id : '3' }
//    }



    return 0;
}