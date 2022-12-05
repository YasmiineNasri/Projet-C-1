#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "Lelectorale.h"

// e.tab_cand[1].cin,e.tab_cand[1].genre

// variables golables 
int c1 =1, c2 = 1 , c3 = 1;
int cM1 =1, cM2 = 1 , cM3 = 1;

/* ---------------------------- INTERFACE MENU ------------------------------- */
void
on_toStats_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	window1 = create_stats ();
  	gtk_widget_show (window1);
}


void
on_toVote_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	window1 = create_vote();
  	gtk_widget_show (window1);
}


void
on_toModLE_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	window1 = create_modifier_liste ();
  	gtk_widget_show (window1);
}


void
on_toAffLE_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	window1 = create_afficher_liste_electorale ();
  	gtk_widget_show (window1);
}


void
on_toAddLE_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	window1 = create_ajout_listeE ();
  	gtk_widget_show (window1);
}


void
on_toSupprimerListe_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	window1 = create_supprimer_liste();
  	gtk_widget_show (window1);
}

/* ---------------------------- INTERFACE Ajout ------------------------------- */
void
on_radioFA1_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		c1=2;
	}
}


void
on_radioHA2_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		c2=1;
	}
}


void
on_radioHA1_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		c1=1;
	}
}


void
on_radioHA3_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		c3=1;
	}
}


void
on_radioFA2_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		c2=2;
	}
}


void
on_radioFA3_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		c3=2;
	}
}


void
on_ajouterLE_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *nomLE, *idLE , *orientation,*nomCT , *cinCT ,*num_tel  , *cinC1 ,*cinC2 ,*cinC3 , *j,*m,*a,*output  ;
	
	Lelectoral e;
	char message[200];
	
	
	
	
	idLE=lookup_widget(objet,"idLE");
	strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(idLE)));


	nomLE=lookup_widget(objet,"nomLE");
	strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(nomLE)));


	orientation = lookup_widget(objet,"comboOrient");
	strcpy(e.orientation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(orientation)));

	nomCT=lookup_widget(objet,"nomT");
	strcpy(e.nomCT,gtk_entry_get_text(GTK_ENTRY(nomCT)));

	
	cinCT=lookup_widget(objet,"cinT");
	strcpy(e.cinT,gtk_entry_get_text(GTK_ENTRY(cinCT)));


	num_tel=lookup_widget(objet,"num_tel");
	strcpy(e.num_tel,gtk_entry_get_text(GTK_ENTRY(num_tel)));


	candidat ca1,ca2,ca3;

	cinC1=lookup_widget(objet,"cinC1");
	strcpy(ca1.cin,gtk_entry_get_text(GTK_ENTRY(cinC1)));
	if(c1 == 1){
		strcpy(ca1.genre,"Homme");
	}else{
		strcpy(ca1.genre,"Femme");
	}


	cinC2=lookup_widget(objet,"cinC2");
	strcpy(ca2.cin,gtk_entry_get_text(GTK_ENTRY(cinC2)));
	if(c2 == 1){
		strcpy(ca2.genre,"Homme");
	}else{
		strcpy(ca2.genre,"Femme");
	}


	cinC3=lookup_widget(objet,"cinC3");
	strcpy(ca3.cin,gtk_entry_get_text(GTK_ENTRY(cinC3)));
	if(c3 == 1){
		strcpy(ca3.genre,"Homme");
	}else{
		strcpy(ca3.genre,"Femme");
	}

	e.tab_cand[0] = ca1;
	e.tab_cand[1] = ca2;
	e.tab_cand[2] = ca3;

	j = lookup_widget(objet,"spinJA");
	m = lookup_widget(objet,"spinMA");
	a = lookup_widget(objet,"spinAA");

	e.d.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j));
	e.d.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m));
	e.d.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(a));

	output = lookup_widget(objet,"outputLE");


	



	e.nbrVote = 0 ;

			

	
	if(rechercher_listeE(e.id)){
		sprintf(message,"Verifier vos informations \n");
		
    		gtk_label_set_text(GTK_LABEL(output),message);	
	}
	else{
		ajouter(e);		
		sprintf(message,"Votre ajout a été effectué avec succés ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
		
	}
	

}

/* ---------------------------- INTERFACE Supp ------------------------------- */


void
on_supListe_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *idLE , *output;
	char message[200];
	char id[20];

	idLE = lookup_widget(objet,"idSupp");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idLE)));


	output = lookup_widget(objet,"outputSupp");

	if(rechercher_listeE(id)){
		sprintf(message,"Votre suppression a été effectué avec succés ! ");
	gtk_label_set_text(GTK_LABEL(output),message);
		
	supprimer(id);
	}
	else{
		sprintf(message,"Identifiant non existant ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	
	}
}

/* ---------------------------- INTERFACE Affichage ------------------------------- */
void
on_afficherLE_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview;	
	treeview = lookup_widget(objet,"treeviewLE");
		
	afficher_listeE(treeview,"listeE.txt");
}
/* ---------------------------- INTERFACE Modification ------------------------------- */

void
on_checkModif_activate                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radioHM1_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		cM1=1;
	}
}


void
on_radioFM1_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		cM1=2;
	}
}


void
on_radioHM2_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		cM2=1;
	}
}


void
on_radioFM2_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		cM2=2;
	}
}


void
on_radioHM3_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		cM3=1;
	}
}


void
on_radioFM3_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		cM3=2;
	}
}


void
on_rechercherLE_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *nomLE, *idLE , *orientation,*nomCT , *cinCT ,*num_tel  , *cinC1 ,*cinC2 ,*cinC3 , *j,*m,*a,*output  ;

	char message[200];
	char id[20];

	idLE = lookup_widget(objet,"idLEE");
	
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idLE)));
	output = lookup_widget(objet,"outputLEE");	
	

	if(!rechercher_listeE(id)){
		sprintf(message,"ID NON EXISTANT\n");
		
    		gtk_label_set_text(GTK_LABEL(output),message);	
	}
	else{
		Lelectoral e;

		strcpy(e.id,id);		
		strcpy(e.nom,recherche_listeE(id).nom);
		strcpy(e.orientation,recherche_listeE(id).orientation);

		strcpy(e.nomCT,recherche_listeE(id).nomCT);
		strcpy(e.cinT,recherche_listeE(id).cinT);


		strcpy(e.num_tel,recherche_listeE(id).num_tel);


		strcpy(e.tab_cand[0].cin,recherche_listeE(id).tab_cand[0].cin);
		strcpy(e.tab_cand[1].cin,recherche_listeE(id).tab_cand[1].cin);
		strcpy(e.tab_cand[2].cin,recherche_listeE(id).tab_cand[2].cin);

		


					
		sprintf(message,"Tapez vos nouveau donnée puis cliquez sur\n\tenregistrer les modifications\n");
		gtk_label_set_text(GTK_LABEL(output),message);	
		

		nomLE=lookup_widget(objet,"nomLEE");
    		gtk_entry_set_text(GTK_ENTRY(nomLE),e.nom);

		nomCT=lookup_widget(objet,"nomCTE");
		gtk_entry_set_text(GTK_ENTRY(nomCT),e.nomCT);

		cinCT=lookup_widget(objet,"cinTE");
		gtk_entry_set_text(GTK_ENTRY(cinCT),e.cinT);

		num_tel = lookup_widget(objet,"numtelM");
		gtk_entry_set_text(GTK_ENTRY(num_tel),e.num_tel);



		orientation = lookup_widget(objet,"comboOrientM");
		int comboValue = 0;
		if(strcmp(e.orientation,"Center") == 0){
			comboValue = 1;
		}
		else if(strcmp(e.orientation,"Droite")){
			comboValue = 2;
		}
		gtk_combo_box_set_active(orientation,comboValue);



		cinC1=lookup_widget(objet,"cinCE1");
		gtk_entry_set_text(GTK_ENTRY(cinC1),e.tab_cand[0].cin);



		cinC2=lookup_widget(objet,"cinCE2");
		gtk_entry_set_text(GTK_ENTRY(cinC2),e.tab_cand[1].cin);


		cinC3=lookup_widget(objet,"cinCE3");
		gtk_entry_set_text(GTK_ENTRY(cinC3),e.tab_cand[2].cin);



		
		j = lookup_widget(objet,"spinJM");
		gtk_spin_button_set_value(j,recherche_listeE(id).d.j);


		m = lookup_widget(objet,"spinMM");
		gtk_spin_button_set_value(m,recherche_listeE(id).d.m);

		a = lookup_widget(objet,"spinAM");
		gtk_spin_button_set_value(a,recherche_listeE(id).d.a);

		
	}
}


void
on_saveChangesLE_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *nomLE, *idLE , *orientation,*nomCT , *cinCT ,*num_tel  , *cinC1 ,*cinC2 ,*cinC3 , *j,*m,*a,*output  ;
	
	Lelectoral e;
	char message[200];
	
	
	
	
	idLE=lookup_widget(objet,"idLEE");
	strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(idLE)));
	
	output = lookup_widget(objet,"outputLEE");

	if(rechercher_listeE(e.id)){
		nomLE=lookup_widget(objet,"nomLEE");
		strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(nomLE)));


		orientation = lookup_widget(objet,"comboOrientM");
		strcpy(e.orientation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(orientation)));

		nomCT=lookup_widget(objet,"nomCTE");
		strcpy(e.nomCT,gtk_entry_get_text(GTK_ENTRY(nomCT)));

		
		cinCT=lookup_widget(objet,"cinTE");
		strcpy(e.cinT,gtk_entry_get_text(GTK_ENTRY(cinCT)));


		num_tel=lookup_widget(objet,"numtelM");
		strcpy(e.num_tel,gtk_entry_get_text(GTK_ENTRY(num_tel)));


		candidat ca1,ca2,ca3;

		cinC1=lookup_widget(objet,"cinCE1");
		strcpy(ca1.cin,gtk_entry_get_text(GTK_ENTRY(cinC1)));
		if(cM1 == 1){
			strcpy(ca1.genre,"Homme");
		}else{
			strcpy(ca1.genre,"Femme");
		}


		cinC2=lookup_widget(objet,"cinCE2");
		strcpy(ca2.cin,gtk_entry_get_text(GTK_ENTRY(cinC2)));
		if(cM2 == 1){
			strcpy(ca2.genre,"Homme");
		}else{
			strcpy(ca2.genre,"Femme");
		}


		cinC3=lookup_widget(objet,"cinCE3");
		strcpy(ca3.cin,gtk_entry_get_text(GTK_ENTRY(cinC3)));
		if(cM3 == 1){
			strcpy(ca3.genre,"Homme");
		}else{
			strcpy(ca3.genre,"Femme");
		}

		e.tab_cand[0] = ca1;
		e.tab_cand[1] = ca2;
		e.tab_cand[2] = ca3;

		j = lookup_widget(objet,"spinJM");
		m = lookup_widget(objet,"spinMM");
		a = lookup_widget(objet,"spinAM");

		e.d.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j));
		e.d.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m));
		e.d.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(a));

		


		



		e.nbrVote = recherche_listeE(e.id).nbrVote ; 

		sprintf(message,"Votre modification a été effectué avec succés ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
		modifier_listeE(e);
	}
	else{
		sprintf(message,"Identifiant non existant ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	}
	
}

