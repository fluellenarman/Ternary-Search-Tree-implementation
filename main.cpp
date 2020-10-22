//Fluellen  Arman Umali
// CS 130A project 1
// started 10/14/2020


// #include <iostream>     //  std::cout
// #include <algorithm>    // std::sort
// #include <vector>       // std::vector

#include "TST.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc == 1) {return 0;} // if no arguments

    TST obj4;
    
    string input = argv[1];

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

}
