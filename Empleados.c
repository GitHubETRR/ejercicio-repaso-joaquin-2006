#include <stdio.h>
#include <string.h>

#define MAX_EMPLEADOS 5

//Parte de la estructura del empleado 
struct Empleado {
    char nombre[50];
    int edad;
    float salario;
};

//Prototipos de funciones de ingresar, procesar, mostrar datos
void ingresarDatos(struct Empleado empleados[], int *numEmpleados);
void procesarDatos(struct Empleado empleados[], int numEmpleados);
void mostrarDatos(struct Empleado empleados[], int numEmpleados);

int main() {
    struct Empleado empleados[MAX_EMPLEADOS];
    int numEmpleados = 0;
    int opcion;

    do {
        // Menú interactivo
        printf("\nMenú:\n");
        printf("1. Ingresar datos de un empleado\n");
        printf("2. Procesar y mostrar información relevante de los empleados\n");
        printf("3. Salir del programa\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                ingresarDatos(empleados, &numEmpleados);
                break;
            case 2:
                procesarDatos(empleados, numEmpleados);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
        }
    } while(opcion != 3);

    return 0;
}

// Función para ingresar los datos de un empleado
void ingresarDatos(struct Empleado empleados[], int *numEmpleados) {
    if (*numEmpleados < MAX_EMPLEADOS) {
        printf("Ingrese el nombre del empleado: ");
        scanf("%s", empleados[*numEmpleados].nombre);
        printf("Ingrese la edad del empleado: ");
        scanf("%d", &empleados[*numEmpleados].edad);
        printf("Ingrese el salario del empleado: ");
        scanf("%f", &empleados[*numEmpleados].salario);
        (*numEmpleados)++;
        printf("Empleado ingresado correctamente.\n");
    } else {
        printf("No se pueden ingresar más empleados. Límite alcanzado.\n");
    }
}

// Función para procesar los datos de los empleados
void procesarDatos(struct Empleado empleados[], int numEmpleados) {
    if (numEmpleados == 0) {
        printf("No hay empleados ingresados.\n");
        return;
    }

    float promedioSalarios = 0;
    float salarioMaximo = empleados[0].salario;
    char nombreMaximo[50];
    for (int i = 0; i < numEmpleados; i++) {
        promedioSalarios += empleados[i].salario;
        if (empleados[i].salario > salarioMaximo) {
            salarioMaximo = empleados[i].salario;
            strcpy(nombreMaximo, empleados[i].nombre);
        }
    }
    promedioSalarios /= numEmpleados;

    printf("Promedio de salarios: %.2f\n", promedioSalarios);
    printf("Empleado con el salario más alto: %s\n", nombreMaximo);
}

// Función para mostrar los datos de todos los empleados
void mostrarDatos(struct Empleado empleados[], int numEmpleados) {
    if (numEmpleados == 0) {
        printf("No hay empleados ingresados.\n");
        return;
    }

    printf("Información de los empleados:\n");
    for (int i = 0; i < numEmpleados; i++) {
        printf("Empleado %d:\n", i+1);
        printf("Nombre: %s\n", empleados[i].nombre);
        printf("Edad: %d\n", empleados[i].edad);
        printf("Salario: %.2f\n", empleados[i].salario);
        printf("\n");
    }
}

