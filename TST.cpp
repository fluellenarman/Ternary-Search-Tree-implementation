//Fluellen  Arman Umali
// CS 130A project 1
// started 10/14/2020


// #include <iostream>     // std::cout
// #include <algorithm>    // std::sort // used only to sort linear vectors.
// #include <vector>       // std::vector

#include "TST.h"
using namespace std;
TST::Node::Node() {  //default constructor
    right = NULL;
    left = NULL;
    middle = NULL;
}

TST::Node::Node(string inputWord)  //paramterized constructor
{
    word = inputWord;
    count = 1;
    left = NULL;
    right = NULL;
    middle = NULL;
}

TST::TST() : root(NULL) { } 

TST::~TST() {
    clear(root);
}

void TST::clear(Node* n) {
    if (n) {
	    clear(n->left);
        clear(n->middle);
	    clear(n->right);
        delete n;
    }
}


void TST::insert(string inputWord) {
    if (!root) {
	root = new Node(inputWord);
    cout << root->word << " inserted, new count = " << root->count << endl;
	return;
    }
    // otherwise use recursive helper
    return insert(inputWord, root);
}

void TST::insert(string inputWord, Node * n) {
    if (n->word == inputWord) { //if input and word are the same word.
        n->count = n->count + 1;
        cout << n->word << " inserted, new count = " << n->count << endl; // counter insert
        return;
    }
    
    if (n->word[0] == inputWord[0]) { // if input and n->word share same first letter
        if (n->middle == NULL) {
            n->middle = new Node(inputWord);
            n->middle->parent = n;
            cout << n->middle->word << " inserted, new count = " << n->middle->count << endl; // M insert
            return;
        }

        if (n->middle != NULL) {
            return insert(inputWord, n->middle);
        }
    }

    if (inputWord > n->word) {  //if word is greater than n
        if (n->right == NULL) { // if right child is empty
            n->right = new Node(inputWord);
            n->right->parent = n;
            cout << n->right->word << " inserted, new count = " << n->right->count << endl; // R insert
            return;
        }
        if (n->right != NULL) { // if right child exists
            return insert(inputWord, n->right);
        }
    }

    if (inputWord < n->word) {  //if word is less than n
        if (n->left == NULL) { // if left child is empty
            n->left = new Node(inputWord);
            n->left->parent = n;
            cout << n->left->word << " inserted, new count = " << n->left->count << endl; // L insert
            return;
        }
        if (n->left != NULL) { // if left child exists
            return insert(inputWord, n->left);
        }
    }
}

void TST::lookup(string inputWord) {
    lookup(inputWord,root);
}

void TST::lookup(string inputWord, Node *n) {
    if (inputWord == n->word) {
        cout << n->word << " found, count = " << n->count << endl;
        return;
    }

    if (inputWord != n->word) { //if inputWord doesnt equal word
        if (inputWord[0] == n->word[0] && n->middle != NULL) {  // if first character is equivalent and n->middle does exist
            return lookup(inputWord, n->middle);
        }
        if (inputWord[0] == n->word[0] && n->middle == NULL) { // if first character is equivalent and there is no next middle node
            return;
        }
    }

    if (inputWord > n->word) { // if input is greater than n word
        if (n->right == NULL) { // if right child does not exist
            return;
        }
        if (n->right != NULL) { // if right child exists
            return lookup(inputWord, n->right);
        }
    }

    if (inputWord < n->word) { // if input is lesser than n word
        if (n->left == NULL) { // if left child does not exist
            return;
        }
        if (n->left != NULL) { // if left child exists
            return lookup(inputWord, n->left);
        }
    }
}

void TST::remove(string inputWord) {
    remove(inputWord,root);
}

void TST::remove(string inputWord, Node *n) {
    if (inputWord != n->word && inputWord[0] == n->word[0]) { // if the first letter is equal to each other, but words are not equal
        if (n->middle == NULL) { // if no middle child
            return;
        }
        if (n->middle != NULL) { // if middle child exists
            return remove(inputWord, n->middle);
        }
    }

    if (inputWord > n->word && inputWord[0] != n->word[0]) { // if the input is greater than n word and the first letters are not equal
        if (n->right == NULL) {
            return;
        }
        if (n->right != NULL) {
            return remove(inputWord, n->right);
        }
    }

    if (inputWord < n->word && inputWord[0] != n->word[0]) { // if the input is less than n word
        if (n->left == NULL) {
            return;
        }
        if (n->left != NULL) {
            return remove(inputWord, n->left);
        }
    }

    if (inputWord == n->word) {
        if (n->count > 1) { //if more than 1 count
            n->count = n->count - 1; 
            cout << n->word << " deleted, new count = " << n->count << endl;
            return;}
        if (n->count == 1) { // if only 1 count
            if (n->middle != NULL) { // if middle child exists, go down, replace bottommost node with top node, then delete bottom node.
                Node *findLastNode = n;
                while (findLastNode->middle != NULL) {findLastNode = findLastNode->middle;}
                cout << n->word << " deleted" << endl;
                n->word = findLastNode->word;
                n->count = findLastNode->count;
                findLastNode->parent->middle = NULL;
                findLastNode->parent = NULL;
                delete findLastNode;
                return;
            }

            if (n->middle == NULL && n->right == NULL && n->left == NULL) { // if node has no children
                if (n->parent->right == n) { n->parent->right == NULL;} 
                if (n->parent->left == n) { n->parent->left == NULL;}
                n->parent = NULL;
                cout << n->word << " deleted" << endl;
            }

            if (n->right != NULL && n->left == NULL && n->middle == NULL) { // if only right child exists
                if (n->parent->right = n) {
                    n->parent->right = n->right;
                    n->right->parent = n->parent;
                }
                if (n->parent->left = n) {
                    n->parent->left = n->right;
                    n->right->parent = n->parent;
                }
            }

            if (n->left != NULL && n->right == NULL && n->middle == NULL) { // if only left child exists
                if (n->parent->right = n) {
                    n->parent->right = n->left;
                    n->left->parent = n->parent;
                }
                if (n->parent->left = n) {
                    n->parent->left = n->left;
                    n->left->parent = n->parent;
                }
            }

            if (n->middle == NULL && n->right != NULL && n->left != NULL) { // if no middle child and both L R child exists
                Node * findSuccessor = n;

                if (findSuccessor->right != NULL) { findSuccessor = findSuccessor->parent;} //possible segfault
                findSuccessor = findSuccessor->right;
                while (findSuccessor->left != NULL) {findSuccessor = findSuccessor->left;}
                cout << n->word << " deleted" << endl;
                n->word = findSuccessor->word;
                n->count = findSuccessor->count;
                if(findSuccessor->middle != NULL) { // if successor node has middle child
                    n->middle = findSuccessor->middle;  // transport middle child to n node
                    findSuccessor->middle->parent = n;
                }
                if (findSuccessor->right != NULL) { // if successor node has children
                    findSuccessor->right->parent = findSuccessor->parent;
                    findSuccessor->parent->left = findSuccessor->right;
                }
                findSuccessor->parent = NULL;
            }

            
        }
    }
}

void TST::rangeSearch(string input1, string input2) {
    rangeSearch(input1, input2, root);
}

void TST::rangeSearch(string input1, string input2, Node * n) {
    if (n == NULL) {return;}
    rangeSearch(input1, input2, n->left);

    if (n->word >= input1 && n->word <= input2) {
        if (n->middle != NULL) { // if middle child exists
            Node * middleTravel = n;
            vector<string> midVector;

            while (middleTravel->middle != NULL) {  // traverse middle
                midVector.push_back(middleTravel->word);
                middleTravel = middleTravel -> middle;
            }

            sort(midVector.begin(), midVector.end());

            for (int i = 0; i < midVector.size(); i++) {
                if (midVector[i] >= input1 && midVector[i] <= input2) {
                    cout << midVector[i] << endl;
                }
            }


        }

        if (n->middle == NULL) { // if no middle child
            cout << n->word << endl;
        }
    }

    rangeSearch(input1, input2, n->right);
}