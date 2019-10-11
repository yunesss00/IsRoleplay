## Cancelar Tratamiento
**ID:** 07 **Descripción:** Se introduce el DNI del paciente y aparece la opción de cancelar el tratamiento
**Actores principales:** Administrador

**Precondiciones:**
- El paciente debe de estar ya registrado y tener un tratamiento en vigor

**Flujo principal:**
1. El administrador busca el paciente
2. El administrador conoce el tratamiento que se quiere cancelar
3. El administrador cancela el tratamiento
4. El tratamiento cancelado queda registrado como tal en el sistema

**Postcondiciones:**
- Ninguna

**Flujos alternativos:**
1.a Si el sistema no encuentra coincidencia de DNI, el sistema envía un mensaje de error
3.a Si el paciente no tiene ningún tratamiento activo, el sistema envía un mensaje de error
