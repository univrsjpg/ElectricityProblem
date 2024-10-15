/* Hands-on 1
   Problem: Electricity

   Name: <TO DO: Replace this with your Lastname, Firstname>
   Section: <TO DO: Replace this with your section>
   
   Number of TO DOs: 4
   Total points: 15 pts
*/

#include <stdio.h>
#include "DIMAUNAHAN-Electricity.c"	/* replace this line with the actual filename
                               		you used.  For example, if the file containing
							   		your solution for all functions is in 
							   		SANTOS-Cost.c, then indicate
							   		#include "SANTOS-Electricity.c"
                            		*/

// Definition of constant for tax rate
#define TAX 0.12

int main()
{
	/* NOTE: Use the following variables.
			 You are not allowed to add, edit, or remove any of the variables.
	*/
	int nPreviousReading, nCurrentReading, nConsumption;
	float fGeneration, fTransmission, fSystemLoss, fDistribution, fSubsidies;
	float fBaseCharges, fTax, fTotal;
	
	printf("Previous Reading: ");
	scanf("%d", &nPreviousReading);
	// TO DO #1: Provide the code for getting the nPreviousReading (3 pts)
	
	printf("\nCurrent Reading: ");
	scanf("%d", &nCurrentReading);
	// TO DO #2: Provide the code for getting the nCurrentReading (3 pts)
	
	
	/* TO DO #3: Provide the assignment statement for nConsumption. 
			  You are required to call the computeConsumption(<parameter list>) 
			  function. (3 pts)
	*/
	
	nConsumption = computeConsumption(nPreviousReading, nCurrentReading);
	printf("\nActual Consumption: %d", nConsumption);
	
	/* TO DO #4: Provide the assignment statement for fBaseCharges. 
			  You are required to call the computeBaseCharges(<parameter list>) 
			  function. (6 pts)
	*/

	fBaseCharges = computeBaseCharges(nConsumption, &fGeneration, &fTransmission, &fSystemLoss, &fDistribution, &fSubsidies);
	fTax = fBaseCharges * TAX;
	fTotal = fBaseCharges + fTax;
	
	printf("\n%s%s%s", "----------", "----------", "----------");
	displayBillSummary(nConsumption, fGeneration, fTransmission, fSystemLoss, fDistribution, fSubsidies, fTax, fTotal);
	printf("%s%s%s\n", "----------", "----------", "----------");
		
	return 0;
}
