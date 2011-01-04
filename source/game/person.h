#ifndef OSS_PERSON_H
#define OSS_PERSON_H


#include "../general.h"
#include "../core/coreobject.h"
#include "item.h"
#include "route.h"


namespace OSS {	
	class Person : public CoreObject {
	protected:
		const Pointer<Tower> tower;
		
	public:
		//Initialization
		Person(Tower * tower);
		
		/**
		 * Location
		 */
	private:
		int floor;
		Pointer<Item> item;
		double arrivalTime;
	public:
		//Floor
		int getFloor();
		void setFloor(int floor);
		
		//Item
		Item * getItem() const;
		void setItem(Item * item);
		
		//Arrival time
		double getArrivalTime();
		void setArrivalTime(double time);
		
		//Convenience
		double getTimeSinceArrival();
		bool isAt(Item * item);
		bool hasBeenAtFor(Item * item, double duration);
		
		
		/**
		 * Journey
		 */
	private:
		int nextFloor;
		unsigned int nodeIndex;
	public:
		int getNextFloor();
		void setNextFloor(int nextFloor);
		void initJourney();
		void advanceJourney();
		
		
		/**
		 * Route
		 */
	private:
		Pointer<Item> destination;
		Pointer<Route> route;
	public:
		Item * getDestination();
		void setDestination(Item * destination);
		Route * getRoute();
		void setRoute(Route * route);
		void updateRoute();
		
		
		/**
		 * Notifications
		 */
		virtual void onArrivedAtDestination();
	};
}


#endif
