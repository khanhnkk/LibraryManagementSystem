#include "User.h"

static string xorEncode(const string &s) {
    string r = s;
    for (char &c : r) c ^= 0x66;
    return r;
}

User::User() 
    : id(0), name(""), email(""), password(""), dob(""), role(Role::User) {}

User::User(int id, const string &name, const string &email,
           const string &password, const string &dob, Role r)
    : id(id), name(name), email(email), password(password), dob(dob), role(r) {}

int User::getId() const { return id; }
string User::getName() const { return name; }
string User::getEmail() const { return email; }
Role User::getRole() const { return role; }

void User::setPassword(const string &plain) {
    password = xorEncode(plain);
}

bool User::checkPassword(const string &plain) const {
    return xorEncode(password) == plain;
}

string User::encode(const string &plain) {
    return xorEncode(plain);
}

string User::roleToStr() const {
    switch (role) {
        case Role::User: return "user";
        case Role::Librarian: return "librarian";
        case Role::Admin: return "admin";
    }
    return "user";
}
