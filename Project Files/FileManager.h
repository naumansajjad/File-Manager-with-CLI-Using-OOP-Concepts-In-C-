#include <iostream>
#include "Command.h"
using namespace std;

// This class manages all commands and directs to dedicated functions

class FileManager {
    public: 
        // Here we created object of base class command using pointers

        void execute_command(Command* cmd){
            
            cmd->execute(); // execution of virtual function in dedicated derived classess
cmd=nullptr;
delete cmd;
        }
};