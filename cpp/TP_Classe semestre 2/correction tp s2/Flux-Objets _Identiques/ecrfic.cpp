#include "ecrfic.h"

CVect::CVect(int n)
{
	m_n = n;
	m_pdon = new double [m_n];
}

CVect::CVect(const CVect& V)
{
	m_n = V.m_n;
	m_pdon = new double [m_n];
	for (int i=0; i<m_n; i++)
		m_pdon[i] = V.m_pdon[i];
}

CVect::~CVect()
{
	if (m_pdon != NULL)
	{
		delete [] m_pdon;
		m_pdon = NULL;
	}
}

void CVect::Remplir()
{
	int i;
	for (i=0; i<m_n; i++)
		m_pdon[i] = 20.*(double)rand()/RAND_MAX-10.0;
}

ostream& operator<< (ostream& os,const CVect &V)
{
	int i;
	if (V.m_n > 0)
		for (i=0; i<V.m_n; i++)
			os << V.m_pdon[i] << " ";
	else 
		os << "vecteur vide ";
	os << endl;
	return (os);
}

void CVect::Ecrit(char* name)
{
	fstream fl(name,ios::out);

	if (!fl)
	{
		cerr << "Erreur ouverture fichier : " << name << endl;
		exit(1);
	}

    // NB: Si on souhaite modifier le format d'éciture
//	fl.setf(ios::scientific|ios::showpos);

	for (int i=0; i<m_n; i++)
		fl << m_pdon[i] << " ";
	fl.close();
}

void CVect::Lit(char* name)
{
	double tmp;
	fstream fl(name,ios::in);
	if (!fl)
	{
		cerr << "Erreur ouverture fichier : " << name << endl;
		exit(1);
	}

    // Comptage du nombre d'éléments du flux, version flux texte
	int i = 0;
	while (!fl.eof())
	{
		fl >> tmp;
		i++;
	}
    
    // Nettoyage des tampons mémoires
	fl.clear();
    
    // Repositionnement en début du fichier
	fl.seekg(0,ios::beg); 

    // Allocation mémoire
	m_n = i-1;
	if (m_pdon != NULL) delete [] m_pdon;
	m_pdon = new double [m_n];

	i = 0;
	while (!fl.eof())
	{
		fl >> m_pdon[i];
		i++;
	}
	fl.close();
}


void CVect::Ecrit_Bin(char *name)
{
	fstream fl(name,ios::out);

	if (!fl)
	{
		cerr << "Erreur ouverture fichier : " << name << endl;
		exit(1);
	}

    // Ecriture dans le flux
	fl.write((char*)m_pdon,m_n*sizeof(double));
	fl.close();
}

void CVect::Lit_Bin(char* name)
{
	fstream fl(name,ios::in);

	if (!fl)
	{
		cerr << "Erreur ouverture fichier : " << name << endl;
		exit(1);
	}
    
    // Positionnement en fin de fichier pour ensuite lire la taille du fichier
    // et calculer le nombre d'éléments
	fl.seekp(0,ios::end);
	m_n = (int)(fl.tellp()/sizeof(double));

    // Allocation mémoire
	if (m_pdon != NULL) delete [] m_pdon;
	m_pdon = new double [m_n];

    // Nettoyage des tampons mémoires
	fl.clear();
    
    // Repositionnement en début du fichier
	fl.seekp(0,ios::beg);
    
    // Lecture du flux
	fl.read((char*)m_pdon,m_n*sizeof(double));
    
    // Fermetture du flux
	fl.close();
}

void CVect::Add_Flux(char *name)
{
	char extname[3];
    
    // Ouverture du flux en mode ajout
	fstream fl(name,ios::app);

	if (!fl)
	{
		cerr << "Erreur ouverture fichier : " << name << endl;
		exit(1);
	}

    // Lecture de l'extension du fichier ".txt" ou ".bin"
	for (int i=0; i<3; i++)
		extname[2-i] = name[strlen(name)-i-1];

    // Ajout en mode binaire
	if (!strcmp(extname,"bin"))
		fl.write((char*)m_pdon,m_n*sizeof(double));
    // Ajout en mode text
	else if(!strcmp(extname,"txt"))
		for (i=0; i<m_n; i++)
			fl << m_pdon[i] << " ";
	else
		cerr << "erreur extension" << endl;

	fl.close();
}
