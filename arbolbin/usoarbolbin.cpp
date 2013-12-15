void inordenNR(const ArbolBinario<int>& a){
    ArbolBinario<int>::Nodo actual;
    stack<ArbolBinario<int>::Nodo> p;
    
    actual=a.raiz();
    p.push(ArbolBinario<int>::nodo_nulo);
    p.push(actual);
    
    while (actual!=ArbolBinario<int>::nodo_nulo){
        if (a.izquierda(actual)!=ArbolBinario<int>::nodo_nulo){
            actual= a.izquierda(actual);
            p.push(actual);
        }
        else{
            cout << a.etiqueta(actual) << ' ';
            if (a.derecha(actual)!=ArbolBinario<int>::nodo_nulo){
                actual=a.derecha(actual);
                p.pop();
                p.push(actual);
            }
            else{
                p.pop();
                actual=p.top();

                // Nos vamos al hermano (excepto si se trataba de la raíz)
                if (actual != ArbolBinario<int>::nodo_nulo) {
                        cout << a.etiqueta(actual) << ' ';
                        p.pop();
                        actual = a.derecha(actual);
                        p.push(actual);
                }
            }
        }
    }
}