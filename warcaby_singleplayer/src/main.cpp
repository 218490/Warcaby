#include <iostream>
#include <stack>
#include "Symulacja.hh"
#include "gracz.hh"
using namespace std;

int main(){
  ruchy plansza;
  int ID,flaga;
  string strona;
  pozycja miejsce;
  int x, y, a, b;
  bool i=true;
  bool wybrano=false;
  pionek pio;
  plansza.wyswietl();
  gracz gr;
  while(i<2)
    {
      while(i==true)
	{
	  try{
	    cout<<"gracz bialy"<<endl;
	    plansza.wyswietl();
	    if(wybrano==false)
	      {
		cout<<"Podaj wiersz i kolumne pionka ktorym chcesz sie ruszyc"<<endl;
		cin>>x>>y;
		pio=gr.ZaznaczPionek(plansza,x-1,y-1, 'B');
	      }
	    else
	      gr.ZaznaczPionek(plansza, pio.poz.I, pio.poz.J, 'B');
	    while(i==true)
	      {
		cout<<"Podaj wiersz i kolumne pola na ktore chcesz sie ruszyc"<<endl;
		cin>>a>>b;
		i=gr.RuszPionek(plansza, pio, a-1, b-1);
		pio=plansza.wyszukajPionek(a-1,b-1);
		if(plansza.CzyBicie(pio)!=true || i!=true)
		  i=false;
		else
		  {
		    wybrano=true;
		    gr.ZaznaczPionek(plansza, pio.poz.I, pio.poz.J, 'B');
		  }

	      }
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
      wybrano=false;
      cout<<endl;
      while(i==true)
	{
	  try{
	    cout<<"gracz czarny"<<endl;
	    plansza.wyswietl();
	    if(wybrano==false)
	      {
		cout<<"Podaj wiersz i kolumne pionka ktorym chcesz sie ruszyc"<<endl;
		cin>>x>>y;
		pio=gr.ZaznaczPionek(plansza,x-1,y-1, 'C');
	      }
	    else
	      gr.ZaznaczPionek(plansza, pio.poz.I, pio.poz.J, 'C');
	    while(i==true)
	      {
		cout<<"Podaj wiersz i kolumne pola na ktore chcesz sie ruszyc"<<endl;
		cin>>a>>b;
		i=gr.RuszPionek(plansza, pio, a-1, b-1);
		pio=plansza.wyszukajPionek(a-1,b-1);
		if(plansza.CzyBicie(pio)!=true || i!=true)
		  i=false;
		else
		  {
		    wybrano=true;
		    gr.ZaznaczPionek(plansza, pio.poz.I, pio.poz.J, 'C');
		  }
	      }
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
	  catch (gracz::pionek_przeciwnika)
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
      wybrano=false;
      cout<<endl;
    }
 
  int zysk=Symuluj(plansza,ID,strona,flaga,miejsce);

  if(flaga==0){
  cout<<"ID: "<<ID<<endl;
  cout<<"strona: "<<strona<<endl;
  cout<<"zysk: "<<zysk<<endl;
  }

}
