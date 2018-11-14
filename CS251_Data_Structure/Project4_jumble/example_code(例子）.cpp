#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]){

  std::unordered_map<std::string, vector<string> > word2freq;
  std::ifstream file;
  std::string dictStr;
  std::string keyStr;
  std::string inputStr;
  std::string longestLenKey;
  int numWords = 0;
  int numClasses = 0;
  int longestLen = 0;
  
  if(argc != 2) {
    std::cout << "usage:  ./freq <filename>\n";
    std::cout << "goodbye\n";
    return 1;
  }

  file.open(argv[1], std::ios::in);

  if(!file.is_open()){
    std::cout << "Error: could not open file '" <<
                     argv[1] << "'\n";
    std::cout << "goodbye\n";
    return 1;
  }

  std::cout << "reading input file...\n";

  while(!file.eof()) {
    file >> dictStr; 
    numWords++;
    keyStr = dictStr;
    sort(keyStr.begin(), keyStr.end());

    if(word2freq[keyStr].size() == 0){
      numClasses++;
    }
    
    word2freq[keyStr].push_back(dictStr);

    if(word2freq[keyStr].size() > longestLen) {
      longestLen = word2freq[keyStr].size();
      longestLenKey = keyStr;
    }
  }

  std::cout << 
    "enter a word and I will tell you what I know about it\n";
  std::cout << 
    "  when you are done, type ctrl-d (ctrl-z on windows)\n\n";
  std::cout << "> ";


  while(std::cin >> word) {
    sort(inputStr.begin(), inputStr.end());
    if(word2freq[inputStr].size() == 0) {
       std::cout << "sorry, '" << word << 
            "' does not appear in the input file '" <<
            argv[1] << "'\n";
    }
    else {
       std::cout << "English Anagrams Found:" << endl;
       for (int i=0; i < word2freq[inputStr].size(); i++ ){
            cout << word2freq[inputStr][i] << endl;
        }
    }
  }
  // user has quit.  Let's dump the map contents

  //the user wants to end the program. send a final report of the dictionary
  std::cout << "> REPORT:  " << endl << endl;
  std::cout << "  num_words            :  " << numWords << endl;
  std::cout << "  num_classes          :  " << numClasses << endl;
  std::cout << "  size-of-largest-class:  " << longestLen << endl;
  std::cout << "  largest-class key    :  " << "'" << longestLenKey << "'" << endl;
  std::cout << "  members of largest-class: \n\n";

  for (int i =0; i < dictionary[longestLenKey].size(); i++) {
    std::cout << "    " << dictionary[longestLenKey][i] << endl;
  }
  
  std::cout << "-----------------PQ CS251 Project4-----------------\n\n";
  std::cout << "---------------------Thank You---------------------\n\n";
  
  return 0;
}


