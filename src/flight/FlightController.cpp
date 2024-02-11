// #include "FlightController.h"
// #include "../motor/MotorController.h"
// #include <Wire.h>
// #include "MPU9250.h"


// const float kp = 1.0;   
// const float ki = 0.1;   
// const float kd = 0.01;  


// float setpoint = 0;     
// float pid_p = 0;        
// float pid_i = 0;        
// float pid_d = 0;       
// float last_error = 0;  
// float pid_output = 0;   


// MotorController *motorFL;
// MotorController *motorFR;
// MotorController *motorBL;
// MotorController *motorBR;


// MPU9250 mpu;

// FlightController::FlightController(MotorController *FL, MotorController *FR, MotorController *BL, MotorController *BR) {
//   motorFL = FL;
//   motorFR = FR;
//   motorBL = BL;
//   motorBR = BR;
// }

// void FlightController::init() {

//     Wire.begin();
//     delay(2000);

//     MPU9250Setting setting;
//     setting.accel_fs_sel = ACCEL_FS_SEL::A16G;
//     setting.gyro_fs_sel = GYRO_FS_SEL::G2000DPS;
//     setting.mag_output_bits = MAG_OUTPUT_BITS::M16BITS;
//     setting.fifo_sample_rate = FIFO_SAMPLE_RATE::SMPL_200HZ;
//     setting.gyro_fchoice = 0x03;
//     setting.gyro_dlpf_cfg = GYRO_DLPF_CFG::DLPF_41HZ;
//     setting.accel_fchoice = 0x01;
//     setting.accel_dlpf_cfg = ACCEL_DLPF_CFG::DLPF_45HZ;

//     if (!mpu.setup(0x68, setting)) {
//         while (1) {
//             Serial.println("MPU connection failed. Please check your connection with `connection_check` example.");
//             delay(5000);
//         }
//     }


// }

// void FlightController::loop() {

//   if (mpu.update()) {
//     float ax, ay, az, gx, gy, gz;
//     ax = mpu.getAccX();
//     ay = mpu.getAccY();
//     az = mpu.getAccZ();
//     gx = mpu.getGyroX();
//     gy = mpu.getGyroY();
//     gz = mpu.getGyroZ();

//     float current_value = gx; 
//     float error = setpoint - current_value;

    
//     pid_p = kp * error;
//     pid_i += ki * error;
//     pid_d = kd * (error - last_error);
//     pid_i = constrain(pid_i, -50, 50); 
//     pid_output = pid_p + pid_i + pid_d;
//     last_error = error;

   
//     int basePower = 50; 
//     motorFL->setPower(constrain(basePower + pid_output, 0, 100));
//     motorFR->setPower(constrain(basePower - pid_output, 0, 100));
//     motorBL->setPower(constrain(basePower + pid_output, 0, 100));
//     motorBR->setPower(constrain(basePower - pid_output, 0, 100));

//   }
// }

// void FlightController::calibrate() {
    
//     Serial.println("Accel Gyro calibration will start in 5sec.");
//     Serial.println("Please leave the device still on the flat plane.");
//     mpu.verbose(true);
//     delay(5000);
//     mpu.calibrateAccelGyro();

//     Serial.println("Mag calibration will start in 5sec.");
//     Serial.println("Please Wave device in a figure eight until done.");
//     delay(5000);
//     mpu.calibrateMag();

//     print_calibration();
//     mpu.verbose(false);
// }

// void FlightController::print_calibration() {
//     Serial.println("< calibration parameters >");
//     Serial.println("accel bias [g]: ");
//     Serial.print(mpu.getAccBiasX() * 1000.f / (float)MPU9250::CALIB_ACCEL_SENSITIVITY);
//     Serial.print(", ");
//     Serial.print(mpu.getAccBiasY() * 1000.f / (float)MPU9250::CALIB_ACCEL_SENSITIVITY);
//     Serial.print(", ");
//     Serial.print(mpu.getAccBiasZ() * 1000.f / (float)MPU9250::CALIB_ACCEL_SENSITIVITY);
//     Serial.println();
//     Serial.println("gyro bias [deg/s]: ");
//     Serial.print(mpu.getGyroBiasX() / (float)MPU9250::CALIB_GYRO_SENSITIVITY);
//     Serial.print(", ");
//     Serial.print(mpu.getGyroBiasY() / (float)MPU9250::CALIB_GYRO_SENSITIVITY);
//     Serial.print(", ");
//     Serial.print(mpu.getGyroBiasZ() / (float)MPU9250::CALIB_GYRO_SENSITIVITY);
//     Serial.println();
//     Serial.println("mag bias [mG]: ");
//     Serial.print(mpu.getMagBiasX());
//     Serial.print(", ");
//     Serial.print(mpu.getMagBiasY());
//     Serial.print(", ");
//     Serial.print(mpu.getMagBiasZ());
//     Serial.println();
//     Serial.println("mag scale []: ");
//     Serial.print(mpu.getMagScaleX());
//     Serial.print(", ");
//     Serial.print(mpu.getMagScaleY());
//     Serial.print(", ");
//     Serial.print(mpu.getMagScaleZ());
//     Serial.println();
// }
