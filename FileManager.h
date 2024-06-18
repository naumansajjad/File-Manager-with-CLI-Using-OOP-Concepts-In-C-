#include <iostream>
#include "Command.h"
using namespace std;

class FileManager {
    public: 
        void execute_command(Command* cmd){
            cmd->execute();
        }
};