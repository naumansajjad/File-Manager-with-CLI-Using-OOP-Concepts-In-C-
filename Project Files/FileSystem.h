#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

// Class to to store actual functions that manipulate files

class FileSystem {
    private:

        // Declaration of functions

        void readfile(const string &filename);
        bool makedirectory(const string &directoryname);
        bool changedirectory(const string &directoryname);
        bool copyfile(const string &source, const string &destination);
        bool renamefile(const string &file, const string &newfile);
        bool deletefile(const string &filename);
        void writetofile(const string &filename, const string &content);
        bool findfile(const string &filename);
        void listdirectory(const string &directory);
        void movetoparentdirectory(const string &directory);

    public:

        // function calling for private members

        void read_file(const string &filename){
            readfile(filename);
        }
        void make_directory(const string &directoryname){
            makedirectory(directoryname);
        }
        void change_directory(const string &directoryname){
            changedirectory(directoryname);
        }
        void copy_file(const string &sourcefile, const string &destinationfile){
            copyfile(sourcefile, destinationfile);
        }
        void rename_file(const string &file,const string &newfile){
            renamefile(file,newfile);
        }
        void delete_file(const string &filename){
            deletefile(filename);
        }
        void write_to_file(const string &filename, const string &content){
            writetofile(filename,content);
        }
        void find_file(const string &filename){
            findfile(filename);
        }
        void list_directory(const string &directory){
            listdirectory(directory);
        }
        void move_to_parent_directory(const string &directory){
            movetoparentdirectory(directory);
        }
}obj_FS; // object initialization of FileSystem Class

// Function Definitions for all private members


//function for reading a file

void FileSystem::readfile(const string &filename){
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

// function for creating new directory

bool FileSystem::makedirectory(const string &directoryname){
    try{
            // try catch statements for efficient error handling

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
    }catch (const fs::filesystem_error &error){ // exception handling and system error handling
                cerr << "Error: " << error.what() << endl;
                return false;
    }
}

// function for changing directories

bool FileSystem::changedirectory(const string &newDirectory){
    try
    {
        fs::path currentPath = fs::current_path();
        fs::path newPath = currentPath / newDirectory;

        if (fs::exists(newPath) && fs::is_directory(newPath))
        {
            fs::current_path(newPath);
            cout << "Changed directory to " << newPath << "\n";
            return true;
        }
        else
        {
            cerr << "Error: Directory '" << newDirectory << "' does not exist or is not a directory.\n";
            return false;
        }
    }
    catch (const fs::filesystem_error &error) 
    {
        cerr << "Error: " << error.what() << "\n";
        return false;
    }
}
        
// function for copying files

bool FileSystem::copyfile(const string &source, const string &destination){
    try
    {
        fs::path currentPath = fs::current_path();
        fs::path sourcePath = currentPath / source;
        fs::copy(sourcePath, destination, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
        cout << "File copied from " << source << " to " << destination << "\n";
        return true;
    }
    catch (const fs::filesystem_error &error)
    {
        cerr << "Error: " << error.what() << "\n";
        return false;
    }
}

// function to rename a file or directory

bool FileSystem::renamefile(const string &currentFile, const string &newFile){
    try
    {
        fs::path currentPath = fs::current_path();
        fs::path currentFilePath = currentPath / currentFile;
        fs::path newFilePath = currentPath / newFile;
        if (fs::exists(newFilePath))
        {
            cout << "Error: The file name already exists." << endl;
            return true;
        }
        else
        {
            fs::rename(currentFilePath, newFilePath);
            cout << "File renamed from " << currentFile << " to " << newFile << "\n";
            return false;
        }
    }
    catch (const fs::filesystem_error &error)
    {
        cerr << "Error: " << error.what() << "\n";
        return false;
    }
}

// function to delete a file or directory

bool FileSystem::deletefile(const string &filename){
    try
    {
        fs::path currentPath = fs::current_path();
        fs::path filePath = currentPath / filename;

        if (fs::exists(filePath) && fs::is_directory(filePath))
        {
            fs::remove_all(filename);
            cout << "Directory '" << filename << "' and all its contents deleted successfully.\n";
            return true;
        }else if(fs::exists(filePath) && !fs::is_directory(filePath))
        {
            fs::remove(filename);
            cout << "File '" << filename << "' deleted successfully.\n";
            return true;
        }
        else if(!fs::exists(filePath))
        {
            cerr << "Error: File or Directory does not exist.\n";
            return false;
        }
        else
        {
            cerr << "Error: File or Directory cannot be deleted!\n";
return false;
        }
    }
    catch (const fs::filesystem_error &error)
    {
        cerr << "Error: " << error.what() << "\n";
        return false;
    }
}

// function to create a new file

void FileSystem::writetofile(const string &filename, const string &content){
    fstream file(filename, ios::out | ios::app);
    if (file.is_open())
    {
        file << content;
        file.close();
        cout << "Content is successfully written on the file " << filename << "!" << endl;
    }
    else
    {
        cerr << "Unable to create file '" << filename << "' for writing.\n";
    }
}
        
// function to find a file or directory

bool FileSystem::findfile(const string &filename){
    try {
        fs::path currentPath = fs::current_path();

        for (const auto& entry : fs::recursive_directory_iterator(currentPath)) {
            if (entry.path().filename() == filename) {
                if (fs::is_directory(entry.path())) {
                    std::cout << "The directory '" << filename << "' is present at '" << entry.path() << "'" << std::endl;
                    return true;
                } else {
                    std::cout << "The file '" << filename << "' is present at '" << entry.path() << "'" << std::endl;
                    return true;
                }
return true;
            }else{
                cerr << "The file '" << filename << "' is not found\n";
                return false;
            }
        }
    } catch (const fs::filesystem_error& error) {
        std::cerr << "Error: " << error.what() << "\n";
        return false;
    }
}

// function to list contents of the current directory

void FileSystem::listdirectory(const string &directory){
    cout << "Listing contents of directory: "<< "\n";
    for (const auto &entry : fs::directory_iterator(directory))
    {
        cout << entry.path().filename() << "\n";
    }
}
        
// function to move to parent directory 

void FileSystem::movetoparentdirectory(const string &directory){
    fs::path path(directory);
    fs::path newpath = path.parent_path();
    fs::current_path(newpath);
    cout << "Moved up to directory: " << newpath << "\n";
}