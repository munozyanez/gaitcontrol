#include <iostream>
#include <fstream>

#include "GaitLipm.h"
#include "MiddlewareInterface.h"
#include "SensorIntegration.h"

using namespace std;

using namespace teo;


int main()
{


    kin::Pose initialRightFoot(0,-0.1285,-0.85);
    initialRightFoot.ChangeRotation(0,1,0,-M_PI/2);
    initialRightFoot.ChangeRotation(1,0,0,M_PI);
    kin::Pose initialLeftFoot(0,+0.15,-0.85);
    initialLeftFoot.ChangeRotation(0,1,0,-M_PI/2);
    //every gait operation start with instantiation and initialization of a Gait child class
    GaitLipm walk01(initialRightFoot,initialLeftFoot,80.);
    walk01.SetSwingParameters(0.05,0.05); //(swing distance, swing height). revisar valores
    walk01.SetHipParameters(0.25, 0.10); //(hip sideshift, hip lowering). revisar estos valores

    //The Gait objects can do the following tasks.


    std::vector<double> x={0,0};
    std::vector<double> y={0.3,0.2999};
    std::vector<double> z={1,1};
    std::cout << "initial x: " << x << std::endl;
    std::cout << "initial y: " << y << std::endl;
    std::cout << "initial z: " << z << std::endl;


    walk01.LipZmpTrajectory(x,y,z,0.001);

    std::vector<double> lipm1={0.15,0.1465};

    walk01.LipmAngularResponse(lipm1,0.01,1);
    std::cout << "lipm1: " << lipm1 << std::endl;


    return 0;
}
