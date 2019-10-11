## Modificar datos de un paciente por DNI

**ID**:02
**Descripción**: Modificación de datos de un paciente tras búsqueda por DNI.

**Actores principales**: Administrador

**Precondiciones**:
* Debe haber un paciente con el DNI que se introduzca

**Flujo principal**:
1. El administrador desea modificar los datos de un paciente.
1. El administrador posee el DNI del paciente que quiere modificar.
1. El administrador abre el menú y elige la opción de modificar datos de un paciente.
1. El administrador introduce el DNI del paciente en cuestión.
1. El sistema muestra los datos del paciente por pantalla y permite modificar cada campo.

**Postcondiciones**:
* Los datos antiguos del paciente son desechados

**Flujos alternativos**:
4.a. Si no hay ningún paciente con el DNI introducido, se muestra mensaje de error

