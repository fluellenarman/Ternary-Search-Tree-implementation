//Fluellen  Arman Umali
// CS 130A project 1
// started 10/14/2020


// #include <iostream>     // std::cout
// #include <algorithm>    // std::sort
// #include <vector>       // std::vector

#include "TST.h"

using namespace std;

int main(int argc, char* argv[])
{
    cout<<"Hello World" << endl;

    string w1 = "cat";
    string w2 = "cut";

    cout << w1[0] << endl;
    cout << w2[0] << endl;

    if (w1[0] == w2[0]) {
        cout << "ccc" << endl;
    }

    TST obj1;

    obj1.insert("cat");
    obj1.insert("cut");
    obj1.insert("ant");
    obj1.insert("dog");
    obj1.insert("cat");
    obj1.insert("cut");
    obj1.insert("dag");
    obj1.insert("woof");
    obj1.insert("Rad");

    obj1.lookup("cat");
    obj1.lookup("cut");
    obj1.lookup("dog");

    obj1.rangeSearch("ant", "dog");

    obj1.remove("cat");
    obj1.remove("cat");
    obj1.remove("cat");

    TST obj2;

    obj2.insert("jagged");
    obj2.insert("free");
    obj2.insert("alpfa");
    obj2.insert("cat");
    obj2.insert("cut");
    obj2.insert("cute");
    obj2.insert("crew");
    obj2.insert("hard");
    obj2.insert("imp");
    obj2.insert("among");
    obj2.insert("us");
    obj2.insert("red");
    obj2.insert("dead");
    obj2.insert("redemption");
    obj2.insert("halo");
    obj2.insert("cortana");
    obj2.insert("rim");
    obj2.insert("world");

    obj2.insert("yiff");
    obj2.insert("zanzibar");
    obj2.insert("water");
    obj2.insert("target");
    obj2.insert("rim");
    obj2.insert("oxy");
    obj2.insert("ozymandias");
    obj2.insert("cut");
    obj2.insert("jagged");
    obj2.insert("halo");
    obj2.insert("alpfa");
    obj2.insert("crew");
    obj2.insert("among");
    obj2.insert("red");

    obj2.lookup("red");
    obj2.lookup("hard");

    obj2.lookup("nonagram");
    obj2.remove("nonagram");

    obj2.remove("hard");

    obj2.rangeSearch("a","z");

    cout << endl << "testing obj3" << endl;

    TST obj3;

    obj3.insert("computer");
    obj3.insert("science");
    obj3.remove("science");
    obj3.lookup("computer");

//////
    cout << endl << endl;
    TST obj4;
    
    
    string input = argv[1];
    

    cout << endl << " command line test " << endl;

    string read1;
    string read2;
    string comma = ", "; // comma and space  

    for (int i = 0; i < input.length(); i++) { 
        if (input[i] != comma[1]) { read1.push_back(input[i]);}
        
        if (read1 == "insert") {
            i = i+2; // skip a space
            read1 = "";
            while (i+1 <= input.length() && input[i] != comma[0]) { // if the next indice exceed input length and the current indice doesnt equal ","
                read1.push_back(input[i]);
                i++;
            }
            // put function here
            obj4.insert(read1);
            // cout << read1 << endl;
            read1 = "";
        }

        if (read1 == "lookup") {
            i = i+2; // skip a space
            read1 = "";
            while (i+1 <= input.length() && input[i] != comma[0]) { // if the next indice exceed input length and the current indice doesnt equal ","
                read1.push_back(input[i]);
                i++;
            }
            // put function here
            obj4.lookup(read1);
            // cout << read1 << endl;
            read1 = "";
        }

        if (read1 == "delete") {
            i = i+2; // skip a space
            read1 = "";
            while (i+1 <= input.length() && input[i] != comma[0]) { // if the next indice exceed input length and the current indice doesnt equal ","
                read1.push_back(input[i]);
                i++;
            }
            // put function here
            obj4.remove(read1);
            // cout << read1 << endl;
            read1 = "";
        }

        if (read1 == "range_search") {
            i = i+2; // skip a space
            read1 = "";
            while (i+1 <= input.length() && input[i] != comma[1]) { // if the next indice exceed input length and the current indice is a space
                read1.push_back(input[i]);
                i++;
            }
            i = i + 4;
            
            while (i+1 <= input.length() && input[i] != comma[0]) { // if the next indice exceed input length and the current indice doesnt equal ",")
                read2.push_back(input[i]);
                i++;
            }

            // put function here
            obj4.rangeSearch(read1, read2);
            
            read1 = "";
            read2 = "";
        }

        //cout << i << endl;
    }
    cout << endl << " command line test end " << endl << endl;
    //cout << read1 << endl;

    TST obj5;
    obj5.insert("foo");
    obj5.insert("bar");
    obj5.insert("foo");
    obj5.lookup("foo");
    obj5.remove("foo");
    obj5.rangeSearch("a","z");

    return 0;
}
