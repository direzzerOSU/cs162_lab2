#include "countLetters.hpp"

// reads each character from the inputFile and adds 1 to each character's (letter)
// corresponding array position each time each letter appears
void count_letters(ifstream &inputFile, int* letters){
   // count the number of possible characters for counting
   int number = 26;    // count for each letter in the alphabet

   // count the paragraphs
   int count = 1;

   // create a variable to collect a line of text, separated by a newline char (one paragraph)
   std::string line;

   // initialize a pointer to char(s)
   char* chars;

   // while the inputFile has characters/content
   while(!inputFile.eof()){
      // initialize/reset the count for each letter, space, and newline to 0
      for(int n=0; n<number; n++){
         letters[n] = 0;
      }

      // clear line
      line = "";

      // get a paragraph of text
      getline(inputFile, line);  // reads a line of text until a newline char
      // cout << "line: " << endl << line << endl;

      while(line == "" && !inputFile.eof()){
         getline(inputFile, line);
      }

      // dynamically allocate pointer of characters for each char in the paragraph
      chars = new char[line.length()];

      // copy the string of text in the paragraph within 'line' & copy + assign
      // each char (from the string) to an array element
      strcpy(chars, line.c_str());

      // iterate over each char within the paragraph
      for(int i=0; i<line.length(); i++){
         // cout << "chars[" << i << "] = " << chars[i] << endl;  // verify chars[i] contains the proper char

         // evaluates whether the inputFile character is a letter in the alphabet, space, or newline
         for(int n=0; n<number; n++){
            // if the character is in the list of possible chars, then add 1 to the
            // appropriate count for that letter
            if(tolower(chars[i]) == intToChar(n)){
               letters[charToInt(tolower(chars[i]))] += 1;
            }
         }
      }

      // deallocate pointer's dynamically allocated memory; will be reallocated for the next paragraph
      delete[] chars;

      cout << endl << "Please enter the filename for your output (from paragraph #" << count << "): ";
      std::string filename;
      cin >> filename;
      ofstream outputFile;
      outputFile.open(filename);
      printCounts(outputFile, letters);
      outputFile.close();
      count += 1;
   }
}

// returns the corresponding integer from each letter based on the order of letters
// in the alphabet
int charToInt(char character){
   // associate a letter in the alphabet to an int (array position)
   std::map<char, int> letter;

   letter['a'] = 0;
   letter['b'] = 1;
   letter['c'] = 2;
   letter['d'] = 3;
   letter['e'] = 4;
   letter['f'] = 5;
   letter['g'] = 6;
   letter['h'] = 7;
   letter['i'] = 8;
   letter['j'] = 9;
   letter['k'] = 10;
   letter['l'] = 11;
   letter['m'] = 12;
   letter['n'] = 13;
   letter['o'] = 14;
   letter['p'] = 15;
   letter['q'] = 16;
   letter['r'] = 17;
   letter['s'] = 18;
   letter['t'] = 19;
   letter['u'] = 20;
   letter['v'] = 21;
   letter['w'] = 22;
   letter['x'] = 23;
   letter['y'] = 24;
   letter['z'] = 25;

   return letter[character];
}

// returns a corresponding character from an integer based on the order
// of letters in the alphabet
char intToChar(int num){
   // associate an array position (based on an int) to a letter in the alphabet
   std::map<int, char> digit;

   digit[0] = 'a';
   digit[1] = 'b';
   digit[2] = 'c';
   digit[3] = 'd';
   digit[4] = 'e';
   digit[5] = 'f';
   digit[6] = 'g';
   digit[7] = 'h';
   digit[8] = 'i';
   digit[9] = 'j';
   digit[10] = 'k';
   digit[11] = 'l';
   digit[12] = 'm';
   digit[13] = 'n';
   digit[14] = 'o';
   digit[15] = 'p';
   digit[16] = 'q';
   digit[17] = 'r';
   digit[18] = 's';
   digit[19] = 't';
   digit[20] = 'u';
   digit[21] = 'v';
   digit[22] = 'w';
   digit[23] = 'x';
   digit[24] = 'y';
   digit[25] = 'z';

   return digit[num];
}

// prints (in the outputFile & terminal) the number of times each letter
// appeared in the inputFile
void printCounts(ofstream& outputFile, int* counts){
   cout << "The Number of Times Each Letter Appeared in the inputFile are:" << endl;
   outputFile << "The Number of Times Each Letter Appeared in the inputFile are:" << endl;
   // iterate over each letter in the alphabet
   for(int n=0; n<26; n++){
      // print to terminal
      cout << intToChar(n) << ": " << counts[n] << endl;
      // print to outputFile
      outputFile << intToChar(n) << ": " << counts[n] << endl;
   }
}
