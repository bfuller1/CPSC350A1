#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// No matter what I did the function could not properly read a file, but here is what I have
// Audrey helped me get rid of white space, I also looked this part up on http://www.martinbroadhurst.com/how-to-trim-a-stdstring.html
std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
  str.erase(0, str.find_first_not_of(chars));
  return str;
}

std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
  str.erase(0, str.find_first_not_of(chars));
  return str;
}

std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
  str.erase(0, str.find_first_not_of(chars));
  return str;
}

class DNA
{
public:
  string userInput();
  void readFile(string fileName);
private:
  // N/A
};

// Maddie helped me with trying to open up the file and turn the characters into uppercase
int main(int argc, char **argv) { // this function was supposed to open up the file but it sadly is not able to do that
  DNA dna;
  string fileName = dna.userInput();
  string dnaLine;

  ifstream insideFile;
  ofstream newFile;

  string totalDNA = "";

  insideFile.open(fileName);

  string upperCase;
  while(getline(insideFile, dnaLine)) {
    for(char c:dnaLine) {
      if(c == 'A') {
        upperCase += "a";
        totalDNA = totalDNA + "A";
      }
      else if(c == 'T') {
        upperCase += "t";
        totalDNA = totalDNA + "T";
      }
      else if(c == 'G') {
        upperCase += "g";
        totalDNA = totalDNA + "G";
      }
      else if(c == 'C') {
        upperCase += "c";
        totalDNA = totalDNA + "C";
      }
    }
    upperCase += "/n";
  }
  insideFile.close();

  newFile.open(fileName);
  newFile << upperCase;
  //newFile.close();
  //dna.readFile(fileName);
  cout << totalDNA << endl;
  return 0;
}

string DNA::userInput() { // this function determines if the user input a valid file by checking if the name ended with a ".txt"
  string fileName;
  string validFileName;
  string fileNameEnd;
  bool valid = false;

  while (!valid) {
    validFileName = ".txt";
    cout << "Please enter the name of a valid file: ";
    cin >> fileName;
    fileNameEnd = fileName.substr((fileName.size() - 4), (fileName.size() - 1));
    if (fileNameEnd == validFileName) {
      //cout << "Valid File" << endl;
      valid = true;
      return fileName;
    }
    else {
      cout << "Invalid File" << endl;
    }
  }
} // below is some of the past code that was used in order to try and open up the file, it sadly did not work
/*
void DNA::readFile(string fileName) {
  ifstream openFile;
  string totalDNA = "";
  string currentLine;
  string dnaLine;
  int dnaSum;
  //ifstream dnaFile (fileName); // making container for file
  openFile.open(fileName);
  //dnaFile.open(fileName);

  //int lines = -7;
  //int total = -13;

  if (!openFile) {
    cout << "Cannot open file" << endl;
  }
    while (openFile.good()) {
      getline(openFile,currentLine);
      std::string str = currentLine;
      trim(str);
      cout << "Total DNA" << totalDNA << endl;
      //str += 1;
      totalDNA.append(currentLine);
      dnaSum = currentLine.length();
      //cout << "Sum: " << dnaSum << endl;



      //totalDNA.append(currentLine);
      //currentLineLength = currentLine.size() - 1;
    }
  }
  else {
    cout << "Cannot open file" << endl;
  }
  cout << "Sum: " << dnaSum << endl;
  cout << totalDNA << endl;
  //cout << "lines = " << currentline << endl;
  //cout << "total = " << total << endl;
}
*/
