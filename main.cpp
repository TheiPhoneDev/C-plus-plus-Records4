#include <iostream>

using namespace std;

struct Studente {
    string nome;
    string cognome;
    float voto;
    
};

const int dimensioneMax=100;

//prototipi
void carica(Studente v[], int &n, Studente v2[], int &k, Studente v3[], int &j);
float media(Studente v[], int n);
void votoMaggiore(Studente v[], int n);
void insufficienze(Studente v[], int n);
float percAssenti(int n, int k);
void stampa(Studente v[], int n);
int Menu();


int main() {
    
    int n=0;
    Studente studenti[dimensioneMax];
    Studente assenti[dimensioneMax];
    Studente presenti[dimensioneMax];
    int scelta;
    float m=0.00;
    int k=0;
    int j=0;
    float perc=0.00;
    
    carica(studenti,n,assenti,k,presenti,j);

    do {
        scelta=Menu();
        switch(scelta) {
            case 1:
                stampa(studenti,n);
            break;
            case 2:
                m=media(studenti,n);
                cout<<"La media dei voti e' : "<<m<<endl;
            break;
            case 3:
                votoMaggiore(presenti,j);
            break;
            case 4:
                insufficienze(presenti,j);
            break;
            case 5:
                perc=percAssenti(n,k);
                cout<<"La percentuale di studenti assenti e' del "<<perc<<"%"<<endl;
            break;
        }
    }while(scelta!=0);

    return 0;
}

int Menu () {
  int scegli;
  cout<<"-------MENU'-------"<<endl;
  cout<<"1-Visualizza studenti"<<endl;
  cout<<"2-Calcola media voti"<<endl;
  cout<<"3-Visualizza studente con voto piu' alto"<<endl;
  cout<<"4-Visualizza studenti insufficienti"<<endl;
  cout<<"5-Percentuale studenti assenti"<<endl;

  cout<<"0-Fine"<<endl;

  cout<<"Scegli un operazione: "<<endl;
  cin>>scegli;

  return scegli;
}

void carica(Studente v[], int &n, Studente v2[], int &k, Studente v3[], int &j) {
    
    cout<<"Quanti studenti vuoi registrare ? : ";
    cin>>n;
    
    for(int i=0; i<n; i++) {
        cout<<endl;
        cout<<"Inserisci il nome dello studente: ";
        cin>>v[i].nome;
        cout<<"Inserisci il cognome dello studente: ";
        cin>>v[i].cognome;
        do{
            cout<<"Inserisci il voto: ";
            cin>>v[i].voto;
        }while(v[i].voto<0);
        if(v[i].voto==0) {
            v2[i]=v[i];
            k++;
        }
        if(v[i].voto>0) {
            v3[i]=v[i];
            j++;
        }
        cout<<endl;
    }

    cout<<endl;
        
}

void stampa(Studente v[], int n) {
    
    cout<<endl;
    
    cout<<"Studenti: "<<endl;
    
    cout<<endl;
    
    for(int i=0; i<n; i++) {
        cout<<endl;
        cout<<"Nome studente: "<<v[i].nome<<endl;
        cout<<"Cognome studente: "<<v[i].cognome<<endl;
        cout<<"Voto: "<<v[i].voto<<endl;
        cout<<endl;
    }
    
    cout<<endl;
    
}



float media(Studente v[], int n) {
   
   float m=0.00;
   float s=0.00;
   
   for(int i=0; i<n; i++) {
       s=s+v[i].voto;
   }
   
   m=s/n;
   
   return m;
   
    
}

void votoMaggiore(Studente v[], int n) {

    float votoMax=v[0].voto;
    string nome;
    string cognome;
    
    cout<<endl;
    

    for(int i=0; i<n; i++) {
        if(v[i].voto>votoMax) {
            votoMax=v[i].voto;
            nome=v[i].nome;
            cognome=v[i].cognome;
        }
    }

    cout<<"Studente con voto maggiore: "<<endl;

    cout<<endl;
    cout<<"Nome: "<<nome<<endl;
    cout<<"Cognome: "<<cognome<<endl;
    cout<<"Voto: "<<votoMax<<endl;
    cout<<endl;
    


}

void insufficienze(Studente v[], int n) {


    cout<<endl;

    cout<<"Studenti insufficienti: "<<endl;

    cout<<endl;

    for(int i=0; i<n; i++) {
        if(v[i].voto<6) {
            cout<<endl;
            cout<<"Nome studente: "<<v[i].nome<<endl;
            cout<<"Cognome studente: "<<v[i].cognome<<endl;
            cout<<"Voto: "<<v[i].voto<<endl;
            cout<<endl;
        }
    }


    cout<<endl;


}


float percAssenti(int n, int k) {

    float perc=0.00;

    perc=k*100/n;

    return perc;


}
