# POO en C++ – Ejercicios nivel High

Ejercicios sobre excepciones, archivos, bases de datos (SQLite) y librerías externas.

**Alumno:** Gerardo Avalos Sanchez
**Materia:** Programación Orientada a Objetos – Universidad Autónoma de Guadalajara

## Ejercicios

| # | Archivo | Tema | Qué hace |
|---|---------|------|----------|
| 0 | `0_Validacion_Excepciones.cpp` | Excepciones propias | Pide edad y correo. Lanza `EdadInvalida` o `CorreoInvalido` si el dato está mal y las captura con mensajes claros. |
| 1 | `1_Archivo_Texto.cpp` | Archivos de texto | Menú: 1 guarda 5 tareas en `tareas.txt`, 2 las lee y las muestra. |
| 2 | `2_Base_Datos_SQLite.cpp` | Base de datos | Crea `tienda.db` con la tabla `productos`, inserta 3 productos y los consulta. |
| 3 | `3_Libreria_JSON.cpp` | Librería externa | Usa nlohmann/json para guardar las calificaciones de un alumno en `alumno.json`, leerlas y sacar el promedio. |
| 4 | `4_Integracion_Errores.cpp` | Archivos + BD + excepciones | Lee un archivo o consulta una BD. Si el archivo no existe o la conexión falla, muestra el error y el programa sigue. |

## Qué instalar (CachyOS / Arch)

```bash
sudo pacman -S --needed gcc sqlite nlohmann-json
```

- `sqlite`: trae la librería y el header `sqlite3.h` (ejercicios 2 y 4).
- `nlohmann-json`: es solo un header (`/usr/include/nlohmann/json.hpp`), así que basta con `#include <nlohmann/json.hpp>` y no hay que enlazar nada.

## Cómo compilar y ejecutar

Desde la raíz del repositorio:

```bash
g++ -std=c++17 -Wall Proyects/POO_Proyects/High/0_Validacion_Excepciones.cpp -o build/0_Validacion_Excepciones
./build/0_Validacion_Excepciones
```

Cambia el nombre del archivo para los demás ejercicios. Los ejercicios 2 y 4 usan SQLite, así que llevan `-lsqlite3` al final:

```bash
g++ -std=c++17 -Wall Proyects/POO_Proyects/High/2_Base_Datos_SQLite.cpp -o build/2_Base_Datos_SQLite -lsqlite3
./build/2_Base_Datos_SQLite
```

Ejecuta el 1 y el 2 antes del 4 para tener `tareas.txt` y `tienda.db` y probar el caso que funciona.

## Ejemplo de salida (ejercicio 4)

```
[Error de archivo] El archivo 'noexiste.txt' no existe
[Error de base de datos] No se pudo conectar a 'noexiste.db': unable to open database file
```

## Uso de IA

Usé IA como apoyo para generar el código y resolver dudas de sintaxis y de compilación. Compilé, probé y revisé cada programa.
