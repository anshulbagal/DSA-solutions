class Solution {
public:
    double angleClock(int hour, int minutes) {
        // convert 12 -> 0
        hour = hour % 12;

        double minute_angle = minutes * 6;          // 6 degrees per minute
        double hour_angle = hour * 30 + minutes * 0.5; // 30 per hour + movement

        double angle = abs(hour_angle - minute_angle);

        return min(angle, 360 - angle);
    }
};