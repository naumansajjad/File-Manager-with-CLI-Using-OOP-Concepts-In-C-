#include <iostream>
#include <string>
#include "FileManager.h"
#include "Customize.h"
using namespace std;

int main(){

    system("cls"); // clear screen function for windows platform

    obj_disp.display(); // function call for displaying welcome msg

    string current_directory = fs::current_path().string(); //function to get and store current path

    FileManager obj_FM; // initialization of object of FileManager Class

    string user_input;

// while loop to stay in program until user exits the program

    while(true){
        cout <<"\n"<< current_directory << " >> ";
        getline(cin, user_input);

        istringstream iss(user_input); // iss : used to separate single words from a string
        string command;
        iss >> command;

        if (command == obj_disp.get_exit_cmd()){
            break;
        }else if (command == "help"){ // help command lists all available commands

            cout << "Available Commands:\n\n";
            cout << obj_disp.get_customize_cmd()<<" - customize a command keyword\n";
            cout << obj_disp.get_mkdir_cmd()<<" [directory_name] - Create directory\n";
            cout << obj_disp.get_read_cmd()<<" [file_name.ext] - read file\n";
            cout << obj_disp.get_write_cmd()<<" [file_name.ext] - write to a file\n";
            cout << obj_disp.get_ls_cmd()<<" - List Directory\n";
            cout << obj_disp.get_ver_cmd()<<" - Version Info\n";
            cout << obj_disp.get_parentdir_cmd()<<" - Move to Parent Directory\n";
            cout << obj_disp.get_cd_cmd()<<" [directory_name] - Change directory\n";
            cout << obj_disp.get_ren_cmd()<<" [file_name] [new_file_name] - Rename File\n";
            cout << obj_disp.get_copy_cmd()<<" [file_name] [destination] - Copy File\n";
            cout << obj_disp.get_find_cmd()<<" [file_Name] - Find File In current Directory\n";
            cout << obj_disp.get_delete_cmd()<<" [file_name] - Delete file\n";
            cout << obj_disp.get_exit_cmd()<<" - Exit CLI\n";

        }else if(command == obj_disp.get_copy_cmd()){

            string source, destination;
            iss >> source >> destination;

            // function calling of filemanager class
                                //(                  Command* cmd          )

            obj_FM.execute_command(new CopyFileCommand(source, destination));

        }else if(command == obj_disp.get_write_cmd()){

            string fileName,data;
            getline(iss >> ws, fileName);
            cout << "Content of file: ";
            getline(cin, data);
            obj_FM.execute_command(new WriteToFileCommand(fileName,data));

        }else if(command == obj_disp.get_delete_cmd()){

            string fileName;
            getline(iss >> ws, fileName);
            obj_FM.execute_command(new DeleteFileCommand(fileName));

        }else if(command == obj_disp.get_find_cmd()){

            string fileName;
            getline(iss >> ws, fileName);
            obj_FM.execute_command(new FindFileCommand(fileName));

        }else if(command == obj_disp.get_ren_cmd()){

            string filename, new_file_name;
            iss >> filename >> new_file_name;
            obj_FM.execute_command(new RenameFileCommand(filename,new_file_name));

        }else if(command == obj_disp.get_cd_cmd()){

            string directoryName;
            getline(iss >> ws, directoryName);
            obj_FM.execute_command(new ChangeDirectoryCommand(directoryName));
            current_directory = fs::current_path().string();

        }else if(command == obj_disp.get_parentdir_cmd()){

            obj_FM.execute_command(new MoveToParentDirectoryCommand(current_directory));
            current_directory = fs::current_path().string();

        }else if(command == obj_disp.get_ver_cmd()){

            cout<<"\n\t (c)SN_TECHNOLOGIES      [ Version 4.1.3 ]\n";

        }else if(command == obj_disp.get_ls_cmd()){

            cout << "\n\tDirectory: " << current_directory << "\n\n";
            obj_FM.execute_command(new ListDirectoryCommand(current_directory));

        }else if(command == obj_disp.get_read_cmd()){

            string fileName;
            getline(iss >> ws, fileName);
            obj_FM.execute_command(new ReadFileCommand(fileName));

        }else if(command == obj_disp.get_customize_cmd()){

            Customize obj_cstmize;
            obj_cstmize.customize();

        }else if(command == obj_disp.get_mkdir_cmd()){

            string directoryName;
            getline(iss >> ws, directoryName);
            obj_FM.execute_command(new MakeDirectoryCommand(directoryName));

        }else{

            cerr << "Command not recognized! Type 'help' for available commands" << endl;

        }
    }

    return 0;
}