# POO en C++ – Ejercicios nivel Medium

Ejercicios de Programación Orientada a Objetos sobre herencia, polimorfismo, sobrecarga e iteradores.

**Alumno:** Gerardo Avalos Sanchez
**Materia:** Programación Orientada a Objetos – Universidad Autónoma de Guadalajara

## Ejercicios

| # | Archivo | Tema | Qué hace |
|---|---------|------|----------|
| 1 | `1_Jerarquia_Simple.cpp` | Herencia | Clase base `Vehiculo` y dos clases hijas, `Auto` (puertas, transmisión) y `Motocicleta` (cilindrada), cada una con su propio `mostrarInfo()`. |
| 2 | `2_Polimorfismo.cpp` | Polimorfismo | Arreglo de `Vehiculo*` con autos y motos. Al llamar `mostrarInfo()`, cada objeto imprime su propia versión. |
| 3 | `3_Sobrecarga_Operadores.cpp` | Sobrecarga de operadores | Clase `Fraccion` con `+` (suma y simplifica) y `==` (compara si son equivalentes). |
| 4 | `4_Sobrecarga_Metodos.cpp` | Sobrecarga de métodos | Clase `Calculadora` con tres versiones de `sumar()`: dos enteros, tres enteros y dos decimales. |
| 5 | `5_Coleccion_Iterador.cpp` | Iteradores | `vector<Vehiculo*>` recorrido con `vector<Vehiculo*>::iterator`. |

## Cómo compilar y ejecutar

Desde la raíz del repositorio:

```bash
g++ -std=c++11 -Wall Proyects/POO_Proyects/Medium/1_Jerarquia_Simple.cpp -o build/1_Jerarquia_Simple
./build/1_Jerarquia_Simple
```

Cambia el nombre del archivo para los demás ejercicios. Los ejecutables se guardan en `build/`, que está en el `.gitignore`.

## Ejemplo de salida (ejercicio 3)

```
Pizza que nos comimos: 1/4 + 2/4 = 3/4
1/2 y 3/6 son equivalentes
1/2 y 2/3 no son equivalentes
```

## Uso de IA

Usé IA como apoyo para generar el código y resolver dudas de sintaxis y de compilación. Compilé, probé y revisé cada programa. Las dificultades y lo que aprendí están en la reflexión de cada ejercicio, dentro del reporte.