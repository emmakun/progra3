//Funcion que devuelve la copia de una lista enlazada:

template<class T>
List<T>& List<T>::copy()
{
  List<T> copyList;
  Node<T> *tmp = first;

  while(tmp)
  {
    copyList.insert(temp->item);
    temp = temp->next;
  }

  return copyList;
}



//Funcion que devuelve la copia de una lista doblemente enlazada:

template<class T>
DList<T>& DList<T>::copy()
{
  first();
  DList<T> copyList;
  Node<T> *tmp = first;

  while(tmp)
  {
    copyList.insert(temp->item);
    temp = temp->next;
  }

  return copyList;
}



//Funcion que copia los primeros n elementos de una lista enlazada

template<class T>
List<T>& List<T>::copyN(int n)
{
  List<T> copyList;
  Node<T> *tmp = first;

  for(int i=0;i<n;i++)
  {
    copyList.insert(tmp->item);
    tmp = tmp->next;
  }

  return copyList;
}
