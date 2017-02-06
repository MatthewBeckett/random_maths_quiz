#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "params.h"



void	addsub		(void);
void 	multiply	(void);
void 	divide		(void);
void 	callQuestion	(void);
void 	setsec		();
void 	downLevel	(void);
void 	upLevel		(void);
void 	manageLevel	(void);
void 	manageParts	(void);
void	welcomMessage	();
void	input		();
void 	pageDown	();
int 	randNum		();


int answer,answer_given,start_time,finish_time,t1,t2,level,question,part,addedTimes = 0,addedLevels = 0;
int levels[15],times[15];


int main(){
	part = 1;
	level = 0;
	pageDown(80);

	// Show opening message including total questions and the time limits for level changes
	welcomMessage();

	pageDown(4);	
	printf("\nPress Enter to start the test");

	// Press enter to start test	
	getchar();
	
	// Seed random function with with current clock
	srand(clock());	

	pageDown(80);
	printf("\nLevel : %d",level+1);
	// Initialise test start time variable
	setsec(&start_time);

	// start looping for each question in total questions
	for(question = 0;question < totalQuestions;question++){
		// Run question part manager to change the part variable 
		manageParts();
		// Print question number
		printf("\nQuestion: %d",question+1);
		pageDown(4);

				
		// Print question associated with the part and level updating the answer variable
		callQuestion();
		
		// Update question start time variable				
	    	setsec(&t1);
		
		// Input answer
		input();
		pageDown(80);
		
		// Update question end time variable 
	    	setsec(&t2);

		// If the answer is wrong
		if(answer == answer_given){
			// Print "well done"
			printf("\nWell done! :)");
			// Add the question time to the question time array/list
			times[question] = t2 - t1;
			// variable according to the time taken	to answer the question		
			manageLevel();					
		}else{
			// Print the answer given, a message saying the question is 
			// wrong and print the right answer
			printf("\n%d is the wrong answer :( , the answer was %d",answer_given,answer);
			// Add the question time x2  to the question times array/list
			times[question] = (t2 - t1)*2;	
			// Decrease the level 
			downLevel();
		}
		// Add the level to the level array/list 
		levels[question] = level+1;
	}// End of loop	
	// Initialise the test end time variable
	setsec(&finish_time);

	// Calculate the average time taken and level per question
	int i;	
	for(i=0;i<totalQuestions;i++){
		addedLevels 	= addedLevels + levels[i];
		addedTimes	= addedTimes + times[i];	
	}
	pageDown(4);
	// Print the total seconds taken for completing the test
	printf("\nTotal seconds taken: %ld",finish_time - start_time);
	// Print the average level of questions attmpted	
	printf("\nAverage Level: %d",addedLevels/totalQuestions);
	// Print the average time taken per question
	printf("\nAverage Time Per Question: %d",addedTimes/totalQuestions);	
	pageDown(2);	
	getchar();
	getchar();	
	getchar();


	return 0;
}
////////////////// Functions /////////////////////////

// Function that creates and prints the addition or subtraction question
void addsub(){
		// Initialise numbers 1 and 2 with random numbers within a
		// range according to current level
	int 	number1 = randNum(params1[level][0],params1[level][1]),
		number2 = randNum(params1[level][0],params1[level][1]),
		// Initialise operand varable with random number from 1 to 10
		operand = randNum(1,10);

	// If operand is even add numbers 1 and 2
	if (operand % 2 == 0){
		// Update answer with added numbers
		answer = number1 + number2;

		// Print addition sum
		printf("\n(addition)\t%d + %d = ",number1,number2);

	// If operand is odd subtract smallest number from largest
	}else{
		if(number1 < number2){
			int tmp = number1;
			number1 = number2;
			number2 = tmp;
		}		
		// Update answer with subtracted numbers
		answer = number1 - number2;
		
		// Print subtraction sum
		printf("\n(subtraction)\t%d - %d = ",number1,number2);	
	}
}
// Function that creates and prints the multiplication question
void multiply(){	
	int 	number1,
		number2,
		ok=0;

	while(ok < 1){
		ok = 1;
		// Initialise number1 with random number within range according
		// to current level
		number1 = randNum(params2[level][0][0],params2[level][0][1]);
		int i;
		for(i=0;i<2;i++)				
			// If number equals excluded number, try again
			if(number1 == params2[level][2][i])
				ok = 0;	
	}		
	while(ok < 2){
		ok = 2;	
		// Initialise number2 with random number within range according
		// to current level
		number2 = randNum(params2[level][1][0],params2[level][1][1]);
		int i;
		for(i=0;i<10;i++)
			if(params2[level][3][i] == 0);
			// If number equals excluded number, try again
			else if(number2 == params2[level][3][i])
				ok = 1;
	}
	// Update answer with multiplied numbers
	answer = number1 * number2;
	// Print multiplication sum
	printf("\n(multiplication)\t%d x %d = ",number1,number2);
}
// Function that creates and prints the division question
void divide(){
	int 	number1,number2,number3,ok;
	do{
		ok = 1;
		// Initialise number1 (answer) with random number within range
		// according to current level 
		number1 = randNum(params3[level][0][0],params3[level][0][1]);
		// If number equals excluded number, try again
		if(number1 == params3[level][1][0] || number1 == params3[level][1][1] || number1 == params3[level][1][2])
			ok = 0;
	}while(ok != 1);
	do{
		// Initialise number2 (division number) with randomly selected 
		// number from params array
		number2 = params3[level][2][randNum(0,7)];
	// If number equales 0,try again
	}while(number2 == 0);

	// Initialise number3 (first number) by multiplying numbers 1 and 2
	number3 = number1 * number2;

	// Update answer with number1
	answer = number1;
	// Print division question
	printf("\n(division)\t%d / %d = ",number3,number2);
}
// Function that calls the related question function acording to the part variable
void callQuestion(){

	switch(part){
		case 1:
			addsub();
			break;
		case 2:
			multiply();
			break;
		case 3:
			divide();			
			break;	
	}		
}
// Function use to tidy and shorten the code, taking the address of a time variable
// add initialising it with the current seconds
void setsec(int *secs){
	time_t sec;
	sec = time (NULL);
	*secs = sec;
}
// Function for decreasing and printing the level veriable
void downLevel(){
	if(level > 0) level--;
	printf("\nLevel -1 - new level: %d",level+1);
}
// Function for increasing and printing the level variable 
void upLevel(){
	if(level < 9) level++;
	printf("\nLevel +1 - new level: %d",level+1);
}
// Function that calls the increase/decrease level functions depending on the time 
// stored in the question times array/list using the current question
void manageLevel(){
	if(times[question] <= upLevelSec)
		upLevel();
	else if(times[question] >= downLevelSec)
		downLevel();
	else printf("\nLevel : %d",level+1);
}
// Function for eveluation what part of the test the question is associated with,
// changing the part by using the current question and total questions variables
void manageParts(){
	if(question < totalQuestions/3)
		part = 1;
	else if(question >= totalQuestions/3 && question < (totalQuestions/3)*2)
		part = 2;
	else if(question >= (totalQuestions/3)*2)
		part = 3;
}
// Function for returning a random number using a min and max limit
int randNum(int min,int max){
	int number =0;		
	do{
		number = rand() % max + 1;
	}while(number < min);
	return number;
}
// Function for creating space between lines skipping the same number of lines
// as the value entered 
void pageDown(int lines){
	int i;
	for(i=0;i<lines;i++)
		printf("\n");
}
// Presents dynamic welcom message
void welcomMessage(){
	printf(	"This test has %d questions, the first %d  cover  addition\n",totalQuestions,totalQuestions/3);
	printf(	"and  subtraction,  the  next %d  will  be  multiplication\n",totalQuestions/3);
	printf(	"and the final %d will be division.  There  are  10 levels\n",totalQuestions - ((totalQuestions/3)*2));
	printf(	"and the first question starts at level 1. If  you answer\n");
	printf(	"the question within %d seconds the level will  increase,\n",upLevelSec);
	printf(	"however if you take too long, more than %d seconds, your\n",downLevelSec);
	printf(	"level will go down. The higher the level the harder the\n");
	printf(	"question,  the lower the level the easier the  question.\n");
	printf(	"Good luck!");
}
// Process input
void input(){
	int x = 0;
	int tmp;
	do{	
		tmp = scanf("%d", &answer_given);   	
		if(tmp)	
			x++;		
		else{
			printf("Enter a number\t");
			scanf ("%*[^\n]");	
		}	
	}while(x == 0);
}


