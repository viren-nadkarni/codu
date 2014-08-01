/*  An insurance company maintains 3 types of policies:
 *  1) Life insurance
 *  	beneficiary name, loyalty benefit
 *  2) Vehicle
 *  	model number, model name, depreciation(%)
 *  3) Home/fire
 *  	year of construction, property value
 *  Common information in all 3 cases is
 *  	policy number, holder name, date of birth (date,month,year), address(city,state,pincode)
 *  Use command line arguments to get number of entries to be entered. Increase all life insurance by 10% and decrease all home insurance by 5%
 *  Print details in tabular form
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
	int n, i;
	
	if(argc!=2)
	{
		printf("\nCorrect usage:\n%s <number of entries to be entered>\n", argv[0]);
		printf("Enter the number of entries to be entered: ");
		scanf("%d",&n);
	}
	else
		n = atoi(argv[1]);
	
	struct Dob
	{
		int day,month,year;
	};
	
	struct Address
	{
		char city[20], state[20];
		int pincode;
	};
	
	struct Life
	{
		char benefic_name[30];
		int loy_benefit;
	};
	
	struct Vehicular
	{
		int model_number;
		char model_name [20];
		float depreciation;
	};
	
	struct Home
	{
		int year;
		int value;
	};
	
	struct Policy
	{
		int policy_number;
		char policy_holder[40];
		
		struct Dob d;
		struct Address a;
		
		int type;
		
		union PolicyInfo
		{
			struct Life l;
			struct Vehicular v;
			struct Home h;
		} pi;
		
	} list[20];
		
	for (i=0;i<n;++i)
	{
		printf("\n_Entry no. %d_\nEnter the details:\n  Policy number: ",i+1);
		scanf("%d",&list[i].policy_number);
		
		printf("  Policy holder: ");
		scanf("%s",list[i].policy_holder);
		
		printf("  Date of birth (DD MM YYYY): ");
		scanf("%d %d %d", &list[i].d.day, &list[i].d.month, &list[i].d.year);
		
		printf("  Address\n    City: ");
		scanf("%s",list[i].a.city);
		printf("    State: ");
		scanf("%s",list[i].a.state);
		printf("    Pincode: ");
		scanf("%d",&list[i].a.pincode);
		
		printf("  Type of insurance (1)Life (2)Vehicular (3)Home: ");
		scanf("%d",&list[i].type);
		
		switch(list[i].type)
		{
			case 1:
				printf("  Beneficiary Name: ");
				scanf("%s",list[i].pi.l.benefic_name);
				printf("  Loyalty benefit: ");
				scanf("%d",&list[i].pi.l.loy_benefit);
				break;
			case 2:
				printf("  Model number: ");
				scanf("%d",&list[i].pi.v.model_number);
				printf("  Model name: ");
				scanf("%s",list[i].pi.v.model_name);
				printf("  Depreciation (%%): ");
				scanf("%f",&list[i].pi.v.depreciation);
				break;
			case 3:
				
				printf("  Year of construcion: ");
				scanf("%d",&list[i].pi.h.year);
				printf("  Property value: ");
				scanf("%d",&list[i].pi.h.value);
				break;
			
		}		
	}
	
	printf("\nAll life insurance values will be increased by 10%%\nAll home insurance values will be decreased by 5%\n");
	
	printf("\n#\tHolder\t\tType(L/V/H)\t\tLoyalty\t\tDepreciation\tProperty Value");
	
	for(i=0;i<n;++i)
	{
		printf("\n%d \t%s \t",list[i].policy_number,list[i].policy_holder);
		switch(list[i].type)
		{
			case 1:
			{
				printf("\tL\t\t");
				printf("Before:\t%d\t\t\t\n\t",list[i].pi.l.loy_benefit);
				list[i].pi.l.loy_benefit+=(list[i].pi.l.loy_benefit)*10/100;
				printf("\t\t\t\tAfter:\t%d\t\t\t\n",list[i].pi.l.loy_benefit);
				break;
			}
			
			case 2:
			{
				printf("\tV\t\t");
				printf("Before:\t\t\t%f\t\n\t",list[i].pi.v.depreciation);
				printf("\t\t\t\tAfter:\t\t\t%f\t\n",list[i].pi.v.depreciation);
				break;
			}
			
			case 3:
			{
				printf("\tH\t\t");
				printf("Before:\t\t\t\t\t%d\n\t",list[i].pi.h.value);
				list[i].pi.h.value-=(list[i].pi.h.value)*5/100;
				printf("\t\t\t\tAfter:\t\t\t\t\t%d\n",list[i].pi.h.value);
				break;
			}
			
		}
	}
	
	return 0;
}
