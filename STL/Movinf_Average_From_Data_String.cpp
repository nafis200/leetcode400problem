// 0 - 3 months:
// Meta (37) — Spotify (6) — Amazon (4)

// 0 - 6 months:
// Google (5) — Bloomberg (2)

// 6 months ago:
// Arista Networks (3) — Microsoft (2) — LinkedIn (2) — Citadel (2) — ZScaler (2)

// problem_Link:https://www.hellointerview.com/community/questions/moving-average-stream/cm5eh7nri04wm838ohohaia3c

class MovingAverage {
public:
    int k;
    deque<int> dq;
    long long sum;

    MovingAverage(int size) {
        k = size;
        sum = 0;
    }

    double next(int val) {
        dq.push_back(val);
        sum += val;

        if (dq.size() > k) {
            sum -= dq.front();
            dq.pop_front();
        }

        return (double)sum / dq.size();
    }
};