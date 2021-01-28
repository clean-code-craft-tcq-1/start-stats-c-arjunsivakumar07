#include "stats.h"
#include <math.h>

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 9999;
    s.max = 0;
	float sum =0;
	if(setlength == 0)
	{
		s.average = NAN;
		s.min = NAN;
		s.max = NAN;
	}
	else
	{
		for(int i = 0; i < setlength; i++,numberset++)
		{
			sum+=*numberset;
			if(s.min>*numberset)
				s.min = *numberset;
			if(s.max<*numberset)
				s.max = *numberset;
		}
		s.average = sum/setlength;
	}
	return s;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
	alerters[0]();
	alerters[1]();
}
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
