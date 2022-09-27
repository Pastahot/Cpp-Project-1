#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <string.h>
#include <windows.h>
using namespace std;

void menu();

bool zaciatok_slova(const string& str, const string& cmp)    //s pomocou
{
    return str.compare(0, cmp.length(), cmp) == 0;
}

bool koniec_slova(string const& str, string const& suffix) // s pomocou
{
    if (str.length() < suffix.length()) {
        return false;
    }
    return str.compare(str.length() - suffix.length(), suffix.length(), suffix) == 0;
}

void starting()
{
    ofstream output("out.txt");
    string line;
    string wstart;
    cout << "Enter the starting letter:\n";
    cin >> wstart;
    output << wstart << endl;
    system("cls");
    ifstream DictFile;
    DictFile.open("slovnik.txt");
    if (!DictFile)
    {
        cout << "Error while opening the file!\n";
        exit(1);
    }
    else
    {
        while (true)
        {
            if (DictFile.fail())
                break;
            getline(DictFile, line);
            int pos = line.find(";");
            string slovo = line.substr(0, pos);
            if (zaciatok_slova(slovo, wstart))
            {
                cout << line << endl;
                output << line << endl;
            }
        }
        output.close();
    }
    Sleep(3000);
    menu();
}

void containing()
{
    ofstream output("out.txt");
    string line;
    string wcon;
    cout << "Enter letters contained in the word:\n";
    cin >> wcon;
    output << wcon << endl;
    system("cls");
    ifstream DictFile;
    DictFile.open("slovnik.txt");
    if (!DictFile)
    {
        cout << "Error while opening the file!\n";
        exit(1);
    }
    else
    {
        while (true)
        {
            getline(DictFile, line);
            int pos = line.find(";");
            string slovo = line.substr(0, pos);
            size_t found = slovo.find(wcon);
            if (found != string::npos)
            {
                cout << line << endl;
                output << line << endl;
            }
            if (DictFile.fail())
                break;
        }
        output.close();
    }
    Sleep(3000);
    menu();
}

void ending()
{
    ofstream output("out.txt");
    string line;
    string wend;
    cout << "Enter the ending letter:\n";
    cin >> wend;
    output << wend << endl;
    system("cls");
    ifstream DictFile;
    DictFile.open("slovnik.txt");
    if (!DictFile)
    {
        cout << "Error while opening the file!\n";
        exit(1);
    }
    else
    {
        while (true)
        {
            getline(DictFile, line);
            int pos = line.find(";");
            string slovo = line.substr(0, pos);
            if (koniec_slova(slovo, wend))
            {
                cout << line << endl;
                output << line << endl;
            }
            if (DictFile.fail())
                break;
        }
        output.close();
    }
    Sleep(3000);
    menu();
}

void menu()
{
    ofstream output("out.txt");
    system("cls");
    string value;
    cout << "----------------------------------------------------------------\n";
    cout << "starting.......Find a meaning of the word starting with certain letters.\n";
    cout << "containing.......Find a meaning of the word containing certain letters.\n";
    cout << "ending.......Find a meaning of the word ending with certain letters.\n";
    cout << "stop.......Stop the program.\n";
    cout << "----------------------------------------------------------------\n";
    cin >> value;
    output << value << endl;
    transform(value.begin(), value.end(), value.begin(), ::tolower);
    if (value == "starting")
    {
        starting();
    }
    else if (value == "containing")
    {
        containing();
    }
    else if (value == "ending")
    {
        ending();
    }
    else if (value == "stop")
    {
        cout << "END OF THE PROGRAM.\n";
        exit(-1);
    }
    else
    {
        menu();
    }
}

int main()
{
    ofstream output("out.txt");
    menu();
    return 1;
}