
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct course
  {
	int course_nr;
	char course_name[30];
	int course_duration;
	float course_fee;

  };

void add_course(struct course *);
void showall_course(struct course );
void remove_course(struct course ,char *);

	
struct student
  {
	int student_ID;
	char student_name[30];
	char student_mob_nr[15];
	float student_result;
	
 };
void add_student(struct student *);
void showall_student(struct student );
void remove_student(struct student,char *);

	
struct trainer
 {
	char trainer_name[30];
	char address[30];
	char mob_no[15];
	char course_name[30];
 };
void add_trainer(struct trainer *);
void showall_trainer(struct trainer );
void remove_trainer(struct trainer,char *);

	
struct batch
 {
	char batch_name[30];
	char trainer_name[30];
	int batch_time;
 };
void add_batch(struct batch *);
void showall_batch(struct batch );
void remove_batch(struct batch,char *);
	

struct admission
  {
	char student_name[30];
   	char course_name[30];
	int admission_date;
	
  };



void add_course(struct course *c)
  {	
	FILE *fpt;
	fpt=fopen("course.dat","ab");
	if(fpt==NULL)
	  {
	    printf("\nerror in opening file:");
	  }
	else
	  {
	   
	
        printf("\n enter th nr of the course:");
	scanf("%d",&c->course_nr);
	printf("\n enter the name of the course:");
	scanf("%s",c->course_name);
	printf("enter the duration of the course:");
	scanf("%d",&c->course_duration);
	printf("\n enter the fee of the course:");
	scanf("%f",&c->course_fee);
       fwrite(c,sizeof(struct course),1,fpt);
	
         }
	fclose(fpt);
  }


void showall_course(struct course c)

{	
	   
 printf("\n\t%d\t%s\t%d\t%f\n",c.course_nr,c.course_name,c.course_duration,c.course_fee);


}

void remove_course(struct course c,char *snm)
{
  	 int i;
	 FILE *fpt;
	 FILE *fp;
	  fpt=fopen("course.dat","rb");
	if(fpt==NULL)
	  {
	    printf("\nerror in opening file:");
	  }
	else
	{
	  fp=fopen("temp.dat","wb");
	  while(!feof(fpt))
		{
	   fread(&c,sizeof(c),1,fpt);
	   if(strcmp(c.course_name,snm)==0)
	    {
              continue;
            }	    	
           else
            {
             fwrite(&c,sizeof(c),1,fp);
	    }
	}
      }
	fclose(fpt);
	fclose(fp);
	remove("course.dat");
	rename("temp.dat","course.dat");
	return;
  }




void add_student(struct student *s)
	{
	 FILE *fpt;
	 
	  fpt=fopen("student.dat","ab");
	if(fpt==NULL)
	  {
	    printf("\nerror in opening file:");
	  }
	else
	  {
	   	

	printf("\n enter the ID of the student:");
	scanf("%d",&s->student_ID);
	printf("enter the name of the student:");
	scanf("%s",s->student_name);
	printf("\n enter the mob.no of the student:");
	scanf("%s",s->student_mob_nr);
	printf("\n enter the result of the student:");
	scanf("%f",&s->student_result);
       fwrite(s,sizeof(struct student),1,fpt);
	
         }
	fclose(fpt);
  }


 void showall_student(struct student s)
	{
	 		   
	   printf("%d\t%s\t%s\t%f\n",s.student_ID,s.student_name,s.student_mob_nr,s.student_result);

   
	    
	}

void remove_student(struct student s,char *snm)
{
  	 int i;
	 FILE *fpt;
	 FILE *fp;
	  fpt=fopen("student.dat","rb");
	if(fpt==NULL)
	  {
	    printf("\nerror in opening file:");
	  }
	else
	{
	  fp=fopen("temp.dat","wb");
	  while(!feof(fpt))
		{
	   fread(&s,sizeof(s),1,fpt);
	   if(strcmp(s.student_name,snm)==0)
	    {
              continue;
            }	    	
           else
            {
             fwrite(&s,sizeof(s),1,fp);
	    }
	}
      }
	fclose(fpt);
	fclose(fp);
	remove("student.dat");
	rename("temp.dat","student.dat");
	return;
  }



void add_trainer(struct trainer *t)
	{

	   {
	  FILE *fpt;
	  fpt=fopen("trainer.dat","ab");
	if(fpt==NULL)
	  {
	    printf("\nerror in opening file:");
	  }
	else
	  {
	   
	

	   printf("\n enter the name of the trainer:");
	   scanf("%s",t->trainer_name);
	   printf("\n enter the trainer address:");
	   scanf("%s",t->address);
	   printf("\n enter the mob.no of the trainer:");
	   scanf("%s",t->mob_no);
	   printf("\n enter the course name :");
	   scanf("%s",t->course_name);
	   fwrite(t,sizeof(struct trainer),1,fpt);
	
         }
	fclose(fpt);
  }
	}

void showall_trainer(struct trainer t)
	{
	   printf("%s\t%s\t%s\t%s\n",t.trainer_name,t.address,t.mob_no,t.course_name);


	 
	}




void remove_trainer(struct trainer t,char *snm)
{
  	 int i;
	 FILE *fpt;
	 FILE *fp;
	  fpt=fopen("trainer.dat","rb");
	if(fpt==NULL)
	  {
	    printf("\nerror in opening file:");
	  }
	else
	{
	  fp=fopen("temp.dat","wb");
	  while(!feof(fpt))
		{
	   fread(&t,sizeof(t),1,fpt);
	   if(strcmp(t.trainer_name,snm)==0)
	    {
              continue;
            }	    	
           else
            {
             fwrite(&t,sizeof(t),1,fp);
	    }
	}
      }
	fclose(fpt);
	fclose(fp);
	remove("trainer.dat");
	rename("temp.dat","trainer.dat");
	return;
  }



void add_batch(struct batch *b)
	{
	 
	   {
	  FILE *fpt;
	  fpt=fopen("batch.dat","ab");
	if(fpt==NULL)
	  {
	    printf("\nerror in opening file:");
	  }
	else
	  {
	    printf("\n enter the batch name:");
	    scanf("%s",b->batch_name);
	    printf("\n enter the traner name:");
	    scanf("%s",b->trainer_name);
	    printf("\n enter the batch time:");
	    scanf("%d",&b->batch_time);
	    fwrite(b,sizeof(struct batch),1,fpt);
	   }
	fclose(fpt);
	}
	}

void showall_batch(struct batch b)
	{	   
	   printf("\n%s\t%s\t%d\n",b.batch_name,b.trainer_name,b.batch_time);


	   
	}

void remove_batch(struct batch b,char *snm)
{
  	 int i;
	 FILE *fpt;
	 FILE *fp;
	  fpt=fopen("batch.dat","rb");
	if(fpt==NULL)
	  {
	    printf("\nerror in opening file:");
	  }
	else
	{
	  fp=fopen("temp.dat","wb");
	  while(!feof(fpt))
		{
	   fread(&b,sizeof(b),1,fpt);
	   if(strcmp(b.batch_name,snm)==0)
	    {
              continue;
            }	    	
           else
            {
             fwrite(&b,sizeof(b),1,fp);
	    }
	}
      }
	fclose(fpt);
	fclose(fp);
	remove("batch.dat");
	rename("temp.dat","batch.dat");
	return;
  }


