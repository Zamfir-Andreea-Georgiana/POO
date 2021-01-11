/* Zamfir Andreea Georgiana, grupa 211
Compilator: GNU GCC Compiler in Codeblocks
Tutore de laborator: Eduard Gabriel Szmeteanca*/

// Pentru constructori si destructori am preluat modelul de sintaxa din laboratorul 3 si din proiectul personal
// Pentru citiri si afisari am preluat modelul de sintaxa din laboratorul 4 si din proiectul personal
// Pentru lista am preluat modelul de sintaxa din laboratorul 10 si din proiectul personal

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <list>

using namespace std;

class Vaccin
{
protected:
    float pret;
    float temperatura_depozitare;
    list <string> compozitie;

public:
    Vaccin()        //constructor fara parametri
    {
        pret=0;
        temperatura_depozitare=0;
        //compozitie="necunoscut";
    }
    Vaccin(float pret, float temperatura_depozitare, list <string> compozitie)        //constructor cu parametri
    {
        this->pret=pret;
        this->temperatura_depozitare=temperatura_depozitare;
        this->compozitie=compozitie;
    }
    Vaccin(const Vaccin& v)        //constructor de copiere
    {
        this->pret=v.pret;
        this->temperatura_depozitare=v.temperatura_depozitare;
        this->compozitie=v.compozitie;
    }

    ~Vaccin();      //destructor
};

class VaccinAntigripal: public Vaccin
{
private:
    string tulpini;
    bool respecta_recomandarile_OMS;
public:
    VaccinAntigripal()        //constructor fara parametri
    {
        tulpini="necunoscut";
        respecta_recomandarile_OMS=false;
    }
    VaccinAntigripal(string tulpini, bool respecta_recomandarile_OMS)        //constructor cu parametri
    {
        this->tulpini=tulpini;
        this->respecta_recomandarile_OMS=respecta_recomandarile_OMS;
    }
    VaccinAntigripal(const VaccinAntigripal& vag)        //constructor de copiere
    {
        this->tulpini=vag.tulpini;
        this->respecta_recomandarile_OMS=vag.respecta_recomandarile_OMS;
    }
    //void citire (istream& in);
    //void afisare (ostream &out);
    //friend istream& operator >> (istream&, VaccinAntigripal&);
   // friend ostream& operator << (ostream&, VaccinAntigripal&);
    ~VaccinAntigripal();        //destructor
};
//istream& operator>> (istream& in, VaccinAntigripal& x){
  //  x.citire(in);
   // return in;

//ostream& operator<< (ostream& out, VaccinAntigripal& x){
    //x.afisare(out);
   // return out;

class VaccinAntihepatic: public Vaccin
{
private:
    char tip_hepatita;
    string mod_de_vaccinare;
public:
    VaccinAntihepatic()        //constructor fara parametri
    {
        //tip_hepatita="necunoscut";
        mod_de_vaccinare="necunoscut";
    }
    VaccinAntihepatic(char tip_hepatita, string mod_de_vaccinare)        //constructor cu parametri
    {
        this->tip_hepatita=tip_hepatita;
        this->mod_de_vaccinare=mod_de_vaccinare;
    }
    VaccinAntihepatic(const VaccinAntihepatic& vah)        //constructor de copiere
    {
        this->tip_hepatita=vah.tip_hepatita;
        this->mod_de_vaccinare=vah.mod_de_vaccinare;
    }
    ~VaccinAntihepatic();        //destructor
};

class VaccinAntiSarsCov2: public Vaccin
{
private:
    list <string> reactii_adverse_posibile;
    float rata_de_eficienta;
    list <string> medicamente_contraindicate;
public:
    VaccinAntiSarsCov2()        //constructor fara parametri
    {
        //reactii_adverse_posibile="necunoscut";
        rata_de_eficienta=0;
        //medicamente_contraindicate="necunoscut";
    }
    VaccinAntiSarsCov2(list <string> reactii_adverse_posibile, float rata_de_eficienta, list <string> medicamente_contraindicate)        //constructor cu parametri
    {
        this->reactii_adverse_posibile=reactii_adverse_posibile;
        this->rata_de_eficienta=rata_de_eficienta;
        this->medicamente_contraindicate=medicamente_contraindicate;
    }
    VaccinAntiSarsCov2(const VaccinAntiSarsCov2& vac)        //constructor de copiere
    {
        this->reactii_adverse_posibile=vac.reactii_adverse_posibile;
        this->rata_de_eficienta=vac.rata_de_eficienta;
        this->medicamente_contraindicate=vac.medicamente_contraindicate;
    }
    ~VaccinAntiSarsCov2();      //destructor
};

class Comanda
{
private:
    int id_comanda;
    char* data;
    string nume_client;
    list<Vaccin*> listaVaccinuri;
    int cantitate;
public:
    Comanda()        //constructor fara parametri
    {
        id_comanda=0;
        this->data=new char[strlen("data")+1];
        strcpy(this->data, data);
        nume_client="necunoscut";
        //listaVaccinuri="necunoscuta";
        cantitate=0;
    }
    Comanda(int id_comanda, char* data, string nume_client, list<Vaccin*> listaVaccinuri, int cantitate)        //constructor cu parametri
    {
        this->id_comanda=id_comanda;
        if(this->data!=NULL)
                    delete[] this->data;
        this->data=new char[strlen("data")+1];
        strcpy(this->data, data);
        this->nume_client=nume_client;
        this->listaVaccinuri=listaVaccinuri;
        this->cantitate=cantitate;
    }
    Comanda(const Comanda& com)        //constructor de copiere
    {
        this->id_comanda=com.id_comanda;
        this->data=new char[strlen(com.data)+1];
        strcpy(this->data, com.data);
        this->nume_client=com.nume_client;
        this->listaVaccinuri=com.listaVaccinuri;
        this->cantitate=com.cantitate;
    }
    ~Comanda()      //destructor
    {
        if(this->data!=nullptr)
            delete[] this->data;
    }

};

/*class ListaComenzi
{
private:

public:
};*/

int main()
{
/*VaccinAntigripal a;
VaccinAntihepatic b;
VaccinAntiSarsCov2 c;
cin>>a>>b>>c;
cout<<a<<b<<c;
Vaccin* list1[3];
list1[0]=new VaccinAntigripal();
list1[1]=new VaccinAntihepatic ();
list1[2]=new VaccinAntiSarsCov2();
for(int i=0; i<3; i++)
list1[i]-> afisareSchemaVaccinare();
Comanda com1(“20-12-2020”, ”SpitalX”, ”AntiSarsCov2”,20);
ListaComenzi lista;
lista=lista+com1;
cout<<lista[0];*/


/* meniu
    int optiune;
    optiune=0;
    int n=0;
    do
    {
        cout<<"1. Adauga un vaccin nou"<<endl;
        cout<<"2. Afiseaza toate vaccinurile"<<endl;
        cout<<"3. Afiseaza numele producatorilor pentru taote vaccinurile"<<endl;
        cout<<"4. Adauga o comanda"<<endl;
        cout<<"5. Afiseaza toate comenzile"<<endl;
        cout<<"6. Afiseaza valoarea comenzilor dintr-o anumita zi"<<endl;
        cout<<"7. Afiseaza schema de vaccinare pentru un anumit tip de vaccin"<<endl;
        cout<<"8. Exporta comenzile intr-un fisier"<<endl;
        cout<<"0. Iesire."<<endl;
        cout<<"Scrieti optiunea dorita: ";
        cin>>optiune;
        if (optiune==1)
        {

        }
        if (optiune==2)
        {

        }
        if (optiune==3)
        {

        }
        if (optiune==4)
        {

        }
        if (optiune==5)
        {

        }
        if (optiune==6)
        {

        }
        if (optiune==7)
        {

        }
        if (optiune==8)
        {

        }
        if (optiune==0)
        {
            cout<<"\nIesire\n";
        }
        if (optiune<0||optiune>8)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause"); ///Apasati orice tasta pentru a continua
    }
    while(optiune!=0);
*/

return 0;
}
