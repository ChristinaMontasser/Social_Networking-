#include "User.h"
#include <iostream>
#include "Treap.h"

User::User()
{
    TreapBST = new Treap;
}

string User::getUsername()
{
    return username;
}

string User::getName()
{
    return name;
}

string User::getEmail()
{
    return email;
}

void User::setUserName(string name)
{
    username = name;
}

void User::setName(string n)
{
    name = n;
}

void User::setEmail(string email)
{
    this->email = email;
}

void User::setTreapItem(User *obj)
{
    TreapBST->insertion(obj);
}

void User::printUser()
{
    cout<<username<<name<<email<<endl;
}

User::~User()
{
    delete TreapBST;
}
