/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Contributors:   Korede Adegboye 101001124        */
/* 									Emmanuel Dairo 101010678   			 */
/* 	Date:     DEC-2017                               */
/*                                                   */
/*  (c) Dec 2017                                     */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _Observer_H
#define _Observer_H

#include <string.h>

class Subject;
class Observer {
  public:
  virtual void update(Subject * subject)= 0;

  //virtual void printOn(ostream & out) const = 0;

  int operator==(const Observer & obs) const {
    return this == & obs;
  }

};

/*ostream & operator<<(ostream & out, const Observer & obs) {
 obs.printOn(out);
 return out;
}*/

#endif
