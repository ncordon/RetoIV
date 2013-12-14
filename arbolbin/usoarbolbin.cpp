#include <iostream>
#include <string>
#include <ArbolBinario.h>
#include <queue>
#include <stack>

using namespace std;

template <class Tbase>
void preorden(const ArbolBinario<Tbase>& a, 
              const typename ArbolBinario<Tbase>::Nodo n){
  if (n!=0){
    cout << a.etiqueta(n) << ' ';
    preorden(a,a.izquierda(n));
    preorden(a,a.derecha(n));
  }
}

template <class Tbase>
void inorden(const ArbolBinario<Tbase>& a, 
             const typename ArbolBinario<Tbase>::Nodo n){
  if (n!=0){
    inorden(a,a.izquierda(n));
    cout << a.etiqueta(n) << ' ';
    inorden(a,a.derecha(n));
  }
}
     
template <class Tbase>
void postorden(const ArbolBinario<Tbase>& a, 
               const typename ArbolBinario<Tbase>::Nodo n){
  if (n!=0){
    postorden(a,a.izquierda(n));         
    postorden(a,a.derecha(n));
	cout << a.etiqueta(n) << ' ';
  }
}


template <class Tbase>
int Altura(const ArbolBinario<Tbase>& a, 
           const typename ArbolBinario<Tbase>::Nodo n){
  int iz,de;
  if (n==0)
    return -1;
  else {
    iz= Altura(a,a.izquierda(n));
    de= Altura(a,a.derecha(n));
    return 1+(iz>de?iz:de);
  }
}


template <class Tbase>
void refleja(ArbolBinario<Tbase>& a){
  ArbolBinario<Tbase> ai,ad;

  if (!a.empty()){
    a.podar_izquierda(a.raiz(),ai);
    a.podar_derecha(a.raiz(),ad);
    refleja(ai);
    refleja(ad);
    a.insertar_izquierda(a.raiz(),ad);
    a.insertar_derecha(a.raiz(),ai);
  }
}
 
      
template <class Tbase>
void Esquema(const ArbolBinario<Tbase>& a, 
             const typename ArbolBinario<Tbase>::Nodo n, string& pre){
  int i;
  
  if (n==0)
    cout << pre << "-- x" << endl;
  else {
    cout << pre << "-- " << a.etiqueta(n) << endl;
    if (a.derecha(n)!=0 || a.izquierda(n)!=0) {// Si no es una hoja
      pre += "   |";
      Esquema(a, a.derecha(n), pre);
      pre.replace(pre.size()-4, 4, "    ");
      Esquema (a, a.izquierda(n), pre);
      pre.erase(pre.size()-4, 4);    
    }
  }
}

template <class Tbase>
void Niveles(const ArbolBinario<Tbase> & a){
  queue<typename ArbolBinario<Tbase>::Nodo> c;
  typename ArbolBinario<Tbase>::Nodo n;

  if (!a.empty()){
    c.push(a.raiz());
    while (!c.empty()){
      n=c.front();
      c.pop();
      cout << a.etiqueta(n) << ' ';
      if (a.izquierda(n) != 0)
        c.push(a.izquierda(n));
      if (a.derecha(n) != 0)
        c.push(a.derecha(n));
    }
  }
  cout << endl;
}


// Formato de entrada: n 1 n 2 n 4 x x n 5 x n 8 x x n 3 n 6 x x n 7 x x
//          El arbol: n 1 n 2 n 4 x x n 5 x n 8 x x n 3 n 6 x x n 7 x x  
//          tiene el esquema:
//          -- 1
//             |-- 3
//             |   |-- 7
//             |    -- 6
//              -- 2
//                 |-- 5
//                 |   |-- 8
//                 |    -- x
//                  -- 4  
//

void inordenNR(const ArbolBinario<int>& a){
    ArbolBinario<int>::Nodo actual;
    stack<ArbolBinario<int>::Nodo> p;
    
    actual=a.raiz();
    p.push(0);
    p.push(actual);
    
    while (actual!=0){
        if (a.izquierda(actual)!=0){
            actual= a.izquierda(actual);
            p.push(actual);
        }
        else{
            cout << a.etiqueta(actual) << ' ';
            if (a.derecha(actual)!=0){
                actual=a.derecha(actual);
                p.pop();
                p.push(actual);
            }
            else{
                p.pop();
                actual=p.top();

                // Mostramos el padre, nos vamos al hermano (excepto si se trataba de la raíz)
                if (actual != 0) {
                        cout << a.etiqueta(actual) << ' ';
                        p.pop();
                        actual = a.derecha(actual);
                        p.push(actual);
                }
            }
        }
    }
}
/*
void inordenNR(const ArbolBinario<int>& a) {
 ArbolBinario<int>::Nodo actual;
 stack <ArbolBinario<int>::Nodo> p;
 bool sacando = false;

 actual = a.raiz();

 while (actual != 0) {
  if (!sacando) {
   if (a.izquierda(actual) != 0) {
    p.push(actual);
    actual = a.izquierda(actual);
   } else {
    cout << a.etiqueta(actual) << ' ';
    sacando = true;
    actual = p.top();
    p.top();
   }
  } else {
   if (a.derecha(actual) != 0) {
    actual = a.derecha(actual);
    sacando = false;
   }
  }
 }
}
*/
int main(int argc, char *argv[]){
  ArbolBinario<int> a;
  string pre;


  cout << "Introduce el arbol en el formato:" << endl;
  cout << "n 1 n 2 n 4 x x n 5 x n 8 x x n 3 n 6 x x n 7 x x" << endl;
  cin >> a; 
	
  cout << "El arbol: " << a << " tiene recorridos:" << endl;	

  cout << "Preorden: ";
  preorden(a,a.raiz());
  cout << endl;

  cout << "Inorden: ";
  inorden(a,a.raiz());
  cout << endl;

  cout << "Postorden: ";
  postorden(a,a.raiz());
  cout << endl;	       

  cout << "y la altura es: " << Altura(a,a.raiz()) << endl;
  
  cout << "Listado por niveles del arbol" << endl;
  Niveles(a);

  cout << "El arbol: " << a << " tiene el esquema:" << endl;	
  pre="";
  Esquema(a,a.raiz(), pre);
  
  inordenNR(a);
  
  return 0;
}
