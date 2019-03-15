
#ifndef _READER_H_
#define _READER_H_

#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

class Reader {
    private:
        string fileName;
        ifstream file;
        stack<char> stac;
        vector<int> numOfCharacters;
        //for numOfCharacters:
        //0 = # of (
        //1 = # of )
        //2 = # of {
        //3 = # of }
        //4 = # of [
        //5 = # of ]
        //6 = # of <
        //7 = # of >

    public:
        //creates reader class type with string input
        //input: string file name
        Reader(string fN) {
            fileName = fN;
            file = ifstream(fileName);

            if(file.fail()) {
                cout << "file not found" << endl;
            }

            for(int i = 0; i<8; i++) {
                numOfCharacters.push_back(0);
            }
        }

        //returns the file name
        //output: string filename 
        string getFileName() {
            return fileName;
        }

        //sets the file name
        //input: string file name
        void setFileName(string fn) {
            fileName = fn;
        }

        //sets the file name
        //input: string file name
        void setFile(string fn) {
            file = ifstream(fn);
             if(file.fail()) {
                cout << "file not found" << endl;
            }
        }

        //reads the file into stack, then closes file
        void setStack() {
            //loop through file and add parenthesis, brackets(curly and standard), and greater than/leass than
            char c;
            while(file >> c) {
               addToVector(c);
            }
           
            file.close();
        }

        //throws errors when there is an uneven amount of syntax, or when there is stuff left in the stack
        void checkStack() {
            for(int i = 0; i<5; i+=2) {
                if(numOfCharacters.at(i) != numOfCharacters.at(i+1)) {
                    throw logic_error("unbalanced syntax");
                }
            }

            if(stac.size() > 0) {
                throw logic_error("unbalanced syntax");
            }
            
        }

        //pushes values onto stack that are open
        //pops values off of stack when open matches close
        //increments numOfCharacters whenever a char is found
        void addToVector(char c) {
            if(c == '(') {
                stac.push(c);
                numOfCharacters.at(0) = numOfCharacters.at(0) +=1;
                
            } else if(c==')') {
                if(stac.top() == '(') {
                    stac.pop();
                    numOfCharacters.at(0) = numOfCharacters.at(0) -=1;
                } else {
                    stac.push(c);
                    numOfCharacters.at(1) = numOfCharacters.at(1) +=1;
                    
                }
            }  else if(c=='{') {
                stac.push(c);
                numOfCharacters.at(2) = numOfCharacters.at(2) +=1;
                
            }  else if(c=='}') {
                if(stac.top() == '{') {
                    stac.pop();
                    numOfCharacters.at(2) = numOfCharacters.at(2) -=1;
                } else {
                    stac.push(c);
                    numOfCharacters.at(3) = numOfCharacters.at(3) +=1;
                    
                }
            }  else if(c=='[') {
                stac.push(c);
                numOfCharacters.at(4) = numOfCharacters.at(4) +=1;
                
            }  else if(c==']') {
                if(stac.top() == '[') {
                    stac.pop();
                    numOfCharacters.at(4) = numOfCharacters.at(4) -=1;
                } else {
                    stac.push(c);
                    numOfCharacters.at(5) = numOfCharacters.at(5) +=1;
                    
                }

            //code for checking <> values
            /*}  else if(c=='<') {
                stac.push(c);
                numOfCharacters.at(6) = numOfCharacters.at(6) +=1;
                
            }  else if(c=='>') {
                if(stac.top() == '<') {
                    stac.pop();
                    numOfCharacters.at(6) = numOfCharacters.at(6) -=1;
                } else {
                    stac.push(c);
                    numOfCharacters.at(7) = numOfCharacters.at(7) +=1;
                    
                }
                */
            } 
            
        }

        //prints out the stack and clears it.
        void printStac() {
            while(stac.empty() == false) {
                cout << stac.top();
                stac.pop();
            }
            cout << endl;
        }

};

#endif