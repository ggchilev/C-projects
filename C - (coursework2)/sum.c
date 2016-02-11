#include <stdio.h>
//#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void input(void); //funkcii koito se izpolzvat v main() funkciqta
void dlcs(void);
int rows(void);
void avgnum(void);
void letterschange(void); // do tuk vkliuchitelno .. opisani sa pod neq
char fname[100]; // masiv za imeto na faila koito iska da zapishe potrebitelq
int main(void)
{
    //char filename;
    char choice;


    do{
         printf("Input file name (like '****.c'): ");
		 fscanf(stdin, "%s", fname); //prisvoqva vyvedenite simvoli ot potrebitelq i zadava ime na faila
    }while(fname[strlen(fname)-2]!='.'&&fname[strlen(fname)-1]!='c'); // proverqva dali imeto na faila zavyrshva s ".c"
    printf("%s", fname);
      //strlen - dyljinata na strigna
      //filename = getchar();
    do{
         printf("\nChoose an option:\n");
         printf("1. Input source code in ***.c\n");
         printf("2. Find the number of numbers/letters - the capital and non-capital letters.\n");
         printf("3. Find the average number of capital and non-capital letters.\n");
         printf("4. Change lowercase letters to uppercase and uppercase letters to lowercase.\n");
         printf("5. Quit\n");

         printf("\nWhat's your choice?: ");
         choice=getchar();// prisvoqva 1-ta vyvedena stoinost za izbor ( edin edinstven znak )

         switch(choice){
                      case '9': {
                            printf ("\nYour choice is 9!\n\n"); //izvikva funkciqta input
                            rows();break;
                            }
                       case '1': {
                            printf ("\nYour choice is 1!\n\n"); //izvikva funkciqta input
                            input();break;
                            }
                       case '2': {
                            printf ("\nYour choice is 2!\n\n");
                            avgNumbers();break; //izvikva funkciqta dlcs
                            }
                       case '3': {
                            printf ("\nYour choice is 3!\n\n");
                            avgnum();break; // tuk avgnum
                            }
                       case '4':{
                            printf ("\nYour choice is 4!\n\n");
                            letterschange();break;	// analogichno
                            }
                       case '5':{
                            printf("\nGoodbye\n\n");
                            return 0; //prekysva cikyla i spira programata
                            }
                       default: {
                                printf("\nInvalid choice\n\n");
                                }
         }
     }while(choice!=5);

     printf("\nGoodbye\n\n");

     system ("PAUSE");
     return 0;
}
void input(void)
{
     FILE *in, *out;
     int c;
     in=stdin; //prisvoqva vyvejdanite stoinosti ot klaviaturata
     out=fopen(fname, "w"); //otvarq fail s imeto na promenlivata fname ( ako nqma takyv go syzdava )
     if(out==NULL){
                   printf("FAIL !!!");
                   exit(EXIT_FAILURE);
                  } //proverka dali failyt e syzdaden
     else{
          printf("\nInput text: ");
          do{
                          c=fgetc(in); //vzima simvola ot klaviaturata koito e vyveden
                          if(feof(in))break; // ako e Ctrl + Z prekratqva cikyla
                          fputc(c,out); // postavq tozi simvol vyv faila
          }while (c!=EOF);
          printf("\nThe input was saved!\n\n");
         }
          fclose(in);
          fclose(out);//zatvarq failovete
}
//2
/*void dlcs(void)
{
     FILE *fp;
	 char c;
     int  numbers=0;

     fp=fopen(fname,"r"); //otvarq faila v rejim na chetene

     if(fp==NULL){
                  printf("\nFAIL !!!\n\n");
                  exit(EXIT_FAILURE);
                 }// ako ne syshtestvuva prekysva programata

     do{
         c=getc(fp);//vzima ti simvol ot faila

         do{
                     c=getc(fp);
                     if(isdigit(c)) numbers++; //isdigit - ako e chislo ...

         }while(c!='\n'); // cikylyt se povtarq do dostiganeto na nov red


         line++;
         printf("\n\nLine number %d\n", line);
         printf("\nThe number of numbers is: %d", numbers);
         printf ("\n");

         numbers=0;

     }while(c!=EOF);        // cikylyt se povtarq do dostigane kraq na faila

     fclose(fp);
}*/
void avgnum(void)
{
     FILE *fp;
	 int c;
	 float q=0, n=0;
	 fp=fopen(fname,"r");//otvarq faila v rejim na chetene

	 if(fp==NULL){
                  printf("\nFAIL !!!\n\n");
	              exit(EXIT_FAILURE);
	             }
     do{
                  c=getc(fp);
                  if(c>='0' && c<='9') n++;
     }while(c!=EOF);

     fclose(fp);//zatvarq ti faila
     q=rows();//izvikva ti funkciqta za broq na redovete
     printf("\n\nThe average number of Uppercase letters per line is: %.2f", n/q);
     printf("\n\n");
}
//1
int rows(void)
{
     FILE *fp;
	 char c;
	 int q=0;
	 fp = fopen(fname,"r");
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

     return q;
}
void avgNumbers(void)
{
     FILE *fp;
	 char c;
	 int q=0;
	 fp = fopen(fname,"r");
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
     printf("%d\n", allNumbers);
     printf("%d\n", q);
     printf("Average numbers per row : %.1f ", avg);

}
/*
void letterschange(void){
     FILE *fp, *out;
     int c;
     fp=fopen(fname, "r");
     out=fopen("Letters.txt","w");//otvarq faila letters.c v rejim na pisane

     if(fp==NULL){
                  printf("\nThere is no text in text.txt\n\n");
                  exit(EXIT_FAILURE);
                  }
     else{
          do{
             c=fgetc(fp);
             if(feof(fp))break;
             if(c == "/"){
                     do{

                     if((c>='A')&&(c<='Z')) fputc(tolower(c),out);
                     else if((c>='a')&&(c<='z')) fputc(toupper(c),out);
                     }while(c != "\n");
             }
          }while(c!=EOF); // zapisva malkite bukvi kato glavni i glavnite kato malki v Letters.c

     fclose(fp);
     fclose(out);
     printf("\nFile was saved as Letters.c\n\n");
     }
}*/

void letterschange(void){
     FILE *fp, *out;
     int c;
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
             if((c>='A')&&(c<='Z')) fputc(tolower(c),out);
             else if((c>='a')&&(c<='z')) fputc(toupper(c),out);
          }while(c!=EOF); // zapisva malkite bukvi kato glavni i glavnite kato malki v Letters.c

     fclose(fp);
     fclose(out);
     printf("\nFile was saved as Letters.c\n\n");
     }
}



