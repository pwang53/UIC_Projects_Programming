#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "myClasses.h"

class TravelNetwork
{
 private:
   // Create the Data Members for the Travel Network here
   int numAirport;      // number of airports
   MyFileList fileLists;      // link list of file names for f command
   Airport *network;
 
 public:
  
 // Use a constructor to initialize the Data Members for Travel Network
 TravelNetwork()
 {
   numAirport = 10;                        // initialize the number of airports as 10 (according to the instruction)
   network = new Airport[numAirport + 1];
 }

 // The main loop for reading in input
 void processCommandLoop (FILE* inFile)
 {
  char  buffer[300];
  char* input;

  input = fgets ( buffer, 300, inFile );   // get a line of input
    
  // loop until all lines are read from the input
  while (input != NULL)
  {
    // process each line of input using the strtok functions 
    char* command;
    command = strtok (input , " \n\t");

    printf ("*%s*\n", command);
    
    if ( command == NULL )
      printf ("Blank Line\n");
 
    else if ( strcmp (command, "q") == 0) 
      exit(1);
     
    else if ( strcmp (command, "?") == 0) 
      showCommands();
     
    else if ( strcmp (command, "t") == 0) 
      doTravel();
     
    else if ( strcmp (command, "r") == 0) 
      doResize();

    else if ( strcmp (command, "i") == 0) 
      doInsert();

    else if ( strcmp (command, "d") == 0) 
      doDelete();

    else if ( strcmp (command, "l") == 0) 
      doList();

    else if ( strcmp (command, "f") == 0) 
      doFile();

    else if ( strcmp (command, "#") == 0) 
      ;
     
    else
      printf ("Command is not known: %s\n", command);
     
    input = fgets ( buffer, 300, inFile );   // get the next line of input

  }
 }
 
 void showCommands()
 {
   printf ("The commands for this project are:\n");
   printf ("  q \n");
   printf ("  ? \n");
   printf ("  # \n");
   printf ("  t <int1> <int2> \n");
   printf ("  r <int> \n");
   printf ("  i <int1> <int2> \n");
   printf ("  d <int1> <int2> \n");
   printf ("  l \n");
   printf ("  f <filename> \n");
 }
 
 void doTravel()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // check if val1 is in the range of airports number
   if (val1 <= 0 || val1 > this->numAirport) {
       cout << "Error, " << val1 << " is not a valid airport." << endl;
       return;
   }

   // check if val2 is in the range of airports number
   if (val2 <= 0 || val2 > this->numAirport) {
       cout << "Error, " << val2 << " is not a valid airport." << endl;
       return;
   }

   printf ("Performing the Travel Command from %d to %d\n", 
            val1, val2);

   depthFirstSearchHelper(val1,val2);
 }
 
 void doResize()
 {
   int val1 = 0;
  
   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   int arrAirport = this->numAirport + 1;

   // delete all list of airport
   for (int i=0; i < arrAirport; i++){
       network[i].deleteAll();
   }

   // delete array
   delete [] network;

   // resize the array
   this->numAirport = val1;
   network = new Airport[arrAirport];
   printf ("Performing the Resize Command with %d\n", val1 );
 }
 
 void doInsert()
 {
   int val1 = 0;
   int val2 = 0;

     // get an integer value from the input
     char* next = strtok (NULL, " \n\t");
     if ( next == NULL )
     {
       printf ("Integer value expected\n");
       return;
     }
     val1 = atoi ( next );
     if ( val1 == 0 && strcmp (next, "0") != 0)
     {
       printf ("Integer value expected\n");
       return;
     }

     // get another integer value from the input
     next = strtok (NULL, " \n\t");
     if ( next == NULL )
     {
       printf ("Integer value expected\n");
       return;
     }
     val2 = atoi ( next );
     if ( val2 == 0 && strcmp (next, "0") != 0)
     {
       printf ("Integer value expected\n");
       return;
     }

   //check if val1 is in the range of airports number
   if (val1 <= 0 || val1 > this->numAirport) {
       cout << "Error, " << val1 << " is not a valid airport." << endl;
       return;
   }

   //check if val2 is in the range of airports number
   if (val2 <= 0 || val2 > this->numAirport) {
       cout << "Error, " << val2 << " is not a valid airport." << endl;
       return;
   }

   //check if val2 is already an edge of val 1
   if (network[val1].checkEdge(val2) == true) {
       cout << "Error， " << val2 << " already exists." << endl;
       return;
     }

   //passes all error check so push it onto the list
   network[val1].addEdge(val2);

   printf ("Performing the Insert Command from %d to %d\n",
              val1, val2);
 }
 

 void doDelete()
 {
   int val1 = 0;
   int val2 = 0;

     // get an integer value from the input
     char* next = strtok (NULL, " \n\t");
     if ( next == NULL )
     {
       printf ("Integer value expected\n");
       return;
     }
     val1 = atoi ( next );
     if ( val1 == 0 && strcmp (next, "0") != 0)
     {
       printf ("Integer value expected\n");
       return;
     }

     // get another integer value from the input
     next = strtok (NULL, " \n\t");
     if ( next == NULL )
     {
       printf ("Integer value expected\n");
       return;
     }
     val2 = atoi ( next );
     if ( val2 == 0 && strcmp (next, "0") != 0)
     {
       printf ("Integer value expected\n");
       return;
     }

   // check if val1 is in the range of airports number
   if (val1 <= 0 || val1 > this->numAirport) {
       cout << "Error, " << val1 << " is not a valid airport." << endl;
       return;
   }

   // check if val2 is in the range of airports number
   if (val2 <= 0 || val2 > this->numAirport) {
       cout << "Error, " << val2 << " is not a valid airport." << endl;
       return;
   }
   
   if (network[val1].checkEdge(val2) == false){
       cout << "Error, " << val2 << "is NOT in the list of airport " << val1 << "." << endl;
       return;
   }

   network[val1].deleteEdge(val2);

      printf ("Performing the Delete Command from %d to %d\n",
              val1, val2);
 }
 
 void doList()
 {
   int arrAirport = 0;
   arrAirport = numAirport + 1;
   
   for (int i = 1; i < arrAirport; i++) {
         cout << "Airport " << i << ": ";
         network[i].printAll();
     }
 }
 
 void doFile()
 {
   // get a filename from the input
   char* fname = strtok (NULL, " \n\t");
   if ( fname == NULL )
   {
     printf ("Filename expected\n");
     return;
   }
   
   printf ("Performing the File command with file: %s\n", fname);
   
   // next steps:  (if any step fails: print an error message and return ) 
   //  1. verify the file name is not currently in use
   //  2. open the file using fopen creating a new instance of FILE*
   //  3. recursively call processCommandLoop() with this new instance of FILE* as the parameter
   //  4. close the file when processCommandLoop() returns
 // check if file name exists
   if (fileLists.checkExist(fname) == true) {
       cout << "Error filename already in use " << endl;
       return;
   }

   // create new instance
   FILE* myFileName;
   myFileName = fopen(fname, "r");

    if(myFileName == NULL) {
        cout << "Error couldnt open file or find it" << endl;
        return;
    }

   // add to link list
   fileLists.addFile(fname);

   // recursive call
   processCommandLoop(myFileName);

   // close file
   fclose (myFileName);

   // remove name from link list
   fileLists.deleteFile(fname);

 }

 void depthFirstSearchHelper (int x, int y) {
    int arrAirport = 0;
    arrAirport = numAirport + 1;
    // mark all airports as unvisisted
    for (int i=0; i < arrAirport; i++) {
        network[i].markUnVisisted();
    }

    if (dfs(x,y) == true) {
        cout << "You can get from airport " << x << " to airport " << y <<  " in one or more flights" << endl;
    }
    else {
        cout << "You can NOT get from airport " << x << " to airport " <<  y << " in one or more flights" << endl;
    }
}

 bool dfs (int a, int b) {
    // traverse through the list for the current location
    Node *temp = network[a].getAHead();

    // base case
    if (temp == NULL) {
        return false;
    }

    for (; temp != NULL; temp = temp->next) {

        // found it
        if (temp->data == b) {
            return true;
        }

        // mark visit or not
        if (network[temp->data].getStatus() == false) {

            // mark it as visisted
            network[temp->data].markVisisted();

            // recursive call
            if (dfs (temp->data, b ) == true) {
                return true;
            }
        }
    }
    return false;
}

};

int main (int argc, char** argv)
{
  
  // set up the variable inFile to read from standard input
  FILE* inFile = stdin;

  // set up the data needed for the airport adjcency list
  TravelNetwork airportData;
   
  // call the method that reads and parses the input
  airportData.showCommands();
  printf ("\nEnter commands at blank line\n");
  printf ("    (No prompts are given because of f command)\n");
  airportData.processCommandLoop (inFile);
   
  printf ("Goodbye\n");
  return 1;
 }
