#include "countLetters.hpp"

// reads each character from the inputFile and adds 1 to each character's (letter)
// corresponding array position each time each letter appears
void count_letters(ifstream &inputFile, int* letters){
   // count the number of possible characters for counting
   int number = (26*2);    // count for both uppercase and lowercase letters
   number += 2;   // add two possible chars for spaces and newlines

   // char letter;

   // while the inputFile has characters/content
   while(!inputFile.eof()){
      // create a variable to collect a line of text, separated by a newline char (one paragraph)
      std::string line;

      // get a paragraph of text
      getline(inputFile, line);  // reads a line of text until a newline char

      // create a dynamically allocated pointer of characters for each char in the paragraph
      char* chars = new char[line.length()]; //

      // copy the string of text in the paragraph within 'line' & copy + assign
      // each char (from the string) to an array element
      std::strcpy(chars, line.c_str());

      // add 1 per newline/paragraph
      letters[charToInt('\n')] += 1;   // add 1 to the newline char

      // iterate over each char within the paragraph
      for(int i=0; i<line.length(); i++){
         // cout << "chars[" << i << "] = " << chars[i] << endl;  // verify chars[i] contains the proper char

         // evaluates whether the inputFile character is a letter in the alphabet, space, or newline
         for(int n=0; n<number; n++){
            // if the character is in the list of possible chars, then add 1 to the
            // appropriate count for that letter
            if(chars[i] == intToChar(n)){
               letters[charToInt(chars[i])] += 1;
            }
         }
      }
   }
}

// returns the corresponding integer from each letter based on the order of letters
// in the alphabet while also returning spaces and newlines
int charToInt(char character){
   // associate a letter in the alphabet, space, and newline to an int (array position)
   std::map<char, int> letter;

   letter['A'] = 0;
   letter['a'] = 1;
   letter['B'] = 2;
   letter['b'] = 3;
   letter['C'] = 4;
   letter['c'] = 5;
   letter['D'] = 6;
   letter['d'] = 7;
   letter['E'] = 8;
   letter['e'] = 9;
   letter['F'] = 10;
   letter['f'] = 11;
   letter['G'] = 12;
   letter['g'] = 13;
   letter['H'] = 14;
   letter['h'] = 15;
   letter['I'] = 16;
   letter['i'] = 17;
   letter['J'] = 18;
   letter['j'] = 19;
   letter['K'] = 20;
   letter['k'] = 21;
   letter['L'] = 22;
   letter['l'] = 23;
   letter['M'] = 24;
   letter['m'] = 25;
   letter['N'] = 26;
   letter['n'] = 27;
   letter['O'] = 28;
   letter['o'] = 29;
   letter['P'] = 30;
   letter['p'] = 31;
   letter['Q'] = 32;
   letter['q'] = 33;
   letter['R'] = 34;
   letter['r'] = 35;
   letter['S'] = 36;
   letter['s'] = 37;
   letter['T'] = 38;
   letter['t'] = 39;
   letter['U'] = 40;
   letter['u'] = 41;
   letter['V'] = 42;
   letter['v'] = 43;
   letter['W'] = 44;
   letter['w'] = 45;
   letter['X'] = 46;
   letter['x'] = 47;
   letter['Y'] = 48;
   letter['y'] = 49;
   letter['Z'] = 50;
   letter['z'] = 51;
   letter[' '] = 52;
   letter['\n'] = 53;

   return letter[character];
}

// returns a corresponding character from an integer based on the order
// of letters in the alphabet
char intToChar(int num){
   // associate an array position (based on an int) to a letter in the alphabet
   std::map<int, char> digit;

   digit[0] = 'A';
   digit[1] = 'a';
   digit[2] = 'B';
   digit[3] = 'b';
   digit[4] = 'C';
   digit[5] = 'c';
   digit[6] = 'D';
   digit[7] = 'd';
   digit[8] = 'E';
   digit[9] = 'e';
   digit[10] = 'F';
   digit[11] = 'f';
   digit[12] = 'G';
   digit[13] = 'g';
   digit[14] = 'H';
   digit[15] = 'h';
   digit[16] = 'I';
   digit[17] = 'i';
   digit[18] = 'J';
   digit[19] = 'j';
   digit[20] = 'K';
   digit[21] = 'k';
   digit[22] = 'L';
   digit[23] = 'l';
   digit[24] = 'M';
   digit[25] = 'm';
   digit[26] = 'N';
   digit[27] = 'n';
   digit[28] = 'O';
   digit[29] = 'o';
   digit[30] = 'P';
   digit[31] = 'p';
   digit[32] = 'Q';
   digit[33] = 'q';
   digit[34] = 'R';
   digit[35] = 'r';
   digit[36] = 'S';
   digit[37] = 's';
   digit[38] = 'T';
   digit[39] = 't';
   digit[40] = 'U';
   digit[41] = 'u';
   digit[42] = 'V';
   digit[43] = 'v';
   digit[44] = 'W';
   digit[45] = 'w';
   digit[46] = 'X';
   digit[47] = 'x';
   digit[48] = 'Y';
   digit[49] = 'y';
   digit[50] = 'Z';
   digit[51] = 'z';
   digit[53] = ' ';
   digit[55] = '\n';

   return digit[num];
}

// prints (in the outputFile & terminal) the number of times each letter (uppercase and lowercase),
// spaces, and newlines appeared in the inputFile
void printCounts(ofstream& outputFile, int* counts){
   cout << "The Number of Times Each Letter Appeared in the inputFile are:" << endl;
   outputFile << "The Number of Times Each Letter Appeared in the inputFile are:" << endl;

   // count the number of possible characters for counting
   int number = (26*2);    // count for both uppercase and lowercase letters
   number += 2;   // add two possible chars for spaces and newlines

   // iterate over each possible char
   for(int n=0; n<number; n++){
      // print to terminal
      cout << intToChar(n) << ": " << counts[n] << endl;
      // print to outputFile
      outputFile << intToChar(n) << ": " << counts[n] << endl;
   }
}
