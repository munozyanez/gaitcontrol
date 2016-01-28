#include <iostream>
#include <vector>

using namespace std;

#include "spgait.h"

//kdl
//#include <frames.hpp>

/**
 * @brief This function will add "stepNumber" steps in forward direction, using
 * support poligon stability criteria. Results are stored in the trajectory source variable.
 * @param stepNumber = Number of steps to add.
 * @return true at success.
 */
bool spGait::AddStepForward(int stepNumber)
{

    double x,y,z;
    Pose actualRightFoot, actualLeftFoot;
    Pose desiredRightFoot,desiredLeftFoot;



    //SpaceTrajectory next;
    //strategy
    //-1-move root over right foot (or right and left foot under root)
    trajRightFoot.GetCurrentPose(actualRightFoot);
    actualRightFoot.GetPosition(x,y,z);

    desiredRightFoot.SetPosition(0,0,z);
    trajRightFoot.AddWaypoint(desiredRightFoot);

    desiredLeftFoot.ChangePosition(0-x,0-y,z-z);
    trajLeftFoot.AddWaypoint(desiredLeftFoot);

    //-2-balance over right foot
    //TODO
    //-3-left foot forward
    desiredLeftFoot.ChangePosition(swingDistance,0,swingElevation);
    trajLeftFoot.AddWaypoint(desiredLeftFoot);
    //move root over center
    //move root over left foot
    //balance over left foot
    //right foot forward
    //move root over center


    return true;
}


/**
 * @brief spGait::spGait = Constructor with the initial feet poses.
 * @param initialRightFoot = Initial right foot pose.
 * @param initialLeftFoot = Initial left foot pose.
 */
spGait::spGait(Pose initialRightFoot, Pose initialLeftFoot)
{
    trajRightFoot.AddTimedWaypoint(-1, initialRightFoot);
    trajLeftFoot.AddTimedWaypoint(-1, initialLeftFoot);

    swingDistance = 0.0;
    swingElevation = 0.0;

}

/**
 * @brief spGait::SetStepParameters = Set the step parameters for the gait functions.
 * @param swingFootDistance = The distance the floating foot will move forward on every step.
 * @param swingFootElevation = The distance the floating foot will raise from ground on every step.
 * @return
 */
bool spGait::SetStepParameters( double swingFootDistance, double swingFootElevation )
{
    swingDistance = swingFootDistance;
    swingElevation = swingFootElevation;

    return true;
}

/*
bool StepStageUpdatePoses(spGaitParameters params, std::vector<Transform>& effectorPosesResult)
{

    double dx, dy, dz; //root translation
    switch(params.stepPhase)
    {

    //--Double support. Moving root inside poligon to left foot.--

    case 1: //--Move root over left foot while in double support--
        dx = 0;
        dy = effectorPosesResult[6].trans.y - effectorPosesResult[0].trans.y;
        dz = 0;
        RootTranslationWithAttachments(dx, dy, dz, effectorPosesResult);

        break;

        //--Single support on left foot. Move root and right floating foot.--

    case 2: //First half swing of right foot

        //righ foot swing
        effectorPosesResult[5].trans.z += params.swingElevation;
        effectorPosesResult[5].trans.x += params.swingDistance/2;

        //root translation
        dx = params.swingDistance/4;
        dy = 0;
        dz = 0;
        RootTranslationWithAttachments(dx, dy, dz, effectorPosesResult);
        break;

    case 3: //Second half swing of right foot

        //righ foot swing
        effectorPosesResult[5].trans.z -= params.swingElevation;
        effectorPosesResult[5].trans.x += params.swingDistance/2;

        //root translation
        dx = params.swingDistance/4;
        dy = 0;
        dz = 0;
        RootTranslationWithAttachments(dx, dy, dz, effectorPosesResult);
        break;

        //--Double support. Moving root inside poligon.--

    case 4: //--Move root over right foot while in double support--
        dx = 0;
        dy = effectorPosesResult[5].trans.y - effectorPosesResult[0].trans.y;
        dz = 0;
        RootTranslationWithAttachments(dx, dy, dz, effectorPosesResult);
        break;

        //--Single support on right foot. Move root and left floating foot.--

    case 5: //First half swing of left foot

        //left foot swing
        effectorPosesResult[6].trans.z += params.swingElevation;
        effectorPosesResult[6].trans.x += params.swingDistance/2;

        //root translation
        dx = params.swingDistance/4;
        dy = 0;
        dz = 0;
        RootTranslationWithAttachments(dx, dy, dz, effectorPosesResult);
        break;

    case 6: //Second half swing of left foot

        //left foot swing
        effectorPosesResult[6].trans.z -= params.swingElevation;
        effectorPosesResult[6].trans.x += params.swingDistance/2;

        //root translation
        dx = params.swingDistance/4;
        dy = 0;
        dz = 0;
        RootTranslationWithAttachments(dx, dy, dz, effectorPosesResult);
        break;

    case 7:
        //move root from right foot to double support center


    default:
        //If this is no step phase stop and return error.
        return false;
    };


    return true;
}
*/
