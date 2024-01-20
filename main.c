#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int fillarrays();// Function to read the data from the file and fill the data into arrays
void menu();// Function to display the menu
void swap(int ,int );// Function to swap the data
void sortid();// Function to sort data in ascending order according to students' IDs
void sortName();// Function to sort data in ascending order according to students' names
void sortScore();// Function to sort data in descending order according to students' scores
void searchId();// Function to find the student ID and display his score
void searchName();// Function to find the student name and display his score
void print();// Function to print ID,name and score
int findlines(char *);// Function to find the number of lines in the file
int id[1000]={0};// Define student ID and make their value equal zero
char name[1000][50];// Define name of the student with size 1000 about the lines and size 50 to one line
double score[1000]={0};// Define student's score and make their score equal zero
int lines=0;// Define the lines and make it's value equal zero
 int main()// main
{
 if (fillarrays()==1)// If the function fill data into arrays and return 1
 {
int choice;// Define choice
char ans;// Define answer (the user answer to save data into a file or not )
 do // Do loop
 {
 menu();// To call function to display the menu
 scanf("%d",&choice);// Ask the user to enter his/her choice about the data
if(choice==1)// If the user entered 1
{
sortid();// Call function to sort data in ascending order according to students' IDs
print();// Call function to print ID,name and score
printf("\n Are you want to save the result? y for yes or n for no \n");// If the user want to save a result in a file(y or n)
scanf(" %c",&ans);// The answer of the user
if(ans=='y')// If the user enter yes (y)
  {
   FILE *fp;// Define the file
   char output[50];// Define output of size 50
   printf("Please enter the name file.txt to save the result\n");// Ask user to enter the file name to save the result
   scanf("%s",output);
   fp = fopen(output,"w");// Open this file in reading mode
for(int i=0;i<lines+1;i++)// For loop to print the data in a file
     {
    fprintf(fp, "%d   %s   %f\n", id[i], name[i],score[i]);// Print the data in a file
     }
    fclose(fp);// Close the file input file
  }
}
else if(choice==2)// If the user entered 2
{
sortName();// Call function to sort data in ascending order according to students' names
print();// Call function to print ID,name and score
printf("\n are you want to save the result?  y for yes or n for no \n");// If the user want to save a result in a file(y or n)
scanf(" %c",&ans);// The answer of the user
if(ans=='y')// If the user enter yes (y)
  {
   FILE *fp;// Define the file
char output[50];// Define output of size 50
   printf("Please enter the name file.txt to save the result\n");// Ask user to enter the file name to save the result
   scanf("%s",output);
   fp = fopen(output,"w");// Open this file in reading mode
for(int i=0;i<lines+1;i++)// For loop to print the data in a file
      {
    fprintf(fp, "%d   %s   %f\n", id[i], name[i],score[i]);// Print the data in a file
      }
    fclose(fp);// Close the file input file
  }
}
else if(choice==3)// If the user entered 3
{
sortScore();// Call function to sort data in descending order according to students' scores
print();// Call function to print ID,name and score
printf("\n are you want to save the result?  y for yes or n for no\n");// If the user want to save a result in a file(y or n)
scanf(" %c",&ans);// The answer of the user
if(ans=='y')// If the user enter yes (y)
  {
   FILE *fp;// Define the file
   char output[50];// Define output of size 50
   printf("Please enter the name file.txt to save the result\n");// Ask user to enter the file name to save the result
   scanf("%s",output);
   fp = fopen(output,"w");// Open this file in reading mode
for(int i=0;i<lines+1;i++)// For loop to print the data in a file
       {
    fprintf(fp, "%d   %s   %f\n", id[i], name[i],score[i]);// Print the data in a file
       }
    fclose(fp);// Close the file input file
  }
}
else if(choice == 4)// If the user entered 4
 {
searchId();// Call Function to find the student ID and display his score
 }
else if(choice==5)// If the user entered 5
 {
  searchName();//Call function to find the student name and display his score
 }
 }
 while(choice!=6);// If the user  not enter 6
 printf("BYE\n");// Exit the program
 return 0;
}
}
int fillarrays()// Function to read the data from the file and fill the data into arrays
{
  int i=0,c=0;// Define i and define c,lines and make initial value equal zero
  char buf[255];// Define buf and it is the length of the line in the file and max size is 255
  int ass=0,quiz=0,mid=0,prac=0,finalm=0;// Define assigment,quizzes,midterm,practical exam and final exam and it's initial values equal zero
  FILE *fptr;// Define the file
  char filename[255];// Define the name of the file that the user is going to enter it and the size is 255
  printf("Please enter the file name.txt\n");// Ask user to enter the file name that he/she wanted to open and read
  scanf("%s",filename);// User entered the name of the file that he/she wanted to open and read
  fptr=fopen(filename,"r");// Open this file in reading mode
if(fptr==NULL)// If the user entered the name of a file and this name is not found
  {
      printf("No file is found\n");// There is no file contains this name!!
      return 0;
  }
else
  {
    lines=findlines(filename);// Call functuion to find the number of lines in the file
    printf("The number of lines in the file is %d \n\n",lines+1);// Print the number of the lines in the file
    printf("\tid            name                scores\n\n ");// id,name and score
    while(i<=lines)
    {
      fgets(buf,255,fptr);// To read the lines from the file
      char *p=strtok(buf,"$");// To separate the data in a file by ($) save in p
      while(p)// P not equal NULL
       {
      printf("\t%s",p);//Print each part separately
 if(c==0)//Student ID
         {
 	      id[i]=atoi(p);// Function to converts character into integer(id become int)
         }
else if(c==1)//Student name
         {
          for(int j=0;j<strlen(p);j++)// Save the names in array
 	       name[i][j]=p[j];
 	       // or strcpy(name[i],p);
         }
else if(c==2)// Assigment
         {
	      ass=atoi(p);// Function to converts character into integer(assigment become int)
         }
         else if(c==3)// Quizzez
         {
 	      quiz=atoi(p);// Function to converts character into integer(quizzez become int)
         }
         else if(c==4)//Midterm
         {
 	      mid=atoi(p);// Function to converts character into integer(midterm become int)
         }
         else if(c==5)// Practical exam
         {
 	      prac=atoi(p);// Function to converts character into integer(practical exam become int)
         }
        else //if(c==6)// Final exam
        {
 	     finalm=atoi(p);// Function to converts character into integer(final exam become int)
        }
 	    p=strtok(NULL,"$");// Go to the next and check $
 	    c++; // Increment c
    }// End while(p)
  score[i]=(0.15*ass+0.15*quiz+0.25*mid+0.1*prac+0.35*finalm)*1.0; // The equation
   i++;// Increment i
   c=0;
   ass=quiz=mid=prac=finalm=0;
  }//End while(EOF)
 }//End else
fclose(fptr);// Close the file
return 1;
}
void menu()// Function to display the menu
{
	printf("\n1. Sort data in ascending order according to students' IDs\n");
	printf("2. Sort data in ascending order according to students' names\n");
	printf("3. Sort data in descending order according to students' scores\n");
	printf("4. Enter Student ID\n");
	printf("5. Enter student name\n");
	printf("6. Exit\n");
	printf("Enter your choice ....\n");
}
void swap(int i,int j)// Function to swap the data
{
 int tmp=id[i];// Swap student ID
 id[i]=id[j];
 id[j]=tmp;
 char st[50];

 strcpy(st,name[i]); // Swap student name
 strcpy(name[i],name[j]);
 strcpy(name[j],st);

 double scr=score[i];// Swap student scores
 score[i]=score[j];
 score[j]=scr;
}
void sortid()//Function to sort data in ascending order according to students' IDs
{
int i=0;// Define i
for(i=0;i<lines;i++)
 {
 	for(int j=0;j<lines-1;j++)// For loop to sort data in ascending order according to students' IDs
 	{
	 	if(id[j]>id[j+1])
	 	 swap(j,j+1);
	 }
 }
}
void print()// Function to print ID,name and score
{
 int i=0;// Define i
  printf("\t   \t\tThe average\n");
    while(id[i]!=0)// While student ID not equal zero
    {
        printf("  %d  %s  %f \n",id[i],name[i],score[i]);// print ID,name and score
        i++;// Increment i
    }
}
int findlines(char filename[])// Function to find a number of lines in the file
{
    FILE *fp;// Define the file
    int lcount = 0;// Define Icount and make it equal zero
    char ch;// Define ch
    fp = fopen(filename, "r");// Opent this file in reading mode
    while((ch=fgetc(fp))!=EOF) // To read untill end of file
        {
      if(ch=='\n')// End of the line
         lcount++;// Increment lcount
        }
   fclose(fp);// Close the file
    return lcount;// Return number of line
}
void sortName()// Function to sort data in ascending order according to students' names
{
 int i=0;// Define i
 for(i=0;i<=lines;i++)
 {
 	for(int j=0;j<=lines-1;j++)// For loop to sort data in ascending order according to students' names
 	{
	 	if(strcmp(name[j],name[j+1])==1)// First name > Second name returned 1
	 	 swap(j,j+1);
	 }
 }
}
void sortScore()// Function to sort data in descending order according to students' scores
{
 int i=0;// Define i
 for(i=0;i<lines;i++)
 {
 	for(int j=0;j<lines-1;j++)// For loop to sort data in descending order according to students' scores
 	{
	 	if(score[j]<score[j+1])
	 	 swap(j,j+1);
	 }
 }
}
void searchId()// Function to find the student ID and display his score
{
 int num,flag=0;// Define num and flag equal zero
 printf("Enter student ID \n");
 scanf("%d",&num);
 for(int i=0;i<lines+1;i++)
  {
  	if(id[i]==num)// If the number entered exist
    {
	  flag=1;
printf("The average of id %d is %f\n",num,score[i]);// Print his score
	  break;// Exit
    }
  }
  if(flag==0)// If the number entered not exist
   printf("This ID is not found\n");
}
void searchName()// Function to find the student name and display his score
{
    char f[50],L[50];// Define first name,second name with size 50
    int flag=0;// Define flag and it's value equal zero
    printf("\nPlease enter the first name with capital letter:");
    scanf("%s",f);
    printf("Please enter the last name with capital letter:");
    scanf("%s",L);
    strcat(f," ");// To add first name with space to the last name
    strcat(f,L);
     for(int i=0;i<lines+1;i++)
  {
      if(strcmp(f,name[i])==0)// If the name entered exist
  	{
	  flag=1;
	  printf("The average of Student %s  = %f\n",name[i],score[i]);// Print his score
	  break;// Exit
    }
  }
  if(flag==0)// If the name entered not exist
   printf("This Name is not found\n");
}
// The end of project
// Mohammad Abu Shams
// 1200549
