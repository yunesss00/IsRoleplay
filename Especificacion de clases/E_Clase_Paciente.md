## Clase Paciente
#### Descripción:
Esta clase contiene los atributos y las funciones de los pacientes. Entre las funciones se puede encontrar añadir un paciente nuevo, modificar datos de un paciente y mostrar una lista de los pacientes ordenada alfabéticamente.

#### Atributos:
* Nombre:
    * Tipo string
    * Descipción : Nombre del paciente
* Apellidos:
    * Tipo string
    * Descripción: Apellidos del paciente
* Teléfono:
    * Tipo long
    * Descripción: Teléfono de contacto del paciente
* Pública_o_Privada:
    * Tipo string
    * Descripción: Tipo de sanidad de la que proviene el paciente
* Código_Postal:
    * Tipo integer
    * Descripción: número identificador de dirección del paciente
* DNI:
    * Tipo string
    * Descripción: identificador del paciente
* Descripción:
    * Tipo string
    * Descripción: breves apuntes sobre el paciente

#### Operaciones:
* Paciente:
    * Descripción: Constructor de la clase. Inicializa los parámetros obligatorios(DNI,nombre,apellidos) para el uso de la clase.
* Set_Paciente:
    * Descripción: Función que añade un nuevo paciente a la base de datos.
* Modificar_Paciente:
    * Descripción: Función que permite modificar los datos de un paciente.
* Get_Pacientes_Ordenado:
    * Descripción: Función que muestra la lista de pacientes ordenados alfabéticamente.
* Buscar_Paciente:
    * Descripción: Función que busca un paciente tras introducir sus apellidos.
* Borrar_Paciente:
    * Descripción: Función que permite borrar un paciente de la base de datos.
* Comentar_Paciente:
    * Descripción: Función que permite hacer apuntes sobre un paciente.
