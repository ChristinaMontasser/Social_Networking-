# Introduction
You and your friends are building a smart social networkingsystem (choose its name). 
You are going to compete with the facebook app. 
Competitionis very hard, and you need to build strong features. One of the most critical partsof this system is user manager, 
and they decided you are the one to develop it. Are you upto the task?

# Problem Statement
You are required to implement the user manager foryour system. 
This is a program that keeps track of all user information (profile, friends, ..). You can also quickly reach a user through search.

**- User linked list**

You are given a file with all users. This file iscalled "all-users.in". Each line of the file will be in the following format (without quotes): "username","name","email" A linked list will be created to save all user inthe system and each user object contains (username-is a unique value-, name, email,friendsBST)

**- Friend list Balanced BST**

  You will get a file with all users relations. This file is called "all-users-relations.in". Each line of the file will be in the following format(without quotes):
  "username1","username2" "username2","username3" "username1","username4"

  You are required to build a friends list using a balancedBST with all the users sorted by username alphabetically. Each friend is an object,carrying the username and reference     to the user object.

  Using Linked List to keep all user friends is inefficientfor this task. We need a better data structure to efficiently search for a usernameand get the name. We will use a         “Balanced Binary Search Tree” because it allows usto search in O(log n) while keeping the friend list dynamic. Each node in thetree will carry a username and a pointer to the     user.For this task you are requiredto implement a "Treap". It is a Randomized Balanced Binary Search Tree that performsvery well in practice. 
