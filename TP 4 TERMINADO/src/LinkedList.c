#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNodae(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));//creo el linkedList en memoria dinamica LOCOMOTORA
    if(this!=NULL)
    {
        this->size = 0;//Inicializo en el primer elemento pq no hay ninguno
        this->pFirstNode = NULL; // apunto a null para que despues pueda engancharse
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(this->size == 0)//Si solo esta la locomotora y no tiene otro vagon el ll_len devuelve 0
        {
           returnAux = 0;
        }
        else{
             returnAux = this->size;//En caso de que no este solo la locomotara, devolvera la cantidad de locomotoras enganchadas
        }
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;//Creo un nodo en null por si no hay vagones, puedo devolver un null
    int contador = 0;
    if(this !=NULL && (nodeIndex < ll_len(this) && nodeIndex >= 0))//Me fijo con el len de que haya vagones
    {
        pNode = this->pFirstNode;//Como hay vagones apunto el nodo al primer vagon de la locomotora,inicializo
        while(contador < nodeIndex)
        {
            pNode = pNode->pNextNode;//Me muevo por el array hasta que encuentro el nodo que quiere el usuario(nodeIndex)
            contador++;
        } //Y se lo asigno, que se ejecute hasta que encuentra el indice que quiere
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* prev;
    //Node* next;
    Node* nuevoNodo = NULL;

    if(this!=NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        nuevoNodo = (Node*) malloc(sizeof(Node));
        if(nuevoNodo !=NULL)//Me fijo si se pudo construir
        {
            nuevoNodo->pElement = pElement; //Cargo el vagon, con el elemento que me pasaron
            if(nodeIndex == 0)
            {
                nuevoNodo->pNextNode = this->pFirstNode; //Nuevo nodo tiene que enganchar vagon 0, copiar la direccion de memoria del que ya esta enganchado en esa posicion para no perderlo
                this->pFirstNode = nuevoNodo;//Engancho el primer elemento a la locomotora
            }
            else{
                prev = getNode(this,nodeIndex-1);//Le pido a getnode que me de la direccion de memoria del vagon que esta antes del que me quiero meter
                nuevoNodo->pNextNode = prev->pNextNode;//Mi nuevo vagon apunta al anterior
                prev->pNextNode = nuevoNodo;//Enganchar el que estaba antes al nuevo
            }
            this->size++;//Como aumento la cantidad de vagones, aumento el size de la locomotora
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    return addNode(this,ll_len(this),pElement);
}
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    Node* pNodo = NULL;
    void* returnAux = NULL;
    if(this != NULL && index >=0 && index < ll_len(this))
    {
        pNodo = getNode(this,index);
        if(pNodo != NULL)//importante validar que no devuelva null
        {
            returnAux = pNodo->pElement;//Devuelve la ubicacion de la carga
        }
    }
    return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* actual;

    if(this != NULL && index >= 0 && index< ll_len(this))
    {
        actual = getNode(this,index);
        if(actual !=NULL)
        {
            actual->pElement = pElement;
            returnAux = 0;
        }
    }
    return returnAux;
}
/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* anterior;
    Node* actual;
    //int indice = 0;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        actual = getNode(this,index);
        if(index == 0)
        {
            if(actual !=NULL)
            {
                this->pFirstNode = actual->pNextNode;//Asigno el siguiente nodo del vagon a la locomotora para no romper la cadena de enganches.
            }
        }
        else{
            anterior = getNode(this,index-1);
            if(anterior !=NULL)
            {
                anterior->pNextNode = actual->pNextNode;//Asigno el pNex node del vagon que voy a eliminar al que esta atras para no romper la cadena de enganches.
            }
        }
        free(actual);//Libero la memoria del vagon que quiero eliminar.
        this->size--;//Como tengo un vagon menos achico el tamaño del size.
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        while(ll_len(this) != 0)//Mientras queden elementos remove, siempre elimina el vagon 0.
        {
            ll_remove(this,0);
        }
        returnAux = 0;
    }
    return returnAux;
}
/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this !=NULL)
    {
        if(!ll_clear(this))
        {
            free(this);
            returnAux = 0;
        }
    }
    return returnAux;
}
/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
        int len = ll_len(this);//Lo calculo aca para no estar llamando a la funcion cada vez que itera el for
        for(int i=0;i<len;i++)//Recorro la lista
        {
            if(ll_get(this,i) == pElement)//ll_get me devuelve un PElent con el cual puedo comparar
            {
                returnAux = i;
                break;//Pq se puede repetir el pElement
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 0;
        if(ll_len(this) == 0)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this,index,pElement); //Add node devuelve lo mismo asique puedo hacer directamente un return
}
/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL && index >=0)
    {
        returnAux = ll_get(this,index);//Uso ll_get para obtener el pElement
        if(ll_remove(this,index))
        {
            returnAux = NULL; //Por si falla al remover, hago que tire error.
        }
    }
    return returnAux;
}
/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    if(this != NULL)
    {
        returnAux = 0;
        len = ll_len(this);
        for(int i=0;i<len;i++)
        {
            if(ll_get(this,i) == pElement)
            {
                returnAux = 1;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int contador = 0;
    if(this !=NULL && this2 != NULL)
    {
        returnAux = 0;
        int len = ll_len(this);
        for(int i=0;i<len;i++)
        {
            if(ll_get(this,i) == ll_get(this2,i))
            {
                contador++;
            }
        }
        if(contador == len)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}
/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* pElement = NULL;
    if(this != NULL && from >=0 && from < ll_len(this) && to > from && to <= ll_len(this))
    {
        LinkedList* nuevaLista = ll_newLinkedList();
        if(nuevaLista !=NULL)
        {
            for(i=from;i<=to;i++)
            {
                pElement = ll_get(this,i);
                ll_add(nuevaLista,pElement);
            }
        }
        cloneArray = nuevaLista;
    }
    return cloneArray;
}
/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL)
    {
        cloneArray = ll_subList(this,0,ll_len(this));
    }
    return cloneArray;
}
/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    void* pAux;
    if(this !=NULL &&(order == 0 || order == 1)&&pFunc != NULL)
    {
       int len = ll_len(this);
       for(int i=0;i<len-1;i++)
       {
           for(int j=i+1;j<len;j++)
           {
               if(order == 1 && pFunc(ll_get(this,i),ll_get(this,j))>0)
               {
                   pAux = ll_get(this,i);
                   ll_set(this,i,ll_get(this,j));
                   ll_set(this,j,pAux);
               }
               else if(order == 0 &&pFunc(ll_get(this,i),ll_get(this,j))<0)
               {
                   pAux = ll_get(this,i);
                   ll_set(this,i,ll_get(this,j));
                   ll_set(this,j,pAux);
               }
           }
       }
       returnAux = 0;
    }
    return returnAux;
}

