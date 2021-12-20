//Name: Zachary Carper
//Class: CS-300-T2623 DSA
//Semester: 21EW2


#include <iostream>

#include <fstream>

#include <vector>

using namespace std;

// Definition of the structure course

struct Course{

   string courseNumber;

   string name;

   vector<string> prerequisites;

};

// The function is used to split string to a list of strings

vector<string> tokenize(string s, string del = " ")

{

   vector<string> stringArray;

   int start = 0;

   int end = s.find(del);

   while (end != -1) {

      

       stringArray.push_back(s.substr(start, end - start));

       start = end + del.size();

       end = s.find(del, start);

   }

    stringArray.push_back(s.substr(start, end - start));

   

    return stringArray;

}

// Function to load file and store the details into list of courses

vector<Course> LoadDataStructure()

{

   // Creating an object of iftsream class to open file

   ifstream fin("abcu.txt",ios::in);

  

   vector<Course> courses;

  

   string line;

  

   // Infinite loop

   while(1)

   {

       getline(fin,line);

      

       // if end of file is reached then break the loop

       if(line=="-1")

           break;

      

       Course course;

      

       // seperates tokenized information by utilizing commas

       vector<string> tokenizedInformation=tokenize(line,",");

      

       // Stores information on the structure course

       course.courseNumber=tokenizedInformation[0];

       course.name =tokenizedInformation[1];

      

       // if there are prerequisites then store them as well

       for(int i=2;i<tokenizedInformation.size();i++)

       {

           course.prerequisites.push_back(tokenizedInformation[i]);

       }

      

       // appending the course into list of courses

       courses.push_back(course);

      

   }

  

   // closes file

   fin.close();

  

   // return the list of all courses applicable

   return courses;

  

}

// prints the course information in a proper format

void printCourse(Course course)

{

   string courseNumber= course.courseNumber;

   string name=course.name;

   vector<string> prerequisites=course.prerequisites;

  

   cout<<"Course Number: "<<courseNumber<<endl;

   cout<<"Course Name: "<<name<<endl;

   cout<<"Prerequisites: ";

   for(int i=0;i<prerequisites.size();i++)

   {

       cout<<prerequisites[i]<<" ";

   }

   cout<<"\n\n";

  

}

// prints the course information in a proper format

void printCourseList(vector<Course> courses)

{

   int n=courses.size();

  

   // Utilize bubble sort in order to sort the list

   for(int i=0;i<n-1;i++)

   {

       for(int j=0;j<n-i-1;j++)

       {

           if(courses[j].courseNumber > courses[j+1].courseNumber)

           {

               swap(courses[j+1],courses[j]);

           }

       }

   }

  

   // traversing list of courses to print all courses information

   for(int i=0;i<n;i++)

   {

    

       printCourse(courses[i]);

      

   }

  

}

// search the course using the course number inputted by user

void searchCourse(vector<Course> courses)

{

   int n=courses.size();

   string courseNumber;

   int f=0;

  

   cout<<"Enter courseNumber: ";

   cin>>courseNumber;

  

   for(int i=0;i<n;i++)

   {

       // if course found then print it

       if(courses[i].courseNumber==courseNumber)

       {

           f=1;

           printCourse(courses[i]);

           break;

       }

   }

  

   // if course not found then display proper error message

   if(f==0)

   {

       cout<<"Course with given course number not found\n";

   }

}

int main(int argc, char **argv)

{

   vector<Course> courses;

  

   // Prints menu

   cout<<"1.Load Data Structure\n";

   cout<<"2.Print Course List\n";

   cout<<"3.Print Course\n";

   cout<<"4.Exit\n";

  

   int ch;

  

   // loop will break once user enter 4

   do{

       // Gives user opportunity to enter their choice

       cout<<"\nEnter your choice: ";

       cin>>ch;

      

       switch(ch)

       {

           case 1: courses=LoadDataStructure(); break;

           case 2: printCourseList(courses); break;

           case 3: searchCourse(courses); break;

           case 4: cout<<"Exit\n"; break;

          

           default: cout<<"Invalid Choice\n";

       }

      

   }while(ch!=4);

  

  

   return 0;

}

