#ifndef FLIGHTCONTROLLER_H
#define FLIGHTCONTROLLER_H

#include "../motor/MotorController.h"

class FlightController {
public:
    // Construtor: recebe ponteiros para os objetos MotorController dos quatro motores
    FlightController(MotorController *FL, MotorController *FR, MotorController *BL, MotorController *BR);

    void init();  // Função para inicializar componentes, como a MPU-9250
    void loop();   // Função principal de controle de voo que deve ser chamada repetidamente
    void calibrate();   
    void print_calibration();

private:
    // Ponteiros para os objetos MotorController dos quatro motores
    MotorController *motorFL; // Motor da frente esquerda
    MotorController *motorFR; // Motor da frente direita
    MotorController *motorBL; // Motor de trás esquerdo
    MotorController *motorBR; // Motor de trás direito

    // Você pode adicionar aqui outras variáveis necessárias para o controle de voo,
    // como variáveis para armazenar leituras de sensores, estados do drone, etc.
};

#endif // FLIGHTCONTROLLER_H
