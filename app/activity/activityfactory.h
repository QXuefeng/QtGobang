#ifndef ACTIVITYFACTORY_H
#define ACTIVITYFACTORY_H

#include "localactivity.h"
#include "robotactivity.h"

// 活动工厂
class ActivityFactory
{
public:
    static Activity* createActivity(MODEL md)
    {
        if(md == MODEL::PVP) return new LocalActivity;
        else if(md == MODEL::PVE) return new RobotActivity;

        return new Activity;
    }
};

#endif // ACTIVITYFACTORY_H
