//
// Created by Grove on 2017-05-17.
//

#include "Scheduler.h"


namespace academia
{
    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule teacher_wektor;

        for( auto n : scheduled_items_)
        {
            if(n.TeacherId() == teacher_id)
            {
                teacher_wektor.InsertScheduleItem(n);
            }
        }
        return teacher_wektor;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule room_wektor;

        for(auto &n : scheduled_items_)
        {
            if(n.RoomId() == room_id)
            {
                room_wektor.InsertScheduleItem(n);
            }
        }

        return room_wektor;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule year_wektor;

        for(auto &n : scheduled_items_)
        {
            if(n.Year() == year)
            {
                year_wektor.InsertScheduleItem(n);
            }
        }

        return year_wektor;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        bool is_available[n_time_slots+1];
        std::vector<int> available_slots;

        for (int i = 1; i < n_time_slots+1; ++i) {
            is_available[i]= true;
        }
        for(auto n : scheduled_items_)
        {
            is_available[n.TimeSlot()] = false;
        }
        for (int j = 1; j < n_time_slots+1; ++j) {
            if(is_available[j])
            {
                available_slots.emplace_back(j);
            }
        }
        return available_slots;
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
scheduled_items_.emplace_back(item);
    }

    size_t Schedule::Size() const {
        return scheduled_items_.size();
    }

    SchedulingItem Schedule::operator[](const int &schedule_item_number) const {
        return SchedulingItem(this->scheduled_items_[schedule_item_number]);
    }

    Schedule::Schedule() {

    }

    SchedulingItem::SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year) {
        course_id_ = course_id;
        teacher_id_=teacher_id;
        room_id_=room_id;
        time_slot_ = time_slot;
        year_=year;
    }

    int SchedulingItem::CourseId() const {
        return course_id_;
    }

    int SchedulingItem::TeacherId() const {
        return teacher_id_;
    }

    int SchedulingItem::RoomId() const {
        return room_id_;
    }

    int SchedulingItem::TimeSlot() const {
        return time_slot_;
    }

    int SchedulingItem::Year() const {
        return year_;
    }


    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {


        return Schedule();
    }



}