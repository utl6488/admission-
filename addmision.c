#include<stdio.h>
#include<stdlib.h>
#include "addmission.h"
int main()
{
  int ch,i;
//int count=0;
char cp,snm[40];
FILE *fpt;
struct course c;
struct student s;
struct trainer t;
struct batch b;
  do
	{  
	  printf("\nchoice are: \n1.add course  \n2.showall course \n3.remove course \n4.add student \n5.showall student \n6.remove student \n7.add trainer\n8.showall trainer \n9.remove trainer \n10.add batch \n11.showall batch \n12.remove batch:");
	  scanf("%d",&ch);
  switch(ch)
		{
		  case 1:
			add_course(&c);
			break;
		  
		 case 2:
			
		
			fpt=fopen("course.dat","rb");
			if(fpt==NULL)
	  		{
	    		printf("\nerror in opening file:");
			}
			else
	 		 {
			  rewind(fpt);
                           printf("\nnr\t\tName\t\tDuration\t\tFees\n");

	 		  while(fread(&c,sizeof(struct course),1,fpt))
					{   
					   showall_course(c);
					}
		         }
			fclose(fpt);
			break;
			

		case 3:
		        printf("Enter name of course : ");
                        scanf("%s",snm);
                	remove_course(c,snm);
		        break;


	     
		case 4:
			add_student(&s);
			break;

	
		case 5:
			fpt=fopen("student.dat","rb");
			if(fpt==NULL)
			{
			 printf("\n error in opening file:");
			}
			else
			{
			 rewind(fpt);
			 printf("\nstudent ID \tstudent name \tstudent mob.no \tstudent result\n:");
			 while(fread(&s,sizeof(struct student),1,fpt))
			{
			 showall_student(s);
			}
			}
			fclose(fpt);
			break;

		
		case 6:
		        printf("Enter name of student : ");
                        scanf("%s",snm);
                	remove_student(s,snm);
		        break;



		case 7:
			add_trainer(&t);
			break;



	       case 8:
			fpt=fopen("trainer.dat","r+");
			if(fpt==NULL)
			{
			 printf("\n error in opening file:");
			}
			else
			{
			 rewind(fpt);
			 printf("\ntrainer name \ttrainer address \tmob.no \tcourse name:\n");
			 while(fread(&t,sizeof(struct trainer),1,fpt))
			{
			 showall_trainer(t);
			}
			}
			fclose(fpt);
			break;



	     
		case 9:
		        printf("Enter name of trainer : ");
                        scanf("%s",snm);
                	remove_trainer(t,snm);
		        break;

	     case 10:
			add_batch(&b);
			break;


	    case 11:
			fpt=fopen("batch.dat","r+");
			if(fpt==NULL)
			{
			 printf("\n error in opening file:");
			}
			else
			{
			 rewind(fpt);
			 printf("\n\tbatch name \ttrainer name \tbatch time:");
			 while(fread(&b,sizeof(struct batch),1,fpt))
			{
			 showall_batch(b);
			}
			}
			fclose(fpt);
			break;


	case 12:
		        printf("Enter name of batch : ");
                        scanf("%s",snm);
                	remove_batch(b,snm);
		        break;


	      }
		
		}while(ch<=12);
		
		}












