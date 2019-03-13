
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

        string GetFileName() {
            return fileName;
        }

        void setFileName(string fn) {
            fileName = fn;
        }

        /*
        ifstream getFile() {
            return file;
        }
        */

        void setFile(string fn) {
            file = ifstream(fn);
             if(file.fail()) {
                cout << "file not found" << endl;
            }
        }

        void setStack() {
            //loop through file and add parenthesis, brackets(curly and standard), and greater than/leass than
            char c;
            while(file >> c) {
               addToVector(c);
            }
           
            file.close();
        }

        void checkStack() {
            for(int i = 0; i<5; i+=2) {
                cout << "got here" << endl;
                if(numOfCharacters.at(i) != numOfCharacters.at(i+1)) {
                    throw logic_error("unbalanced syntax");
                }
            }

            //check the stack for stupid stuff
            //[] should be close to each other
            //should not be one bracket(curly or standard) within parthensis
            //as long as > is contained by parathesis its fine
            for(int i = 0; i<stac.size(); i++) {
                //if()

            }
            



            
        }

        void addToVector(char c) {
            if(c == '(') {
                stac.push(c);
                numOfCharacters.at(0) = numOfCharacters.at(0) +=1;
                cout << c;
            } else if(c==')') {
                if(stac.top() == '(') {
                    stac.pop();
                    numOfCharacters.at(0) = numOfCharacters.at(0) -=1;
                } else {
                    stac.push(c);
                    numOfCharacters.at(1) = numOfCharacters.at(1) +=1;
                    cout << c;
                }
            }  else if(c=='{') {
                stac.push(c);
                numOfCharacters.at(2) = numOfCharacters.at(2) +=1;
                cout << c;
            }  else if(c=='}') {
                if(stac.top() == '{') {
                    stac.pop();
                    numOfCharacters.at(2) = numOfCharacters.at(2) -=1;
                } else {
                    stac.push(c);
                    numOfCharacters.at(3) = numOfCharacters.at(3) +=1;
                    cout << c;
                }
            }  else if(c=='[') {
                stac.push(c);
                numOfCharacters.at(4) = numOfCharacters.at(4) +=1;
                cout << c;
            }  else if(c==']') {
                if(stac.top() == '[') {
                    stac.pop();
                    numOfCharacters.at(4) = numOfCharacters.at(4) -=1;
                } else {
                    stac.push(c);
                    numOfCharacters.at(5) = numOfCharacters.at(5) +=1;
                    cout << c;
                }
            }  else if(c=='<') {
                stac.push(c);
                numOfCharacters.at(6) = numOfCharacters.at(6) +=1;
                cout << c;
            }  else if(c=='>') {
                if(stac.top() == '<') {
                    stac.pop();
                    numOfCharacters.at(6) = numOfCharacters.at(6) -=1;
                } else {
                    stac.push(c);
                    numOfCharacters.at(7) = numOfCharacters.at(7) +=1;
                    cout << c;
                }
                
                //cout << "me ur looking for" << endl;
            } 
        }

        void printStac() {
            while(stac.empty() == false) {
                cout << stac.top() << endl;
                stac.pop();
            }
        }


};

#endif