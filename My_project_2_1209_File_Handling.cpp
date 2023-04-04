#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>

using namespace std;
// varaiable for size
const int SIZE = 10;

// making class
class StudentData{
	//private section
	private:
		// taking varaiable
		int sessonialMarks , midsMarks ,  finalMarks, totalMarks;
		char grades;
		string regNo, studName, degree;
		// public section
	public:
		// default constructor
		StudentData()
		{
		}
		
		// for input data
		void input()
		{
			// name
			cout << "Enter the name:\t";
			cin >> studName;
			
			// roll no
			cout << "Enter the rollNo:\t";
			cin >> regNo;
			
			// degree
			cout << "Enter the Degree Program:\t";
			cin >> degree;
			
			// sessoinial marks
			cout << "Enter the Sessonial Marks:\t";
			cin >> sessonialMarks;
			
			// mids marks
			cout << "Enter the Mid Marks:\t";
			cin >> midsMarks ;
			
			// final marks
			cout << "Enter the Final Marks:\t";
			cin >> finalMarks ;
			
			
			cout << endl;
			cout << "-------------------\n" << endl;
			// total of marks
			totalMarks = sessonialMarks  + midsMarks  + finalMarks ;
			
			// condition for finding grades
			if(totalMarks  <= 100 && totalMarks  >= 81)
			{
				grades = 'A';
			}
			else if(totalMarks  <= 80 && totalMarks  >= 71)
			{
				grades = 'B';
			}
			else if(totalMarks  <= 70 && totalMarks  >= 61)
			{
				grades  = 'C';
			}
			else if(totalMarks  <= 60 && totalMarks  >= 50)
			{
				grades  = 'D';
			}
			else
			{
				grades  = 'F';
			}
			
		}
	// making function for write data on file	
		void outputStream()
		{
			// taking class
				ofstream output;
			output.open("Addmission.txt", ios::out);
			
			// finding the errors
			if(!output)
		{
			cout << "ERROR IN FILE" << endl;
		}
		else
		{	
		// for write data on file
			output << "----------------------------------------------------------------------------------------------------------" << endl;
			output << "--------------------------------RESULTS OF STUDENTS AT NTU -----------------------------------------------" << endl;
			output << "NAME\t\tROLLNO\t\tDEGREE\t\tSESSONIAL\tMIDS\tFINAL\t\tTOTAL\tGRADES" << endl;
			output << "----\t\t-------\t\t------\t\t---------\t----\t-----\t\t-----\t-----" << endl;
		}
	}
	// making function for write data on file
		void output()
		{
			// taking class
			ofstream output;
			output.open("Addmission.txt", ios::app);
			// finding the errors
			if(!output)
		{
			cout << "ERROR IN FILE" << endl;
		}
		else
		{
//			for write data on file
			
			output  <<  studName << "   \t" << regNo << " \t" << degree << "\t\t  " << sessonialMarks << "\t\t  " << midsMarks << "\t " << finalMarks << "\t=\t"    << totalMarks << "  \t " << grades << endl;
		}
	}
				// display function using ifstream input
		void display()
		{
			string data;
//			taking class
			ifstream input;
			input.open("Addmission.txt");
			
			// finding the errors
			if(!input)
			{
				cout << "ERROR IN FILE" << endl;
			}
			
			else
			{
				while(!input.eof())
				{
					// line by read function
				getline(input, data);	
				cout << data << endl;	
			}
			}
}
		
};


int main()
{
	// important announcement
	cout << "\nIMPORTANT ANNOUNCEMENT\n 1:PLZ ENTRE YOUR ONLY MAIN NAME IN 5 TO 7 LETTER (LIKE AQEEL)\n 2:YOUR DEGREE PROGRAM IN CODES WORD (LIKE BSCS)\n 3:YOUR FULL ROLLNO (LIKE 21-NTU-CS-1209)\n\nTOTAL MARKS IS 100:\n 30 MARKS SESSONIAL \n 30 MARKS MIDS \n 40 MARKS FINAL" << endl << endl;
	
	// making object
	StudentData std;
	
			// enter the data of student
			
			// calling the function  for typing the nav bar 
			std.outputStream();
			
			for(int i = 0; i < SIZE; i++)
			{
				// calling input function
			std.input();
			// calling the function for typing in the file
			std.output();
			}		
			// calling the function for read the file and display on console
			std.display();
	return 0;
}

