#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "User.h"

class Librarian : public User {
public:
    Librarian(int id, const string &name, const string &email,
              const string &password, const string &dob)
        : User(id, name, email, password, dob, Role::Librarian) {}

    string roleToStr() const override { return "librarian"; }
};

#endif
