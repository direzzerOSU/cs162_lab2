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

      // initialize a pointer array with 26 positions; one for each letter in the alphabet
      int* count = new int[26];

      // initialize the count for each letter to 0
      for(int n=0; n<26; n++){
         count[n] = 0;
      }

      // check to verify that the file was successfully opened
      if(inputFile){
         count_letters(inputFile, count);

         // initialize an output file, which will store all values for letter counts
         ofstream outputFile;

         // open a textfile to write content to; if not available, create a new file
         outputFile.open("letterCounts.txt");

         // print the number of times each letter appeared within the inputFile
         printCounts(outputFile, count);

         // close the outputFile
         outputFile.close();
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
