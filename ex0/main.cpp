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
using std::get;
using std::ofstream;
//-----------const section & enum -------
const int MAX_STR_LEN=1000;
//--------prororype section -------
// reading input files
void read_file();
//read from file to the str
void print_to_file( ifstream &d_file ,ifstream &inp_file,char fname[]);
//compare chr to the dycription and returns the right one
void check(char &ch_c,ifstream &d_file);
//---------main section ----
int main() {
    
    
    read_file();
    //decrypy();
    //output();
    return 0;
}
//---------------------
// reading input files
void read_file()
{
    char fname[MAX_STR_LEN]; // redaing the file name from user
    ifstream d_file, inp_file;
    
    cin >> setw(MAX_STR_LEN)>>fname;
    d_file.open(fname);
    cin >> setw(MAX_STR_LEN)>>fname;
    inp_file.open(fname);
    
    print_to_file(d_file,inp_file,fname);
}
//------------------------------
//read from file to the str
void print_to_file( ifstream &d_file ,ifstream &inp_file,char fname[])
{
    char ch_c ; // redaing the file name from user
    ofstream out;
    cin >> setw(MAX_STR_LEN)>>fname;
    out.open(fname);
    
    if (!d_file.is_open() && !inp_file.is_open()&&
        !out.is_open())
    {
        exit(EXIT_FAILURE);
    }
    ch_c=inp_file.get();
    cout <<ch_c;
    
    while (!inp_file.eof()) {
        if (isalpha(ch_c)) {
        check(ch_c,d_file);
        }
        out << ch_c ;
        cout <<ch_c;
        inp_file.get(ch_c);
    }

    out.close();
    inp_file.close();
    d_file.close();
}
//----------------------------------
//compare chr to the dycription and returns the right one
void check(char &ch_c,ifstream &d_file)
{
    char d;
    d_file.clear();
    d_file.seekg(0,std::ios::beg);
    
    while (!d_file.eof()) {
        d_file.get(d);
        cout <<d <<" " <<endl;
        if (ch_c==d) {
            ch_c=d_file.get();
            return;
        }
        if(d!= ' ' )
            d_file.get(d);
        cout <<d <<" " <<endl;
       // d_file.seekg(2,std::ios::cur);
    }
}
