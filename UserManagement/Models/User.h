#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

enum class Role { User, Librarian, Admin };

class User {
protected:
    int id;
    string name;
    string email;
    string password; 
    string dob;
    Role role;

public:
    User();
    User(int id, const string &name, const string &email,
         const string &password, const string &dob, Role r);

    virtual ~User() {}

    int getId() const;
    string getName() const;
    string getEmail() const;
    Role getRole() const;

    void setPassword(const string &plain);
    bool checkPassword(const string &plain) const;

    virtual string roleToStr() const;

    static string encode(const string &plain);
};

#endif
