#ifndef OSS_TIMEDPERSON_H
#define OSS_TIMEDPERSON_H


#include "../general.h"
#include "person.h"


namespace OSS {
	class TimedPerson : public Person {
	public:
		//Initialization
		TimedPerson(Tower * tower) : Person(tower) {}
		
		
		/**
		 * Next Destination
		 */
	private:
		Pointer<Item> nextDestination;
		double nextDestinationTime;
		bool nextDestinationValid;
		double nextDestinationPauseDuration;
	public:
		
		//Information on the next destination
		Item * getNextDestination();
		double getNextDestinationTime();
		double getNextDestinationPauseDuration();
		bool isNextDestinationValid();
		
		//Changing the next destination
		void setNextDestination(Item * destination);
		void setNextDestination(Item * destination, double duration);
		void setNextDestination(double time, Item * destination);
		void setNextDestination(double time, Item * destination, double duration);
		void clearNextDestination();
		
		
		/**
		 * Route
		 */
		
		//Journey
		void updateTimedDestination();
		
		
		/**
		 * Location
		 */
	private:
		double pauseDurationAtDestination;
		double pauseDuration;
		double pauseEndTime;
	public:
		
		//Pause duration once arrived at the destination
		double getPauseDurationAtDestination();
		void setPauseDurationAtDestination(double duration);
		
		//Pause duration
		double getPauseDuration();
		void setPauseDuration(double duration);
		
		//End of pause
		double getPauseEndTime();
		void setPauseEndTime(double time);
		
		//Convenience
		bool isPausing();
		bool hasNoPlans();
		
		
		/**
		 * Notifications
		 */
		void onArrivedAtDestination();
	};
}


#endif
