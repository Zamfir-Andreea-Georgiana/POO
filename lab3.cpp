#include <iostream>
#include <string.h>// strcpy, strlen....

using namespace std;

class Student{
// private, protected, public

private:
    const int ID_Matricol;
    int varsta;
    char* nume;
    int nrNote;
    int* note;
public:
    static int anCurent;
    static void mesaj(){

        cout<<"Bine ati venit studenti de anul  "<<anCurent;

    }

    Student():ID_Matricol(00000){

        varsta=0;
        nume=new char[strlen("Anonim")+1];
        strcpy(this->nume,"Anonim");

    }



    Student(int id,int varsta, char* nume, int nrNote, int* note):ID_Matricol(id){

        this->varsta=varsta;

        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);

        this->nrNote=nrNote;

        this->note=new int[nrNote];

        for(int i=0; i<nrNote; i++)
            this->note[i]=note[i];



    }

    Student(int varsta):ID_Matricol(00){

        this->varsta=varsta;

    }


    void afisare(){

        cout<<"Student "<<this->nume<<" are urmatoarele note: ";
        for(int i=0; i<this->nrNote; i++)
            cout<<this->note[i]<<" ";

    }
    int getNrNote(){

        return this->nrNote;
    }

    char* getNume(){
        return this->nume;
    }
    int* getNote(){
        return this->note;// forma frumoasa este cu this

    }
    int getVarsta(){
        return varsta;

    }

    void setVarst(int a)
    {
        this->varsta=a;
    }

    void setNume(char* a){

            if(this->nume!=nullptr)
                delete[] this->nume;

            this->nume=new char[strlen(a)+1];
            strcpy(this->nume,a);

    }

    void setNote(int* a, int b)
   {
       if(this->note!=nullptr)
        delete[] this->note;

       this->nrNote=b;
       this->note=new int[b];

       for(int i=0; i<b;i++)
        this->note[i]=a[i];
   }

    float medieStudent(){

        float medie_note;
        for(int i=0; i<this->nrNote;i++)
            medie_note=medie_note+this->note[i];
        medie_note=medie_note/this->nrNote;
        return medie_note;


    }

    ~Student(){

        if(this->note!=nullptr)
            delete[] this->note;
        if(this->nume!=nullptr)
            delete[] this->nume;


    }



};

int Student::anCurent=2;

int main()
{
    /*
    cout<<Student::anCurent;
    Student::mesaj();
*/

   Student s;

   char nume[]={"POO"};
   char nume2[]={"POO2"};
   int alabalaprocola[]={5,6,7,8};
   int alabalaprocola2[]={5,6,7,8,10};

   Student s2(101,3,nume,4,alabalaprocola);
   s2.afisare();

   cout<<s2.getNume();
   cout<<endl;
   s2.setNume(nume2);
    cout<<s2.getNume()<<endl;
   int* note=s2.getNote();
   for(int i=0;i<s2.getNrNote();i++)
        cout<<*(note+i)<<" ";
    cout<<endl<<endl;
    cout<<s2.getVarsta();
    cout<<endl;
    s2.setVarst(24);
    cout<<s2.getVarsta();
    cout<<"---------------------------------\n";
    int* note2=s2.getNote();
    for(int i=0;i<s2.getNrNote();i++)
        cout<<*(note2+i)<<" ";

    cout<<endl;

    s2.setNote(alabalaprocola2,5);

    int* note3=s2.getNote();
    for(int i=0;i<s2.getNrNote();i++)
        cout<<*(note3+i)<<" ";
    cout<<"----------\n";
        cout<<s2.medieStudent();


    return 0;
}
