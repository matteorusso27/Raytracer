#ifndef INTERVAL_H
#define INTERVAL_H

#include <limits>  // for std::numeric_limits

class interval {
public:
    double min, max;

    // Default constructor: empty interval
    interval() 
        : min(std::numeric_limits<double>::infinity()), 
          max(-std::numeric_limits<double>::infinity()) {}

    // Constructor with bounds
    interval(double min_val, double max_val) 
        : min(min_val), max(max_val) {}

    // Returns the size of the interval
    double size() const {
        return max - min;
    }

    // Check if a value is inside [min, max]
    bool contains(double x) const {
        return min <= x && x <= max;
    }

    // Check if a value is strictly inside (min, max)
    bool surrounds(double x) const {
        return min < x && x < max;
    }

    double clamp(double x) const {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }

    // Static constants for convenience
    static const interval empty;
    static const interval universe;
};

// Definition of static constants
const interval interval::empty = interval(
    std::numeric_limits<double>::infinity(),
    -std::numeric_limits<double>::infinity()
);

#endif