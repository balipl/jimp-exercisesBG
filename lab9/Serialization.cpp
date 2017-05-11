//
// Created by Grove on 2017-05-04.
//

#include "Serialization.h"

namespace academia{
    Building::Building(int id_, const std::string &name_, const std::vector<Room> &rooms_) : id_(id_), name_(name_),
                                                                                             rooms_(rooms_) {}
    std::string Room::TypeToString() const {
        switch(type_) {
            case Type ::CLASS_ROOM :
                return "CLASS_ROOM";
            case Type ::COMPUTER_LAB :
                return "COMPUTER_LAB";
            case Type ::LECTURE_HALL :
                return "LECTURE_HALL";
        }
    }


    Room::Room(int id_, const std::string &name_, Room::Type type_) : id_(id_), name_(name_), type_(type_) {}

    void Building::Serialize(Serializer *ser) const {

    }

    void Room::Serialize(Serializer *ser) const {

    }


    void XmlSerializer::IntegerField(const std::string &field_name, int value) {

    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {

    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {

    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {

    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {

    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {

    }

    void XmlSerializer::Header(const std::string &object_name) {

    }

    void XmlSerializer::Footer(const std::string &object_name) {

    }

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {

    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {

    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {

    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {

    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {

    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {

    }

    void JsonSerializer::Header(const std::string &object_name) {

    }

    void JsonSerializer::Footer(const std::string &object_name) {

    }
}