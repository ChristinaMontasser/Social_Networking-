#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "LinkedList.h"
#include "Treap.h"
#include "User.h"
using namespace std;

int main()
{
    bool flag = false;
    //add users to linked userLinkedList
    LinkedList userLinkedList;
    ifstream users("all-users.in");
    string username;
    string name;
    string email;
    string line;
    while(getline(users, line))
    {
        User *user = new User;
        stringstream ss(line);
        getline(ss,username, ',');
        getline(ss,name,',');
        name.erase(0,1);
        getline(ss,email,',');
        email.erase(0,1);
        user->setUserName(username);
        user->setName(name);
        user->setEmail(email);
        userLinkedList.InsertNodeAtTail(user);
    }
    users.close();

    ifstream userRelations("all-users-relations.in");
    string username1;
    string username2;
    while(getline(userRelations, line))
    {
        User *temp = new User;
        User *temp2 = new User;
        stringstream ss(line);
        getline(ss, username1, ',');
        getline(ss, username2, ',');
        username2.erase(0,1);
        temp = userLinkedList.searchForItemInLinkedList(username1);
        temp2 = userLinkedList.searchForItemInLinkedList(username2);
        temp->setTreapItem(temp2);
        temp2->setTreapItem(temp);
    }
    userRelations.close();

    string choice;
    cout << "===Welcome in Debug Bugs==== "<<endl;

    while(true) {
        cout <<"===========CHOOSE NUMBER========="<<endl;
        cout<<"1- LOGIN.: Type: login"<<endl<<"2- EXIT.: Type: exit"<<endl;
        cin >> choice;
        for(int indexTemp=0;indexTemp<choice.size();indexTemp++) choice[indexTemp] = tolower(choice[indexTemp]);
        if (choice=="login"){
            cout << "ENTER YOUR USERNAME\n";
            string name;
            cin >> name;
            User *user = new User;
            user =userLinkedList.searchForItemInLinkedList(name);
            if(user != nullptr){
                cout<<"Successfully Login\n"<<endl;
                while(true){
                    cout<<"1- List All Friends\n";
                    cout<<"2- Search by username\n";
                    cout<<"3- Add friend\n";
                    cout<<"4- Remove friend\n";
                    cout<<"5- People you may know\n";
                    cout<<"6- Logout\n";
                    cin>>choice;
                    if(choice == "1"){
                        user->getTreap()->inOrder();

                    }else if(choice == "2"){
                        string searchedName;
                        TreapNode* name;
                        cout<<"Please Enter Username"<<endl;
                        cin>>searchedName;
                        name = user->getTreap()->searchForNode(searchedName);
                        if(name != 0){
                            cout<<name->ptr->getUsername()<<", ";
                            cout<<name->ptr->getName()<<", ";
                            cout<<name->ptr->getEmail()<<endl;
                        }
                        else
                        {
                            cout<<"not found"<<endl;
                        }
                    } else if(choice == "3"){
                        User * anotherUser = new User;
                        string name;
                        cout<<"Please Enter Username:\n";
                        cin>>name;
                        anotherUser = userLinkedList.searchForItemInLinkedList(name);
                        if(anotherUser!= nullptr){
                            TreapNode* friendName;
                            friendName = user->getTreap()->searchForNode(anotherUser->getUsername());
                            if(friendName == nullptr){
                                user->setTreapItem(anotherUser);
                                anotherUser->setTreapItem(user);
                                cout<<"Successfully added friend!\n";
                            } else {
                                cout<<"You already friends!\n";
                            }
                        }else {
                            cout<<"Invalid Username\n";
                        }
                    } else if(choice == "4"){
                        User * anotherUser = new User;
                        string name;
                        cout<<"Please Enter Username:\n";
                        cin>>name;
                        anotherUser = userLinkedList.searchForItemInLinkedList(name);
                        if(anotherUser!= nullptr){
                            bool a = user->getTreap()->deleteNode(anotherUser->getUsername());
                            anotherUser->getTreap()->deleteNode(user->getUsername());
                            if(a){
                                cout<<"Done, Deleted"<<endl;
                            }
                            else{
                                cout<<"You are not friends"<<endl;
                            }
                        }else {
                            cout<<"Invalid Username\n";
                        }
                    } else if(choice == "5"){
                        int counterFriends = 0;
                        string *arr;
                        arr = new string [1000];

                        user->getTreap()->storeBst(arr);
                        int arrSize=0;
                        while(true){
                            if(arr[arrSize]!=""){
                                arrSize++;
                            } else
                                break;
                        }
                        Node * temp = userLinkedList.getHead();
                        while (temp!= nullptr){
                            if(temp->data->getUsername()==user->getUsername()){
                                temp = temp->addressOfNextNode;
                                continue;
                            }
                            else{
                                for(int i=0;i<arrSize;i++){
                                    if(temp->data->getUsername() == arr[i]){
                                        flag = true;
                                        break;
                                    }
                                }
                                if(!flag &&  counterFriends < 5){
                                    cout<<temp->data->getUsername()<<", ";
                                    cout<<temp->data->getName()<<endl;
                                    counterFriends++;

                                }
                                temp = temp->addressOfNextNode;
                                flag = false;
                            }
                        }
                    }
                    else if(choice == "6"){
                        break;
                    }

                }
            }else{
                cout<<"Please enter valid username\n";
            }

        } else if(choice == "exit"){
            break;
        }else {
            cout<<"Please enter right choice!\n";
        }

    }
}
