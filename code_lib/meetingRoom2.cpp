

/*
    write the body of the is_overlapp function below:
    // A. time interval is defined as
    typdef struct {
        unit32_t start; // Time stamp of the interval start point (inclusive)
        uint32_t stop;  // Time stamp of the interval end point (inclusive)
    } time_interval_t;

    // intervals[] - an array of time intervals sorted by the 'start' field, followed by the 'stop' field.
    // 
    // count - number of elements in intervals
    // new_interval - a new time interval to be tested
    //
    // returns - true if new_interval overlaps in time with any interval in the intervals array, false other

    int comp(void **x, void **y) {
        int *a = (int **)x;
        int *b = (int **)y;
        
        if(a[0] == b[0]) {
            return a[1] - b[1];
        }

        return a[0] - b[0];
    }

    bool is_overlapp(time_interval_t intervals, uint32_t count, time_interval_t new_interval) {
        // 1. sort intervals
        qsort(intervals, count, sizeof(uint32_t), comp);
        // 2. if new_interval[0][1] < first[0], return false
        // 3. if new_interval[size - 1][0] > last[1], return false
        // 4. if new_interval[0] >= intervals[i][1] && new_interval[1] <= intervals[i + 1][0] return false
        // 5. return true;
    }
*/