//
// Created by Grove on 2017-05-17.
//

#include "Scheduler.h"


namespace academia {
    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule teacher_wektor;

        for (auto n : scheduled_items_) {
            if (n.TeacherId() == teacher_id) {
                teacher_wektor.InsertScheduleItem(n);
            }
        }
        return teacher_wektor;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule room_wektor;

        for (auto &n : scheduled_items_) {
            if (n.RoomId() == room_id) {
                room_wektor.InsertScheduleItem(n);
            }
        }

        return room_wektor;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule year_wektor;

        for (auto &n : scheduled_items_) {
            if (n.Year() == year) {
                year_wektor.InsertScheduleItem(n);
            }
        }

        return year_wektor;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        bool is_available[n_time_slots + 1];
        std::vector<int> available_slots;

        for (int i = 1; i < n_time_slots + 1; ++i) {
            is_available[i] = true;
        }
        for (auto n : scheduled_items_) {
            is_available[n.TimeSlot()] = false;
        }
        for (int j = 1; j < n_time_slots + 1; ++j) {
            if (is_available[j]) {
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
        teacher_id_ = teacher_id;
        room_id_ = room_id;
        time_slot_ = time_slot;
        year_ = year;
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

        Schedule schedule;
        int actual_time_slot = 1;
        int actual_room = 0;
        int room_count = rooms.size();
        bool found_solution = false;
        vector<int> used_years_an_hour[n_time_slots + 1];


        for (auto &teacher_assignment : teacher_courses_assignment) {
            int teacher_id = teacher_assignment.first;
            std::vector<int> teacher_courses = teacher_assignment.second;

            for (auto &teacher_single_course : teacher_courses) {
                found_solution = false;

                for (auto &year_assignment : courses_of_year) {
                    int year_id = year_assignment.first;
                    std::set<int> year_courses = year_assignment.second;

                    for (auto &year_single_course : year_courses) {

                        if (teacher_single_course == year_single_course and
                            std::find(used_years_an_hour[actual_time_slot].begin(),
                                      used_years_an_hour[actual_time_slot].end(), year_id) ==
                            used_years_an_hour[actual_time_slot].end())
                        {
                            found_solution = true;
                            schedule.InsertScheduleItem(
                                    SchedulingItem(teacher_single_course, teacher_id, rooms[actual_room],
                                                   actual_time_slot, year_id));
                            used_years_an_hour[actual_time_slot].emplace_back(year_id);
                            if (actual_room == room_count and actual_time_slot == n_time_slots-1) {
                                throw NoViableSolutionFound("No Viable Solution Found");
                            }

                            if (actual_time_slot < n_time_slots) {
                                actual_time_slot++;
                            } else if (actual_time_slot == n_time_slots) {
                                actual_time_slot = 0;
                                actual_room++;
                            }
                        }
                    }
                }
                if (!found_solution) { throw NoViableSolutionFound("No Viable Solution Found"); }
            }
        }


        return schedule;
    }


}