#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void print_menu(string actions) {
    system("cls"); // очищаем консоль
    cout << actions << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "1. Open WIN+R" << endl;
    cout << "2. Write text or link" << endl;
    cout << "3. Enter" << endl;
    cout << "4. Wait (and number of seconds)" << endl;
    cout << "5.To exit, write exit and close programm" << endl;
    cout << "-------------------------------------------------------------" << endl;
}

int main() {
    


        string name;
        cout << "Script name: " << endl;
        cin >> name;

        ofstream f(name + ".txt", ios_base::app);

        string actions = ""; // список сделанных действий

        print_menu(actions);

        while (true) {
            int p;
            cin >> p;

            if (p == 1) {
                f << "GUI r\n";
                f << "DELAY 200\n";
                actions += "Opened WIN+R\n";
                print_menu(actions);
            }

            if (p == 2) {
                string text;
                cout << "Text: " << endl;
                cin >> text;
                f << "STRING " << text << "\n";
                f << "DELAY 200\n";
                actions += "Wrote \"" + text + "\"\n";
                print_menu(actions);
            }

            if (p == 3) {
                f << "ENTER\n";
                f << "DELAY 200\n";
                actions += "Pressed Enter\n";
                print_menu(actions);
            }

            if (p == 4) {
                int delay;
                cout << "Delay time (in milliseconds): " << endl;
                cin >> delay;
                f << "DELAY " << delay << "\n";
                actions += "Waited " + to_string(delay) + " ms\n";
                print_menu(actions);
            }

            if (p == 'exit') {
                f.close();
                cout << "File saved in the program directory!" << endl;
                break;
                std::exit(0);
            }
        }


    return 0;
}

