#include <iostream>
#include "FileSystem.h"


int main(){
    obj_disp.display();
    string current_directory = obj_disp.get_directory();

    FileManager obj_FM;
    string user_input;
    while(true){
        cout << current_directory << " >> ";
        getline(cin, user_input);

        istringstream iss(user_input);
        string command;
        iss >> command;

        if (command == "exit"){
            break;
        }else if (command == "help"){
            cout << "Available Commands:\n";
            cout << "customize - customize a command keyword\n";
            cout << "mkdir [directory_name] - Create directory\n";
            cout << obj_disp.get_read_cmd()<<"  [file_name] - read text file\n";
            cout << "exit - Exit CLI\n";
        }else if(command == obj_disp.get_read_cmd()){
            string fileName;
            getline(iss >> ws, fileName);
            obj_FM.execute_command(new ReadFileCommand(fileName));
        }else if(command == "customize"){
            Customize obj_cstmize;
            obj_cstmize.customize();
        }else if(command == "mkdir"){
            string directoryName;
            getline(iss >> ws, directoryName);
            obj_FM.execute_command(new MakeDirectoryCommand(directoryName));
        }else{
            cerr << "Command not recognized! Type 'help' for available commands" << endl;
        }
    }

    return 0;
}