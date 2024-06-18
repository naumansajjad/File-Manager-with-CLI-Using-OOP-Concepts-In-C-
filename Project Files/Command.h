#include <iostream>
#include "FileSystem.h"
using namespace std;


// Base Class Command (Abstract Class) for execution of commands

class Command{ //abstract class 
    public:
        virtual void execute() = 0; // pure virtual function
};


// Derived Classess for each Command, which executes the required functions.

class ReadFileCommand : public Command {
    private:
        string filename;
        
    public:
        ReadFileCommand(const string &file) : filename(file){} // Constructor

        void execute() override{
            obj_FS.read_file(filename); // FunctionCall to execute a member function of FileSystem Class
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

class ChangeDirectoryCommand : public Command {
    private:
        string directoryname;
    public:
        ChangeDirectoryCommand(const string &directory) : directoryname(directory){}

        void execute() override{
            obj_FS.change_directory(directoryname);
        }
};

class CopyFileCommand : public Command {
    private:
        string sourcefile, destinationfile;

    public:
        CopyFileCommand(const string &source, const string &destination ) : sourcefile(source), destinationfile(destination){}
        
        void execute() override{
            obj_FS.copy_file(sourcefile,destinationfile);
        }
};

class RenameFileCommand : public Command {
    private:
        string filename;
        string newfilename;

    public:
        RenameFileCommand(const string &file, const string &newfile) : filename(file), newfilename(newfile){}

        void execute() override{
            obj_FS.rename_file(filename,newfilename);
        }
};

class DeleteFileCommand : public Command {
    private:
        string filename;

    public:
        DeleteFileCommand(const string &file) : filename(file){}

        void execute() override{
            obj_FS.delete_file(filename);
        }
};

class WriteToFileCommand : public Command {
    private:
        string filename;
        string Data;

    public:
        WriteToFileCommand(const string &file, const string &data) : filename(file), Data(data){}

        void execute() override{
            obj_FS.write_to_file(filename,Data);
        }
};

class FindFileCommand : public Command {
    private:
        string filename;

    public:
        FindFileCommand(const string &file) : filename(file){}

        void execute() override{
            obj_FS.find_file(filename);
        }
};

class ListDirectoryCommand : public Command {
    private:
        string directoryname;

    public:
        ListDirectoryCommand(const string &directory) : directoryname(directory){};

        void execute() override{
            obj_FS.list_directory(directoryname);
        }
};

class MoveToParentDirectoryCommand : public Command {
    private:
        string directoryname;

    public:
        MoveToParentDirectoryCommand(const string &directory) : directoryname(directory){};
        
        void execute() override{
            obj_FS.move_to_parent_directory(directoryname);
        }
};