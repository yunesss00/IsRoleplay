## Clase Citas
#### Descripcion:
Esta clase almacena los datos de la citas, asi como los datos de los pacientes asociados a ellas.También posee las funciones necesarias para gestionar las citas.

#### Atributos:
* Fecha :
  * Tipo: String
  * Descripción: Día en el que se almacena la cita
 * Hora:
   * Tipo: String
   * Descripción: Hora a la que se almacena la cita
 * Nombre_Paciente:
   * Tipo: String
   * Descripción: Nombre al que esta asociado la cita

#### Operaciones:
* Cita:
  * Descripción: Constructor de la clase. Permite inicializar todos los parámetros imprescindibles para el uso de la clase.
* Set_Cita :
  * Descripción: Funcion que resgistra una cita de un paciente en la base de datos a una hora y fecha en concreto.
* Get_Cita:
  * Descripción: Funcion que imprime por pantallas las citas programadas para el dia actual.
* Modificar_Cita:
  * Descripción: Funcion que permite reemplazar los datos de una cita previamente programada.
* Borrar_Cita:
  * Descripción: Función que permite eliminar de la base de datos una cita previamente programada.
