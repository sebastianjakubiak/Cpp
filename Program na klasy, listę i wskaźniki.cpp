#include <iostream>
#include <string>
using namespace std;
int o = 7;


class pamiecRAM {
    int nrObiektu;
    string producent;
    string model;
    string typ;
    float taktowanie;
    float timing;
    pamiecRAM *nastepny;
    pamiecRAM *poprzedni;
    
public:
    
    void setNumerObiektu (int nrO)
    {
        nrObiektu = nrO;
    }
    int getNumerObiektu ()
    {
        return nrObiektu;
    }
    
    void setProducent(string pr)
    {
        producent = pr;
    }
    string getProducent()
    {
        return producent;
    }
    
    void setModel(string m)
    {
        model = m;
    }
    string getModel()
    {
        return model;
    }
    
    void setTyp(string tp)
    {
        typ = tp;
    }
    string getTyp()
    {
        return typ;
    }
    
    void setTaktowanie(float ta)
    {
        taktowanie = ta;
    }
    float getTaktowanie()
    {
        return taktowanie;
    }

    void setTiming(float ti)
    {
        timing = ti;
    }
    float getTiming()
    {
        return timing;
    }
    
    void setNastepny(pamiecRAM *next)
    {
         nastepny = next;
    }
    pamiecRAM* getNastepny()
    {
        return nastepny;
    }
    
    void setPoprzedni(pamiecRAM *prev)
    {
        poprzedni = prev;
    }
    pamiecRAM* getPoprzedni()
    {
        return poprzedni;
    }
    
    pamiecRAM ()
    {
        nastepny = 0;
    }
    
    virtual ~pamiecRAM (){
        cout << "a wlasnie ze dziala!";
    }
    friend ostream& operator<< (ostream&,pamiecRAM *RAM);
};

class lista : pamiecRAM {
public:
    pamiecRAM *pierwszy;
    lista(){
        pierwszy = 0;
    }
    ~lista(){
        pierwszy = NULL;
        cout << "Nara" << endl;
        cout << pierwszy;
    }
    void dodaj_obiekt (int nrO, string pr, string m, string tp, float ta, float ti)
    {
        pamiecRAM *nowy = new pamiecRAM;
        nowy->setNumerObiektu(nrO);
        nowy->setProducent(pr);
        nowy->setModel(m);
        nowy->setTyp(tp);
        nowy->setTaktowanie(ta);
        nowy->setTiming(ti);
        if (pierwszy==0)
        {
            pierwszy = nowy;
        }
        else
        {
            pamiecRAM *x = pierwszy;
            while (x->getNastepny())
            {
                x = x->getNastepny();
            }
            x->setNastepny(nowy);
            nowy->setNastepny(0);
        }
    }
    void wyswietl_liste()
    {
        pamiecRAM *x = pierwszy;
        while (x)
        {
            cout << "Numer porządkowy:" << x->getNumerObiektu() <<endl;
            cout << "Producent: " << x-> getProducent() << endl;
            cout << "Model: " << x->getModel() << endl;
            cout << "Typ: " << x->getTyp() << endl;
            cout << "Taktowanie: " << x->getTaktowanie() << endl;
            cout << "Timing: " << x->getTiming() << endl;
            x=x->getNastepny();
        }
    }
    void wyswietl_obiekt (int no)
    {

    }
    void usun_obiekt (int nr)
    {
        if (nr==1)
        {
            pamiecRAM *x = pierwszy;
            pierwszy = x->getNastepny();
        }
        else
        {
            int j = 1;
            pamiecRAM *x = pierwszy;
            while (x)
            {
                if ((j+1)==nr) break;
                x = x->getNastepny();
                j++;
            }
            if (x->getNastepny()->getNastepny()==0)
                x->setNastepny(0);
            else
                x->setNastepny(x->getNastepny()->getNastepny());
        }
    }
        friend ostream& operator<< (ostream&,lista *RAM);
};

ostream& operator<< (ostream &wyjscie, pamiecRAM *RAM)
{
    wyjscie << "Numer obiektu:" << RAM->getNumerObiektu() <<endl;
    wyjscie << "Producent: " << RAM->producent << endl;
    wyjscie << "Model: " << RAM->model << endl;
    wyjscie << "Typ: " << RAM->typ << endl;
    wyjscie << "Takrowanie: "<< RAM->taktowanie <<endl;
    wyjscie << "Timing:"<< RAM->timing <<endl;
    return wyjscie;
}
    
int main()
{
    lista *RAM = new lista;
    int wybor;
    RAM->dodaj_obiekt(1, "corsair","D627A", "DDR3", 334, 1600);
    RAM->dodaj_obiekt(2, "corsair","D627A22", "DDR3", 335, 1600);
    RAM->dodaj_obiekt(3, "corsair","D627A21", "DDR2", 336, 1600);
    RAM->dodaj_obiekt(4, "kingston","D627A22A", "DDR2", 442, 1600);
    RAM->dodaj_obiekt(5, "kingston","D6231A", "DDR2", 4410, 1602);
    RAM->dodaj_obiekt(6, "corsair","D62713A21", "DDR3", 336, 1800);
    RAM->dodaj_obiekt(7, "kingston","D627A22A", "DDR1", 442, 2000);
    do
    {
        cout << "Elementów na liście:" << o << endl << endl;
        cout << "MENU" <<endl;
        cout << "1. Wyswietl liste" <<endl;
        cout << "2. Dodaj element" <<endl;
        cout << "3. Usun element" <<endl;
        cout << "4. Wyświetl obiekt" <<endl;
        cout << "5. KONIEC" <<endl;
        cout << "Twoj wybor:";
        cin >>wybor;
        switch (wybor)
        {
            case 2:
            {
                int nrO;
                cout << "Podaj numer obiektu:" <<endl;
                cin >> nrO;
                cout << "Podaj producenta:" <<endl;
                string pr;
                cin >> pr;
                cout << "Podaj model:" <<endl;
                string m;
                cin >>m;
                cout << "Podaj typ:" <<endl;
                string tp;
                cin >>tp;
                cout << "Podaj taktowanie:" <<endl;
                float ta;
                cin >> ta;
                cout << "Podaj timing:" <<endl;
                float ti;
                cin >> ti;
                RAM->dodaj_obiekt(nrO, pr, m, tp, ta, ti);
                o++;
                RAM->wyswietl_liste();
                break;}
            case 1:
                RAM->wyswietl_liste();
                break;
            case 3:
                cout << "Podaj numer obiektu do usunięcia:" << endl;
                int nr;
                cin >> nr;
                RAM->usun_obiekt(nr);
                o--;
                RAM->wyswietl_liste();
                break;
            case 4:
            {
                int no;
                cout << "Podaj numer obiektu do wyświetlenia:";
                cin >> no;
                if (no==1)
                {
                    cout << RAM->pierwszy;
                }
                else
                {
                    pamiecRAM *x = RAM->pierwszy;
                    for (int licznik=1; licznik<no; licznik ++) x = x->getNastepny();
                    RAM->pierwszy = x;
                    cout << RAM->pierwszy;
                }
            }
            case 5:
                RAM->~lista();
                delete(RAM);
                return 0;
            default:
                cout << "Nie ma takiej opcji w MENU. Spróbuj jeszcze raz!" <<endl;
                break;
        }
    }
    while (wybor!=5);
    return 0;
}

