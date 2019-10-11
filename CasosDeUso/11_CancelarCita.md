## Cancelar cita

**ID**: 11
**Descripción**: Da la opción de poder cancelar una cita

**Actores principales**: Administrador


**Precondiciones**:
* Ninguna

**Flujo principal**:
1. El administrador desea cancelar una cita determinada
1. El administrador selecciona en el menú principal "Cancelar cita"
1. El sistema pide al administrador introducir el dia y la hora de la cita que desea cancelar
1. El sistema cancela la cita seleccionada 
1. El sistema devuelve un mensaje diciendo que se ha cancelado correctamente

**Postcondiciones**:

* Se le da al administrador la opción de volver al menú principal

**Flujos alternativos**:

3.a. Si no existe la cita seleccionada se muestra un mensaje diciendo que no hay cita para cancelar y le da la opción de volver al menú. 
