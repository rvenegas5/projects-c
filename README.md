# Lección - Películas

Para esta lección se evaluará el uso de funciones y colecciones, por lo que deben reutilizar las funciones creadas cuando aplique.

Se le ha dado datos acerca de películas en una cadena, con la siguiente estructura:

**num,pelicula(anio),genero1|genero2|....|generoN`;`num2,pelicula2(anio),genero4|genero5|....|generoZ`;`....**

Ejemplos:

**5,ToyStory(1995),Adventure|Animation|Children|Comedy|Fantasy`;`3,Jumanji(1995),Adventure|Children|Fantasy;...**

Implementar las siguientes funciones:

**1) Implemente la función que reciba la cadena `con una sola película` y retorna un diccionario con los datos de esa película. (5pt)**

Ej: 

```
unaPelicula = '1,ToyStory2(1995),Adventure|Comedy|Fantasy'
diccPeli = funcion1(unaPelicula)


#diccPeli es un diccionario con: 

```
{ `'pelicula'`:'ToyStory2(1995)', 
`'generos'`:{'Adventure','Comedy','Fantasy'} 
}

**Nota: el nombre de la película es un string y los generos un conjunto**

**2) Implemente la función que reciba la cadena con `varias películas` (separadas por ';') y retorne una tupla con los géneros de todas las películas sin duplicados.(5pt)**

Ej: 

```
peliculas = '1,ToyStory(1995),Adventure|Animation|Children|Comedy|Fantasy;2,Jumanji(1995),Adventure|Children|Fantasy'
generos = funcion2(peliculas)
```

```
# generos es una tupla con: ('Adventure','Animation','Children','Comedy','Fantasy')
```

**3) Implemente la función que reciba la cadena con `varias películas` y retorne un diccionario con la siguiente estructura:(5pt)**

```
{'<pelicula1>':<conjunto de generos1>, '<pelicula2>':<conjunto de generos2>,..., '<peliculaN>':<conjunto de generosN>}
```
Ej: 
```
peliculas = '1,ToyStory(1995),Adventure|Animation|Children;
2,Jumanji(1995),Adventure|Children|Fantasy'
diccPeli = funcion3(peliculas)
```

```
#diccPeli--> {'ToyStory(1995)': {'Adventure','Animation','Children'},
              'Jumanji(1995)':  {'Adventure','Fantasy','Children'},.. }
```

**4) Implemente la función que reciba un diccionario como el anterior y retorne otro diccionario agrupado por años, como se muestra(5pt):**

```
{ año1 : [ peli1, peli2, ... , peliN], 
  año2 : [ peli3, peli4, ... , peliZ], ... }
```
Ej:
```
diccPeli = {'ToyStory(1995)': {'Adventure','Animation','Children'},
              'Jumanji(1995)':  {'Adventure','Fantasy','Children'},
              'HarryPotter(2002)':  {'Fantasy','Children'}, ..}

resultado = funcion4(diccPeli)
```

```
#resultado es un diccionario 
{1995:['ToyStory', 'Jumanji' ], 2002:['HarryPotter'] }
```

# Extra 

**Implemente la función que muestre las películas de un determinado género. La función recibe un diccionario como el del tema3 y el género, y  muestra por pantalla los nombre de las películas que pertenecen ese género.  (5pt)**

Ej:

```
funcionExtra( dicTema3, 'Adventure')
```

```
# la función mostrará 
ToyStory(1995)
Jumanji(1995)
```

