# 🧩 Push Swap
## *Proyecto de Algoritmia en C (Escuela 42)*

## 📚 Descripción General

**Push Swap** es un proyecto de la Escuela 42 que consiste en desarrollar un programa en C capaz de ordenar una lista de enteros utilizando un conjunto limitado de operaciones de manipulación de pilas. El objetivo es generar la secuencia más corta posible de instrucciones para lograr la ordenación ascendente de los números en la pila A.

---

## 🎯 Objetivo del Proyecto

- 🧠 Implementar un algoritmo de ordenación eficiente utilizando dos pilas (A y B).
- 🔧 Utilizar un conjunto limitado de operaciones para manipular las pilas.
- 📉 Minimizar el número total de operaciones necesarias para ordenar la lista.

---

## 🛠️ Operaciones Permitidas

| Operación | Descripción |
|-----------|-------------|
| `sa` | Intercambia los dos primeros elementos de la pila A. |
| `sb` | Intercambia los dos primeros elementos de la pila B. |
| `ss` | Realiza `sa` y `sb` simultáneamente. |
| `pa` | Mueve el primer elemento de la pila B a la cima de la pila A. |
| `pb` | Mueve el primer elemento de la pila A a la cima de la pila B. |
| `ra` | Desplaza todos los elementos de la pila A una posición hacia arriba. |
| `rb` | Desplaza todos los elementos de la pila B una posición hacia arriba. |
| `rr` | Realiza `ra` y `rb` simultáneamente. |
| `rra` | Desplaza todos los elementos de la pila A una posición hacia abajo. |
| `rrb` | Desplaza todos los elementos de la pila B una posición hacia abajo. |
| `rrr` | Realiza `rra` y `rrb` simultáneamente. |

---

## 🧱 Arquitectura del Sistema

El sistema se organiza en módulos funcionales distintos:

- **Controlador Principal**: `push_swap.c` contiene la función `main()` que orquesta la ejecución del programa.
- **Procesamiento de Entrada**: Archivos como `check_args.c` y `manage_arr.c` manejan la validación de argumentos y la creación de arreglos.
- **Gestión de Pilas**: `manage_stacks.c` se encarga de la inicialización y manipulación de las pilas.
- **Motor de Ordenación**: `sort_stacks.c` implementa el algoritmo principal de ordenación.
- **Optimización de Costes**: Archivos como `stack_props.c` y `stack_movs.c` calculan y optimizan los movimientos necesarios.
- **Operaciones de Pila**: Archivos como `push.c`, `swap.c`, `rotate.c` y `reverse_rotate.c` implementan las operaciones básicas permitidas.
- **Utilidades**: `utils.c` contiene funciones auxiliares como `ft_atoi()`, `ft_strlen()`, `ft_putstr()`, entre otras.

---

## 🧩 Estructura de Datos Principal

El sistema se centra en la estructura `t_stack`, que representa tanto nodos individuales como las pilas completas. Esta estructura permite una gestión eficiente de los elementos y sus propiedades durante el proceso de ordenación.

---

## 🧠 Estrategia del Algoritmo

El algoritmo implementa diferentes estrategias según el tamaño de la entrada:

- **2 elementos**: Comparación simple y posible intercambio utilizando `sa()`.
- **3 elementos**: Ordenación especializada mediante la función `sort_three()`.
- **Más de 3 elementos**: Estrategia de divide y vencerás con optimización de costes, utilizando funciones como `sort_nums()`, `calculate_cost()` y `find_cheaper()`.

El flujo general del algoritmo para entradas grandes es el siguiente:

1. **Fase de Particionamiento**: Se trasladan elementos de la pila A a la pila B utilizando una partición basada en la mediana.
2. **Fase de Reducción**: Se reduce la pila A a 3 elementos y se ordenan.
3. **Fase de Reconstrucción**: Se calculan los movimientos óptimos para transferir los elementos de la pila B de vuelta a la pila A.
4. **Posicionamiento Final**: Se asegura que la pila A esté completamente ordenada en orden ascendente.

---

## 🧪 Ejecución del Programa

Para compilar y ejecutar el programa:

```bash
make
./push_swap [lista de números]
```



```bash
./push_swap 3 2 1
```

---

## 📌 Conclusión

El proyecto **Push Swap** es una excelente oportunidad para profundizar en:

- 📊 **Algoritmos de ordenación**
- 🧠 **Optimización de recursos**
- 🧮 **Análisis algorítmico**
- 🧱 **Gestión eficiente de estructuras de datos**

💡 A través de su implementación, desarrollarás habilidades clave en programación, análisis lógico y toma de decisiones basada en eficiencia.

> ¡Prepárate para enfrentar el desafío y optimizar cada movimiento! 🚀🤖

---

# 📝 Créditos

- 💻 **Proyecto:** Minishell – Escuela 42  
- ✍️ **Autor original:** Miriam Fernández Pérez  

---
