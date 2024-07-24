#include <bits/stdc++.h>
using namespace std;

class Job {
	public:
		int time;
		int deadline;

		Job(int t, int d) {
			time = t;
			deadline = d;
		}
};

bool cmp(Job j1, Job j2) {
	return j1.deadline < j2.deadline;
}

int minMaxLateness(vector<int> time, vector<int> deadline, int n) {
	vector<Job> job;
	for(int i = 0; i < n; ++i) {
		Job curJob(time[i], deadline[i]);
		job.push_back(curJob);
	}

	sort(job.begin(), job.end(), cmp);

	int curTime = 0, maxLatenessSoFar = 0;
	for(int i = 0; i < n; ++i) {
		int curDeadlne = job[i].deadline;
		int curEnd = curTime + job[i].time;

		maxLatenessSoFar = max(maxLatenessSoFar, curEnd - curDeadlne);
		curTime = curEnd;
	}
	return maxLatenessSoFar;
}

int main() {
	int n; cin >> n;
	vector<int> time(n), deadline(n);

	for(int i = 0; i < n; ++i)
		cin >> time[i] >> deadline[i];

	cout << minMaxLateness(time, deadline, n) << '\n';
 	return 0;
}