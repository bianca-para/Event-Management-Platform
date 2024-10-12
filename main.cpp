#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;


class Utilizator
{
   private:
       string Nume;
       string Adresa_email;
       string Parola;
       list <string> Evenimente_c;
       list <string> Evenimente_p;

    public:

    Utilizator(){}

    Utilizator(const string _nume, const string _adresa_email, const string _parola)
    {
        Nume=_nume;
        Adresa_email=_adresa_email;
        Parola=_parola;

    }

    Utilizator(const Utilizator& user)
    {
          Nume=user.Nume;
          Adresa_email=user.Adresa_email;
          Parola=user.Parola;
          Evenimente_c=user.Evenimente_c;
          Evenimente_p=user.Evenimente_p;
    }


    void introducere_parola()
    {

    string parola;

    cout << "Introduceti parola: ";
    char ch;
    while((ch = _getch()) != '\r')
    {
        if(ch == '\b')
        {
            if(parola.length() > 0)
            {
                parola.pop_back();
                cout<<"\b \b";
            }
        } else
        {
            parola.push_back(ch);
            cout << '*';
        }
    }

    cout<<endl;
    cout<<"Parola introdusa: "<<parola<<endl;
    Parola=parola;
    }


    void setNume(const string& nume)
    {
        Nume = nume;
    }


    string getNume() const
    {
        return Nume;
    }


    void setAdresaEmail(const string& adresaEmail)
    {
        Adresa_email = adresaEmail;
    }


    string getAdresaEmail() const
    {
        return Adresa_email;
    }


    void setParola(const string& parola)
    {
        Parola = parola;
    }


    string getParola() const
    {
        return Parola;
    }

    void setEvenimenteCreate(const list<string>& evenimenteCreate) {
        Evenimente_c = evenimenteCreate;
    }

    list<string> getEvenimenteCreate() const {
        return Evenimente_c;
    }


    void setEvenimenteParticipate(const list<string>& evenimenteParticipate)
    {
        Evenimente_p = evenimenteParticipate;
    }


    list<string> getEvenimenteParticipate() const
    {
        return Evenimente_p;
    }



    void adaugaEvenimentCreat(const string& numeEveniment)
    {
        Evenimente_c.push_back(numeEveniment);
    }

    void adaugaEvenimentParticipat(const string& numeEveniment)
    {
        Evenimente_p.push_back(numeEveniment);
    }



    void creeareCont()
    {
        cin.ignore();
        cout << "Introduceti numele: ";
        getline(cin, Nume);

        cout << "Introduceti adresa de email: ";
        getline(cin, Adresa_email);

        introducere_parola();
    }

    bool logareCont(const string &nume, const string &adresaEmail, const string &parola) const
    {

        return (nume==Nume && adresaEmail==Adresa_email && parola==Parola);
    }



    void getInfo()
    {
        cout<<"Nume: "<<Nume<<endl;
        cout<<"Adresa de email: "<<Adresa_email<<endl;
        cout<<"Parola: "<<Parola<<endl;
        cout<<"Evenimente organizate de tine sunt: ";
        for(string eveniment : Evenimente_c)
            cout<<eveniment<<endl;
        cout<<endl;
        cout<<"Evenimente la care ai participat: ";
        for(string eveniment_p : Evenimente_p)
            cout<<eveniment_p<<endl;


    }

      friend istream& operator>>(istream& is, Utilizator& u)
        {
            string nume, adresaEmail, parola;

            cout << "Introduceti numele: ";
            getline(is, nume);
            u.setNume(nume);

            cout << "Introduceti adresa de email: ";
            getline(is, adresaEmail);
            u.setAdresaEmail(adresaEmail);

            cout << "Introduceti parola: ";
            getline(is, parola);
            u.setParola(parola);

            return is;
        }
};



class Eveniment
{
    private:
        string Nume_Eveniment;
        string Data_ora_eveniment;
        string Locatia;
        string Gazda;
        string Descriere;
        string Pret;

    public:
        Eveniment(){}

       Eveniment(const string& nume, const string& dataOra, const string& locatia, const string& gazda, const string& descriere, const string& pret)
       {
        Nume_Eveniment = nume;
        Data_ora_eveniment = dataOra;
        Locatia = locatia;
        Gazda = gazda;
        Descriere = descriere;
        Pret = pret;
        }

       Eveniment(const Eveniment& eveniment, const string& gazda)
        {
            Nume_Eveniment = eveniment.Nume_Eveniment;
            Data_ora_eveniment = eveniment.Data_ora_eveniment;
            Locatia = eveniment.Locatia;
            Gazda = gazda;
            Descriere = eveniment.Descriere;

        }


         bool operator==(const Eveniment& other) const
         {
            return Nume_Eveniment == other.Nume_Eveniment && Data_ora_eveniment == other.Data_ora_eveniment && Locatia == other.Locatia && Gazda == other.Gazda && Descriere == other.Descriere;
         }


        void setNume_Eveniment(const string& nume_ev)
        {
            Nume_Eveniment = nume_ev;
        }


        string getNume_Eveniment() const
        {
            return Nume_Eveniment;
        }


        void setData_Ora_Eveniment(const string& data_si_ora)
        {
            Data_ora_eveniment = data_si_ora;
        }


        string getData_Ora_Eveniment() const
        {
            return Data_ora_eveniment;
        }


        void setLocatia(const string& locatia)
        {
            Locatia = locatia;
        }


        string getLocatia() const
        {
            return Locatia;
        }

        void setGazda(const string& gazda)
        {
            Gazda = gazda;
        }


        string getGazda() const
        {
            return Gazda;
        }

        void setDescriere(const string& descriere)
        {
            Descriere= descriere;
        }


        string getDescriere() const
        {
            return Descriere;
        }

        void setPret(const string& pret)
        {

            Pret=pret;
        }


        string getPret() const
        {
            return Pret;
        }



       friend istream& operator>>(istream& is, Eveniment& e)
        {
            string numeEveniment, dataOraEveniment, locatiaEveniment, gazdaEveniment, descriereEveniment, pret;

            cout << "Introduceti numele evenimentului: ";
            getline(is, numeEveniment);

            cout << "Introduceti data si ora evenimentului: ";
            getline(is, dataOraEveniment);

            cout << "Introduceti locatia evenimentului: ";
            getline(is, locatiaEveniment);

            cout << "Introduceti numele gazdei: ";
            getline(is, gazdaEveniment);

            cout << "Introduceti o scurta descriere a evenimentului: ";
            getline(is, descriereEveniment);

            cout << "Introduceti pretul unui bilet: ";
            getline(is, pret);


            e.setNume_Eveniment(numeEveniment);
            e.setData_Ora_Eveniment(dataOraEveniment);
            e.setLocatia(locatiaEveniment);
            e.setGazda(gazdaEveniment);
            e.setDescriere(descriereEveniment);
            e.setPret(pret);

            return is;
        }

    friend ostream& operator<<(ostream& os, const Eveniment& e)
    {
        os << "Nume eveniment: " << e.getNume_Eveniment() << endl;
        os << "Data si ora evenimentului: " << e.getData_Ora_Eveniment() <<endl;
        os << "Locatia evenimentului: " << e.getLocatia() <<endl;
        os << "Gazda evenimentului: " << e.getGazda() <<endl;
        os << "Descriere eveniment: " << e.getDescriere() <<endl;
        return os;
    }



};

class Platforma {
private:
    list<Utilizator> utilizatori;
    list<Eveniment> evenimente;

public:
    Platforma() {}

    Platforma(const list<Utilizator>& listaUtilizatori, const list<Eveniment>& listaEvenimente)
    {
        utilizatori = listaUtilizatori;
        evenimente = listaEvenimente;
    }

    Platforma(const Platforma& platforma)
    {
        utilizatori = platforma.utilizatori;
        evenimente = platforma.evenimente;
    }

    ~Platforma() {}

    void setUtilizatori(const list<Utilizator>& listaUtilizatori)
    {
        utilizatori = listaUtilizatori;
    }

    list<Utilizator> getUtilizatori() const
    {
        return utilizatori;
    }


    void setEvenimente(const list<Eveniment>& listaEvenimente)
    {
        evenimente = listaEvenimente;
    }


    list<Eveniment> getEvenimente() const
    {
        return evenimente;
    }

    void adaugaEveniment(const Eveniment& eveniment)
    {
        evenimente.push_back(eveniment);
    }

    void stergeEveniment(const string& numeEveniment)
    {
        evenimente.remove_if([numeEveniment](const Eveniment& e) {
            return e.getNume_Eveniment() == numeEveniment;
        });
    }

    list<Eveniment> cautaEveniment(const string& numeEveniment) const
    {
        list<Eveniment> rezultate;
        for (const auto& eveniment : evenimente)
        {
            if (eveniment.getNume_Eveniment() == numeEveniment)
                {
                rezultate.push_back(eveniment);
            }
        }
        return rezultate;
    }
    void adaugaUtilizator(const Utilizator& utilizator)
    {
        utilizatori.push_back(utilizator);
    }


    const Utilizator* cautaUtilizator(const string& numeUtilizator) const
    {
        for (auto it = utilizatori.begin(); it != utilizatori.end(); ++it)
        {
            if (it->getNume() == numeUtilizator)
            {
                return &(*it);
            }
        }

        return nullptr;
    }


    void generareRaport() const
    {
        cout << "Raport statistic:" << endl;
        cout << "Numar total de utilizatori: " << utilizatori.size() << endl;
        cout << "Numar total de evenimente: " << evenimente.size() << endl;

    }
};


int main()
{


    int t1, t2,t3;
    vector<Utilizator> U;
    vector <Eveniment> E;
    Platforma P;
    Utilizator user1("Bianca Paraschiv","biancaparaschiv@gmail.com","bianca2004");
    user1.adaugaEvenimentParticipat("Hypnotic Christmas Party");
    U.push_back(user1);
    Utilizator user2("Paul Rascu", "rascupaul@mail.com", "parola123");
    user2.adaugaEvenimentParticipat("Hypnotic Christmas Party");
    U.push_back(user2);
    Utilizator user3("Eliza Popa", "eliza2005@yahoo.com", "password");
    user3.adaugaEvenimentParticipat("Dia de los muertos");
    U.push_back(user3);
    Utilizator user4("Tudor Predescu","tudipredi@gmail.com","gta5");
    user4.adaugaEvenimentCreat("Hypnotic Christmas Party");
    user4.adaugaEvenimentCreat("Dia de los muertos");
    U.push_back(user4);
    Utilizator user5("Rares Mandu","mandu23@gmail.com","djsince2020");
    user5.adaugaEvenimentCreat("Beach Party");
    U.push_back(user5);
    Utilizator user6("Bivolaru Carol","carol.biv@mail.com","mister");
    user6.adaugaEvenimentCreat("Glitter night");
    user6.adaugaEvenimentParticipat("Beach Party");
    U.push_back(user6);

    E.push_back(Eveniment("Hipnotic Christmas Party", "22.12.2023 22:00", "Beluga", "Tudor Predescu", "Hai sa ne petrecem Craciunul #altfel", "40 RON"));
    E.push_back(Eveniment("Dia de los muertos", "30.10.2023 22:00", "Nuba", "Tudor Predescu", "Petrecere de Halloween, costum obligatoriu!", "60 RON"));
    E.push_back(Eveniment("Beach Party", "09.07.2024 14:00", "La Nueve Cucaracha", "Rares Mandu", "Vino la cea mai tare petrecere a verii! Atmosfera de paradis alaturi de dj-ul vostru preferat!", "70 RON"));
    E.push_back(Eveniment("Glitter night", "12.05.2024 21:00", " Apolo111", "Bivolaru Carol", "Explozie de culoare si voie buna! Vino sa stralucesti pe ringul de dans!", "50 RON"));

    for (const Eveniment& e : E)
    {
        P.adaugaEveniment(e);

    }
    for (const Utilizator& u : U)
    {
        P.adaugaUtilizator(u);
    }



    do
    {
        system("CLS");
        cout << "-------MENIU PRINCIPAL-------" << endl<<endl;
        cout<<"Bine ati venit pe platforma noastra de organizare evenimente. Alege ce vrei sa faci: "<<endl;
        cout << "1. Creeare cont" << endl;
        cout << "2. Logare cont" << endl;
        cout << "0. Exit" << endl << endl;
        cout << "Alege:" << endl;
        cin>>t1;

        switch (t1)
        {
            case 1:
             {
                 do
                {
                    system("CLS");
                    cout<<"Bine ai venit! Creaza-ti un cont."<<endl;
                    Utilizator user;
                    user.creeareCont();
                    U.push_back(user);

                    cout << endl;
                    cout << "Contul a fost creat cu succes. Logheaza-te in cont!" << endl;
                    cout << "0.Inapoi la meniul principal." << endl << endl;
                    cout << "Astept sa alegi:";

                    cin >> t2;
                    switch (t2)
                    {
//
                    }
                } while (t2 != 0);
               } break;

            case 2:
            {

                system("CLS");
                cin.ignore();
                string nume, adresaEmail, parola;
                cout << "Introduceti numele: ";
                getline(cin, nume);
                cout << "Introduceti adresa de email: ";
                getline(cin, adresaEmail);
                cout << "Introduceti parola: ";
                getline(cin, parola);

                bool autentificareReusita = false;

                cout<<endl;
                for (Utilizator& user : U)
                {

                    if (user.logareCont(nume, adresaEmail,parola))
                    {

                        autentificareReusita = true;
                        cout << "Autentificare reusita!" << endl<<endl;;
                        do
                        {

                            system("CLS");
                            cout<<"Bine ai revenit! Ce vrei sa faci azi?"<<endl<<endl;
                            cout<<"1. Administrativ : Despre contul meu"<<endl;
                            cout<<"2. Creeaza un eveniment nou!"<<endl;
                            cout<<"3. Ia-ti bilet : Participa la un eveniment"<<endl;
                            cout<<"4. Cauta un utilizator"<<endl;
                            cout<<"0. Inapoi la meniul principal"<<endl;
                            cout<<"Alege:"<<endl;
                            cin>>t3;
                            switch(t3)
                            {
                            case 1:
                                {
                                    user.getInfo();

                                }_getch();break;
                            case 2:
                                {

                                    Eveniment evenimentNou;
                                    cin.ignore();
                                    std::cin >> evenimentNou;
                                    P.adaugaEveniment(evenimentNou);
                                    string numeEvenimentNou = evenimentNou.getNume_Eveniment();
                                    user.adaugaEvenimentCreat(numeEvenimentNou);
                                    cout <<"Evenimentul a fost creat cu succes!"<<endl;

                                }_getch();break;
                            case 3:
                                {
                                    for (const Eveniment& event : P.getEvenimente())
                                    {
                                        std::cout << event << endl;
                                    }
                                    string numeEvenimentAles;
                                    cout<<endl<< "Introdu numele evenimentului la care vrei sa participi: ";
                                    cin.ignore();
                                    getline(cin, numeEvenimentAles);


                                    bool evenimentGasit = false;
                                    for (Eveniment& event : P.getEvenimente())
                                    {
                                        if (event.getNume_Eveniment() == numeEvenimentAles)
                                        {

                                            user.adaugaEvenimentParticipat(event.getNume_Eveniment());
                                            cout<<"Ai luat bilet pentru evenimentul \""<<event.getNume_Eveniment()<<"\". Felicitari!" << endl;
                                            evenimentGasit = true;
                                            break;
                                        }
                                    }


                                    if (!evenimentGasit)
                                    {
                                        cout << "Evenimentul \"" << numeEvenimentAles << "\" nu a fost gasit. Te rugam sa alegi un eveniment valid." << endl;
                                    }
                                    _getch();


                                }break;
                            case 4:
                                {
                                    string numeUtilizatorCautat;
                                cout << "Introdu numele utilizatorului pentru a cauta evenimentele create de el: ";
                                cin.ignore();
                                getline(cin, numeUtilizatorCautat);

                                const Utilizator* utilizatorGasit = P.cautaUtilizator(numeUtilizatorCautat);

                                if (utilizatorGasit != nullptr)
                                {
                                    cout << "Evenimentele create de utilizatorul " << utilizatorGasit->getNume() << " sunt:" << endl;
                                    for (const string& eveniment : utilizatorGasit->getEvenimenteCreate())
                                        cout << eveniment << endl;

                                }
                                else
                                {

                                    cout << "Utilizatorul \"" << numeUtilizatorCautat << "\" nu a fost gasit." << endl;
                                }

                                _getch();
                                }break;


                            }


                        }while(t3!=0);

                        break;
                    }
                }

                if (!autentificareReusita)
                    cout << "Autentificare esuata. Verifica daca toate datele introduse sunt cele corecte." << endl;

            }_getch();break;
        }
    } while (t1 != 0);

    return 0;
}
