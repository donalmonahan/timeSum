/*==================================================================
 *
 *               University College Dublin
 *      COMP20080 - Computer Science for Engineers II
 *
 * File Name	:	timeSum.cpp
 *
 * Description	: This program takes 3 times as input, each
 *                comprising hours, minutes and seconds components.
 *                The two shorter times, and twice the longest time,
 *                are added together. Time objects are stored
 *                together as structs.
 *
 * Author		:	Donal C. Monahan
 *
 * Date			:	18-09-23
 *
 *==================================================================*/

#include <iostream>
using namespace std;

/* struct definition */
struct timet
{
  int hours;
  int minutes;
  int seconds;
};

/* function prototypes */
timet calcTime(timet, timet, timet);
int maxTime(int, int, int);
timet convertTime(int);

int main()
{
  timet t1, t2, t3;
  timet sum;

  cout << "This program requires you to enter 3 time values.\nEach time value is to consist of 3 components: hours, minutes and seconds.\nAll values entered must not be less than zero. \n\nPlease enter the hours component of the first time: ";
  cin >> t1.hours;
  cout << "Please enter the minutes component of the first time: ";
  cin >> t1.minutes;
  cout << "Please enter the seconds component of the first time: ";
  cin >> t1.seconds;
  cout << "The first time is " << t1.hours << " hours, " << t1.minutes << " minutes and " << t1.seconds << " seconds.\n\nPlease enter the hours component of the second time: ";

  cin >> t2.hours;
  cout << "Please enter the minutes component of the second time: ";
  cin >> t2.minutes;
  cout << "Please enter the seconds component of the second time: ";
  cin >> t2.seconds;
  cout << "The second time is " << t2.hours << " hours, " << t2.minutes << " minutes and " << t2.seconds << " seconds.\n\nPlease enter the hours component of the third time: ";

  cin >> t3.hours;
  cout << "Please enter the minutes component of the third time: ";
  cin >> t3.minutes;
  cout << "Please enter the seconds component of the third time: ";
  cin >> t3.seconds;
  cout << "The third time is " << t3.hours << " hours, " << t3.minutes << " minutes and " << t3.seconds << " seconds.\n\n";

  sum = calcTime(t1, t2, t3); /* calcTime function takes all 3 times as arguments */

  cout << "The sum of the two shorter times, and twice the longest time is " << sum.hours << " hours, " << sum.minutes << " minutes and " << sum.seconds << " seconds.\n";

  return 0;
}

timet calcTime(timet t1, timet t2, timet t3)
{
  timet t4;
  int seconds1, seconds2, seconds3, seconds4, maxtime;

  /* convert times to seconds */
  seconds1 = t1.hours * 60 * 60 + t1.minutes * 60 + t1.seconds;
  seconds2 = t2.hours * 60 * 60 + t2.minutes * 60 + t2.seconds;
  seconds3 = t3.hours * 60 * 60 + t3.minutes * 60 + t3.seconds;

  /* determine longest time */
  maxtime = maxTime(seconds1, seconds2, seconds3);

  /* calculation */
  seconds4 = seconds1 + seconds2 + seconds3 + maxtime; /* each time added once; longest time added once more */

  /* convert back to hours/minutes/seconds */
  t4 = convertTime(seconds4);

  return t4;
}

int maxTime(int seconds1, int seconds2, int seconds3)
{
  int maxtime = 0;

  if (seconds1 > maxtime)
    maxtime = seconds1;

  if (seconds2 > maxtime)
    maxtime = seconds2;

  if (seconds3 > maxtime)
    maxtime = seconds3;

  return maxtime;
}

timet convertTime(int seconds4)
{
  timet t4;
  int remaining_sec;

  t4.hours = seconds4 / (60 * 60); /* total number of hours */
  remaining_sec = seconds4 % (60 * 60); /* remaining seconds after hours accounted for */

  t4.minutes = remaining_sec / 60; /* number of minutes in remaining number of seconds */
  remaining_sec = remaining_sec % 60; /* remaining seconds after hours and minutes accounted for */

  t4.seconds = remaining_sec;

  return t4;
}
