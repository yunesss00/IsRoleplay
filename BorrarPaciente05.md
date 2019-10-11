## Borrar datos de un paciente

**ID**: 05
**Descripción**: Se borran los datos de un paciente en concreto tras introducir su DNI y confirmar la acción.

**Actores principales**: Administrador

**Precondiciones**:
* El paciente debe haber pedido que sus datos sean borrados.

**Flujo principal**:
1. El paciente desea que sus datos sean borrados del sistema.
1. El administrador abre el menú principal y elige la opción de borrar datos de paciente.
1. El administrador introduce el DNI del paciente en cuestión y el sistema busca alguna coincidencia.
1. El sistema muestra los datos del paciente y un mensaje de confirmación de borrado.
1. El administrador confirma el borrado.
1. El sistema borra los datos del paciente y éste deja de estar en la lista de pacientes.

**Postcondiciones**:
* La historia médica del paciente no es borrada.

**Flujos alternativos**:
3.a. Si el sistema no encuentra coincidencia mediante DNI muestra un mensaje de error.
5.a. Si el administrador no confirma el borrado, el sistema lo manda de vuelta al menú principal.
