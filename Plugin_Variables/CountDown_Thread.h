/* ----------------------------------------------------------------- */
/*           The Toolkit for Building Voice Interaction Systems      */
/*           "MMDAgent" developed by MMDAgent Project Team           */
/*           http://www.mmdagent.jp/                                 */
/* ----------------------------------------------------------------- */
/*                                                                   */
/*  Copyright (c) 2009-2011  Nagoya Institute of Technology          */
/*                           Department of Computer Science          */
/*                                                                   */
/* All rights reserved.                                              */
/*                                                                   */
/* Redistribution and use in source and binary forms, with or        */
/* without modification, are permitted provided that the following   */
/* conditions are met:                                               */
/*                                                                   */
/* - Redistributions of source code must retain the above copyright  */
/*   notice, this list of conditions and the following disclaimer.   */
/* - Redistributions in binary form must reproduce the above         */
/*   copyright notice, this list of conditions and the following     */
/*   disclaimer in the documentation and/or other materials provided */
/*   with the distribution.                                          */
/* - Neither the name of the MMDAgent project team nor the names of  */
/*   its contributors may be used to endorse or promote products     */
/*   derived from this software without specific prior written       */
/*   permission.                                                     */
/*                                                                   */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND            */
/* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,       */
/* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF          */
/* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE          */
/* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS */
/* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,          */
/* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED   */
/* TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     */
/* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON */
/* ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,   */
/* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY    */
/* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE           */
/* POSSIBILITY OF SUCH DAMAGE.                                       */
/* ----------------------------------------------------------------- */

/* definitions */

#define COUNTDOWNTHREAD_SLEEPMS         100                 /* check per 0.1 sec */
#define COUNTDOWNTHREAD_TIMERSTARTEVENT "TIMER_EVENT_START"
#define COUNTDOWNTHREAD_TIMERSTOPEVENT  "TIMER_EVENT_STOP"

/* CountDown: timer */
typedef struct _CountDown {
   char *name;
   double goal;
   struct _CountDown *prev;
   struct _CountDown *next;
} CountDown;

/* CountDown_Thread: thread for CountDown */
class CountDown_Thread
{
private:

   CountDown *m_head;
   CountDown *m_tail;

   MMDAgent *m_mmdagent;

   GLFWmutex m_mutex;   /* mutex */
   GLFWthread m_thread; /* thread */

   bool m_kill;

   /* initialize: initialize thread */
   void initialize();

   /* clear: free thread */
   void clear();

public:

   /* CountDown_Thraed: thread constructor */
   CountDown_Thread();

   /* ~CountDown_Thread: thread destructor */
   ~CountDown_Thread();

   /* setupAndStart: load variables and start thread */
   void setupAndStart(MMDAgent *mmdagent);

   /* run: main loop */
   void run();

   /* isRunning: check running */
   bool isRunning();

   /* stopAndRelease: stop thread and free CountDown */
   void stopAndRelease();

   /* set: set timer */
   void set(const char *alias, const char *str);

   /* unset: unset timer */
   void unset(const char *alias);
};
