#include <stdio.h>
//INCLUDECONIOH
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void input(void); //FUNKCIIKOITOSEIZPOLZVATVMAINFUNKCIQTA
void dlcs(void);
int rows(void);
void avgnum(void);
void letterschange(void); //DOTUKVKLIUCHITELNOOPISANISAPODNEQ
char fname[100]; //MASIVZAIMETONAFAILAKOITOISKADAZAPISHEPOTREBITELQ
int main(void)
{
    //CHARFILENAME
    char choice;


    do{
         printf("Input file name (like '****.c'): ");
		 fscanf(stdin, "%s", fname); //PRISVOQVAVYVEDENITESIMVOLIOTPOTREBITELQIZADAVAIMENAFAILA
    }while(fname[strlen(fname)-2]!='.'&&fname[strlen(fname)-1]!='c'); //PROVERQVADALIIMETONAFAILAZAVYRSHVASC
    printf("%s", fname);
      //STRLENDYLJINATANASTRIGNA
      //FILENAMEGETCHAR
    do{
         printf("\nChoose an option:\n");
         printf("1. Input source code in ***.c\n");
         printf("2. Find the number of numbers//etters - the capital and non-capital letters.\n");
         printf("3. Find the average number of capital and non-capital letters.\n");
         printf("4. Change lowercase letters to uppercase and uppercase letters to lowercase.\n");
         printf("5. Quit\n");

         printf("\nWhat's your choice?: ");
         choice=getchar();//PRISVOQVATAVYVEDENASTOINOSTZAIZBOREDINEDINSTVENZNAK

         switch(choice){
                      case '9': {
                            printf ("\nYour choice is 9!\n\n"); //IZVIKVAFUNKCIQTAINPUT
                            rows();break;
                            }
                       case '1': {
                            printf ("\nYour choice is 1!\n\n"); //IZVIKVAFUNKCIQTAINPUT
                            input();break;
                            }
                       case '2': {
                            printf ("\nYour choice is 2!\n\n");
                            avgNumbers();break; //IZVIKVAFUNKCIQTADLCS
                            }
                       case '3': {
                            printf ("\nYour choice is 3!\n\n");
                            avgnum();break; //TUKAVGNUM
                            }
                       case '4':{
                            printf ("\nYour choice is 4!\n\n");
                            letterschange();break;	//ANALOGICHNO
                            }
                       case '5':{
                            printf("\nGoodbye\n\n");
                            return 0; //PREKYSVACIKYLAISPIRAPROGRAMATA
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
     in=stdin; //PRISVOQVAVYVEJDANITESTOINOSTIOTKLAVIATURATA
     out=fopen(fname, "w"); //OTVARQFAILSIMETONAPROMENLIVATAFNAMEAKONQMATAKYVGOSYZDAVA
     if(out==NULL){
                   printf("FAIL !!!");
                   exit(EXIT_FAILURE);
                  } //PROVERKADALIFAILYTESYZDADEN
     else{
          printf("\nInput text: ");
          do{
                          c=fgetc(in); //VZIMASIMVOLAOTKLAVIATURATAKOITOEVYVEDEN
                          if(feof(in))break; //AKOEcTRLzPREKRATQVACIKYLA
                          fputc(c,out); //POSTAVQTOZISIMVOLVYVFAILA
          }while (c!=EOF);
          printf("\nThe input was saved!\n\n");
         }
          fclose(in);
          fclose(out);//ZATVARQFAILOVETE
}
//
//void dlcs(void)
{
     FILE *fp;
	 char c;
     int  numbers=0;

     fp=fopen(fname,"r"); //OTVARQFAILAVREJIMNACHETENE

     if(fp==NULL){
                  printf("\nFAIL !!!\n\n");
                  exit(EXIT_FAILURE);
                 }//AKONESYSHTESTVUVAPREKYSVAPROGRAMATA

     do{
         c=getc(fp);//VZIMATISIMVOLOTFAILA

         do{
                     c=getc(fp);
                     if(isdigit(c)) numbers++; //ISDIGITAKOECHISLO

         }while(c!='\n'); //CIKYLYTSEPOVTARQDODOSTIGANETONANOVRED


         line++;
         printf("\n\nLine number %d\n", line);
         printf("\nThe number of numbers is: %d", numbers);
         printf ("\n");

         numbers=0;

     }while(c!=EOF);        //CIKYLYTSEPOVTARQDODOSTIGANEKRAQNAFAILA

     fclose(fp);
}*//void avgnum(void)
{
     FILE *fp;
	 int c;
	 float q=0, n=0;
	 fp=fopen(fname,"r");//OTVARQFAILAVREJIMNACHETENE

	 if(fp==NULL){
                  printf("\nFAIL !!!\n\n");
	              exit(EXIT_FAILURE);
	             }
     do{
                  c=getc(fp);
                  if(c>='0' && c<='9') n++;
     }while(c!=EOF);

     fclose(fp);//ZATVARQTIFAILA
     q=rows();//IZVIKVATIFUNKCIQTAZABROQNAREDOVETE
     printf("\n\nThe average number of Uppercase letters per line is: %.2f", n//);
     printf("\n\n");
}
//
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
     double avg = (double)allNumbers//;
     printf("%d\n", allNumbers);
     printf("%d\n", q);
     printf("Average numbers per row : %.1f ", avg);

}
//
void letterschange(void){
     FILE *fp, *out;
     int c;
     fp=fopen(fname, "r");
     out=fopen("Letters.txt","w");//OTVARQFAILALETTERSCVREJIMNAPISANE

     if(fp==NULL){
                  printf("\nThere is no text in text.txt\n\n");
                  exit(EXIT_FAILURE);
                  }
     else{
          do{
             c=fgetc(fp);
             if(feof(fp))break;
             if(c == "//){
                     do{

                     if((c>='A')&&(c<='Z')) fputc(tolower(c),out);
                     else if((c>='a')&&(c<='z')) fputc(toupper(c),out);
                     }while(c != "\n");
             }
          }while(c!=EOF); //ZAPISVAMALKITEBUKVIKATOGLAVNIIGLAVNITEKATOMALKIVlETTERSC

     fclose(fp);
     fclose(out);
     printf("\nFile was saved as Letters.c\n\n");
     }
}*//
void letterschange(void){
     FILE *fp, *out;
     int c;
     fp=fopen(fname, "r");
     out=fopen("Letters.c","w");//OTVARQFAILALETTERSCVREJIMNAPISANE

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
          }while(c!=EOF); //ZAPISVAMALKITEBUKVIKATOGLAVNIIGLAVNITEKATOMALKIVlETTERSC

     fclose(fp);
     fclose(out);
     printf("\nFile was saved as Letters.c\n\n");
     }
}



