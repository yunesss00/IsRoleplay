## Añadir citas

**ID**: 09
**Descripción**: Permite añadir una cita para un paciente en una fecha y hora determinada

**Actores principales**: Administrador


**Precondiciones**:
* Que exista el paciente al que va a añadir la cita

**Flujo principal**:
1. El administrador desea añadir una cita para un paciente
1. El administrador selecciona en el menú principal "Añadir cita"
1. El sistema pide al usuario introducir el paciente que necesita la cita, el dia y la fecha correspondiente
1. El sistema imprime por pantalla un mensaje diciendo que la cita se ha añadido correctamente

**Postcondiciones**:

* Se le da al administrador la opción de volver al menú principal

**Flujos alternativos**:

3.a. Si ya hay una cita ese día a esa hora se muestra un mensaje por pantalla avisando de que dos citas coinciden y se le devuelve al menu principal