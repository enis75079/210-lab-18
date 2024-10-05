/*

lab15: movie class
COMSC-210
Naveen Islam
IDE: emacs
  
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// movie class
class Movie {

  // private member variables
private:
  string screenWriter;
  int releaseYear;
  string title;

public:
  // movie constructor
  Movie(string sw, int year, string name) {
    screenWriter = sw;
    releaseYear = year;
    title = name;
  }

  // setter functions for screenWriter, releaseYear, and title
  void setScreenWriter(string sw) {
    screenWriter = sw;
  }

  void setReleaseYear(int year) {
    releaseYear = year;
  }

  void setTitle(string name) {
    title = name;
  }

  // getter functions for screenWriter, releaseYear, and title
  string getScreenWriter() const {
    return screenWriter;
  }

  int getReleaseYear() const {  // fixed getter
    return releaseYear;
  }

  string getTitle() const {  // fixed getter
    return title;
  }
  
  // print function to display variables formatted
  void print() const {
    cout << "Movie: " << title << endl;
    cout << "    Year released: " << releaseYear << endl;
    cout << "    Screenwriter: " << screenWriter << endl;
    cout << endl;
  }
};

// main function
int main() {

  // temporary variables for storing the data from the input file
  string screenWriter;
  string title;
  int releaseYear;
  
  // create vector v to store the Movie objects
  vector<Movie> v;

  // open input file to read
  ifstream inputFile("input.txt");  // fixed typo

  // read all data from file and push back into the vector
  while (true) {
    // read title. if no more titles then break
    if (!getline(inputFile, title)) {
      break;
    }

    // read year released 
    inputFile >> releaseYear;  // fixed input variable
    inputFile.ignore();

    // read screenWriter
    getline(inputFile, screenWriter);

    // temporary Movie object to append the current data into vector v
    Movie movies(screenWriter, releaseYear, title);  // fixed argument order

    // push back the object into vector v 
    v.push_back(movies);
  }

  // utilize print function from Movie class to output the data read from file in print() format
  for (const Movie& x : v) {
    x.print();
  }

  // close input.txt file
  inputFile.close();
  
  return 0;
}
