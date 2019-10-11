## Extracción de requisitos

#### Partes interesadas:
* Doctora Barbero
* Equipo de desarrollo

#### Datos que gestiona el sistema:
* Pacientes
  * Nombre
  * Apellidos
  * Teléfono
  * Pública o Privada
  * Código Postal
* Historia Clínica
  * Día
  * Síntomas
  * Tratamiento
    * Regularidad
    * Fecha inicial y fecha final
* Citas
  * Fecha
  * Hora

#### Requisitos funcionales (ordenados por prioridad)
* Pacientes
1. Añadir nuevo paciente
1. Modificar datos de un paciente
1. Mostrar una lista de los pacientes ordenados alfabéticamente
1. Buscar paciente por apellido
1. Borrar datos de un paciente con confirmación
1. Poder hacer algún apunte sobre el paciente
* Historia Clínica
1. Añadir historia clínica
1. No se permite la modificación
1. Poder cancelar un tratamiento
* Citas
1. Mostrar citas del día
1. Añadir citas
1. Modificar citas
1. Cancelar citas
1. Aviso si coinciden dos citas




#### Requisitos no funcionales
* Sistema operativo Linux
* Interfaz CLI
* Lenguaje de implementación: C++
* Máximo 10 GiB de almacenamiento













