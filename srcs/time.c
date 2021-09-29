#include "philo.h"

long time_now(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		errors("error of time\n");
	return ((long)time.tv_sec * 1000 + time.tv_usec / 1000);
}