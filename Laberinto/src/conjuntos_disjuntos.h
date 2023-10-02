/**
  * @file conjuntos_disjuntos.h
  * @brief TDA Conjunto Disjunto
  *
  * @author Antonio Garrido
  * @date Enero-2018
  *
  * Gestiona un conjunto items clasificados en clases de equivalencia. Forman una partición
  * del conjunto de items en conjuntos disjuntos.
  *
  * En inglés, puede encontrar el TDA con el nombre Disjoint-Set o Union-Find
  *
  */

#ifndef __CONJ_DISJUNTOS_H__
#define __CONJ_DISJUNTOS_H__

#include <vector>
#include <string>
#include <stdexcept> // invalid_argument

class ConjDisjuntos {
   mutable std::vector<int> items; // en 0, número de árboles. Desde 1 los padres (-rango para la raíz)
public:
   /** @brief Constructor
    *  @param nitems Número de items inicial.
    *  @post Contiene \c nitems items en sus respectivos conjuntos unitarios
    */
   ConjDisjuntos(std::size_t nitems= 0): //lista(nitems+1), nelementos(nitems+1, 1),
                                      items(nitems+1,0) {
      items[0]= nitems;
   }

   /// @brief Número de clases de equivalencia
   std::size_t nConjuntos() const { return items[0]; }

   /// @brief Número total de items que componen la partición
   std::size_t nItems() const { return items.size()-1; }

   /**
    * @brief Añadir un nuevo item
    * @return El número del nuevo item
    * @post Se crea una nueva clase con el nuevo item como único elemento
    */
   std::size_t nuevoItem() {
      items.push_back(0);
      items[0]++;
      return items.size()-1;
   }

   /**
    * @brief Buscar representante
    * @param item elemento del conjunto donde buscar. 1<=item<=nItems()
    * @return El representante de la clase donde se incluye item
    */
   std::size_t buscar(std::size_t item) const { // modifica *this por path compression
      if (item<1 || item >nItems())
         throw std::invalid_argument("Conjuntos disjuntos. Se intenta buscar un item incorrecto: "
                                    );
      if (items[item] <= 0)
         return item;
      else return items[item]= buscar(items[item]);
   }

   /**
    * @brief Unir dos clases
    * @param item1 elemento cualquiera de la primera clase. 1<=item1<=nItems()
    * @param item2 elemento cualquiera de la segunda clase. 1<=item2<=nItems()
    * @return si ha tenido éxito (los elementos eran de distintas clases)
    */
   bool unir(std::size_t item1, std::size_t item2) {
      std::size_t raiz1= buscar(item1);
      std::size_t raiz2= buscar(item2);
      if (raiz1 != raiz2) {
         if (items[raiz1]<items[raiz2]) // -rango más negativo
            items[raiz2]= raiz1;
         else {
            if (items[raiz2]==items[raiz1])
               items[raiz2]--;
            items[raiz1]= raiz2;
         }
         items[0]--;
         return true;
      }
      return false;
   }

   /**
    * @brief Comprobar equivalencia
    * @param item1 elemento cualquiera de la primera clase. 1<=item1<=nItems()
    * @param item2 elemento cualquiera de la segunda clase. 1<=item2<=nItems()
    * @return si pertenecen a la misma clase
    */
   bool sonEquiv (std::size_t item1, std::size_t item2 ) const {
      return buscar(item1) == buscar(item2); // Modifica *this
   }
};

#endif // __CONJ_DISJUNTOS_H__
