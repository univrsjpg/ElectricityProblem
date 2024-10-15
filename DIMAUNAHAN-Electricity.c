/* Hands-on 1
   Problem: Electricity

   Name: <TO DO: Replace this with your Lastname, Firstname>
   Section: <TO DO: Replace this with your section>
   
   Number of TO DOs: 3
   Total points: 35 pts
*/

#include <stdio.h>  //Do not remove or replace this line
/* General requirements and restrictions: 
   1. No other header files can be included in this file 
   2. You are not allowed to have main() in this file. 
   3. You are not allowed to create additional functions. 
   4. You are not allowed to modify the function prototypes and
      function headers provided.
   5. You are not allowed to use topics outside of the coverage
      (e.g., not allowed to use arrays).
*/

// Definition of constants for the prices of the 5 rate components
#define GENERATION 7.00
#define TRANSMISSION 0.83
#define SYSTEMLOSS 0.50
#define DISTRIBUTION 1.00
#define SUBSIDIES 0.17


/* TO DO #1: Write the implementation for computeConsumption() function. (5 pts) 

   This function should return the electricity consumption based
   on the previous and current meter readings.
   
   Assumptions: nCurrentReading >= nPreviousReading
   @param nPreviousReading - value of the previous meter reading
   @param nCurrentReading - value of the previous meter reading
   @return electricity consumption

   Restrictions: No printf() allowed in this function.
   
   Example 1: nPreviousReading = 15294, nCurrentReading = 15461; function returns 167
   Example 2: nPreviousReading = 4039, nCurrentReading = 6350; function returns 2311
*/
int computeConsumption(int nPreviousReading, int nCurrentReading)
{
   return nCurrentReading-nPreviousReading;
}


/* TO DO #2: Write the implementation for computeBaseCharges() function. (20 pts) 

   This function should take in 5 pointers for the 5 rate components (i.e. Generation,
   Transmission, System Loss, Distribution, and Subsidies), and updates their values by
   multiplying the electricity consumption by the their respective prices as listed above
   in the "Definition of constants for the prices of the 5 rate components".
   Then, it should return the total base charges by summing up all the base charges
   for the rate components.
   
   Assumption: nConsumption >= 0
   @param nConsumption - value of the previous meter reading
   @param pGeneration - address where the computed generation charge will be placed
   @param pTransmission - address where the computed transmission charge will be placed
   @param pSystemLoss - address where the computed system loss charge will be placed
   @param pDistribution - address where the computed distribution charge will be placed
   @param pSubsidies - address where the computed subsidies charge will be placed
   @return total base charges

   Restrictions: No printf() allowed in this function.
   
   Example 1: nConsumption = 167; function updates the pointer variables with the 
   					corresponding computations, function returns 1586.50
   Example 2: nConsumption = 2311; function updates the pointer variables with the 
   					corresponding computations, function returns 21954.50
*/
float computeBaseCharges(int nConsumption, float* pGeneration, float* pTransmission, float* pSystemLoss, float* pDistribution, float* pSubsidies)
{
   *pGeneration = nConsumption*GENERATION;
   *pTransmission = nConsumption*TRANSMISSION;
   *pSystemLoss = nConsumption*SYSTEMLOSS;
   *pDistribution = nConsumption*DISTRIBUTION;
   *pSubsidies = nConsumption*SUBSIDIES;

   return (*pGeneration + *pTransmission + *pSystemLoss + *pDistribution + *pSubsidies);
}


/* TO DO #3: Write the implementation for displayBillSummary() function. (10 pts) 

   This function should display the bill computation summary.
   
   Assumption: nConsumption >= 0
   @param nConsumption - value of the previous meter reading
   @param fGeneration - value of generation charge
   @param fTransmission - value of transmission charge
   @param fSystemLoss - value of system loss charge
   @param fDistribution - value of distribution charge
   @param fSubsidies - value of subsidies charge
   @param fTax - value of tax
   @param fTotal - value of total amount due

   Requirements:
   - The total number of characters per line is 30
   - The amounts must be right-aligned
   - The amounts must be limited to 2 decimal places
   
   Example 1: nConsumption = 167, fGeneration = 1169.00, fTransmission = 138.61,
	   fSystemLoss = 83.50, fDistribution = 167.00, fSubsidies = 28.39, fTax = 190.38,
	   fTotal = 1776.88; function displays:
   	------------------------------
	Bill Computation Summary
	
	Generation             1169.00
	Transmission            138.61
	System Loss              83.50
	Distribution            167.00
	Subsidies                28.39
	Tax                     190.38
	
	Total Amount Due       1776.88
	------------------------------
   
   Example 2: nConsumption = 3211, fGeneration = 16177.00, fTransmission = 1918.13,
	   fSystemLoss = 1155.50, fDistribution = 2311.00, fSubsidies = 392.87, fTax = 2634.54,
	   fTotal = 24589.04; function displays:
   	------------------------------
	Bill Computation Summary
	
	Generation            16177.00
	Transmission           1918.13
	System Loss            1155.50
	Distribution           2311.00
	Subsidies               392.87
	Tax                    2634.54
	
	Total Amount Due      24589.04
	------------------------------
*/
void displayBillSummary(int nConsumption, float fGeneration, float fTransmission, float fSystemLoss, float fDistribution, float fSubsidies, float fTax, float fTotal)
{
   printf("\nBill Computation Summary\n\n");
   printf("%-22s %7.2f\n", "Generation", fGeneration);
   printf("%-23s %6.2f\n", "Transmission", fTransmission);
   printf("%-23s %6.2f\n", "Distribution", fDistribution);
   printf("%-23s %5.2f\n", "Subsidies", fSubsidies);
   printf("%-23s %6.2f\n", "Tax", fTax);

   printf("\n%-22s %7.2f\n", "Total Amount Due", fTotal);

}
