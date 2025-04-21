#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
int main()
{
    map<string, string> presidentStates;
    map<string, string>::iterator it;
    //create a string pair with your name and state.
     string myName = "Brent Fader";
     string myState = "Michigan";

    string name, state, line;
    ifstream file("presidentsWstates-1.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, name, '\t');
            getline(ss, state, '\t');
            //Fill your presidentStates with the names and states as you read from
            presidentStates.insert(pair<string, string>(name, state));
            }
        file.close();
    }
    //Use an appropriate map iterator to print the values.
    for ( it = presidentStates.begin(); it != presidentStates.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    cout<<"***************************"<<endl;

    //Print the state for Thomas Jefferson
    string searchName = "Thomas Jefferson";
    auto found = presidentStates.find(searchName);
    if (found != presidentStates.end()) {
        cout << searchName << "'s State: " << found->second << endl;
    }

    //Insert your name and state by using the pair you have created at the
    presidentStates.insert(pair(myName,myState));

    //Print your values to see how your name and state are inserted.
    searchName = myName;
    auto found2 = presidentStates.find(searchName);
    if (found2 != presidentStates.end()) {
        cout << searchName << "'s State: " << found2->second << endl;
    }

    //Use pair<map<string,string>::iterator,bool> ret; when you try to insert pair again
    pair<map<string, string>::iterator, bool> ret;
    ret = presidentStates.insert(pair(myName, myState));


    //Using the returning the value, prompt a message if the key exists in you
    if (ret.second == false) {
        cout << "Key already exists " << endl;}
    else {
        cout << myName << "'s State: " << myState << endl;
    }

    }
