/********* Milan Uzelac NRT-93/16**********/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>  /*funkcija za vreme*/
#define MAX 20

void crtajvesala(int brojpromasaja);  /*ispisuje vesala u zavisnosti od broja promasaja*/
void izaberiopciju(int opcija);		/*biranje opcije u glavnom meniju*/
void igraj(char string[]);		/*funkcija koja pretvara rec u '_' i vrsi pogadjanje iste*/
void divljezivotinje();		/*funkcija koja izvlaci random reci iz datoteke divljezivotinje.txt*/
void citadrzave();		/*funkcija koja izvlaci random reci iz datoteke drzave.txt */
void citagradove();		/*funkcija koja izvlaci random reci iz datoteke gradovi.txt */
void glavnimeni();		/*funkcija za ispis glavnog menija*/



main()
{
	glavnimeni();	/*pozivamo funkciju glavnimeni()*/


}

void glavnimeni()	/*koja ispisuje glavni meni*/
{
	int opcija=0; /*inicijalizujemo opciju za biranje na 0*/
	printf("\n");
	printf("           ********************************Dobrodosli u igru vesala!*******************************\n");
	printf("           *                                                                       ############   *\n");
	printf("           *                                                                       ##        #    *\n");
	printf("           *   1. Igraj                                                            ##        #    *\n");
	printf("           *                                                                       ##      __O__  *\n");
	printf("           *   2. Izlaz                                                            ##        |    *\n");
	printf("           *                                                                       ##       / %c   *\n",'\\');
	printf("           *                                                                       ##             *\n");
	printf("           *                                                                       ##             *\n");
	printf("           *                                                                     ######           * \n");
	printf("           ****************************************************************************************");

	izaberiopciju(opcija); /*pozovemo funkciju da se izabere opcija koja vraca vrednost opcije*/
	
}

void izaberiopciju(int opcija){
	int biranje;	

	do{									
	printf("\nIzaberite opciju:.......\t");	/*biramo opciju*/
	scanf("%d",&opcija);
	}while(opcija<1||opcija>2);
	if(opcija==1){			/*ako je izabrana opcija pod 1. - igraj: ispisuje ponudjene oblasti*/
	system("cls");	/*cisti se ekran*/
	printf("\nIgrajmo!\n");
	printf("\nIzaberite oblast: ");
	printf("\t1. DRZAVE SVETA \n");
	printf("\t\t\t2. GRADOVI SVETA \n");
	printf("\t\t\t3. DIVLJE ZIVOTINJE\n");

	scanf("%d",&biranje);	/*biranje oblasti*/

	if(biranje==1){		/*ako je izabran broj 2 cita imena drzava iz tekstualne datoteke drzave.txt*/
	system("cls");	
	citadrzave();
	exit(1);
	}
	else if(biranje==2)  /*ako je izabran broj 2 cita imena gradova iz tekstualne datoteke gradovi.txt*/
	{
	system("cls");
	citagradove();
	exit(1);
	}
	else if(biranje==3)		/*ako je izabran broj 3 cita imena drzava iz tekstualne datoteke divljezivotinje.txt*/
	{
		system("cls");
		divljezivotinje();
		exit(1);
	}
	}
	if(opcija==2){
	printf("\nIzasli ste iz igre!\n");		/*ako je izabrana opcija 2 izlazi se iz igre*/
	exit(1);
	}
}



void citadrzave(){		/*funkcija za otvaranje datoteke i nasumicni odabir drzava iz nje*/
	FILE *drzave;		/*pokazivac na strukturu tipa FILE*/
	int i,slucajnibroj;
	char *bafer;	/*pokazivac na memorijsku lokaciju gde ce biti smesteno ime drzave*/
	char reci[25][20]={""};
	time_t timer;	
	if((drzave=fopen("drzave.txt", "r"))==NULL) /*otvaranje datoteke drzave.txt za citanje*/
	{
		fprintf(stderr,"Greska pri otvaranju datoteke za citanje!"); /*provera*/
		exit(1);
	}
	srand((unsigned int)time(NULL));
	srand(time(&timer));
	slucajnibroj=rand()%15;	/*nasumicno bira broj*/
	
	for(i=1;i<25;i++) 
	{
		fgets(reci[i],25,drzave);
	}
	bafer=(char *)malloc(strlen(reci[slucajnibroj]+1));	/*dinamicko dodeljivanje memorije za bafer*/
	if(bafer==NULL)	
	{
		printf("\nGreska pri dinamickoj dodeli memorije!\n");	/*provera*/
		exit(1);
	}
	strcpy(bafer,reci[slucajnibroj]);  /*kopira se sadrzaj reci u bafer*/
	
	printf("\n");

	igraj(bafer); /*pozivanje funkcije igraj kojoj se prosledjuje sadrzaj bafera*/
	free(bafer);  /*ciscenje memorije bafera*/
	fclose(drzave);
	
}


void citagradove(){		/*funkcija za otvaranje datoteke i nasumicni odabir gradova iz nje*/
	FILE *gradovi;
	int i,slucajnibroj;
	char *bafer;		/*pokazivac na memorijsku lokaciju gde ce biti smesteno ime grada*/
	char reci[25][20]={""};
	time_t timer;

	if((gradovi=fopen("gradovi.txt", "r"))==NULL)	/*otvaranje datoteke gradovi.txt za citanje*/
	{
		fprintf(stderr,"Greska pri otvaranju datoteke za citanje!");	/*provera*/
		exit(1);
	}
	srand((unsigned int)time(NULL));
	srand(time(&timer));
	slucajnibroj=rand()%15;  /*nasumicno se bira broj*/
	
	for(i=1;i<25;i++)
	{
		fgets(reci[i],25,gradovi);
	}
	bafer=(char *)malloc(strlen(reci[slucajnibroj]+1));		/*dinamicko dodeljivanje memorije za bafer*/
	if(bafer==NULL)
	{
		printf("Greska pri dinamickoj dodeli memorije!\n"); /*provera*/
		exit(1);
	}
	strcpy(bafer,reci[slucajnibroj]);	 /*kopira se sadrzaj reci u bafer*/

	printf("\n");
	igraj(bafer);	/*pozivanje funkcije igraj kojoj se prosledjuje sadrzaj bafera*/
	free(bafer);	/*ciscenje memorije bafera*/
	fclose(gradovi);
}

void divljezivotinje(){		/*funkcija za otvaranje datoteke i nasumicni odabir gradova iz nje*/
	FILE *zivotinje;
	int i,slucajnibroj;
	char *bafer;		/*pokazivac na memorijsku lokaciju gde ce biti smesteno ime grada*/
	char reci[25][20]={""};
	time_t timer;

	if((zivotinje=fopen("divljezivotinje.txt", "r"))==NULL)  /*otvaranje datoteke gradovi.txt za citanje*/
	{
		printf("Greska pri otvaranju datoteke za citanje!");  /*provera*/
		exit(1);
	}
	srand((unsigned int)time(NULL));
	srand(time(&timer));
	slucajnibroj=rand()%15;	/*nasumicno bira broj*/
	
	for(i=1;i<25;i++)
	{
		fgets(reci[i],25,zivotinje);
	}
	bafer=(char *)malloc(strlen(reci[slucajnibroj]+1));	/*dinamicko dodeljivanje memorije za bafer*/
	if(bafer==NULL)
	{
		printf("\nGreska pri dinamickoj dodeli memorije!\n");	 /*provera*/
		exit(1);
	}
	
	strcpy(bafer,reci[slucajnibroj]);	/*kopiramo sadrzaj reci u bafer*/
		
	igraj(bafer);	/*pozivanje funkcije igraj kojoj se prosledjuje sadrzaj bafera*/
	free(bafer);	/*ciscenje memorije bafera*/
	fclose(zivotinje);
}



/*funkcija koja dobija sadrzaj bafera iz funkcija citadrzave, 
citagradove ili divljezivotinje u zavisnosti koja je oblast izabrana*/

void igraj(char bafer[]) {
	char *rec, slovo, svaslova[] = "ABCDEFGHIJKLMNOPRSTUVZ";
	int i,brojpogodaka = 0, brojpromasaja = 0, negpoeni = 0, pozpoeni = 0, povratakizbor = 0, isti = 0, brojpoena = 0,obesen=0;
	typedef struct{
	char ime[20 + 1];
	int brojpoena;
}Takmicar;
	Takmicar igrac;

	rec=(char *)malloc(strlen(bafer)*sizeof(char));  /*dinamicko dodeljivanje memorije za rec*/
	if(rec==NULL)
	{
		printf("Greska pri dinamickoj dodeli memorije!\n");  /*provera*/
		exit(1);
	}
	strcpy(rec,bafer);	/*kopiranje sadrzaja bafera u rec*/
	fflush(stdin);
	
	for (i = 0; i < strlen(bafer)-1; i++) {     /*u bafer se smestaju donje crte '_' duzine reci koja je izvucena iz datoteke*/
		bafer[i] = '_';
		printf("%c ", bafer[i]);	/*prikazuju se donje crte umesto reci*/
	}

	/*dok je brojpogodaka manji od duzine bafera - znak za kraj stringa*/
	/*i brojpromasaja manji od 6*/
		while (brojpogodaka < strlen(bafer) - 1 && brojpromasaja<6){	
			
			isti = 0;
			fflush(stdin);
			printf("\nUnesite slovo: ");
			scanf("%c", &slovo);	/*unosimo slovo*/
			slovo = toupper(slovo);		/*koje se pretvara u veliko slovo*/

			printf("\nPreostala slova:\t\t");

			for (i = 0; i < strlen(svaslova); i++)	/*ispisivanje svih ponudjenih slova*/
			{
				if (slovo == svaslova[i])	/*ako je slovo koje je zadato u ponudjenim slovima*/
				{
					svaslova[i] = ' ';   /*to slovo se brise sa ekrana*/
				}
				printf("%c ", svaslova[i]); /*ponovno se stampaju slova*/
			}
			printf("\n");



			for (i = 0; i < strlen(bafer); i++)  /*petlja za proveru postojanja zadatog slova u reci*/
			{


				if (slovo == rec[i]) {		/*ako je slovo u reci[i] */
					bafer[i]=slovo;	 /*slovo se cuva u bafer*/
					brojpogodaka++; /*brojpogodaka se inkrementira za 1*/
					pozpoeni = pozpoeni + 5; /*dodeljuju se pozitivni poeni*/
					isti = 1;	/*zadajemo flag 1 cime dajemo do znanja da je slovo nadjeno*/
				}

				printf("%c ", bafer[i]);  /*stampanje bafera*/
			}

			if (isti == 0)	/*ako je flag 0, slovo nije nadjeno u reci*/
			{
				negpoeni = negpoeni + 2;	/*negativi poeni se dodaju*/
				brojpromasaja++;	/*broj promasaja se inkrementira*/
				printf("\nUneto slovo nije u reci!\n");
				crtajvesala(brojpromasaja);	/*funkcija koja iscrtava vesala u zavisnosti od broja promasaja*/
				
			}
			if(brojpromasaja==6) /*ako je broj promasaja jednak 6, koliko imamo delova tela*/
			{
			obesen=1; /*daje se na znanje da je takmicar obesen*/
			break;	/*izlazi se iz petlje*/
			}

		printf("\n");

	}
		
		if(obesen==0)	/*ako takmicar nije obesen...*/
		{
		printf("\nCestitamo pogodili ste rec! :D");
		printf("\nBroj promasenih slova: \t%d", brojpromasaja);
		printf("\nBroj pozitivnih poena: \t%d", pozpoeni);
		printf("\nBroj negativnih poena:\t%d", negpoeni);

		igrac.brojpoena = pozpoeni - negpoeni;
		printf("\nVase ime je: "); 
		scanf("%s",&igrac.ime);    /*unos imena takmicara koje se smesta u strukturu*/

		printf("Vi ste igrac sa imenom %s i vas broj poena u ovoj igri je: %d\n",igrac.ime,igrac.brojpoena); 

		printf("\nPovratak u glavni meni?");  /*opcije za povratak u glavni meni ili izlaz iz igre*/
		printf("\n1. DA");
		printf("\n2. NE\n");
		scanf("\t%d", &povratakizbor);

			if (povratakizbor == 1)	/*ako je zadata opcija 1*/
			{							
				system("cls");	/*cisti se ekran*/
				glavnimeni();	/*poziva se funkcija glavnimeni() koja nas vraca u glavni meni*/
			}
			else if (povratakizbor == 2) /*ako je zadata opcija 2*/
			{
				exit(1);	/*izlazi se iz igre*/
			}
		}

		else{	/*ako je obesen==1*/	
		printf("\nKraj igre, obeseni ste!\n");
			printf("\nPovratak u glavni meni?");
			printf("\n1. DA");
			printf("\n2. NE\n");
			
			scanf("\t%d", &povratakizbor);
			if (povratakizbor == 1)
			{
				system("cls");
				glavnimeni();
			}
			else if (povratakizbor == 2)
			{
				exit(1);
			}

		}

	}



	/*funkcija za iscrtavanje vesala koja u argumentima ima brojpromasaja*/
		/*pa u zavisnosti od broja promasaja ispisuje se deo tela*/
void crtajvesala(int brojpromasaja)
 {

     switch(brojpromasaja)
     {

     case 6:

	printf("                                                                       ############  \n");
	printf("                                                                       ##        #   \n");
	printf("                                                                       ##        #   \n");
	printf("                                                                       ##      __O__  \n");
	printf("                                                                       ##        |   \n");
	printf("                                                                       ##       / %c  \n",'\\');
	printf("                                                                       ##            \n");
	printf("                                                                       ##            \n");
	printf("                                                                     ######          \n");
	break;

     case 5:

	printf("                                                                       ############\n");
	printf("                                                                       ##        # \n");
	printf("                                                                       ##        # \n");
	printf("                                                                       ##      __O__\n");
	printf("                                                                       ##        | \n");
	printf("                                                                       ##       /  \n");
	printf("                                                                       ##          \n");
	printf("                                                                       ##          \n");
	printf("                                                                     ######        \n");
	break;

     case 4:

	printf("                                                                       ############\n");
	printf("                                                                       ##        # \n");
	printf("                                                                       ##        # \n");
	printf("                                                                       ##      __O__\n");
	printf("                                                                       ##        |  \n");
	printf("                                                                       ##           \n");
	printf("                                                                       ##           \n");
	printf("                                                                       ##           \n");
	printf("                                                                     ######         \n");
	break;

     case 3:
		
    printf("                                                                       ############\n");
	printf("                                                                       ##        # \n");
	printf("                                                                       ##        # \n");
	printf("                                                                       ##      __O__\n");
	printf("                                                                       ##          \n");
	printf("                                                                       ##          \n");
	printf("                                                                       ##          \n");
	printf("                                                                       ##          \n");
	printf("                                                                     ######        \n");
	break;

     case 2:

	printf("                                                                       ############\n");
	printf("                                                                       ##        # \n");
	printf("                                                                       ##        # \n");
	printf("                                                                       ##      __O\n");
	printf("                                                                       ##          \n");
	printf("                                                                       ##          \n");
	printf("                                                                       ##          \n");
	printf("                                                                       ##          \n");
	printf("                                                                     ######        \n");
	break;

     case 1:
    
	printf("                                                                       ############\n");
	printf("                                                                       ##        # \n");
	printf("                                                                       ##        # \n");
	printf("                                                                       ##        O \n");
	printf("                                                                       ##          \n");
	printf("                                                                       ##          \n");
	printf("                                                                       ##          \n");
	printf("                                                                       ##          \n");
	printf("                                                                     ######        \n");
	break;

	 case 0:
    
	printf("                                                                       ############\n");
	printf("                                                                       ##        # \n");
	printf("                                                                       ##        # \n");
	printf("                                                                       ##          \n");
	printf("                                                                       ##          \n");
	printf("                                                                       ##          \n");
	printf("                                                                       ##          \n");
	printf("                                                                       ##          \n");
	printf("                                                                     ######        \n");
	break;
	 }
    return;
}