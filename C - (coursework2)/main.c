#include <stdio.h>
//#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int rows(void);
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
         printf("1. Find the longest row.\n");
         printf("2. Find the average number of numbers per row.\n");
         printf("3. Change lowercase letters to uppercase and uppercase letters to lowercase.\n");
         printf("4. Quit\n");

         printf("\nWhat's your choice?: ");
         choice=getchar();// prisvoqva 1-ta vyvedena stoinost za izbor ( edin edinstven znak )

         switch(choice){
                      case '1': {
                            printf ("\nYour choice is 1!\n\n"); //izvikva funkciqta rows
                            rows();break;
                            }
                       case '2': {
                            printf ("\nYour choice is 2!\n\n"); //izvikva funkciqta avgNumbers
                            avgNumbers();break;
                            }
                       case '3': {
                            printf ("\nYour choice is 3!\n\n");
                            letterschange();break; //izvikva funkciqta letterschange
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

//1
int rows(void)
{
     FILE *fp, *out;
	 char c;
	 int q=0;
	 fp = fopen(fname,"r");
	 out = fopen("rows.txt", "w");
	 int rowLength = 0;
	 int maxLength = 0;
	 int rowNum = 0;

	 if(fp==NULL){
                  printf("\nFAIL !!!\n\n");
	              exit(EXIT_FAILURE);
	             }
     do{
                  c = getc(fp);
                  rowLength += 1;
                  if(c=='\n') {
                      q++;
                      if(rowLength > maxLength){
                          maxLength = rowLength;
                          rowLength = 0;
                          rowNum = q;
                      }
                      else{
                          rowLength = 0;
                      }
                  }


     }while(c!=EOF);

     fclose(fp);
     printf("There are %d rows in the file \n", q);
     printf("The longest row is row N%d and has %d symbols", rowNum, maxLength-1);

     fprintf(out, "There are %d rows in the file \n", q);
     fprintf(out, "The longest row is row N%d and has %d symbols", rowNum, maxLength-1);

     return q;
}
//2
void avgNumbers(void)
{
     FILE *fp, *out;
	 char c;
	 int q=0;
	 fp = fopen(fname,"r");
	 out = fopen("avgNumbers.txt", "w");
	 int allNumbers = 0;

	 if(fp==NULL){
                  printf("\nFAIL !!!\n\n");
	              exit(EXIT_FAILURE);
	             }
     do{
                  c = getc(fp);
                  if(isdigit((c))){
                  allNumbers += 1;
                  }
                  if(c=='\n') {
                      q++;
                  }


     }while(c!=EOF);

     fclose(fp);
     double avg = (double)allNumbers/q;
     printf("Average numbers per row : %.1f ", avg);

     fprintf(out, "Average numbers per row : %.1f ", avg);

}

//3
void letterschange(void){
     FILE *fp, *out;
     char c;
     char nextc;
     fp=fopen(fname, "r");
     out=fopen("Letters.c","w");//otvarq faila letters.c v rejim na pisane

     if(fp==NULL){
                  printf("\nThere is no text in text.txt\n\n");
                  exit(EXIT_FAILURE);
                  }
     else{
          do{
             c=fgetc(fp);
             if(feof(fp))break;
             if(c == '/'){
                 fputc(c, out);
                 nextc = fgetc(fp);
                 if(nextc == '/'){
                 fputc(c, out);
              do{
               c = fgetc(fp);
               if((c>='A')&&(c<='Z')) fputc(tolower(c),out);
               else if((c>='a')&&(c<='z')) fputc(toupper(c),out);

             }while(c != '\n');
             }
             else{
             fputc(c, out);
             }
             }
             if(c != '/'){
             fputc(c, out);
             }

          }while(c!=EOF);

     fclose(fp);
     fclose(out);
     printf("\nFile was saved as Letters.c\n\n");
     }
     }




