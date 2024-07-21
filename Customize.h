#include <iostream>
#include "Display.h"
using namespace std;

// Class Customize to customize different command keywords

class Customize {
    private:
        string key; // variable to store keyword temporarily

    public:
    
        // interface after selecting custmize command

        void customize(){
            cout << "\nChoose command to customize\n"
                    "\n1.Read File ("<<obj_disp.get_read_cmd()<<")"
                    "\n2.Make Directory ("<<obj_disp.get_mkdir_cmd()<<")"
                    "\n3.Create new file ("<<obj_disp.get_write_cmd()<<")"
                    "\n4.List Directory ("<<obj_disp.get_ls_cmd()<<")"
                    "\n5.Version Info ("<<obj_disp.get_ver_cmd()<<")"
                    "\n6.Move to Parent Directory ("<<obj_disp.get_parentdir_cmd()<<")"
                    "\n7.Change Directory ("<<obj_disp.get_cd_cmd()<<")"
                    "\n8.Rename file ("<<obj_disp.get_ren_cmd()<<")"
                    "\n9.Copy File ("<<obj_disp.get_copy_cmd()<<")"
                    "\n10.Find file ("<<obj_disp.get_find_cmd()<<")"
                    "\n11.Delete file ("<<obj_disp.get_delete_cmd()<<")"
                    "\n12.Exit CLI ("<<obj_disp.get_exit_cmd()<<")"
                 << endl;
            cout << "Option: ";
            int op;
            cin >> op;

            // switch to select one command

            switch(op){
                case 1:
                    cout << "New command: "; // new keyword stored in variable
                    cin >> key;
                    obj_disp.set_read_cmd(key); // function-call to set-keyword member function in Display Class
                    break;
                case 2:
                    cout << "New command: ";
                    cin >> key;
                    obj_disp.set_makedirectory_cmd(key);
                    break;
                case 3:
                    cout << "New command: ";
                    cin >> key;
                    obj_disp.set_write_cmd(key);
                    break;
                case 4:
                    cout << "New command: ";
                    cin >> key;
                    obj_disp.set_listdirectory_cmd(key);
                    break;
                case 5:
                    cout << "New command: ";
                    cin >> key;
                    obj_disp.set_version_cmd(key);
                    break;
                case 6:
                    cout << "New command: ";
                    cin >> key;
                    obj_disp.set_moveto_parentdir_cmd(key);
                    break;
                case 7:
                    cout << "New command: ";
                    cin >> key;
                    obj_disp.set_changedir_cmd(key);
                    break;
                case 8:
                    cout << "New command: ";
                    cin >> key;
                    obj_disp.set_renamefile_cmd(key);
                    break;
                case 9:
                    cout << "New command: ";
                    cin >> key;
                    obj_disp.set_copy_cmd(key);
                    break;
                case 10:
                    cout << "New command: ";
                    cin >> key;
                    obj_disp.set_find_cmd(key);
                    break;
                case 11:
                    cout << "New command: ";
                    cin >> key;
                    obj_disp.set_delete_cmd(key);
                    break;
                case 12:
                    cout << "New command: ";
                    cin >> key;
                    obj_disp.set_exit_cmd(key);
                    break;
                default:
                    cerr << "Invalid Input!" << endl;
                    break;
            }
        }
};