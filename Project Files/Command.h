#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
using namespace std;
namespace fs = filesystem;

// Base Class Command (Abstract Class) for execution of commands

class Command{ //abstract class 
    public:
        virtual void execute() = 0; // pure virtual function
};


// Derived Classess for each Command, which executes the required functions.

// Class for read file command

class ReadFileCommand : public Command {
    private:
        string filename;
        
    public:
        ReadFileCommand(const string &file) : filename(file){} // Constructor

        void execute() override{
            ifstream file(filename);
            if(file.is_open()){
                string line;
                cout << "Content of file: " << endl;
                while(!file.eof()){
                    getline(file, line);
                    cout << line << endl;
                }
                file.close();
            }else{
                cerr << "Error: Unable to open file " << filename << " for reading" << endl;
            }
        }
};

// class for making new directory command

class MakeDirectoryCommand : public Command {
    private:
        string directoryname;

    public:
        MakeDirectoryCommand(const string &directory) : directoryname(directory){}

        void execute() override{
            try{ // try catch statements for efficient error handling

                fs::path currentpath = fs::current_path();
                fs::path newpath = currentpath / directoryname;
                if (fs::exists(newpath) && fs::is_directory(newpath)){
                    cerr << "Error: Directory " << directoryname << " already exists!" << endl;
                }else if(fs::create_directory(newpath)){
                    cout << "Directory " << directoryname << " creation successfull!" << endl;
                }else{
                    cerr << "Error: Directory " << directoryname << " creation failed !" << endl;
                }
            }catch (const fs::filesystem_error &error){ // exception handling || system error handling
                cerr << "Error: " << error.what() << endl;
            }
        }
};

//class for changing currrent directory command

class ChangeDirectoryCommand : public Command {
    private:
        string directoryname;
    public:
        ChangeDirectoryCommand(const string &directory) : directoryname(directory){}

        void execute() override{
            try{
                fs::path currentPath = fs::current_path();
                fs::path newPath = currentPath / directoryname;

                if (fs::exists(newPath) && fs::is_directory(newPath)){
                    fs::current_path(newPath);
                    cout << "Changed directory to " << newPath << "\n";
                }else{
                    cerr << "Error: Directory '" << directoryname << "' does not exist or is not a directory.\n";
                }
            }catch (const fs::filesystem_error &error) {
                cerr << "Error: " << error.what() << "\n";
            }
        }
};

// class for copying file command

class CopyFileCommand : public Command {
    private:
        string sourcefile, destinationfile;

    public:
        CopyFileCommand(const string &source, const string &destination ) : sourcefile(source), destinationfile(destination){}
        
        void execute() override{
            try{
                fs::path currentPath = fs::current_path();
                fs::path sourcePath = currentPath / sourcefile;
                fs::copy(sourcePath, destinationfile, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                cout << "File copied from " << sourcefile << " to " << destinationfile << "\n";
            }catch (const fs::filesystem_error &error){
                cerr << "Error: " << error.what() << "\n";
            }
        }
};

// class for renaming file command

class RenameFileCommand : public Command {
    private:
        string filename;
        string newfilename;

    public:
        RenameFileCommand(const string &file, const string &newfile) : filename(file), newfilename(newfile){}

        void execute() override{
            try{
                fs::path currentPath = fs::current_path();
                fs::path currentFilePath = currentPath / filename;
                fs::path newFilePath = currentPath / newfilename;
                if (fs::exists(newFilePath)){
                    cout << "Error: The file name already exists." << endl;
                }else{
                    fs::rename(currentFilePath, newFilePath);
                    cout << "File renamed from " << filename << " to " << newfilename << "\n";
                }
            }catch (const fs::filesystem_error &error){
                cerr << "Error: " << error.what() << "\n";
            }
        }
};

// class for deleting file command

class DeleteFileCommand : public Command {
    private:
        string filename;

    public:
        DeleteFileCommand(const string &file) : filename(file){}

        void execute() override{
            try{
                fs::path currentPath = fs::current_path();
                fs::path filePath = currentPath / filename;

                if (fs::exists(filePath) && fs::is_directory(filePath))
                {
                    fs::remove_all(filename);
                    cout << "Directory '" << filename << "' and all its contents deleted successfully.\n";
                }else if(fs::exists(filePath) && !fs::is_directory(filePath))
                {
                    fs::remove(filename);
                    cout << "File '" << filename << "' deleted successfully.\n";
                }
                else if(!fs::exists(filePath))
                {
                    cerr << "Error: File or Directory does not exist.\n";
                }
                else
                {
                    cerr << "Error: File or Directory cannot be deleted!\n";
                }
            }
            catch (const fs::filesystem_error &error)
            {
                cerr << "Error: " << error.what() << "\n";
            }
        }
};

// class for writing file command

class WriteToFileCommand : public Command {
    private:
        string filename;
        string Data;

    public:
        WriteToFileCommand(const string &file, const string &data) : filename(file), Data(data){}

        void execute() override{
            fstream file(filename, ios::out | ios::app);
            if (file.is_open())
            {
                file << Data;
                file.close();
                cout << "Content is successfully written on the file " << filename << "!" << endl;
            }
            else
            {
                cerr << "Unable to create file '" << filename << "' for writing.\n";
            }
        }
};

// command for finding file command

class FindFileCommand : public Command {
    private:
        string filename;

    public:
        FindFileCommand(const string &file) : filename(file){}

        void execute() override{
            try {
                fs::path currentPath = fs::current_path();

                for (const auto& entry : fs::recursive_directory_iterator(currentPath)) {
                    if (entry.path().filename() == filename) {
                        if (fs::is_directory(entry.path())) {
                            cout << "The directory '" << filename << "' is present at '" << entry.path() << "'" << endl;
                        } else {
                            cout << "The file '" << filename << "' is present at '" << entry.path() << "'" << endl;
                        }
                    }else{
                        cerr << "The file '" << filename << "' is not found\n";
                    }
                }
            } catch (const fs::filesystem_error& error) {
                cerr << "Error: " << error.what() << "\n";
            }
        }
};

// class for listing contents of directory command

class ListDirectoryCommand : public Command {
    private:
        string directoryname;

    public:
        ListDirectoryCommand(const string &directory) : directoryname(directory){};

        void execute() override{
            cout << "Listing contents of directory: "<< "\n";
            for (const auto &entry : fs::directory_iterator(directoryname))
            {
                cout << entry.path().filename() << "\n";
            }
        }
};

// class for moving to parent directory command

class MoveToParentDirectoryCommand : public Command {
    private:
        string directoryname;

    public:
        MoveToParentDirectoryCommand(const string &directory) : directoryname(directory){};
        
        void execute() override{
            fs::path path(directoryname);
            fs::path newpath = path.parent_path();
            fs::current_path(newpath);
            cout << "Moved up to directory: " << newpath << "\n";
        }
};