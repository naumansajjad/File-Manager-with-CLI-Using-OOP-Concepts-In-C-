#include <iostream>
#include "Display.h"
using namespace std;

class Customize {
    private:
        string keyword;
    public:
        void customize(){
            cout << "\nChoose command to customize\n"
                    "\n1.Read File (type)"
                    "\n2.Make Directory (mkdir)"
                    "\n3.Create new file (echo)"
                    "\n4.List Directory (ls)"
                    "\n5.Version Info (ver)"
                    "\n6.Move to Parent Directory (cd..)"
                    "\n7.Change Directory (cd)"
                    "\n8.Rename file (ren)"
                    "\n9.Copy File (copy)"
                    "\n10.Find file (find)"
                    "\n11.Delete file (del)"
                    "\n12.Exit CLI (exit)"
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