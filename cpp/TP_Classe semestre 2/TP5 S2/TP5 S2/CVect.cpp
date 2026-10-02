#include "CVect.hpp"


CVect::CVect(int N)
:m_N(N)
{
    m_vect=new double[m_N];
}

CVect::CVect(double *vect, int N)
:m_vect(NULL), m_N(N)
{
    if (m_N > 0)
    {
        //m_vect=vect? new double[m_N]:NULL;
        m_vect = new double[m_N];
        if(m_vect!=NULL)
        {
            for (int i = 0; i < m_N; i++)
            {
                m_vect[i] = vect[i];
            }
        }
        else
        {
            m_vect=NULL;
        }
    }
}

CVect::CVect(const CVect &V)
    : m_vect(NULL), m_N(V.m_N)
{
    if (m_N > 0)
    {
        m_vect = new double[m_N];
        for (int i = 0; i < m_N; i++)
        {
            m_vect[i] = V.m_vect[i];
        }
    }
}

CVect::~CVect()
{
    if (m_vect != NULL)
        delete[] m_vect;
}

void CVect::remplir()
{
    if (m_N > 0)
    {
        srand((unsigned int)time(NULL));
        //m_vect = new double[m_N];
        for (int i = 0; i < m_N; i++)
        {
            m_vect[i] = -10 + (10 - (-10)) * (double)rand() / RAND_MAX;
        }
    }
}

void CVect::Ecrit(char *nom_fichier)
{
    strcat(nom_fichier, ".txt");
    ofstream fichier(nom_fichier,ios::out);
    
    if (fichier.is_open())
    {
        fichier<<m_N<<" ";
        for(int i=0; i<m_N; i++)
        {
            fichier<<m_vect[i]<<" ";
        }
        fichier<<"\n";
        cout<<"les élements ont été écris dans "<<nom_fichier<<endl;
    }
    else
    {
        cout<<"erreur d'ouverture du fichier\n";
    }
    fichier.close();
    //taille_du_fichier = sizeof(int)+(taille du tableau × sizeof(double))
    //taille_du_fichier = 4octets+(4×8octets) = 4 + 40 = 44octets
}

ostream &operator<<(ostream &cout, const CVect &V)
{
    cout<<"nombre d'élements: "<<V.m_N<<endl;
    for(int i=0; i<V.m_N; i++)
    {
        cout<<"élement "<<i+1<<" : "<<V.m_vect[i]<<endl;
    }
    return cout;
    
}


void CVect::Lit(char *nom_fichier)
{
    ifstream fichier(nom_fichier,ios::in);
    if (fichier.is_open())
    {
        fichier>>m_N;
        if(m_vect!=NULL) delete []m_vect;
        m_vect=new double[m_N];
        for(int i=0; i<m_N; i++)
        {
            fichier >> m_vect[i];
        }
        
    }
    else
    {
        cout<<"erreur d'ouverture du fichier\n";
    }
    fichier.close();
}


void CVect::Ecrit_Bin(char *nom_fichier)
{
    strcat(nom_fichier, ".bin");
    ofstream fichier(nom_fichier,ios::out);
    if (fichier.is_open())
    {
       // fichier.write((char *)&m_N, sizeof(m_N));
        fichier.write((char *)m_vect, m_N * sizeof(double));
    }
    else
    {
        cout<<"erreur d'ouverture du fichier\n";
    }
    fichier.close();
    cout<<"les élements ont été écris dans "<<nom_fichier<<endl;
}


void CVect::Lit_Bin(char *nom_fichier)
{
    ifstream fichier(nom_fichier,ios::in);
    if (fichier.is_open())
    {
        //fichier.flush();
        fichier.seekg(0,ios::end);
        m_N=(int)fichier.tellg()/sizeof(double);
        fichier.clear();
        fichier.seekg(0,ios::beg);
        //fichier.read((char *)&m_N, sizeof(m_N));
        if(m_vect!=NULL) delete []m_vect;
        m_vect=new double[m_N];
        fichier.read((char *)m_vect, m_N * sizeof(double));
    }
    fichier.close();
}

void CVect::Add_Flux(char *nom_fichier)
{
    int ext=0;
    //char extention;
    long L=strlen(nom_fichier);
    if((nom_fichier[L-1]=='t') && (nom_fichier[L-2]=='x') && (nom_fichier[L-3] == 't'))
    {ext = 1;}
    else if((nom_fichier[L-1]=='b') && (nom_fichier[L-2]=='i') && (nom_fichier[L-3] == 'n'))
    {ext = 2;}
    
    {
        fstream fichier(nom_fichier,ios::app);//reouverture du fichier
        if(fichier.is_open())
        {
            if(ext==1)
            {
                fichier<<m_N<<" ";
                for(int i=0; i<m_N; i++)
                {
                    fichier<<m_vect[i]<<" ";
                }
                cout<<"des élements ont été ajoutés dans le fichier.txt \n";
            }
            else if(ext==2)
            {
                //fichier.write((char *)&m_N, sizeof(m_N));
                fichier.write((char *)m_vect, m_N * sizeof(double));
            }
            fichier.close();
            //cout<<"des élements ont été ajoutés dans le fichier .bin \n";
        }
        else
            cout<<"erreur d'ouverture \n";
    }
}

