#include <iostream>
#include <fstream>
#include <algorithm>
#include <regex>
using namespace std;
string removingNonNumbers(string str){
    const regex pattern("[^0-9.]");
    return regex_replace(str, pattern, "");
}
string removeWeirdChars(string str){
    const regex pattern("<.*?>");
    return regex_replace(str, pattern, "");
}
int main(){
    const char *path="C:/Users/Ethan/Desktop/Charges/ChargesAll.csv";
    ofstream MyFile(path);
    string myText;
    ifstream MyReadFile("AllCharges.txt");
    MyFile <<"\"Charge Name\",\"Price\"" << "\n";
    while (getline (MyReadFile, myText)) {
        if ((myText.find("transactionDescription") != string::npos))
        {
            myText.erase(std::remove(myText.begin(), myText.end(), '\t'), myText.end());
            MyFile <<"\"" << removeWeirdChars(myText) << "\"";
        }
        if (myText.find("<span class=\"negative\">") != string::npos)
        {
            myText.erase(std::remove(myText.begin(), myText.end(), '\t'), myText.end());
            MyFile << ",";
            MyFile <<"\"" << removingNonNumbers(removeWeirdChars(myText)) << "\"" << "\n";
        }
        
    }
    MyReadFile.close();
    MyFile.close();
}