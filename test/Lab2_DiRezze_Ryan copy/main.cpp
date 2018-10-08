#include "countLetters.hpp"
#include "menu.hpp"

int main(){
   // initial spacing to separate the program's content from terminal content
   cout << endl;
   bool selection;

   // start with the menu for the user to start the program or quit
   menu(selection);

   // if true, start the program
   if(selection){
      // initialize the input file
      ifstream inputFile;
      // specify the input file's local path - textfile must be located in
      // the same folder as program files
      inputFile.open("file_fun.txt");

      // count the number of elements in the dynamically allocated array for counting chars
      int number = 26;   // elements for each letter in the alphabet

      // initialize a pointer array for each character element
      int* count = new int[number];

      // check to verify that the file was successfully opened
      if(inputFile){
         count_letters(inputFile, count);
      }

      // if inputFile didn't open successfully, notify the user of the error
      else{
         cout << "Uh oh! The file didn't open successfully... Please try again." << endl;
      }

      // close the inputFile (done using inputFile)
      inputFile.close();

      // free dynamically allocated memory from the pointer to an array of integers
      delete[] count;
   }
   cout << endl;

   return 0;
}
