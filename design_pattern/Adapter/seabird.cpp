#include <iostream>
using namespace std;

class IAircraft
{
public:
    virtual bool get_airborne() = 0;
    virtual void takeoff() = 0;
    virtual int get_height() = 0;
};

class Aircraft: public IAircraft
{/*{{{*/
public:
    Aircraft()
    {
        height = 0;
        airborne = false;
    }

    void takeoff()
    {
        cout << "Aircraft engine takeoff" << endl;
        airborne = true;
        height = 200;
    }

    bool get_airborne()
    {
        return airborne;
    }

    int get_height()
    {
        return height;
    }

private:
    bool airborne;
    int height;
};/*}}}*/

class ISeacraft
{
public:
    virtual int get_speed() = 0;
    virtual void increaseRevs() = 0;
};

class Seacraft: public ISeacraft
{/*{{{*/
public:
    Seacraft()
    {
        speed = 0;
    }

    int get_speed()
    {
        return speed;
    }

    virtual void increaseRevs()
    {
        speed += 10;
        cout << "Seacraft engine increase revs to " << get_speed() << " knots" << endl;
    }

private:
    int speed;
};/*}}}*/

class Seabird: public IAircraft, public Seacraft
{/*{{{*/
private:
    int height;
public:
    Seabird()
    {
        height = 0;
    }

    void takeoff()
    {
        while (!get_airborne())
        {
            increaseRevs();
        }
    }

    int get_height()
    {
        return height;
    }

    void increaseRevs()
    {
        //cout << "Seabird::increaseRevs()" << endl;
        Seacraft::increaseRevs();
        if (get_speed() > 40)
        {
            height += 100;
        }
        //cout << "height:" << height << endl;
    }

    bool get_airborne()
    {
        return height > 50;
    }
};/*}}}*/

int main()
{
    cout << "Experiment 1: test the aircraft engine" << endl;
    IAircraft* aircraft = new Aircraft();
    aircraft->takeoff();
    if (aircraft->get_airborne())
    {
        cout << "The aircraft engine is fine, flying at " << aircraft->get_height() << " meters" << endl;
    }

    cout << "\nExperiment 2: Use the engine in the Seabird" << endl;
    IAircraft* seabird = new Seabird();
    seabird->takeoff();
    cout << "The Seabird engine is fine, flying at " << seabird->get_height() << " meters" << endl;
    cout << "The Seabird took off" << endl;

    cout << "\nExperiment 3: Increase the speed of the seabird" << endl;
    //seabird->increaseRevs();
    dynamic_cast<ISeacraft*>(seabird)->increaseRevs();
    dynamic_cast<ISeacraft*>(seabird)->increaseRevs();
    if (seabird->get_airborne())
    {
        cout << "Seabird flying at height " << seabird->get_height() << " meters and speed ";
        cout <<  dynamic_cast<ISeacraft*>(seabird)->get_speed() << " knots" << endl;
        cout << "Experiment successful: the Seabird flies!" << endl;
    }

    delete aircraft;
    delete seabird;
    return 0;
}
