// These are parameters used for configuring and balancing the test

int	totalQuestions 	= 15, // Total amount of questions
	upLevelSec	= 10, // Seconds to complete the question which will encrease the level	
	downLevelSec	= 25; // Seconds to complete the question before the level is dereased 

// This array is used for the adding and subtraction function and holds the 
// maximum and minimum values to generate the random numbers used in the question
			    /* random range*/
int 	params1[10][2] 	= {	{2,10},			// (0) level 1
				{11,30},		// (1) level 2
				{30,99},		// (2) level 3
				{50,150},		// (3) level 4
				{100,200},		// (4) level 5
				{100,300},		// (5) level 6
				{300,999},		// (6) level 7
				{1000,2000},		// (7) level 8
				{1000,10000},		// (8) level 9
				{10000,100000}};	// (9) level 10


// This array is used for the multiplication function and holds maximum and minimum 
// random number ranges for the numbers used in the sum as well as the excluded 
// numbers that may make a question to easy or hard for the level
		           	   /*random range - multiple range - range exclusions - multiple exclusions*/
int 	params2[10][4][10]	= {	{{1,10}		,{1,10}		,{0,0}		,{3,4,6,7,8,9,0,0,0,0}},
					{{3,9}		,{3,9}		,{5,0}		,{2,5,0,0,0,0,0,0,0,0}},
					{{2,9}		,{11,39}	,{0,0}		,{20,25,30,0,0,0,0,0,0,0}},
					{{2,5}		,{41,99}	,{0,0}		,{50,55,60,65,70,75,80,85,90,95}},
					{{2,5}		,{101,199}	,{0,0}		,{110,120,130,140,150,160,170,180,190,0}},
					{{11,39}	,{11,99}	,{20,30}	,{20,30,40,50,60,70,80,90,0,0}},
					{{11,99}	,{101,999}	,{20,50}	,{200,500,0,0,0,0,0,0,0,0}},
					{{11,99}	,{1001,9999}	,{20,50}	,{1200,1500,2500,2000,5000,5200,0,0,0,0}},
					{{101,999}	,{101,999}	,{200,500}	,{200,500,0,0,0,0,0,0,0,0}},
					{{101,999}	,{1001,9999}	,{200,500}	,{1200,1500,2500,2000,5000,5200,0,0,0,0}}};


// This array is for the division question function and holds a randon range for
// one number in the sum, exclusions for that number and a selection of numbers 
// of which one will be chosen at random for the other number in the sum
		      	  /*(pre multiple 1/answer)-(answer exclusions)-(pre multiple 2/sum 2nd number)*/
int	params3[10][3][8]	= {	{{3,10}		,{0,0,0}	,{2,5,0,0,0,0,0,0}},
					{{3,9}		,{0,0,0}	,{3,4,6,8,9,0,0,0}},
					{{11,21}	,{15,20,0}	,{2,3,4,5,6,7,8,9}},
					{{21,29}	,{0,0,0}	,{2,3,4,5,6,7,8,9}},
					{{31,39}	,{0,0,0}	,{2,3,4,5,6,7,8,9}},
					{{11,19}	,{0,0,0}	,{11,12,13,14,16,17,18,19}},
					{{21,29}	,{0,0,0}	,{11,12,13,14,16,17,18,19}},
					{{31,39}	,{0,0,0}	,{11,12,13,14,16,17,18,19}},
					{{41,49}	,{0,0,0}	,{11,12,13,14,16,17,18,19}},
					{{11,49}	,{20,30,40}	,{21,22,23,24,26,27,28,29}}};


