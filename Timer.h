#ifndef TIMER_H_
#define TIMER_H_

#include<chrono>
#include<iostream>

//typedef to make less typing
typedef std::chrono::high_resolution_clock myClock;

class Timer
{
	//time point variable to hold the starting time
	std::chrono::time_point<myClock> begin;

	//duration variable to hold the total seconds passed
	//between start() and stop() stored as a double
	std::chrono::duration<double> elapsedTime;

public:

	void start()
	{
		//assign the current time to begin
		begin = myClock::now();
	}

	void stop()
	{
		//take the current time and subtract the begin time
		//and store the results in elapsedTime
		elapsedTime = myClock::now() - begin;
	}

	//overload the ostream operator for outputting the elapsed time
	friend std::ostream& operator << (std::ostream&, const Timer&);
};

std::ostream& operator << (std::ostream& out, const Timer& t)
{
	out << t.elapsedTime.count();
	return out;
}

#endif /* TIMER_H_ */
