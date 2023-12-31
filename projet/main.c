
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/stat.h>

#include <windows.h>

#define Student struct Stud

void add(FILE * fp);
void modify(FILE * fp);
void display(FILE * fp);
void Indivisual(FILE *fp);

FILE * triercla(FILE *fp);
FILE * triernat(FILE *fp);
FILE * del(FILE * fp);
void printChar(char ch,int n);
void title();
FILE *tp;

void gotoxy(int x,int y)
{
	COORD CRD;
    CRD.X = x;
    CRD.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}

struct pass
{
	char pass[25];
}pa;

struct Stud
{
    char nom[100];
    char dept[50];
    int roll;
    int sgpa[3];
    char reli[50];
    char filiere[50];
    int niv;
    char lieu[50];
    int dateinsc[3];
    char natio[50];

};


int main()
{
    int ch,id,k,i;
    char c,pas[50];
    SetConsoleTitle("Projet");
    FILE * fp;
    Student s;
    int option;
    char another;

    if((fp=fopen("db.txt","rb+"))==NULL)
    {

    }
    system("color 9f");
	gotoxy(42,8);

	//printf("\n\t\t\t\t\t");
	gotoxy(65,11);

        system("cls");
		gotoxy(10,3);
		printf("<<<< Patientez >>>>");

		printf("\n\n\n\n\n\t\t\t\t\tappuyer n'importe quel bouton pour continuer...... ");
		getch();

    title();
    printf("\n\n\t\t\t\t\t\tProjet de gestion etudiant");

    printf("\n\n\t\t\t\t\t\tECOLE\n\t\t\t\t");
    printChar('=',40);
    printf("\n\n\n\t\t\t\tappuyer n'importe quel bouton pour entrer");
    getch();

    while(1)
    {
        title();
        printf("\n\t");
        printChar('*',80);
        printf("\n\n\t\t\t\t\t\t Menu");
        printf("\n\n\t\t\t\t\t\t1. Ajouter %ctudiant",130);
        printf("\n\n\t\t\t\t\t\t2. Modifier %ctudiant",130);
        printf("\n\n\t\t\t\t\t\t3. montrer tous les %ctudiants",130);
        printf("\n\n\t\t\t\t\t\t4. affichage individuel");
        printf("\n\n\t\t\t\t\t\t5. supp %ctudiant",130);
        printf("\n\n\t\t\t\t\t\t6. trier par nationalite");
        printf("\n\n\t\t\t\t\t\t7. trier par classe");
        printf("\n\n\t\t\t\t\t\t8. Sortie\n\t");
        printChar('*',80);
        printf("\n\n\t\t\t\t\Choisissez une option :---> ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                add(fp);
                break;
            case 2:
                modify(fp);
                break;
            case 3:
                display(fp);
                break;
            case 4:
                Indivisual(fp);
                break;
            case 5:
                fp=del(fp);
                break;
            case 6:
                fp=triernat(fp );
                break;
            case 7:
               fp=triercla(fp );
                break;
            case 8:
               return 1;
               break;
            default:
                printf("\n\t\tPas d'action detect%ce",130);
                printf("\n\t\tAppuyer un bouton\n\n\n");
                getch();
                system("pause");
        }
    }

    return 1;

}





void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}

void title()
{
    system("cls");
    system("COLOR 06");
    printf("\n\n\t");
    printChar('=',40);
    printf(" Gestion d'%ctudiant ",130);
    printChar('=',40);
    printf("\n");
}


//Insert at end

 void add(FILE * fp)
{
    title();

    char another='y';

	Student s;
    int i;
    float cgpa;

    memset(&s, 0, sizeof(Student));
    fseek(fp,0,SEEK_END);
    while(another=='y'||another=='Y')
    {

        printf("\n\n\t\tEntrer le nom de l'etudiant: ");
        fflush(stdin);
        fgets(s.nom,100,stdin);
        s.nom[strlen(s.nom)-1]='\0';

        printf("\n\n\t\tEntrer le prénom de l'etudiant: ");
        fflush(stdin);
        fgets(s.dept,50,stdin);
        s.dept[strlen(s.dept)-1]='\0';

        printf("\n\n\t\tEntrer la religion de l'etudiant: ");
        fflush(stdin);
        fgets(s.reli,50,stdin);
        s.reli[strlen(s.reli)-1]='\0';

         printf("\n\n\t\tEntrer le nom de votre filiere: ");
        fflush(stdin);
        fgets(s.filiere,50,stdin);
        s.filiere[strlen(s.filiere)-1]='\0';

        printf("\n\n\t\tEntrer le niveau (par 3 pour 3 Annee: ");
        fflush(stdin);
        scanf("%d",&s.niv);

		/*printf("\n\n\t\tEntrer le nom de la religion: ");
        fflush(stdin);
        fgets(s.rel,50,stdin);
        s.rel[strlen(s.dept)-1]='\0'; */

        printf("\n\n\t\tEntrer le numero idendifiant : ");
        fflush(stdin);
        scanf("%d",&s.roll);
// debut de la demande et valdation de date
          int jj, mm, aaaa,v=1;
  do{
    printf("\n\n\t\tEntrer le jour, le mois et l'annee de votre date de Naissance: ");
    scanf("%d%d%d", &jj,&mm, &aaaa);
    if (jj<1 || jj>31 || mm<1 || mm>12 || aaaa<1980){v=0;};
     switch (mm){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    break;
    case 2:
      if( (aaaa%4==0 && jj>=30) || (aaaa%4!=0 && jj>=29) ){
       v=0;
      }
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      if(jj>=31){
      v=0;
      }
      break;

  }

  }while(v==0);

  s.sgpa[0]=jj;
  s.sgpa[1]=mm;
  s.sgpa[2]=aaaa; // fin de la demande et valdation de date

   printf("\n\n\t\tEntrer le nom de votre lieu de naissance : ");
        fflush(stdin);
        fgets(s.lieu,50,stdin);
        s.lieu[strlen(s.lieu)-1]='\0';

   printf("\n\n\t\tEntrer le jour, le mois et l'annee de votre date d'inscription: ");
    scanf("%d%d%d", &s.dateinsc[0],&s.dateinsc[1], &s.dateinsc[2]);


printf("\n\n\t\tEntrer le nom de votre nationalite: ");
        fflush(stdin);
        fgets(s.natio,50,stdin);
        s.natio[strlen(s.natio)-1]='\0';

        fwrite(&s,sizeof(s),1,fp);

        printf("\n\n\t\tAjouter un autre etudiant?(Y/N)?");
        fflush(stdin);
        another=getchar();
    }
}


FILE * del(FILE * fp)
{
    title();

    Student s;
    int flag=0,tempRoll,siz=sizeof(s);
    FILE *ft;

    if((ft=fopen("temp.txt","wb+"))==NULL)
    {
        printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
        system("pause");
        return fp;
    }

    printf("\n\n\tentrer le Numero id etudiant pour la suppression");
    printf("\n\n\t\t\tRoll No. : ");
    scanf("%d",&tempRoll);

    rewind(fp);


    while((fread(&s,siz,1,fp))==1)
    {
        if(s.roll==tempRoll)
        {
            flag=1;
            printf("\n\tOperation de suppression pour ");
            printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t",s.nom,s.dept,s.roll);
            continue;
        }

        fwrite(&s,siz,1,ft);
    }


    fclose(fp);
    fclose(ft);

    remove("db.txt");
    rename("temp.txt","db.txt");

    if((fp=fopen("db.txt","rb+"))==NULL)
    {
        printf("ERROR");
        return  NULL;
    }

    if(flag==0) printf("\n\n\t\tEtudiant inexistant\n\t");

    printChar('-',80);
    printf("\n\t");
    system("pause");
    return fp;
}


void modify(FILE * fp)
{
    title();

    Student s;
    int i,flag=0,tempRoll,siz=sizeof(s);
    float cgpa;

    printf("\n\n\tentrer le Numero id etudiant pour la modification: ");
    scanf("%d",&tempRoll);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        if(s.roll==tempRoll)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
    {
        fseek(fp,-siz,SEEK_CUR);
        printf("\n\n\t\t\t\tEtudiant trouv%c\n\t\t\t",130);
        printChar('=',38);
        printf("\n\n\t\t\tNom de l'etudiant: %s",s.nom);
        printf("\n\n\t\t\Numeroid etudiant: %d\n\t\t\t",s.roll);
        printChar('=',38);
        printf("\n\n\t\t\tEntrer nouvelles donnees de l'etudiant");

        printf("\n\n\t\t\tEntrer le nom de l'etudiant: ");
        fflush(stdin);
        fgets(s.nom,100,stdin);
        s.nom[strlen(s.nom)-1]='\0';

        printf("\n\n\t\t\tEntrer le prenom de l'etudiant: ");
        fflush(stdin);
        fgets(s.dept,50,stdin);
        s.dept[strlen(s.dept)-1]='\0';

        printf("\n\n\t\tEntrer la religion de l'etudiant: ");
        fflush(stdin);
        fgets(s.reli,50,stdin);
        s.reli[strlen(s.reli)-1]='\0';


        printf("\n\n\t\tEntrer le nom de votre filiere: ");
        fflush(stdin);
        fgets(s.filiere,50,stdin);
        s.filiere[strlen(s.filiere)-1]='\0';

        printf("\n\n\t\tEntrer le niveau (par 3 pour 3 Annee: ");
        fflush(stdin);
        scanf("%d",&s.niv);

        printf("\n\n\t\t\tEntrer numero id: ");
        scanf("%d",&s.roll);

// debut de la demande et valdation de date
          int jj, mm, aaaa,v=1;
  do{
    printf("Entrer le jour, le mois et l'annee:\n");
    scanf("%d%d%d", &jj,&mm, &aaaa);
    if (jj<1 || jj>31 || mm<1 || mm>12 || aaaa<1985){v=0;};
     switch (mm){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    break;
    case 2:
      if( (aaaa%4==0 && jj>=30) || (aaaa%4!=0 && jj>=29) ){
       v=0;
      }
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      if(jj>=31){
      v=0;
      }
      break;

  }

  }while(v==0);

  s.sgpa[0]=jj;
  s.sgpa[1]=mm;
  s.sgpa[2]=aaaa; // fin de la demande et valdation de date

   printf("\n\n\t\tEntrer le nom de votre lieu de naissance : ");
        fflush(stdin);
        fgets(s.lieu,50,stdin);
        s.lieu[strlen(s.lieu)-1]='\0';

printf("\n\n\t\tEntrer le jour, le mois et l'annee de votre date d'inscription: ");
    scanf("%d%d%d", &s.dateinsc[0],&s.dateinsc[1], &s.dateinsc[2]);

    printf("\n\n\t\tEntrer le nom de votre nationalite: ");
        fflush(stdin);
        fgets(s.natio,50,stdin);
        s.natio[strlen(s.natio)-1]='\0';


          fwrite(&s,sizeof(s),1,fp);
    }

    else printf("\n\n\t!! ERROR !! ");

    printf("\n\n\t");
    system("pause");

}

void display(FILE * fp)
{
    title();
    Student s;
    int i,siz=sizeof(s);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        printf("\n\t\tNom : %s",s.nom);
        printf("\n\n\t\tPrenom : %s",s.dept);
        printf("\n\n\t\tReligion : %s",s.reli);
        printf("\n\n\t\tFiliere : %s",s.filiere);
        printf("\n\n\t\tniveau : %d",s.niv);
        printf("\n\n\t\tid : %d",s.roll);
        printf("\n\n\t\tDate de naissance: ");


        for(i=0; i<3; i++)
            printf("%d/",s.sgpa[i]);

        printf("\n\n\t\ttlieu de naissance: %s",s.lieu);



        printf("\n\n\t\tDate d'inscription: ");
        for(i=0; i<3; i++)
            printf("%d/",s.dateinsc[i]);

        printf("\n\n\t\tNationalite: %s",s.natio);

      printf("\n\n\n\t");
     printChar('-',80);
    }



    printf("\n\n\n\t");
    printChar('*',80);
    printf("\n\n\t");
    system("pause");
}

void Indivisual(FILE *fp)
{
    title();

    int tempRoll,flag,siz,i;
    Student s;
    char another='y';

    siz=sizeof(s);

    while(another=='y'||another=='Y')
    {
        printf("\n\n\tEntrer numero id: ");
        scanf("%d",&tempRoll);

        rewind(fp);

        while((fread(&s,siz,1,fp))==1)
        {
            if(s.roll==tempRoll)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            printf("\n\t\tNom : %s",s.nom);
            printf("\n\n\t\tPrenom  : %s",s.dept);
            printf("\n\n\t\tReligion  : %s",s.reli);
            printf("\n\n\t\tFiliere  : %s",s.filiere);
            printf("\n\n\t\tNiveau  : %d",s.niv);
            printf("\n\n\t\tid : %d",s.roll);
            printf("\n\n\tDate de Naissance: ");

            for(i=0; i<3; i++)
                printf("/",s.sgpa[i]);
            printf("\n\n\tlieu de naissance: %s",s.lieu);


             printf("\n\n\tDate d'inscription: ");

            for(i=0; i<3; i++)
                printf("/",s.dateinsc[i]);

            printf("\n\n\t\tNationalite  : %s",s.natio);

            printChar('-',80);


        }
        else printf("\n\n\t\t!! ERROR !!");


        printf("\n\n\t\tmontrer l'information d'un autre etudiant ?? (Y/N)?");
        fflush(stdin);
        another=getchar();
    }
}

FILE* triernat(FILE *fp ){
    title();

    Student *t,
            *s;
    int p[100];

    FILE *li;
    int i,j,l,k;
    struct stat st;
        FILE *ft;

    if((ft=fopen("trier.txt","wb+"))==NULL)
    {
        printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
        system("pause");
        return fp;
    }

    fseek(fp, 0, SEEK_SET);
    fstat(fileno(fp), &st);
    i = (st.st_size / sizeof(struct Stud));
    t = (struct Stud*) malloc(st.st_size);

    fread(t, st.st_size, 1, fp);
    s = t;
    Student a;

    for (j = 0; j < i-1; j++){
     for(k=0;k<i-1-j;k++) {
 if( strcmp(t[k].natio, t[k+1].natio)>=0){
            a=t[k];
            t[k]=t[k+1];
            t[k+1]=a;  };}};


  fwrite(t, st.st_size,1,ft);

    printf("\n\n\t");
    printChar('=',40);
    printf(" Trier par Natio");
    printChar('=',40);
    printf("\n");
// on suppose que l'on connait lenbre de niveau 1 a 5e anneé pour simplifier le code

 for (j = 0; j < i; j++){


        printf("\n\t\tNom : %s",t[j].nom);
        printf("\n\n\t\tPrenom : %s",t[j].dept);
        printf("\n\n\t\tReligion : %s",t[j].reli);
        printf("\n\n\t\tFiliere : %s",t[j].filiere);
        printf("\n\n\t\tniveau : %d",t[j].niv);
        printf("\n\n\t\tid : %d",t[j].roll);
        printf("\n\n\t\tDate de naissance: ");
                for(l=0; l<3; l++)
            printf("%d/",t[j].sgpa[l]);

        printf("\n\n\t\ttlieu de naissance: %s",t[j].lieu);



        printf("\n\n\t\tDate d'inscription: ");
        for(l=0; l<3; l++)
            printf("%d/",t[j].dateinsc[l]);

        printf("\n\n\t\tNationalite: %s",t[j].natio);

      printf("\n\n\n\t");
      };
          fclose(ft);
    system("pause");
    return fp;
}
FILE* triercla(FILE *fp ){
    title();

    Student *t,
            *s;
    int p[100];

    FILE *li;
    int i,j,l,k;
    struct stat st;
        FILE *ft;

    if((ft=fopen("trierparcla.txt","wb+"))==NULL)
    {
        printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
        system("pause");
        return fp;
    }

    fseek(fp, 0, SEEK_SET);
    fstat(fileno(fp), &st);
    i = (st.st_size / sizeof(struct Stud));
    t = (struct Stud*) malloc(st.st_size);

    fread(t, st.st_size, 1, fp);
    s = t;
    Student a;

     for (j = 0; j < i-1; j++){
     for(k=0;k<i-1-j;k++) {
 if( t[k].niv> t[k+1].niv){
            a=t[k];
            t[k]=t[k+1];
            t[k+1]=a;  };}};

   for (j = 0; j < i-1; j++){
     for(k=0;k<i-1-j;k++) {
 if( (t[k].niv==t[k+1].niv) && (strcmp(t[k].filiere,t[k+1].filiere)>=0)){
            a=t[k];
            t[k]=t[k+1];
            t[k+1]=a;  };}};

  fwrite(t, st.st_size,1,ft);

    printf("\n\n\t");
    printChar('=',40);
    printf(" Trier par classe");
    printChar('=',40);
    printf("\n");


 for (j = 0; j < i; j++){


        printf("\n\t\tNom : %s",t[j].nom);
        printf("\n\n\t\tPrenom : %s",t[j].dept);
        printf("\n\n\t\tReligion : %s",t[j].reli);
        printf("\n\n\t\tFiliere : %s",t[j].filiere);
        printf("\n\n\t\tniveau : %d",t[j].niv);
        printf("\n\n\t\tid : %d",t[j].roll);
        printf("\n\n\t\tDate de naissance: ");
                for(l=0; l<3; l++)
            printf("%d/",t[j].sgpa[l]);

        printf("\n\n\t\ttlieu de naissance: %s",t[j].lieu);



        printf("\n\n\t\tDate d'inscription: ");
        for(l=0; l<3; l++)
            printf("%d/",t[j].dateinsc[l]);

        printf("\n\n\t\tNationalite: %s",t[j].natio);

      printf("\n\n\n\t");
      };
          fclose(ft);
    system("pause");
    return fp;
}

