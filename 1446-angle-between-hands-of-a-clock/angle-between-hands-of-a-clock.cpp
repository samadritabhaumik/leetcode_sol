class Solution {
public:
    double angleClock(int hour, int minutes) {
        float hr=(hour%12+(float)minutes/60)*30;
        float min=minutes*6;
        float ang=fabs(hr-min);
        if(ang>180) ang=360-ang;
        return ang;
    }
};