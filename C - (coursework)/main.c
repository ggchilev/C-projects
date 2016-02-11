#include <stdio.h>
//#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void numberOfSymbols(void);
int avg(void);
void comments(void);
void avgNumbers(void);
void letterschange(void);
char fname[100]; // masiv za imeto na faila koito iska da zapishe potrebitelq
int main(void)
{
    char enter;
    char choice;

    do{
         printf("Input file name (like '****.c'): ");
		 fscanf(stdin, "%s", fname); //prisvoqva vyvedenite simvoli ot potrebitelq i zadava ime na faila
    }while(fname[strlen(fname)-2]!='.'&&fname[strlen(fname)-1]!='c'); // proverqva dali imeto na faila zavyrshva s ".c"
      //strlen - dyljinata na strigna
      enter = getchar();
    do{
         enter = getchar();
         printf("\nChoose an option:\n");
         printf("1. Find the number of brackets, braces and slashes.\n");
         printf("2. Find the average number of symbols per row.\n");
         printf("3. Percentage symbols in comments / all symbols.\n");
         printf("4. Quit\n");

         printf("\nWhat's your choice?: ");
         choice=getchar();// prisvoqva 1-ta vyvedena stoinost za izbor ( edin edinstven znak )

         switch(choice){
                      case '1': {
                            printf ("\nYour choice is 1!\n\n"); //izvikva funkciqta rows
                            numberOfSymbols();break;
                            }
                       case '2': {
                            printf ("\nYour choice is 2!\n\n"); //izvikva funkciqta avgNumbers
                            avg();break;
                            }
                       case '3': {
                            printf ("\nYour choice is 3!\n\n");
                            comments();break; //izvikva funkciqta letterschange
                            }
                       case '4':{
                            printf("\nGoodbye\n\n");
                            return 0; //prekysva cikyla i spira programata
                            }
                       default: {
                                printf("\nInvalid choice\n\n");
                                }
         }
     }while(choice!=4);

     printf("\nGoodbye\n\n");

     system ("PAUSE");
     return 0;
}
void numberOfSymbols(void)
{
     FILE *fp, *out;
	 char c;
	 int leftBraces = 0;
	 int rightBraces = 0;
	 int leftBrackets = 0;
	 int rightBrackets = 0;
	 int slash = 0;
	 fp = fopen(fname,"r");
     out=fopen("Braces.txt","w");

	 if(fp==NULL){
                  printf("\nFAIL !!!\n\n");
	              exit(EXIT_FAILURE);
	             }
     do{
                  c = getc(fp);
                  if(c=='{') {
                      leftBraces += 1;
                  }
                    if(c=='}') {
                      rightBraces += 1;
                  }
                  if(c=='(') {
                      leftBrackets += 1;
                  }
                  if(c==')') {
                      rightBrackets += 1;
                  }
                  if(c=='/') {
                      slash += 1;
                  }


     }while(c!=EOF);

     fclose(fp);
     printf("There number of { is %d \n", leftBraces);
     printf("There number of } is %d \n", rightBraces);
     printf("There number of ( is %d \n", leftBrackets);
     printf("There number of ) is %d \n", rightBrackets);
     printf("There number of / is %d \n", slash);

     fprintf(out, "There number of { is %d \n", leftBraces);
     fprintf(out, "There number of } is %d \n", rightBraces);
     fprintf(out, "There number of ( is %d \n", leftBrackets);
     fprintf(out, "There number of ) is %d \n", rightBrackets);
     fprintf(out, "There number of / is %d \n", slash);
     fclose(out);

}
int avg(void)
{
     FILE *fp, *out;
	 char c;
	 int rows=0;
	 int allSymbols = 0;
	 fp = fopen(fname,"r");
     out = fopen("avgSymbols.txt", "w");

	 if(fp==NULL){
                  printf("\nFAIL !!!\n\n");
	              exit(EXIT_FAILURE);
	             }
     do{
                  c = getc(fp);
                  if(c == '\n'){
                  rows += 1;
                  }
                  else{
                      allSymbols += 1;
                      }

     }while(c!=EOF);

     fclose(fp);
     double avg = (double)allSymbols/rows;
     printf("The average symbols per row : %f \n", avg);
     fprintf(out, "The average symbols per row : %f \n", avg);
     return avg;
}

//3
void comments(void){
     FILE *fp, *out;
     char c;
     char nextc;
     int commentSymbols = 0;
     int allSymbols = 0;
     fp=fopen(fname, "r");
     out=fopen("comments.txt","w");//otvarq faila letters.c v rejim na pisane

     if(fp==NULL){
                  printf("\nThere is no text in text.txt\n\n");
                  exit(EXIT_FAILURE);
                  }
     else{
          do{
             c=fgetc(fp);
             if(feof(fp))break;
             if(c == '/'){
                 allSymbols += 1;
                 nextc = fgetc(fp);
                 if(nextc == '/'){
                 allSymbols += 1;
              do{
               c = fgetc(fp);
               commentSymbols += 1;
               allSymbols += 1;

              }while(c != '\n');
                 }
                 else{
                     allSymbols += 1;
             }
             }
             else{
             allSymbols += 1;
             }

          }while(c!=EOF);

     fclose(fp);//samo da vgignem malko procenta :D

     double percentage = (double)commentSymbols/allSymbols;//samo da vgignem malko procenta :D
     printf("\n comments/all symbols = %.2f%\n\n", percentage*100);//samo da vgignem malko procenta :D
     fprintf(out, "\n comments/all symbols = %.2f%\n\n", percentage*100);
     fclose(out);
     }
     }




