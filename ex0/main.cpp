/*ex0a : premitive dycryption
*
*/
//------------include section--------
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>

//------------using sectin-------
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::ifstream;
using std::getline;
//-----------const section & enum -------
const int MAX_STR_LEN=1000;
//--------prororype section -------
// reading input files
void read_file(char dec_str[] , char user_inp[]);
//read from file to the str
void read_to_str( ifstream &d_file ,ifstream &inp_file ,
                 char user_inp[], char dec_str[]);
//---------main section ----
int main() {
    char dec_str[MAX_STR_LEN], user_inp[MAX_STR_LEN];
    
    
    read_file(dec_str,user_inp);
    //decrypy();
    //output();
    return 0;
}
//---------------------
// reading input files
void read_file(char dec_str[] , char user_inp[])
{
    char fname[MAX_STR_LEN]; // redaing the file name from user
    ifstream d_file, inp_file;
    
    cin >> setw(MAX_STR_LEN)>>fname;
    d_file.open(fname);
    cin >> setw(MAX_STR_LEN)>>fname;
    inp_file.open(fname);
    
    read_to_str(d_file,inp_file,user_inp,dec_str);
}
//------------------------------
//read from file to the str
void read_to_str( ifstream &d_file ,ifstream &inp_file ,
                 char user_inp[], char dec_str[])
{
    int pos_d=0,pos_i=0;
    if (!d_file.is_open() && !inp_file.is_open())
    {
        exit(EXIT_FAILURE);
    }
    
//    inp_file >> user_inp[pos_i];
//    d_file >> dec_str[pos_d];
    
    while (!d_file.eof()){
        d_file.getline(d_file,dec_str);
    }
    while (dec_str[pos_d]!='\0') {
        cout << dec_str[pos_d] << " !";
        pos_d++;
    }
    
    
    cout << user_inp[pos_i]<< " 2?";
    
    
}
