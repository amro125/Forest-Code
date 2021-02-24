/*
# Software License Agreement (MIT License)
#
# Copyright (c) 2019, UFACTORY, Inc.
# All rights reserved.
#
# Author: Vinman <vinman.wen@ufactory.cc> <vinman.cub@gmail.com>
*/

#include "xarm/wrapper/xarm_api.h"

int main(int argc, char **argv) {
    //Reads first csv and breaks up joints to arrays
    std::ifstream inFile("forest1a.csv");
    std::vector<std::vector<string>> value1;

    std::string line;
    int i = 0;
    while (std::getline(inFile, line)){
        std::vector<string> v;
        value1.push_back(v);
        split(line, ',', value1[i]);
        i++;
    }   
        std::vector <double> posk1(numRows);
    int numRows = value1.size();
    std::vector <double> pos1(numRows);
    std::vector <double> pos2(numRows);
    std::vector <double> pos3(numRows);
    std::vector <double> pos4(numRows);
    std::vector <double> pos5(numRows);
    std::vector <double> pos6(numRows);
    std::vector <double> pos7(numRows);
    for (int i = 0; i< numRows; i++){
            pos1[i] = std::stod(value1[i][0]);
            pos2[i] = std::stod(value1[i][1]);
            pos3[i] = std::stod(value1[i][2]);
            pos4[i] = std::stod(value1[i][3]);
            pos5[i] = std::stod(value1[i][4]);
            pos6[i] = std::stod(value1[i][5]);
            pos7[i] = std::stod(value1[i][6]);
            std::cout<<pos1[i]<<std::endl;
    }
    std::ifstream inFile("forest1b.csv");
    std::vector<std::vector<string>> value1;

    std::string line;
    int i = 0;
    while (std::getline(inFile, line)){
        std::vector<string> v;
        value1.push_back(v);
        split(line, ',', value1[i]);
        i++;
    }   
// reads second csv and breaks
    int numRows = value1.size();
    std::vector <double> posk1(numRows);
    std::vector <double> posk2(numRows);
    std::vector <double> posk3(numRows);
    std::vector <double> posk4(numRows);
    std::vector <double> posk5(numRows);
    std::vector <double> posk6(numRows);
    std::vector <double> posk7(numRows);

    for (int i = 0; i< numRows; i++){
            posk1[i] = std::stod(value1[i][0]);
            posk2[i] = std::stod(value1[i][1]);
            posk3[i] = std::stod(value1[i][2]);
            posk4[i] = std::stod(value1[i][3]);
            posk5[i] = std::stod(value1[i][4]);
            posk6[i] = std::stod(value1[i][5]);
            posk7[i] = std::stod(value1[i][6]);
            std::cout<<pos1[i]<<std::endl;
    }
// defines each arm based on SDK 
    XArmAPI *arm1 = new XArmAPI('192.168.1.236');
    XArmAPI *arm2 = new XArmAPI('192.168.1.204');
    sleep_milliseconds(500);
    if (arm1->error_code != 0) arm1->clean_error();
    if (arm1->warn_code != 0) arm1->clean_warn();
    if (arm2->error_code != 0) arm2->clean_error();
    if (arm2->warn_code != 0) arm2->clean_warn();
    //Still trying to figure out what this does but xArm says we need it
    arm1->motion_enable(true);
    arm1->set_mode(0);
    arm1->set_state(0);
    arm2->motion_enable(true);
    arm2->set_mode(0);
    arm2->set_state(0);
    //Go to initial position
    ret = arm1->set_servo_angle({0.0, 0.0, 0.0, 1.5708, 0.0, 1.5708, 0.0}, true);
    ret = arm2->set_servo_angle({0.0, 0.0, 0.0, 1.5708, 0.0, 1.5708, 0.0}, true);
    sleep_milliseconds(500);

    printf("=========================================\n");

    int ret;
    arm->reset(true);
    //For loop that runs positions
    for (int i = 0; i < numRows; i++) {
        ret = arm1->set_servo_angle({angles[pos1[i],pos2[i],pos3[i],pos4[i],pos5[i],pos6[i],pos7[i]}, true);
        ret = arm2->set_servo_angle({angles[posk1[i],posk2[i],posk3[i],posk4[i],posk5[i],posk6[i],posk7[i]}, true);
        printf("set_servo_angle, ret=%d\n", ret);
        //still need to make this sample in real time
        /* This was the python way we made it sample in real time
        tts = time.time() - start_time
        print(tts)
        time.sleep(0.004-tts)
         */
    }

    arm->reset(true);
    return 
