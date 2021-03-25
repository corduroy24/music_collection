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

#ifndef _Subject_H
#define _Subject_H

#include <set>
#include <iostream>

using namespace std;

class Subject {
//    =======
protected:
 set<Observer*> observers;
public:
  void attach(Observer & obs) {
   observers.insert(&obs);
   cout << "observers: " << endl;
   for(set<Observer*>::iterator itr=observers.begin(); itr!=observers.end(); ++itr)
    cout << (*itr) <<endl;

    obs.update(this);
  }
  void dettach(Observer & obs) {
   observers.erase(&obs);
   cout << "observers: " << endl;
   for(set<Observer*>::iterator itr=observers.begin(); itr!=observers.end(); ++itr)
   {
     cout << (*itr) <<endl;
     if(observers.size() == 0) return;
}
  }

protected:
  void notify() {

   //notify all observers that something about the subject they
   //are watching has changed. concrete subclasses should call
   //this method whenever a state change has ocurred that
   //observers might be interested in

   //Note: observer collection is copied and the copy
   //iterated over so that observers can dettach
   //when they are being notified (i.e. double buffering)

   //In the Gamma pattern this is not done and that code will
   //blow up in a situtation where observers choose to detach as
   //a result of being notified

    set<Observer*> observers_copy = observers; //make copy to iterate over
   for(set<Observer*>::iterator itr = observers_copy.begin(); itr != observers_copy.end(); itr++) {
      (*itr)->update(this);
   }
  }

  ~Subject(){
    cout << "~Subject(void)" << endl;
    for(set<Observer*>::iterator itr=observers.begin(); itr!=observers.end(); ++itr){
      cout << (*itr) <<endl;
      this->dettach(**itr);
    }
  }


};

#endif
