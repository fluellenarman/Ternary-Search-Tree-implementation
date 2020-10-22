//Fluellen  Arman Umali
// CS 130A project 1
// started 10/14/2020

#ifndef TST_H
#define TST_H

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <cstring>      // strcmp

using namespace std;

class TST
{
    private:
    
        struct Node 
        {
            Node();
            Node(string word);
            int count;
            string word;
            Node *left;
            Node *right;
            Node *middle;
            Node *parent;
            // Node() : middle(NULL), left(NULL), right(NULL), parent(NULL) { }
        };
        Node *root;
        
        void lookup(string word, Node *n);
        void insert(string word, Node *n); // helper function if tree not empty
        void remove(string word, Node *n);
        void rangeSearch(string word1, string word2, Node *n);
    public:
        TST();  //constructor
        TST(string inputWord);  //parameterized constructor
        
        ~TST(); //destructor
        
        void clear(Node *n);

        void lookup(string word);
        void insert(string word); // for if empty tree
        void remove(string word);
        void rangeSearch(string word1, string word2);
};

#endif