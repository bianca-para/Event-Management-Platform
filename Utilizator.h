//#include <iostream>
//#include <string>
//#include <list>
//#include <conio.h>
//
//using namespace std;
//class Utilizator
//{
//   private:
//       string Nume;
//       string Adresa_email;
//       string Parola;
//       list <string> Evenimente_c;
//       list <string> Evenimente_p;
//
//    public:
//
//    Utilizator();
//
//// constr initializare
//
//    Utilizator(const string _nume, const string _adresa_email)
//    {
//        Nume=_nume;
//        Adresa_email=_adresa_email;
//
//    }
//
//// constr copiere
//
//
//    Utilizator(const Utilizator& utilizator)
//    {
//          Nume=utilizator.Nume;
//          Adresa_email=utilizator.Adresa_email;
//          Parola=utilizator.Parola;
//          Evenimente_c=utilizator.Evenimente_c;
//          Evenimente_p=utilizator.Evenimente_p;
//    }
//
//
//    void introducere_parola()
//    {
//
//    std::string parola;
//
//    std::cout << "Introduceti parola: ";
//    char ch;
//    while((ch = _getch()) != '\r')
//    {
//        if(ch == '\b')
//        {
//            if(parola.length() > 0)
//            {
//                parola.pop_back();
//                std::cout << "\b \b";
//            }
//        } else
//        {
//            parola.push_back(ch);
//            std::cout << '*';
//        }
//    }
//
//    std::cout << std::endl;
//    //std::cout << "Parola introdusa: " << parola << std::endl;
//    }
//
//// setter pentru nume
//    void setNume(const string& nume)
//    {
//        Nume = nume;
//    }
//
//// getter pentru Nume
//    string getNume() const
//    {
//        return Nume;
//    }
//
//// setter pentru Adresa_email
//    void setAdresaEmail(const string& adresaEmail)
//    {
//        Adresa_email = adresaEmail;
//    }
//
//// getter pentru Adresa_email
//    string getAdresaEmail() const
//    {
//        return Adresa_email;
//    }
//
//// setter pentru Parola
//    void setParola(const string& parola)
//    {
//        Parola = parola;
//    }
//
//// getter pentru Parola
//    string getParola() const
//    {
//        return Parola;
//    }
//
//
//// metoda pentru adăugarea unui eveniment creat
//    void adaugaEvenimentCreat(const string& numeEveniment)
//    {
//        Evenimente_c.push_back(numeEveniment);
//    }
//
//// metoda pentru adăugarea unui eveniment la care a participat
//    void adaugaEvenimentParticipat(const string& numeEveniment)
//    {
//        Evenimente_p.push_back(numeEveniment);
//    }
//
//    void getInfo()
//    {
//        cout<<"Nume: "<<Nume<<endl;
//        cout<<"Adresa de email: "<<Adresa_email<<endl;
//        introducere_parola();
//
//    }
//};
//
