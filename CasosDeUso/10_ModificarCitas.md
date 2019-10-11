## Modificar citas

**ID**: 10
**Descripción**: Permite modificar el paciente, la fecha o la  una cita ya establecida

**Actores principales**: Administrador


**Precondiciones**:
* Ninguna

**Flujo principal**:
1. El administrador desea modificar una cita 
1. El administrador selecciona en el menú principal "Modificar citas"
1. El sistema pide al administrador introducir el dia y la hora de la cita que desea modificar
1. El sistema borra la cita seleccionada y le da la opcion de añadir una nueva
1. El sistema devuelve un mensaje diciendo que se ha modificado correctamente

**Postcondiciones**:

* Se le da al administrador la opción de volver al menú principal

**Flujos alternativos**:

3.a. Si no existe la cita seleccionada se muestra un mensaje diciendo que no hay citas y le da la opción de volver al menú. 
