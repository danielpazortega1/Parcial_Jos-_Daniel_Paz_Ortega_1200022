#include "pch.h"
#include "../ruta/del/proyecto/Ejercicio01.h"

TEST(Ejercicio01Test, MergeEmptyLists) {
    Ejercicio01 ejercicio01;
    Node<Node<int>*>* lists = nullptr; // Suponiendo que tengas una función para crear esta estructura de datos.

    Node<int>* result = ejercicio01.mergeLists(lists);

    EXPECT_EQ(result, nullptr);
}

TEST(Ejercicio01Test, MergeSingleElementLists) {
    Ejercicio01 ejercicio01;
    // Aquí deberías construir tus listas de prueba con un solo elemento y probar el método `mergeLists`.
}

// Y así sucesivamente para otros casos de prueba.
