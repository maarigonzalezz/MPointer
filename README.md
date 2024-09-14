# MPointer

Este proyecto se centra en la creación de un sistema de gestión de memoria en C++ mediante el uso de una clase de puntero inteligente personalizada llamada `MPointer`. La gestión de memoria se lleva a cabo a través de la clase `MPointerGC`, que actúa como un singleton responsable de controlar las instancias de `MPointer`, asignar identificadores únicos, llevar un registro de las direcciones de memoria y manejar el conteo de referencias para evitar fugas de memoria. 

Además, el proyecto incluye la implementación de algoritmos de ordenamiento como QuickSort, BubbleSort e InsertionSort utilizando listas doblemente enlazadas basadas en `MPointer`. Finalmente, se necesita la creación de pruebas unitarias con cobertura completa utilizando GTest para garantizar el correcto funcionamiento de todas las funcionalidades implementadas.
