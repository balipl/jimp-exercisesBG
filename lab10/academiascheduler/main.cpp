//
// Created by Grove on 2017-05-17.
//

#include "Scheduler.h"

    int main() {

/*
        academia::Schedule schedule;
        schedule.InsertScheduleItem(academia::SchedulingItem {0, 1, 2, 3, 4});
        schedule.InsertScheduleItem(academia::SchedulingItem {5, 33, 7, 5, 2});
        schedule.InsertScheduleItem(academia::SchedulingItem {10, 1, 12, 8, 1});
        schedule.InsertScheduleItem(academia::SchedulingItem {15, 4, 7, 8, 2});
        schedule.InsertScheduleItem(academia::SchedulingItem {35, 35, 37, 9, 1});

            schedule.AvailableTimeSlots(10);
        */
        vector<int> rooms{1000, 2000};
        std::map<int, vector<int>> teachers{make_pair(100, vector<int>{10, 10, 10}), make_pair(200, vector<int>{10, 10})};
        std::map<int, set<int>> years{make_pair(1, set<int>{10})};

        academia::Schedule schedule;
        std::unique_ptr<academia::Scheduler> scheduler = std::make_unique<academia::GreedyScheduler>();
        schedule = scheduler->PrepareNewSchedule(rooms, teachers,years,3);

        for( auto &x : schedule.scheduled_items_)
        {
            cout << x.TeacherId() << " " << x.Year()  << " " << x.CourseId()<< " " << x.RoomId() << " " << x.TimeSlot() << std::endl;
        }
        return 0;
    }
