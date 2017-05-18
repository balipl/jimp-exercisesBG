//
// Created by Grove on 2017-05-17.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <map>
#include <set>
#include <stdexcept>
#include <iostream>
#include <initializer_list>
#include <memory>
#include <algorithm>


using std::vector;
using std::make_pair;
using std::set;
using std::cout;
namespace academia {

    class SchedulingItem {
    public:

    SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year);
    private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot_;
        int year_;

    public:
        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;
    };
    class Schedule {
    public:
        Schedule();
        Schedule OfTeacher(int teacher_id) const;

        Schedule OfRoom(int room_id) const;

        Schedule OfYear(int year) const;

        std::vector<int> AvailableTimeSlots(int n_time_slots) const;

        void InsertScheduleItem(const SchedulingItem &item);

        size_t Size() const;

        SchedulingItem operator[](const int &schedule_item_number)const;

    public:


   std::vector<SchedulingItem> scheduled_items_;
    };



    class Scheduler {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots)=0;
    };

    class GreedyScheduler : public Scheduler{
    public:
        GreedyScheduler(){};
        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                            const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                            const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override ;
    };


    //wyjatek
    class NoViableSolutionFound : public std::invalid_argument {
    public:
        NoViableSolutionFound(std::string err_message) : std::invalid_argument{err_message} {};
    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
