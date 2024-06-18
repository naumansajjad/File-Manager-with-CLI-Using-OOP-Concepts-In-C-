#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

class FileSystem {
    private:
        void readfile(const string &filename);
        bool makedirectory(const string &directoryname);
        
    public:
        void read_file(const string &filename){
            readfile(filename);
        }
        void make_directory(const string &directoryname){
            makedirectory(directoryname);
        }
}obj_FS;

class Command{ //abstract class 
    public:
        virtual void execute() = 0; // pure virtual function
};

class ReadFileCommand : public Command {
    private:
        string filename;
        
    public:
        ReadFileCommand(const string &file) : filename(file){}
        void execute() override{
            obj_FS.read_file(filename);
        }
};

class MakeDirectoryCommand : public Command {
    private:
        string directoryname;
    public:
        MakeDirectoryCommand(const string &directory) : directoryname(directory){}
        void execute() override{
            obj_FS.make_directory(directoryname);
        }
};

class FileManager {
    public:
        void execute_command(Command* cmd){
            cmd->execute();
        //command history saving feature pending
    }
    friend class Display;
};

class Display {
    private:
        string get_current_directory(){
            return fs::current_path().string();
        }
        string readcommand = "read";
        string makedirectorycommand = "mkdir";

    public:    
        void display(){
            cout << "\tWelcome to CLI File Manager\t" << endl;
            cout << "Type 'help' to see available commands" << endl;
            cout << endl;
        }
        string get_directory(){
            string directory = get_current_directory();
            return directory;
        }
        void set_read_cmd(const string &key){
            readcommand = key;
            cout << "command customization successfull!" << endl;
            cin.ignore();
        }
        string get_read_cmd(){
            return readcommand;
        }
}obj_disp;

class Customize {
    private:
        string keyword;
    public:
        void customize(){
            cout << "\nChoose command to customize\n"
                    "\n1.Read File (read)"
                    "\n2.Make Directory (mkdir)"
                 << endl;
            cout << "Option: ";
            int op;
            string key;
            cin >> op;
            switch(op){
                case 1:
                    cout << "New command: ";
                    cin >> key;
                    obj_disp.set_read_cmd(key);
                    break;
                default:
                    cerr << "Invalid Input!" << endl;
                    break;
            }
        }
};

void FileSystem::readfile(const string &filename){
    ifstream file(filename);
    if(file.is_open()){
        string line;
        cout << "Content of file: " << endl;
        while(getline(file, line)){
            cout << line << endl;
        }
        file.close();
    }else{
        cerr << "Error: Unable to open file " << filename << " for reading" << endl;
    }
}

bool FileSystem::makedirectory(const string &directoryname){
    try{
        fs::path currentpath = fs::current_path();
        fs::path newpath = currentpath / directoryname;
        if (fs::exists(newpath) && fs::is_directory(newpath)){
            cerr << "Error: Directory " << directoryname << " already exists!" << endl;
            return false;
        }else if(fs::create_directory(newpath)){
            cout << "Directory " << directoryname << " creation successfull!" << endl;
            return true;
        }else{
            cerr << "Error: Directory " << directoryname << " creation failed !" << endl;
            return false;
        }
    }catch (const fs::filesystem_error &error){
                cerr << "Error: " << error.what() << endl;
                return false;
    }
}