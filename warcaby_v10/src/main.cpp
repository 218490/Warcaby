#include <iostream>
#include <stack>
#include "Symulacja.hh"
#include "gracz.hh"
using namespace std;

int main(){
  ruchy plansza;
  //  int ID,flaga;
  //  string strona;
  //  pozycja miejsce;
  int x, y, a, b;
  bool i=true;
  pionek pio;
  //plansza.wyswietl();
  gracz gr;
  cout<<endl<<"Jezeli chcesz wczesniej zakonczyc program za numer wiersza lub";
  cout<<endl<<"kolumny podaj wartosc 100"<<endl<<endl;

  char poz='a';
  while(poz!='T' && poz!='L'){
  cout<<"Wybierz poziom trudnosci (T-trudny, L-latwy)"<<endl;
  cin>>poz;
  cout<<endl;
  }
  if(poz=='T')
    plansza.Trudnosc(8);
  else
    plansza.Trudnosc(4);

  while(i<2)
    {
      while(i==true)
	{
	  try{
	    if(CzyKoniec(plansza)){
	      return 0;
	    }
	    cout<<"gracz bialy"<<endl;
	    plansza.wyswietl();
	    //ruch gracza czarnego
	    cout<<"Podaj wiersz i kolumne pionka ktorym chcesz sie ruszyc"<<endl;
	    cin>>x>>y;
	    if(x==100 || y==100){
	      cerr<<"Uzytkownik zakonczyl program"<<endl;
	      return 0;
	    }
	    pio=gr.ZaznaczPionek(plansza,x-1,y-1, 'B');
	    cout<<"Podaj wiersz i kolumne pola na ktore chcesz sie ruszyc"<<endl;
	    cin>>a>>b;
	    if(a==100 || b==100){
	      cerr<<"Uzytkownik zakonczyl program"<<endl;
	      return 0;
	    }
	    i=gr.RuszPionek(plansza, pio, a-1, b-1);
	    pio=plansza.wyszukajPionek(a-1,b-1);
	    if(plansza.CzyBicie(pio)!=true || i!=true)
	      i=false;
	  }
	  catch (gracz::brak_ruchu)
	    {
	      cout<<endl;
	      cout<<"brak mozliwosci wykonania ruchu tym pionkiem"<<endl;
	      cout<<endl;
	    }
	  catch(gracz::brak_pionka_na_podanej_pozycji)
	    {
	      cout<<endl;
	      cout<<"brak pionka na podanej pozycji"<<endl;
	      cout<<endl;
	    }
	  catch(gracz::pionek_przeciwnika)
	    {
	      cout<<endl;
	      cout<<"zaznaczony pionek nalezy do przeciwnika"<<endl;
	      cout<<endl;
	    }
	  catch (gracz::niedozwolony_ruch)
	    {
	      cout<<endl;
	      cout<<"ten ruch jest niedozwolnoy"<<endl;
	      cout<<endl;
	    }
	  catch (plansza::wyjscie_poza_plansze)
	    {
	      cout<<endl;
	      cout<<"podano zle pole"<<endl;
	      cout<<endl;
	    }
	}
      i=true;
      plansza.wyswietl();
      cout<<endl;
      while(i==true)
	{
	  if(CzyKoniec(plansza)){
	    return 0;
	  }
	    cout<<"gracz czarny"<<endl;
	    PrzestawCzarny(plansza);
	    i=false;
	}
      i=true;
      cout<<endl;
    }
      /*
  int zysk=Symuluj(plansza,ID,strona,flaga,miejsce);

  if(flaga==0){
  cout<<"ID: "<<ID<<endl;
  cout<<"strona: "<<strona<<endl;
  cout<<"zysk: "<<zysk<<endl;
  }
      */
}
