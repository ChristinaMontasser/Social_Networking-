//
// Created by 20111 on 7/15/2021.
//

#ifndef DS_USER_H
#define DS_USER_H


#include <string>
#include "Treap.h"

using namespace std;
class Treap;

class User {
private:
    string username, name, email;
    Treap *TreapBST;
public:
    User();
    string getUsername();

    string getName();
    void setTreapItem(User *obj);
    Treap* getTreap()
    {
        return TreapBST;
    }
    string getEmail();

    void setUserName(string name);

    void setName(string n);

    void setEmail(string email);
    void printUser();
    ~User();
};


#endif //DS_USER_H
