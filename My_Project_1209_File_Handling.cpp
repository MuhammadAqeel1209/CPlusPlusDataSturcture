#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

int main()
{
	// taking varaiable
	// varaiable for SIZE
	const int SIZE = 4;
	
	// taking department Varaiable for Enter Department	
	string department;
	
	// taking department and applicants array
	string dept[SIZE] = {};
	float applicants[SIZE] = {0};
	
	// maximunAppilicant Varaiable
	int maximumApplicants = 0;
	
	// varaible for calucullate the no of applicants
	int computer = 0, textile = 0, design = 0, management = 0;
	
	// varaiable for calculate the total no of Applicants
	int totalNoOfApplicants = 0;
	
	
	// classes
	ifstream input;
	ofstream output;
	
	// output open the file (for write)
	output.open("Admission.txt", ios::out);
	
	// input open the file (for read)
	input.open("Admission.txt");

	// Detail about method of entering data
	cout << " Select your Choice from\nC for Computer Science\nE for Textile Engineering\nD for Textile Design\nM for Management Science\n" << endl;
	cout << "Enter Your Choice in Capital Alphabet from C,E,D,M\nEnter -1 to stop the Execution and show the results" << endl << endl;
	
	// for finding the errors if errors then go to out of program
	if(!input || !output)
	{
		cout << "Error in file" << endl;
		return 0;
	}
	else
	{
		// infinity loop for enter the department for admission
		
		while( atoi(department.c_str()) != -1)
		{
				// enter the department
			
			cout << "Enter the department\t";
			cin >> department;	
			
			// calculate the no of department which enter by user by enter the value for deparment
			
			// computer
			if(department == "C")
			{
				computer++;
			
			} // textile
			else if(department == "E")
			{
				textile++;
				
			} // design
			else if(department == "D")
			{
				design++;
				
			} // mangement
			else if(department == "M")
			{
				management++;
			
			} // for admission close
			else if	(atoi(department.c_str()) == -1)
			{
				cout << "\nADMISSION CLOSE\nTHANK YOU" << endl;	
			}
			else
			{
				cout << "PLZ CHOSE CORRECT OPTION FROM MENU\nTHANKS" << endl;
			}
			
			
			// assign value to deparment array and Applicants Array for sorting
				applicants[0] = computer;
				dept[0] = "Computer Science";
				
				applicants[1] = textile;
				dept[1] = "Textile Engineering";
				
				applicants[2] = design;
				dept[2] = "Textile Design";
				
				applicants[3] = management;
				dept[3] = "Management Science";
		}

		// find maximum applicants
		// for computer
		if(maximumApplicants < computer )
		{
			maximumApplicants = computer;
		}
		// for textile
			if(maximumApplicants < textile )
		{
			maximumApplicants = textile;
		}
		// for design
			if(maximumApplicants < design )
		{
			maximumApplicants = design;
		}
		// for management
			if(maximumApplicants < management )
		{
			maximumApplicants = management;
		}
		
		
		// to calculate the total no of applicants
		totalNoOfApplicants = management + design + textile + computer ;
		
		// loop for sorting of department and applicants
		for(int i =0; i < 4 ; i++)
		{
			for(int j =0; j < 3; j++)
			{
				if(applicants[j] < applicants[j+1])
				{
					// applicants
					int temp = applicants[j];
					applicants[j] = applicants[j + 1];
					applicants[j+1] = temp;
					
					// department
					string temp2 = dept[j];
					dept[j] = dept[j+1];
					dept[j+1] = temp2;
				}
			}
		}
		
	
		// for write in the file
		output << "Department\tApplication Received\t\tPercentage" << endl;
		output << "----------\t--------------------\t\t----------" << endl;
		for(int i = 0; i < SIZE; i++)
		{	
			output << dept[i] << "  \t\t" << applicants[i] << "\t\t" << (applicants[i]*100)/ totalNoOfApplicants << " %";
			output << endl;
}
		// total No applicants
		output << "\n\n\nTotal Applications:\t" << totalNoOfApplicants << endl << endl << endl << endl;
		
// 		maximum number find		
// 		`computer
		if(maximumApplicants == computer)
		{
			output << "Department of Computer Science is at the top with  " <<  maximumApplicants <<  " applications" << endl;
		}
		
// 		design
		if(maximumApplicants == design)
		{
			output << "Department of Design is at the top with  " <<  maximumApplicants <<  " applications" << endl;
		}

// 		textile
		if(maximumApplicants == textile)
		{
			output << "Department of Textile Enginerring is at the top with  " <<  maximumApplicants <<  " applications" << endl;
		}
		
// 		mangement Science
		if(maximumApplicants == management)
		{
			output << "Department of Management Science is at the top with  " <<  maximumApplicants <<  " applications" << endl;
		}

	cout << endl << endl << endl;
		// for read of the file
		while(!input.eof())
		{
			// using line by line read function
			getline(input, department);
			cout << department; 
			cout << endl ;
		}
	}
		
		// close the file	
	input.close();
	output.close();
	return 0;

}
