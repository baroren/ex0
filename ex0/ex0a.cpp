/*ex0a : premitive encryption
*given 2 files , one for the encryption you need to encrypt the
*input file in the following rules , the rules file contain 2 letters
*each time , the first letter is the letter to change , this one is
*comparing with the input file , and the secon letter is what
*to change to
 
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
const int MAX_STR_LEN=100;
//--------prororype section -------
// reading input files
void read_file();
//read from file to the str
void print_to_file( ifstream &d_file ,ifstream &inp_file,char fname[]);
//compare chr to the dycription and returns the right one
void check(char &ch_c,ifstream &d_file);
//create and open output file
void read_out_file(char fname[], std::ofstream &out);
//close files after we done using them
void close_files(ifstream &d_file, ifstream &inp_file,
                 ofstream &out) ;
//checks if the file are open for reading and writing
void check_if_open(ifstream &d_file, ifstream &inp_file,
                   const ofstream &out);

//---------main section ----
int main() {
        
    read_file();

    return EXIT_SUCCESS;
}
//---------------------
// reading input files
void read_file()
{
    char fname[MAX_STR_LEN]; // redaing the file name from user
    ifstream d_file, inp_file;
    
    cin >> setw(MAX_STR_LEN)>>fname;
    d_file.open(fname);//"opening "file for reading
    cin >> setw(MAX_STR_LEN)>>fname;
    inp_file.open(fname);
    
    print_to_file(d_file,inp_file,fname);
}
//-------------------------------
//create and open output file
void read_out_file(char fname[], ofstream &out) {
        
    cin >> setw(MAX_STR_LEN)>>fname;// redaing the file name from user

    out.open(fname);//opening file for writing
}



//------------------------------
//read from file to the str
void print_to_file( ifstream &d_file ,ifstream &inp_file,char fname[])
{
    std::ofstream out;
    read_out_file(fname, out);
    
    char ch_c;//char to compare with encrypt file
    
    check_if_open(d_file, inp_file, out);
    
    ch_c=inp_file.get();// read char from input file
  
    
    while (!inp_file.eof())
    {//while the input file is not over
        if (isalpha(ch_c))
        {//we only need to convert letters , so numbers and signs
        //are left untouched
        check(ch_c,d_file);
        }
        out << ch_c ;
        cout <<ch_c;
        inp_file.get(ch_c);
    }

    close_files(d_file, inp_file, out);
}


//----------------------------------
//compare chr to the dycription and returns the right one
void check(char &ch_c,ifstream &d_file)
{
    char d;
    d_file.clear();//restart the file place
    d_file.seekg(0,std::ios::beg);


    while (!d_file.eof()&& d_file.tellg()!=-1)
    {//while the decryption file is not over
    //compare the input and dec files

        d_file.get(d);

        if (ch_c==d) {
            ch_c=d_file.get();
            return;
        }

       d_file.seekg(2,std::ios::cur);
//because our system is ab ab (a is the letter to change and b is
//the changed letter , i want to skip 2 places after evrey run in the
//loop
       
    }
}
//-------------------------------
//checks if the file are open for reading and writing
void check_if_open(ifstream &d_file, ifstream &inp_file,
                   const ofstream &out) {
    
    if (!d_file.is_open() && !inp_file.is_open()&&
        !out.is_open())
    {//check if the file is really open and nothing went wrong
        exit(EXIT_FAILURE);
    }
}
//-------------------------
//close files after we done using them
void close_files(ifstream &d_file, ifstream &inp_file,
                 ofstream &out) {
   out.close();
   inp_file.close();
   d_file.close();
}
