int Modifier_LE(char* LE, int id, LE L1)
{
int гер=0; 
LE L;
 FILE * f=fopen(LE, "r"); 
FILE * f1=fopen("fichier.txt", "w"); 
if (f!=NULL && f1!=NULL) 
{
while (fscanf(f,"%d %s %s %s %s %d/%d/%d %d\n",&L1.ID,L1. Nom, L1.Prenom,L1.orientation,L1.profession,&L1.date.jour,&L1.date.mois,&L1.date.annee)!=E0F)
{
if(L.ID==id)
{
fprintf(f1,"%d %s %s %s %s %d/%d/%d %d\n" ,L1.ID,L1. Nom, L1.Prenom,L1.orinetation L1.profession, L1.date. jour, L1.date.mois, L1.date.annee);
 rep=1;}
else
fprintf(f1,"%d %s %s %s %s %d/%d/%d %d\n" ,L.ID, L.Nom, L. Prenom,L.orinetation L. profession, L.date. jour, L.date.mois, L.date.annee);
}
}
fclose(f);
 fclose(f1);
remove(LE);
 rename("fichier.txt", LE); 
return rep;
}
int Supprimer_LE(char* LE, int id)
{
LE L; int rep;
FILE * f=fopen(char * LE, "r");
FILE * f1=fopen("fichier.txt", "w"); 
if (f !=NULL && f1!=NULL)
{
while (fsacnf(f, "%d %s %s %s %s %d/%d/%d %d\n" ,L.ID, L. Nom, L.Prenom,L.orientation, L.profession, L.date.jour, L.date.mois,L.date.annee) !=E0F)
{if (L. iD==id)
rep=1; else
fprintf(fi, "%d %s %s %s %s %d/%d/%d %d\n" ,L.ID, L. Nom, L.Prenom,L.orientation,L.profession, L.date.jour, L.date.mois, L.date.annee);
}
}
fclose(f); fclose(f1); remove(LE); rename("fichier.txt" , LE); return rep;}
LE Chercher_LE(int id);
{
LE L; int rep; FILE * f=fopen(char* LE, "r"); 
if (f!=NULL)
{
while(rep==0 && fscanf(f, "%d %s %s %s %d/%d/%d %d\n" ,L.ID, L. Nom, L.Prenom, L.profession, L.date.jour, L.date.mois,L.date.annee) !=EOF)
{
if(L.ID==id)
rep=1;
}
}
fclose(f); 
if (rep==0)
L.ID=-1; 
return p;}


