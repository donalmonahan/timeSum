/*==================================================================
 *
 *               University College Dublin
 *      COMP20080 - Computer Science for Engineers II
 *
 * File Name	:	timeSumAlt.cpp
 *
 * Description	: This program takes 3 times as input, each
 *                comprising hours, minutes and seconds components.
 *                The two shorter times, and twice the longest time,
 *                are added together. Time components are passed
 *                to functions as reference variables.
 *
 * Author		:	Donal C. Monahan
 *
 * Date			:	04-10-23
 *
 *==================================================================*/

/*  this version of the program uses reference variables instead of
    structures for returning more than one value from a function    */

#include <iostream>
using namespace std;

/* function prototypes */
void calcTime(int&, int&, int&, int&, int&, int&, int&, int&, int&, int&, int&, int&);
int maxTime(int, int, int);

int main()
{
  int t1_hours, t1_minutes, t1_seconds;
  int t2_hours, t2_minutes, t2_seconds;
  int t3_hours, t3_minutes, t3_seconds;
  int sum_hours, sum_minutes, sum_seconds;

  cout << "This program requires you to enter 3 time values.\nEach time value is to consist of 3 components: hours, minutes and seconds.\nAll values entered must not be less than zero. \n\nPlease enter the hours component of the first time: ";
  cin >> t1_hours;
  cout << "Please enter the minutes component of the first time: ";
  cin >> t1_minutes;
  cout << "Please enter the seconds component of the first time: ";
  cin >> t1_seconds;
  cout << "The first time is " << t1_hours << " hours, " << t1_minutes << " minutes and " << t1_seconds << " seconds.\n\nPlease enter the hours component of the second time: ";

  cin >> t2_hours;
  cout << "Please enter the minutes component of the second time: ";
  cin >> t2_minutes;
  cout << "Please enter the seconds component of the second time: ";
  cin >> t2_seconds;
  cout << "The second time is " << t2_hours << " hours, " << t2_minutes << " minutes and " << t2_seconds << " seconds.\n\nPlease enter the hours component of the third time: ";

  cin >> t3_hours;
  cout << "Please enter the minutes component of the third time: ";
  cin >> t3_minutes;
  cout << "Please enter the seconds component of the third time: ";
  cin >> t3_seconds;
  cout << "The third time is " << t3_hours << " hours, " << t3_minutes << " minutes and " << t3_seconds << " seconds.\n\n";

  calcTime(t1_hours, t1_minutes, t1_seconds, t2_hours, t2_minutes, t2_seconds, t3_hours, t3_minutes, t3_seconds, sum_hours, sum_minutes, sum_seconds); /* calcTime function takes all 3 times as arguments */

  cout << "The sum of the two shorter times, and twice the longest time is " << sum_hours << " hours, " << sum_minutes << " minutes and " << sum_seconds << " seconds.\n";

  return 0;
}

void calcTime(int& h1, int& m1, int& s1, int& h2, int& m2, int& s2, int& h3, int& m3, int& s3, int& sh, int& sm, int& ss)
{
  int seconds1, seconds2, seconds3, seconds4, maxtime, remaining_sec;

  /* convert times to seconds */
  seconds1 = h1 * 60 * 60 + m1 * 60 + s1;
  seconds2 = h2 * 60 * 60 + m2 * 60 + s2;
  seconds3 = h3 * 60 * 60 + m3 * 60 + s3;

  /* determine longest time */
  maxtime = maxTime(seconds1, seconds2, seconds3);

  /* calculation */
  seconds4 = seconds1 + seconds2 + seconds3 + maxtime; /* each time added once; longest time added once more */

  /* convert back to hours/minutes/seconds */
  sh = seconds4 / (60 * 60); /* total number of hours */
  remaining_sec = seconds4 % (60 * 60); /* remaining seconds after hours accounted for */

  sm = remaining_sec / 60; /* number of minutes in remaining number of seconds */
  remaining_sec = remaining_sec % 60; /* remaining seconds after hours and minutes accounted for */

  ss = remaining_sec;
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
