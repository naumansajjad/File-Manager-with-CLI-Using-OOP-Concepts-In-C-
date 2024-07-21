#include <iostream>
#include <string>
namespace fs = filesystem;
using namespace std;

// Class Display to give initial display and the storing/retreiving of command keywords

class Display {
    private:

        // all commands keywords stored here

        string read_command = "type";
        string make_directory_command = "mkdir";
        string write_file_command = "echo";
        string list_directory_command = "ls";
        string version_info_command="ver";
        string moveto_parent_directory_command = "cd..";
        string change_directory_command = "cd";
        string rename_file_command = "ren";
        string copy_file_command = "copy";
        string find_file_command = "find";
        string delete_file_command = "del";
        string exit_command = "exit";
        string customize_command = "customize";

    public:    

        // function to display welcome msg at startup

        void display(){
            cout << "\tWelcome to CLI File Manager\t" << endl;
            cout << "Type 'help' to see available commands" << endl;
            cout << endl;
        }

        // Setter functions to set new keywords during customization of keywords

        void set_read_cmd(const string &key){
            read_command = key;
            cout << "command customization successfull!" << endl;
            cin.ignore();
        }
        void set_customize_cmd(const string &key){
            customize_command = key;
            cout << "command customization successfull!" << endl;
            cin.ignore();
        }
        void set_makedirectory_cmd(const string &key){
            make_directory_command = key;
            cout << "command customization successfull!" << endl;
            cin.ignore();
        }
        void set_write_cmd(const string &key){
            write_file_command = key;
            cout << "command customization successfull!" << endl;
            cin.ignore();
        }
        void set_listdirectory_cmd(const string &key){
            list_directory_command = key;
            cout << "command customization successfull!" << endl;
            cin.ignore();
        }
        void set_version_cmd(const string &key){
            version_info_command = key;
            cout << "command customization successfull!" << endl;
            cin.ignore();
        }
        void set_moveto_parentdir_cmd(const string &key){
            moveto_parent_directory_command = key;
            cout << "command customization successfull!" << endl;
            cin.ignore();
        }
        void set_changedir_cmd(const string &key){
            change_directory_command = key;
            cout << "command customization successfull!" << endl;
            cin.ignore();
        }
        void set_renamefile_cmd(const string &key){
            rename_file_command = key;
            cout << "command customization successfull!" << endl;
            cin.ignore();
        }
        void set_copy_cmd(const string &key){
            copy_file_command = key;
            cout << "command customization successfull!" << endl;
            cin.ignore();
        }
        void set_find_cmd(const string &key){
            find_file_command = key;
            cout << "command customization successfull!" << endl;
            cin.ignore();
        }
        void set_delete_cmd(const string &key){
            delete_file_command = key;
            cout << "command customization successfull!" << endl;
            cin.ignore();
        }
        void set_exit_cmd(const string &key){
            exit_command = key;
            cout << "command customization successfull!" << endl;
            cin.ignore();
        }

        // getter functions to get commands keywords to display in help command and during customization.

        string get_exit_cmd(){
            return exit_command;
        }
        string get_delete_cmd(){
            return delete_file_command;
        }
        string get_find_cmd(){
            return find_file_command;
        }
        string get_copy_cmd(){
            return copy_file_command;
        }
        string get_ren_cmd(){
            return rename_file_command;
        }
        string get_cd_cmd(){
            return change_directory_command;
        }
        string get_parentdir_cmd(){
            return moveto_parent_directory_command;
        }
        string get_ver_cmd(){
            return version_info_command;
        }
        string get_ls_cmd(){
            return list_directory_command;
        }
        string get_write_cmd(){
            return write_file_command;
        }
        string get_mkdir_cmd(){
            return make_directory_command;
        }
        string get_read_cmd(){
            return read_command;
        }
        string get_customize_cmd(){
            return customize_command;
        }
}obj_disp; // initialized an object of display class
