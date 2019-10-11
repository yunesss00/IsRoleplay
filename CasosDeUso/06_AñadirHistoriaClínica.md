## Añadir entrada a Historia Clínica
**ID:** 06 **Descripción:** Se introduce el DNI del paciente del paciente y se introducen sus datos médicos.
**Actores principales:** Administrador

**Precondiciones:**
- Los pacientes deben de estar ya registrados en el sistema

**Flujo principal:**
1. El administrador desea añadir una entrada nueva a la historia clínica
2. El administrador conoce los datos médicos del paciente
3. El administrador busca al paciente e introduce los síntomas, día de llegada, tratamiento, regularidad del tratamiento, día que empezó/acabó el tratamiento
4. El sistema guarda los datos del usuario en su historia clínica

**Postcondiciones:**
- Ninguna

**Flujos alternativos:**
4.a Si no existe el usuario, se muestra un mensaje de error
