#include "tools.h"

using namespace std;
using namespace teo::tra;

//Pose definitions

Pose::Pose()
{

}

Pose::Pose(double x0, double y0, double z0)
{
    x=x0;
    y=y0;
    z=z0;
}

bool Pose::GetPosition(double &pose_x, double &pose_y, double &pose_z)
{
    pose_x=x;
    pose_y=y;
    pose_z=z;
    return true;
}

double Pose::GetX()
{
    return x;
}

double Pose::GetY()
{
    return y;
}

double Pose::GetZ()
{
    return z;
}

bool Pose::GetRotation(double &axis_i, double &axis_j, double &axis_k, double &pose_angle)
{
    axis_i=i;
    axis_j=j;
    axis_k=k;
    pose_angle=angle;
    return true;
}

bool Pose::SetPosition(double new_x, double new_y, double new_z)
{
    x=new_x;
    y=new_y;
    z=new_z;
    return true;
}

bool Pose::ChangePosition(double dx, double dy, double dz)
{
    x+=dx;
    y+=dy;
    z+=dz;
    return true;

}
/*
Pose Pose::TransformTo(Pose anotherPose)
{
    Pose transform;
    return transform;
}
*/

//SpaceTrajectory definitions

bool SpaceTrajectory::AddTimedWaypoint(double dt, Pose waypoint)
{

    waypoints.push_back(waypoint);
    delta_t.push_back(dt);
    /*
    error = waypoints.insert(std::pair<double,Pose>(t,waypoint));
    if (error.second == false)
    {
        std::cout << "Trying to insert existing values" << std::endl;
        return -1;
    }*/
    return 0;
}

bool SpaceTrajectory::AddWaypoint(Pose waypoint)
{

    waypoints.push_back(waypoint);

    return 0;
}

bool SpaceTrajectory::GetLastWaypoint(Pose &waypoint)
{
    waypoint = waypoints.back();
    return true;
}

bool SpaceTrajectory::SaveToFile(std::ofstream &csvFile)
{
    //Pose wpPose;
    double x,y,z;
    double i,j,k,angle;
    for (int n=0; n<waypoints.size(); n++)
    {
        //wpPose.GetPosition(x,y,z);
        waypoints[n].GetPosition(x,y,z);
        //wpPose.GetRotation(i,j,k,angle);
        waypoints[n].GetRotation(i,j,k,angle);
        csvFile << x << ",";
        csvFile << y << ",";
        csvFile << z << ",";
        csvFile << i << ",";
        csvFile << j << ",";
        csvFile << k << ",";
        csvFile << angle << std::endl;
    }
}
