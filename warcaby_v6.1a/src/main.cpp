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
  int i=0;
  pionek pio;
  plansza.wyswietl();
  gracz gr;
  while(i<2)
    {
      while(i<1)
	{
	  cout<<"gracz czarny"<<endl;
	  plansza.wyswietl();
	  //ruch gracza czarnego
	  cout<<"Podaj wiersz i kolumne pionka ktorym chcesz sie ruszyc"<<endl;
	  cin>>x>>y;
	  pio=gr.ZaznaczPionek(plansza,x-1,y-1, 'C');
	  cout<<"Podaj wiersz i kolumne pola na ktore chcesz sie ruszyc"<<endl;
	  cin>>a>>b;
	  //if wykonano ruch -> kolej przeciwnika
	  if(a!=x && b!=y)
	    {
	      gr.RuszPionek(plansza, pio, a-1, b-1);
	      i=1;
	    }
	}
      i=0;
      while(i<1)
	{
	  cout<<"gracz bialy"<<endl;
	  plansza.wyswietl();
	  //ruch gracza bialego
	  cout<<"Podaj wiersz i kolumne pionka ktorym chcesz sie ruszyc"<<endl;
	  cin>>x>>y;
	  pio=gr.ZaznaczPionek(plansza,x-1,y-1, 'B');
	  cout<<"Podaj wiersz i kolumne pola na ktore chcesz sie ruszyc"<<endl;
	  cin>>a>>b;
	  //if wykonano ruch -> kolej przeciwnika
	  if(a!=x && b!=y)
	    {
	      gr.RuszPionek(plansza, pio, a-1, b-1);
	      i=1;
	    }
	}
      i=0;
    }
 
  int zysk=Symuluj(plansza,ID,strona,flaga,miejsce);

  if(flaga==0){
  cout<<"ID: "<<ID<<endl;
  cout<<"strona: "<<strona<<endl;
  cout<<"zysk: "<<zysk<<endl;
  }

}
