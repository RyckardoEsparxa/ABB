#include<iostream>
#include<stdlib.h>

using namespace std;

struct Nodoarbol
{
    int dato;
    Nodoarbol *izq;
    Nodoarbol *der;
};
Nodoarbol* BuscarMin(Nodoarbol *nodo)
{
    if(nodo==NULL)
    {
        return NULL;
    }
    if(nodo->izq) 
        return BuscarMin(nodo->izq);
    else
        return nodo;
}
Nodoarbol* BuscarMax(Nodoarbol *nodo)
{
    if(nodo==NULL)
    {
        return NULL;
    }
    if(nodo->der) 
        return(BuscarMax(nodo->der));
    else
        return nodo;
}
Nodoarbol *Insertar(Nodoarbol *nodo,int dato)
{
    if(nodo==NULL)
    {
        Nodoarbol *temp;
        temp=new Nodoarbol;
//temp = (Nodoarbol *)malloc(sizeof(Nodoarbol));
        temp -> dato = dato;
        temp -> izq = temp -> der = NULL;
        return temp;
    }
    if(dato >(nodo->dato))
    {
        nodo->der = Insertar(nodo->der,dato);
    }
    else if(dato < (nodo->dato))
    {
        nodo->izq = Insertar(nodo->izq,dato);
    }
    return nodo;
}
Nodoarbol * Eliminar(Nodoarbol *nodo, int dato)
{
    Nodoarbol *temp;
    if(nodo==NULL)
    {
        cout<<"Element Not Found";
    }
    else if(dato < nodo->dato)
    {
        nodo->izq = Eliminar(nodo->izq, dato);
    }
    else if(dato > nodo->dato)
    {
        nodo->der = Eliminar(nodo->der, dato);
    }
    else
    {
        if(nodo->der && nodo->izq)
        {
            temp = BuscarMin(nodo->der);
            nodo -> dato = temp->dato;
            nodo -> der = Eliminar(nodo->der,temp->dato);
        }
        else
        {
            temp = nodo;
            if(nodo->izq == NULL)
                nodo = nodo->der;
            else if(nodo->der == NULL)
                nodo = nodo->izq;
            free(temp);
        }
    }
    return nodo;
}
Nodoarbol * Buscar(Nodoarbol *nodo, int dato)
{
    if(nodo==NULL)
    {
        return NULL;
    }
    if(dato > nodo->dato)
    {
        return Buscar(nodo->der,dato);
    }
    else if(dato < nodo->dato)
    {
        return Buscar(nodo->izq,dato);
    }
    else
    {
        return nodo;
    }
}
void Enorden(Nodoarbol *nodo)
{
    if(nodo==NULL)
    {
        return;
    }
    Enorden(nodo->izq);
    cout<<nodo->dato<<" ";
    Enorden(nodo->der);
}
void Preordenar(Nodoarbol *nodo)
{
    if(nodo==NULL)
    {
        return;
    }
    cout<<nodo->dato<<" ";
    Preordenar(nodo->izq);
    Preordenar(nodo->der);
}
void Postordenar(Nodoarbol *nodo)
{
    if(nodo==NULL)
    {
        return;
    }
    Postordenar(nodo->izq);
    Postordenar(nodo->der);
    cout<<nodo->dato<<" ";
}
int main()
{
    Nodoarbol *raiz = NULL,*temp;
    int opc;
    system("clear");
    while(1)
    {
        cout<<"\n\n-- Operaciones del Arbol Binario de Busqueda (ABB) --"<< endl;
        cout<<"\n1.Insertar\n2.Eliminar\n3.En orden\n4.Pre-ordenar\n5.Post-ordenar\n6.Buscar Minimo\n7.Buscar Maximo\n8.Buscar\n9.Salir\n";
        cout<<"Selecciona una opcion:";
        cin>>opc;
        switch(opc)
        {
        case 1:
            cout<<"\nInserta un elemento:";
            cin>>opc;
            raiz = Insertar(raiz, opc);
            cout<<"\nLos elementos en el ABB son -> ";
            Enorden(raiz);
            break;
        case 2:
            cout<<"\nIngresa el elemento a eliminar:";
            cin>>opc;
            raiz = Eliminar(raiz,opc);
            cout<<"\nDespues de la eliminacion, los elementos en el ABB son:";
            Enorden(raiz);
            break;
        case 3:
            cout<<"\nEl recorrido en orden es:";
            Enorden(raiz);
            break;
        case 4:
            cout<<"\nEl recorrido pre-ordenado es:";
            Preordenar(raiz);
            break;
        case 5:
            cout<<"\nEl recorrido post-ordenado es:";
            Postordenar(raiz);
            break;
        case 6:
            temp = BuscarMin(raiz);
            cout<<"\nEl minimo elemento es:"<<temp->dato;
            break;
        case 7:
            temp = BuscarMax(raiz);
            cout<<"\nEl maximo elemento es:"<<temp->dato;
            break;
        case 8:
            cout<<"\nIngresa el elemento a buscar:";
            cin>>opc;
            temp = Buscar(raiz,opc);
            if(temp==NULL)
            {
                cout<<"El elemento no ha sido encontrado";
            }
            else
            {
                cout<<"Elemento "<<temp->dato<<" ha sido encontrado\n";
            }
            break;
        case 9:
            exit(0);
            break;
        default:
            cout<<"\nIngresa una opcion correcta:";
            break;
        }
    }
    return 0;
}