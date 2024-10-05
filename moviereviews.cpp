/*
  
lab18: movie reviews
COMSC-210
Naveen Islam
IDE: emacs (i code in emacs and import it into the repo folder)

 */

#include <iostream>
#include <string>
using namespace std;

struct Node{
  double rating;
  string comments;
  Node* next;
};

// function prototypes
void nodeToTail(Node*& head, double userRating, string userComments);
void nodeToHead(Node*& head, double userRating, string userComments);
void displayLinkedList(Node* head);

// main function
int main() {
  Node* head = nullptr;
  int userNum;
  double userRating;
  string userComments;
  char yon = 'y';
  
    // ask user which linked list method they want, option 1 or 2
  cout << "which linked list method should we use?" << endl;
  cout << "[1] New nodes are added at the head of the linked list" << endl;
  cout << "[2] New nodes are added at the tail of the linked list" << endl;
  cout << "Choice: ";
  cin >> userNum;
  cout << endl;

  // while loop that is active until user enters something other than y or Y
  while (yon == 'y' || yon == 'Y') {
    cout << "Enter review rating 0-5: ";
    cin >> userRating;
    cout << "Enter review comments: ";
    cin.ignore();
    getline(cin, userComments);

    // if user chose 1 from which linked list method to use, they will be using the head method while choosing 2 is the tail method
    if (userNum == 1) {
      nodeToHead(head, userRating, userComments);
    } else if (userNum == 2) {
      nodeToTail(head, userRating, userComments);
    }
    
    cout << "Enter another review? Y/N ";
    cin >> yon;
    cout << endl;
  }

  // calls the displayLinkedList function to output all reviews and the average
  displayLinkedList(head);
  
  return 0;
}

// function nodeToHead. Creates a new node and inputs the users rating and comment and inserts it to the beginning of the list
void nodeToHead(Node*& head, double userRating, string userComments) {
  Node* newNode = new Node();
  newNode->rating = userRating;
  newNode->comments = userComments;
  newNode->next = head;
  head = newNode;
}

// function nodeToTail. Creates a new node and inputs the users rating and comments by going to the end of the linked list and inserting there
void nodeToTail(Node*& head, double userRating, string userComments) {
  Node* newNode = new Node();
  newNode->rating = userRating;
  newNode->comments = userComments;
  newNode->next = nullptr;

  if (head == nullptr) {
    head = newNode;
  } else {
    Node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

// function displayLinkedList. displays the users rating and comment for all reviews in the linked list
void displayLinkedList(Node* head) {
  Node* temp = head;
  int reviewNum = 1;
  double average = 0;
  double averageAdder = 0; // to add the sum of all the ratings for the average
  
  cout << "\nOutputting all reviews:" << endl;
  
  while (temp != nullptr) {
    cout << "> Review # " << reviewNum << ": " << temp->rating << ": " << temp->comments << endl;
    
    reviewNum++;
    averageAdder += temp->rating;
    average = (averageAdder / (reviewNum - 1));
    temp = temp->next;
  }
  cout << "> Average: " << average << endl;
  cout << endl;
}
