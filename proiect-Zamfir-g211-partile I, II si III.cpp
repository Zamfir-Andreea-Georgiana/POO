//Zamfir Andreea-Georgiana, grupa 211
//proiect de gestionare a unui magazin de produse kpop

#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <iterator>
#include <set>
#include <map>
#include <fstream>
#include <exception>

using namespace std;


/* PARTEA INTAI*/

class Produs
{
protected:
    const int cod=0;    //codul produsului
    int cantitate;
    bool stoc;
    char p;
    char* denumire;
    char tip[100];
    float pret;
    int* a;
    double rating;

public:
    static int TVA;

    Produs()        //constructor fara parametri
    {
        cantitate=0;
        stoc=false;
        denumire=new char[strlen("necunoscuta")+1];
        strcpy(this->denumire,"necunoscuta");
        strcpy(tip,"necunoscut");
        pret=0;
        rating=0;

    }

    Produs(const int cod, bool stoc, char* denumire, float pret)       //constructor cu parametri
    {
        this->stoc=stoc;
        this->denumire=new char[strlen(denumire)+1];
        strcpy(this->denumire,denumire);
        this->pret=pret;
    }

    Produs(const int cod, int cantitate, bool stoc, char* denumire, char tip[100], float pret, double rating)       //constructor cu parametri
    {
        this->cantitate=cantitate;
        this->stoc=stoc;
        this->denumire=new char[strlen(denumire)+1];
        strcpy(this->denumire,denumire);
        strcpy(this->tip,tip);
        this->pret=pret;
        this->rating=rating;
    }

    Produs(const Produs& prod)      //constructor de copiere
    {
        this->cantitate=prod.cantitate;
        this->stoc=prod.stoc;
        this->denumire=new char[strlen(prod.denumire)+1];
        strcpy(this->denumire,prod.denumire);
        strcpy(this->tip, prod.tip);
        this->pret=prod.pret;
        this->rating=prod.rating;
    }

    Produs& operator=(const Produs& prod)      //supraincarcare operator =
    {
        if (this!=&prod)
        {
            this->cantitate=prod.cantitate;
            this->stoc=prod.stoc;

            if(this->denumire!=NULL)
                    delete[] this->denumire;
            this->denumire=new char[strlen(prod.denumire)+1];
            strcpy(this->denumire,prod.denumire);
            strcpy(this->tip, prod.tip);
            this->pret=prod.pret;
            this->rating=prod.rating;
        }
        return *this;
    }

    const Produs operator++()      //operator ++ pre-incrementare
    {
        this->cantitate++;
        return *this;
    }

    const Produs operator++(int)  //operator ++ post-incrementare
    {
        Produs aux(*this);
        this->cantitate++;
        return aux;
    }

    Produs& operator +(Produs& prod)     //supraincarcare operator +
    {
    prod.cantitate= this->pret + prod.cantitate;
    return prod;
    }

    Produs& operator -(Produs& prod)     //supraincarcare operator -
    {
    prod.cantitate= this->pret - prod.cantitate;
    return prod;
    }
    /*int operator [](int index)      //supraincarcare operator de indexare
    {
        if(index<this->cantitate && index>0)
            return this->cantitate[index];
        else {cout<<"Index invalid";
                return -1;}
    }*/

    bool operator ==(Produs& p1)        //supraincarcare operator ==
    {
    float pret1;
    pret1=p1.pret;
        if(pret1==pret)
            {return true;}
        else
           {return false;}
    }

    explicit operator int()     //supraincarcare cast explicit
    {
        return (int)this->pret;

    }

    bool operator<(Produs& p1)        //supraincarcare operator <
    {
    float pret1;
    pret1=p1.pret;
        if(pret1<pret)
            {return true;}
        else
           {return false;}
    }

    friend istream& operator>>(istream &in, Produs& prod)     //supraincarcare operator >>
    {
        char aux[100];
        cout<<"Introduceti denumirea produsului: ";
        in.getline(aux, 100);
        prod.denumire=new char[strlen(aux)+1];
        strcpy(prod.denumire,aux);
        cout<<"Introduceti cantitatea: ";
        in>>prod.cantitate;
        //cout<<"\n Introduceti tipul produsului: ";
        cout<<"Introduceti pretul: ";
        in>>prod.pret;
        cout<<"Introduceti ratingul: ";
        in>>prod.rating;

        return in;
    }

    friend ostream& operator<<(ostream &out, Produs& prod)      //supraincarcare operator <<
    {
          out<<"\n Produsul "<<prod.denumire<<" are pretul de "<<prod.pret<<" de lei si ratingul de "<<prod.rating<<". Sunt "<<prod.cantitate<<" bucati pe stoc."<<endl;
    }


    char* getDenumire()
    {
        return this->denumire;
    }

    int getCantitate()
    {
        return this->cantitate;
    }

    float getPret()
    {
        return this->pret;
    }

    void setDenumire(char* a)
    {

            if(this->denumire!=nullptr)
                delete[] this->denumire;

            this->denumire=new char[strlen(a)+1];
            strcpy(this->denumire,a);
    }

    void setCantitate(int a)
    {
        this->cantitate=a;
    }

    void setPret(float a)
    {
        this->pret=a;
    }

    ~Produs()       //destructor
    {
        if(this->denumire!=nullptr)
            delete[] this->denumire;
    }

};

class Comanda
{
protected:
    const long int numar=0;    //numarul comenzii
    int nrProduse;     //numarul de produse din comanda
    bool clientNou;
    char c;
    char* numeClient;
    char AWBcolet[100];
    float comision;
    int* s;
    double pretTotal;

public:
    static float taxaLivrare;

    Comanda()       //constructor fara parametri
    {
        nrProduse=0;
        clientNou=false;
        numeClient=new char[strlen("Anonim")+1];
        strcpy(this->numeClient,"Anonim");
        strcpy(AWBcolet, "necunoscut");
        comision=0;
        pretTotal=0;

    }

    Comanda(const long int numar, int nrProduse, char* numeClient, double pretTotal)        //constructor cu parametri
    {
        this->nrProduse=nrProduse;
        this->numeClient=new char[strlen("numeClient")+1];
        strcpy(this->numeClient, numeClient);
        this->pretTotal=pretTotal;
    }

    Comanda(const long int numar, int nrProduse, bool clientNou, char* numeClient, char AWBcolet[100], float comision, double pretTotal)        //constructor cu parametri
    {
        this->nrProduse=nrProduse;
        this->clientNou=clientNou;
        if(this->numeClient!=NULL)
                    delete[] this->numeClient;
        this->numeClient=new char[strlen("numeClient")+1];
        strcpy(this->numeClient, numeClient);
        strcpy(this->AWBcolet,AWBcolet);
        this->comision=comision;
        this->pretTotal=pretTotal;
    }

    Comanda(const Comanda& com)     //constructor de copiere
    {
        this->nrProduse=com.nrProduse;
        this->clientNou=com.clientNou;
        this->numeClient=new char[strlen(com.numeClient)+1];
        strcpy(this->numeClient, com.numeClient);
        strcpy(this->AWBcolet, com.AWBcolet);
        this->comision=com.comision;
        this->pretTotal=com.pretTotal;
    }

    Comanda& operator=(const Comanda& com)     //supraincarcare operator =
    {
        if (this!=&com)
        {
            this->nrProduse=com.nrProduse;
            this->clientNou=com.clientNou;
            this->numeClient=new char[strlen(com.numeClient)+1];
            strcpy(this->numeClient, com.numeClient);
            strcpy(this->AWBcolet, com.AWBcolet);
            this->comision=com.comision;
            this->pretTotal=com.pretTotal;
        }
        return *this;
    }

    const Comanda operator++()      //operator ++ pre-incrementare
    {
        this->nrProduse++;
        return *this;
    }

    const Comanda operator++(int)  //operator ++ post-incrementare
    {
        Comanda aux(*this);
        this->nrProduse++;
        return aux;
    }

    Comanda& operator +(Comanda& com)        //supraincarcare operator +
    {
    com.pretTotal= this->pretTotal + com.pretTotal;
    return com;
    }

    Comanda& operator -(Comanda& com)        //supraincarcare operator -
    {
    com.pretTotal= this->pretTotal - com.pretTotal;
    return com;
    }

    /*int operator [](int index)      //supraincarcare operator de indexare
    {
        if(index<this->nrProduse && index>0)
            return this->nrProduse[index];
        else {cout<<"Index invalid";
                return -1;}
    }*/

    bool operator ==(Comanda& c1)        //supraincarcare operator ==
    {
    float pretTotal1;
    pretTotal1=c1.pretTotal;
        if(pretTotal1==pretTotal)
            {return true;}
        else
           {return false;}
    }

    explicit operator int()     //supraincarcare cast explicit
    {
        return (int)this->pretTotal;

    }

    bool operator<(Comanda& c1)        //supraincarcare operator <
    {
    float pretTotal1;
    pretTotal1=c1.pretTotal;
        if(pretTotal1<pretTotal)
            {return true;}
        else
           {return false;}
    }

    friend istream& operator>>(istream &in, Comanda& com)     //supraincarcare operator >>
    {
        /*char aux2[100];
        cout<<"Introduceti numele clientului: ";
        in.getline(aux2, 100);
        com.numeClient=new char[strlen(aux2)+1];
        strcpy(com.numeClient,aux2);*/
        cout<<"Intoduceti numarul de produse: ";
        in>>com.nrProduse;
        cout<<"Introduceti pretul total: ";
        in>>com.pretTotal;

        return in;
    }

    friend ostream& operator<<(ostream &out, Comanda& com)      //supraincarcare operator <<
    {
          out<<"Comanda doamnei/domnului "<<com.numeClient<<" are "<<com.nrProduse<<" produse si costa "<<com.pretTotal<<" lei."<<endl;
    }

    int getNrProduse()
    {
        return this->nrProduse;
    }

    double getPretTotal()
    {
        return this->pretTotal;
    }

    void setNrProduse(int a)
    {
        this->nrProduse=a;
    }
    void setPretTotal(int a)
    {
        this->pretTotal=a;
    }

    ~Comanda()      //destructor
    {
        if(this->numeClient!=nullptr)
            delete[] this->numeClient;
    }
};

class Client
{
private:
    char* nume;
    char adresa[100];
    char mail[100];

public:
    int varsta;
    char telefon[11];
    Client()        //constructor fara parametri
    {
        nume=new char[strlen("Anonim")+1];
        strcpy(this->nume,"Anonim");
        varsta=0;
        strcpy(adresa, "necunoscuta");
        strcpy(telefon, "necunoscut");
        strcpy(mail, "necunoscut");
    }

    Client(char* nume, char mail[100])      //constructor cu parametri
    {
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        strcpy(this->mail, mail);
    }

    Client(char* nume, int varsta, char adresa[100], char telefon[11], char mail[100])      //constructor cu parametri
    {
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->varsta=0;
        strcpy(this->adresa, adresa);
        strcpy(this->telefon, telefon);
        strcpy(this->mail, mail);
    }

    Client(const Client& cl)        //constructor de copiere
    {
        this->nume=new char[strlen(cl.nume)+1];
        strcpy(this->nume,cl.nume);
        this->varsta=cl.varsta;
        strcpy(this->adresa, cl.adresa);
        strcpy(this->telefon, cl.telefon);
        strcpy(this->mail, cl.mail);
    }

    Client& operator=(const Client& cl)        //supraincarcare operator =
    {
        if (this!=&cl)
        {
        if(this->nume!=NULL)
                delete[] this->nume;
        this->nume=new char[strlen(cl.nume)+1];
        strcpy(this->nume,cl.nume);
        this->varsta=cl.varsta;
        strcpy(this->adresa, cl.adresa);
        strcpy(this->telefon, cl.telefon);
        strcpy(this->mail, cl.mail);
        }
        return *this;
    }


    friend istream& operator>>(istream &in, Client& cl)     //supraincarcare operator >>
    {
        /*char aux[100];
        cout<<"Introduceti numele clientului: ";
        in.getline(aux, 100);
        cl.nume=new char[strlen(aux)+1];
        strcpy(cl.nume,aux);*/
        cout<<"Introduceti varsta clientului: ";
        in>>cl.varsta;
        cout<<"Introduceti orasul: ";
        in>>cl.adresa;
        cout<<"Introduceti numarul de telefon: ";
        in>>cl.telefon;
        cout<<"Introduceti mailul: ";
        in>>cl.mail;
        return in;
    }
    friend ostream& operator<<(ostream &out, Client& cl)      //supraincarcare operator <<
    {
          out<<"Clientul "<<cl.nume<<" are "<<cl.varsta<<" ani. Adresa lui este: "<<cl.adresa<<" . Numarul de telefon este: "<<cl.telefon<<" . Mailul este: "<<endl;
    }
    ~Client()       //destructor
    {
        if(this->nume!=nullptr)
            delete[] this->nume;
    }
};

class Furnizor
{
private:
    char* firma;
    char sediu[100];
    char contact[11];

public:
    Furnizor()      //constructor fara parametri
    {
        firma=new char[strlen("necunoscuta")+1];
        strcpy(this->firma,"necunoscuta");
        strcpy(sediu, "necunoscut");
        strcpy(contact, "necunoscut");
    }

    Furnizor(char* firma, char contact[11])        //constructor cu parametri
    {
        firma=new char[strlen(firma)+1];
        strcpy(this->firma, firma);
        strcpy(this->contact, contact);
    }

    Furnizor(char* firma, char sediu[100], char contact[11])        //constructor cu parametri
    {
        firma=new char[strlen(firma)+1];
        strcpy(this->firma, firma);
        strcpy(this->sediu, sediu);
        strcpy(this->contact, contact);
    }

    Furnizor(const Furnizor& furn)      //constructor de copiere
    {
        firma=new char[strlen(furn.firma)+1];
        strcpy(this->firma, furn.firma);
        strcpy(this->sediu, furn.sediu);
        strcpy(this->contact, furn.contact);
    }

    Furnizor& operator=(const Furnizor& furn)      //supraincarcare operator =
    {
        if (this!=&furn)
        {
        if(this->firma!=NULL)
            delete[] this->firma;
        firma=new char[strlen(furn.firma)+1];
        strcpy(this->firma, furn.firma);
        strcpy(this->sediu, furn.sediu);
        strcpy(this->contact, furn.contact);
        }
        return *this;
    }

    friend istream& operator>>(istream &in, Furnizor& furn)     //supraincarcare operator >>
    {
        /*char aux3[100];
        cout<<"\n Introduceti firma: ";
        in.getline(aux3, 100);
        furn.firma=new char[strlen(aux3)+1];
        strcpy(furn.firma,aux3);*/
        cout<<"Introduceti orasul in care se afla sediul firmei: ";
        in>>furn.sediu;
        cout<<"Introduceti numarul de telefon al firmei: ";
        in>>furn.contact;
        return in;
    }
    friend ostream& operator<<(ostream &out, Furnizor& furn)      //supraincarcare operator <<
    {
          out<<"Firma "<<furn.firma<<" are sediul la adresa "<<furn.sediu<<" . Numarul de contact al firmei este: "<<furn.contact<<endl;
    }
    ~Furnizor()     //destructor
    {
        if(this->firma!=nullptr)
            delete[] this->firma;
    }
};


/* PARTEA A DOUA */

class Album: public Produs
{
protected:
    char* nume_trupa;
    int an_aparitie;

public:
    Album()         //constructor
    {
        nume_trupa=new char[strlen("necunoscuta")+1];
        strcpy(this->nume_trupa,"necunoscuta");
        an_aparitie=0;

    }

    Album(char* nume_trupa, int an_aparitie)        //constructor
    {
        this->nume_trupa=new char[strlen(nume_trupa)+1];
        strcpy(this->nume_trupa,nume_trupa);
        this->an_aparitie=an_aparitie;
    }

    Album(const Album& a)      //constructor de copiere
    {
        this->nume_trupa=new char[strlen(a.nume_trupa)+1];
        strcpy(this->nume_trupa,a.nume_trupa);
        this->an_aparitie=an_aparitie;
    }

    ~Album ()       //destructor
    {
        if(this->nume_trupa!=nullptr)
            delete[] this->nume_trupa;
    }

};

class Livrare_internationala: Comanda
{
protected:
    char* tara;
    float taxa_suplimentara;

public:
    Livrare_internationala()        //constructor
    {
        tara=new char[strlen("necunoscuta")+1];
        strcpy(this->tara,"necunoscuta");
        taxa_suplimentara=0;

    }

    Livrare_internationala(char* tara, int an_aparitie)     //constructor
    {
        this->tara=new char[strlen(tara)+1];
        strcpy(this->tara,tara);
        this->taxa_suplimentara=taxa_suplimentara;
    }

    Livrare_internationala(const Livrare_internationala& l)      //constructor de copiere
    {
        this->tara=new char[strlen(l.tara)+1];
        strcpy(this->tara,l.tara);
        this->taxa_suplimentara=taxa_suplimentara;
    }


    ~Livrare_internationala()       //destructor
    {
        if(this->tara!=nullptr)
            delete[] this->tara;
    }
};

class Garantie      //interfata
{
public:
    virtual int perioada()=0;
};

class Haina     //clasa abstracta
{
protected:
    float dimensiunePoza;
public:
    virtual float dimensiuneImprimeu() = 0;

    friend istream& operator >>(istream& in, Haina&h){
        cout<<"Dimensiunea pozei este: ";
        in>>h.dimensiunePoza;
        return in;

    }

};

class Eticheta
{
    string material;
    float elasticitate;
    string taraFabricatie;
};

class Tricou: public Haina
{
    Eticheta t;             //HAS-A
    public:
    virtual float dimensiuneImprimeu()
    {
        return dimensiunePoza*5;
    }

};


int main()
{

/* PARTEA A TREIA */

    Produs p;
    cin>>p;
    cout<<p;
    Comanda c;
    cin>>c;
    cout<<c;
    Client cl;
    cin>>cl;
    cout<<cl;
    Furnizor f;
    cin>>f;
    cout<<f;
    return 0;


    vector <Album*> listaAlbume;        //vector
    Album a;
    cin>>a;
    listaAlbume.push_back(&a);
     for (auto i = listaAlbume.begin(); i != listaAlbume.end(); i++)
        cout<<*i<<" ";

    list <Produs*> listaProduse;        //lista
    Produs pr;
    listaProduse.push_back(&pr);
    list <Produs*> :: iterator j;
    for(j = listaProduse.begin(); j != listaProduse.end(); j++)
        cout<<*j<< " ";

    set <Tricou*> listaTricouri;        //set
    Tricou t;;
    listaTricouri.insert(&t);
    set <Tricou*> :: iterator k;
    for(k = listaTricouri.begin(); k != listaTricouri.end(); k++)
        cout<<*k<< " ";

    map<string, int> m;     //map
    map<string, int>::iterator it;
    for(it = m.begin(); it!= m.end(); it++)
    m.insert(pair<string, int> ("Album_BTS", 12345));

    ifstream fisierin("Produs.in");     //scriere in fisier
    fisierin>>p;
    ofstream fisierout("Produs.out");       //citire din fisier
    fisierout<<p;

    try         //exceptia 1
    {
        if (cl.varsta >=14)
            cout<<"Cont creat.";
        else
        {
        throw(cl.varsta);
        }

    }
    catch (int altaVarsta)
    {
        cout<<"Contul nu poate fi creat. Trebuie sa ai minim 14 ani."<<endl;
        cout<<"Varsta este: "<<altaVarsta;
    }

    try         //exceptia 2
    {
        if (sizeof(cl.telefon) == 10)
            cout<<"Numarul de telefon introdus este valid.";
        else
        {
        throw(cl.telefon);
        }

    }
    catch (int altNumar)
    {
        cout<<"Numarul de telefon introdus nu este valid."<<endl;
        cout<<"Numarul de telefon este: "<<altNumar;
    }

    return 0;
}
