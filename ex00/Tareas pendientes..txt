Orden de ejecucion de programa:

1º Main recibe los argumentos con el imput
{
	Variables necesarias en main:
	char raw_conditions[]; //guarda la lista de condiciones de los argumentos.
	int clean_conditions[]; //guarda la lista de condiciones como un array de enteros.
	int clean_lenght_conditions; //guarda la longitud de la lista raw_conditions podemos usar una función que devuelva la longitud.
	int solvable = 1; //Variable que usaremos para determinar si las condiciones permiten resolver el problema.
	int board[81];

	Funciones a las que llamamos de otros archivos:
	clean_lenght_conditions = ft_length; // Necesitamos una funion ft_length para conocer la longitud del string de condiciones.
	str_to_int_array(*raw_conditions, *clean_conditions, clean_lenght_conditions); // str_to_int_array Limpia los argumentos y los guarda en el array de int.
	solvable = ft_is_resoluble(clean_conditions); // ft_is_resoluble comprueba si el problema tiene alguna condicion que lo haga imposible de resolver.
	ft_fill_partialy_board(clean_conditions, *solvable) //Llenamos las posiciones conocidas y seguras del array, optimización secundaria que puede ir mejorándose.
	// importante en la función ft_fill_partialy_board comprobar si al colocar las posiciones seguras se llega a alguna imposibilidad que lo haga irresoluble y modificar solvable.
	if (solvable == 1)
	{
		ft_degrees_of_freedom(*board, clean_conditions, clean_lenght_conditions);
	}

}